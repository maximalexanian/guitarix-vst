#! /usr/bin/env python
# encoding: utf-8

import os,shlex,sys,time
try:import cPickle
except ImportError:import pickle as cPickle
import Environment,Utils,Options,Logs
from Logs import warn
from Constants import*
try:
	from urllib import request
except:
	from urllib import urlopen
else:
	urlopen=request.urlopen
conf_template='''# project %(app)s configured on %(now)s by
# waf %(wafver)s (abi %(abi)s, python %(pyver)x on %(systype)s)
# using %(args)s
#
'''
class ConfigurationError(Utils.WscriptError):
	pass
autoconfig=False
def find_file(filename,path_list):
	for directory in Utils.to_list(path_list):
		if os.path.exists(os.path.join(directory,filename)):
			return directory
	return''
def find_program_impl(env,filename,path_list=[],var=None,environ=None):
	if not environ:
		environ=os.environ
	try:path_list=path_list.split()
	except AttributeError:pass
	if var:
		if env[var]:return env[var]
		if var in environ:env[var]=environ[var]
	if not path_list:path_list=environ.get('PATH','').split(os.pathsep)
	ext=(Options.platform=='win32')and'.exe,.com,.bat,.cmd'or''
	for y in[filename+x for x in ext.split(',')]:
		for directory in path_list:
			x=os.path.join(directory,y)
			if os.path.isfile(x):
				if var:env[var]=x
				return x
	return''
class ConfigurationContext(Utils.Context):
	tests={}
	error_handlers=[]
	def __init__(self,env=None,blddir='',srcdir=''):
		self.env=None
		self.envname=''
		self.environ=dict(os.environ)
		self.line_just=40
		self.blddir=blddir
		self.srcdir=srcdir
		self.all_envs={}
		self.cwd=self.curdir=os.getcwd()
		self.tools=[]
		self.setenv(DEFAULT)
		self.lastprog=''
		self.hash=0
		self.files=[]
		self.tool_cache=[]
		if self.blddir:
			self.post_init()
	def post_init(self):
		self.cachedir=os.path.join(self.blddir,CACHE_DIR)
		path=os.path.join(self.blddir,WAF_CONFIG_LOG)
		try:os.unlink(path)
		except(OSError,IOError):pass
		try:
			self.log=open(path,'w')
		except(OSError,IOError):
			self.fatal('could not open %r for writing'%path)
		app=Utils.g_module.APPNAME
		if app:
			ver=getattr(Utils.g_module,'VERSION','')
			if ver:
				app="%s (%s)"%(app,ver)
		now=time.ctime()
		pyver=sys.hexversion
		systype=sys.platform
		args=" ".join(sys.argv)
		wafver=WAFVERSION
		abi=ABI
		self.log.write(conf_template%vars())
	def __del__(self):
		if hasattr(self,'log')and self.log:
			self.log.close()
	def fatal(self,msg):
		raise ConfigurationError(msg)
	def check_tool(self,input,tooldir=None,funs=None):
		tools=Utils.to_list(input)
		if tooldir:tooldir=Utils.to_list(tooldir)
		for tool in tools:
			tool=tool.replace('++','xx')
			if tool=='java':tool='javaw'
			if tool.lower()=='unittest':tool='unittestw'
			mag=(tool,id(self.env),funs)
			if mag in self.tool_cache:
				continue
			self.tool_cache.append(mag)
			module=None
			try:
				module=Utils.load_tool(tool,tooldir)
			except Exception as e:
				ex=e
				if Options.options.download:
					_3rdparty=os.path.normpath(Options.tooldir[0]+os.sep+'..'+os.sep+'3rdparty')
					for x in Utils.to_list(Options.remote_repo):
						for sub in['branches/waf-%s/wafadmin/3rdparty'%WAFVERSION,'trunk/wafadmin/3rdparty']:
							url='/'.join((x,sub,tool+'.py'))
							try:
								web=urlopen(url)
								if web.getcode()!=200:
									continue
							except Exception as e:
								continue
							else:
								loc=None
								try:
									loc=open(_3rdparty+os.sep+tool+'.py','wb')
									loc.write(web.read())
									web.close()
								finally:
									if loc:
										loc.close()
								Logs.warn('downloaded %s from %s'%(tool,url))
								try:
									module=Utils.load_tool(tool,tooldir)
								except:
									Logs.warn('module %s from %s is unusable'%(tool,url))
									try:
										os.unlink(_3rdparty+os.sep+tool+'.py')
									except:
										pass
									continue
						else:
							break
					if not module:
						Logs.error('Could not load the tool %r or download a suitable replacement from the repository (sys.path %r)\n%s'%(tool,sys.path,e))
						raise ex
				else:
					Logs.error('Could not load the tool %r in %r (try the --download option?):\n%s'%(tool,sys.path,e))
					raise ex
			if funs is not None:
				self.eval_rules(funs)
			else:
				func=getattr(module,'detect',None)
				if func:
					if type(func)is type(find_file):func(self)
					else:self.eval_rules(func)
			self.tools.append({'tool':tool,'tooldir':tooldir,'funs':funs})
	def sub_config(self,k):
		self.recurse(k,name='configure')
	def pre_recurse(self,name_or_mod,path,nexdir):
		return{'conf':self,'ctx':self}
	def post_recurse(self,name_or_mod,path,nexdir):
		if not autoconfig:
			return
		self.hash=hash((self.hash,getattr(name_or_mod,'waf_hash_val',name_or_mod)))
		self.files.append(path)
	def store(self,file=''):
		if not os.path.isdir(self.cachedir):
			os.makedirs(self.cachedir)
		if not file:
			file=open(os.path.join(self.cachedir,'build.config.py'),'w')
		file.write('version = 0x%x\n'%HEXVERSION)
		file.write('tools = %r\n'%self.tools)
		file.close()
		if not self.all_envs:
			self.fatal('nothing to store in the configuration context!')
		for key in self.all_envs:
			tmpenv=self.all_envs[key]
			tmpenv.store(os.path.join(self.cachedir,key+CACHE_SUFFIX))
	def set_env_name(self,name,env):
		self.all_envs[name]=env
		return env
	def retrieve(self,name,fromenv=None):
		try:
			env=self.all_envs[name]
		except KeyError:
			env=Environment.Environment()
			env['PREFIX']=os.path.abspath(os.path.expanduser(Options.options.prefix))
			self.all_envs[name]=env
		else:
			if fromenv:warn("The environment %s may have been configured already"%name)
		return env
	def setenv(self,name):
		self.env=self.retrieve(name)
		self.envname=name
	def add_os_flags(self,var,dest=None):
		try:self.env.append_value(dest or var,Utils.to_list(self.environ[var]))
		except KeyError:pass
	def check_message_1(self,sr):
		self.line_just=max(self.line_just,len(sr))
		for x in('\n',self.line_just*'-','\n',sr,'\n'):
			self.log.write(x)
		Utils.pprint('NORMAL',"%s :"%sr.ljust(self.line_just),sep='')
	def check_message_2(self,sr,color='GREEN'):
		self.log.write(sr)
		self.log.write('\n')
		Utils.pprint(color,sr)
	def check_message(self,th,msg,state,option=''):
		sr='Checking for %s %s'%(th,msg)
		self.check_message_1(sr)
		p=self.check_message_2
		if state:p('ok '+str(option))
		else:p('not found','YELLOW')
	def check_message_custom(self,th,msg,custom,option='',color='PINK'):
		sr='Checking for %s %s'%(th,msg)
		self.check_message_1(sr)
		self.check_message_2(custom,color)
	def msg(self,msg,result,color=None):
		self.start_msg('Checking for '+msg)
		if not isinstance(color,str):
			color=result and'GREEN'or'YELLOW'
		self.end_msg(result,color)
	def start_msg(self,msg):
		try:
			if self.in_msg:
				return
		except:
			self.in_msg=0
		self.in_msg+=1
		self.line_just=max(self.line_just,len(msg))
		for x in('\n',self.line_just*'-','\n',msg,'\n'):
			self.log.write(x)
		Utils.pprint('NORMAL',"%s :"%msg.ljust(self.line_just),sep='')
	def end_msg(self,result,color):
		self.in_msg-=1
		if self.in_msg:
			return
		if not color:
			color='GREEN'
		if result==True:
			msg='ok'
		elif result==False:
			msg='not found'
			color='YELLOW'
		else:
			msg=str(result)
		self.log.write(msg)
		self.log.write('\n')
		Utils.pprint(color,msg)
	def find_program(self,filename,path_list=[],var=None,mandatory=False):
		ret=None
		if var:
			if self.env[var]:
				ret=self.env[var]
			elif var in os.environ:
				ret=os.environ[var]
		if not isinstance(filename,list):filename=[filename]
		if not ret:
			for x in filename:
				ret=find_program_impl(self.env,x,path_list,var,environ=self.environ)
				if ret:break
		self.check_message_1('Checking for program %s'%' or '.join(filename))
		self.log.write('  find program=%r paths=%r var=%r\n  -> %r\n'%(filename,path_list,var,ret))
		if ret:
			Utils.pprint('GREEN',str(ret))
		else:
			Utils.pprint('YELLOW','not found')
			if mandatory:
				self.fatal('The program %r is required'%filename)
		if var:
			self.env[var]=ret
		return ret
	def cmd_to_list(self,cmd):
		if isinstance(cmd,str)and cmd.find(' '):
			try:
				os.stat(cmd)
			except OSError:
				return shlex.split(cmd)
			else:
				return[cmd]
		return cmd
	def __getattr__(self,name):
		r=self.__class__.__dict__.get(name,None)
		if r:return r
		if name and name.startswith('require_'):
			for k in['check_','find_']:
				n=name.replace('require_',k)
				ret=self.__class__.__dict__.get(n,None)
				if ret:
					def run(*k,**kw):
						r=ret(self,*k,**kw)
						if not r:
							self.fatal('requirement failure')
						return r
					return run
		self.fatal('No such method %r'%name)
	def eval_rules(self,rules):
		self.rules=Utils.to_list(rules)
		for x in self.rules:
			f=getattr(self,x)
			if not f:self.fatal("No such method '%s'."%x)
			try:
				f()
			except Exception as e:
				ret=self.err_handler(x,e)
				if ret==BREAK:
					break
				elif ret==CONTINUE:
					continue
				else:
					self.fatal(e)
	def err_handler(self,fun,error):
		pass
def conf(f):
	setattr(ConfigurationContext,f.__name__,f)
	return f
def conftest(f):
	ConfigurationContext.tests[f.__name__]=f
	return conf(f)

