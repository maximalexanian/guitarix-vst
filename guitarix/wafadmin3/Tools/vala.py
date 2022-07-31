#! /usr/bin/env python
# encoding: utf-8

import os.path,shutil
import Task,Runner,Utils,Logs,Build,Node,Options
from TaskGen import extension,after,before
EXT_VALA=['.vala','.gs']
class valac_task(Task.Task):
	vars=("VALAC","VALAC_VERSION","VALAFLAGS")
	before=("cc","cxx")
	def run(self):
		env=self.env
		inputs=[a.srcpath(env)for a in self.inputs]
		valac=env['VALAC']
		vala_flags=env.get_flat('VALAFLAGS')
		top_src=self.generator.bld.srcnode.abspath()
		top_bld=self.generator.bld.srcnode.abspath(env)
		if env['VALAC_VERSION']>(0,1,6):
			cmd=[valac,'-C','--quiet',vala_flags]
		else:
			cmd=[valac,'-C',vala_flags]
		if self.threading:
			cmd.append('--thread')
		if self.profile:
			cmd.append('--profile=%s'%self.profile)
		if self.target_glib:
			cmd.append('--target-glib=%s'%self.target_glib)
		features=self.generator.features
		if'cshlib'in features or'cstaticlib'in features:
			output_dir=self.outputs[0].bld_dir(env)
			cmd.append('--library '+self.target)
			if env['VALAC_VERSION']>=(0,7,0):
				for x in self.outputs:
					if x.name.endswith('.h'):
						cmd.append('--header '+x.bldpath(self.env))
			cmd.append('--basedir '+top_src)
			cmd.append('-d '+top_bld)
			if env['VALAC_VERSION']>(0,7,2)and hasattr(self,'gir'):
				cmd.append('--gir=%s.gir'%self.gir)
		else:
			output_dir=self.outputs[0].bld_dir(env)
			cmd.append('-d %s'%output_dir)
		for vapi_dir in self.vapi_dirs:
			cmd.append('--vapidir=%s'%vapi_dir)
		for package in self.packages:
			cmd.append('--pkg %s'%package)
		for package in self.packages_private:
			cmd.append('--pkg %s'%package)
		cmd.append(" ".join(inputs))
		result=self.generator.bld.exec_command(" ".join(cmd))
		if not'cprogram'in features:
			if self.packages:
				filename=os.path.join(self.generator.path.abspath(env),"%s.deps"%self.target)
				deps=open(filename,'w')
				for package in self.packages:
					deps.write(package+'\n')
				deps.close()
			self._fix_output("../%s.vapi"%self.target)
			self._fix_output("%s.vapi"%self.target)
			self._fix_output("%s.gidl"%self.target)
			self._fix_output("%s.gir"%self.target)
			if hasattr(self,'gir'):
				self._fix_output("%s.gir"%self.gir)
		first=None
		for node in self.outputs:
			if not first:
				first=node
			else:
				if first.parent.id!=node.parent.id:
					if env['VALAC_VERSION']<(0,7,0):
						shutil.move(first.parent.abspath(self.env)+os.sep+node.name,node.abspath(self.env))
		return result
	def install(self):
		bld=self.generator.bld
		features=self.generator.features
		if self.attr("install_path")and("cshlib"in features or"cstaticlib"in features):
			headers_list=[o for o in self.outputs if o.suffix()==".h"]
			vapi_list=[o for o in self.outputs if(o.suffix()in(".vapi",".deps"))]
			gir_list=[o for o in self.outputs if o.suffix()==".gir"]
			for header in headers_list:
				top_src=self.generator.bld.srcnode
				package=self.env['PACKAGE']
				try:
					api_version=Utils.g_module.API_VERSION
				except AttributeError:
					version=Utils.g_module.VERSION.split(".")
					if version[0]=="0":
						api_version="0."+version[1]
					else:
						api_version=version[0]+".0"
				install_path='${INCLUDEDIR}/%s-%s/%s'%(package,api_version,header.relpath_gen(top_src))
				bld.install_as(install_path,header,self.env)
			bld.install_files('${DATAROOTDIR}/vala/vapi',vapi_list,self.env)
			bld.install_files('${DATAROOTDIR}/gir-1.0',gir_list,self.env)
	def _fix_output(self,output):
		top_bld=self.generator.bld.srcnode.abspath(self.env)
		try:
			src=os.path.join(top_bld,output)
			dst=self.generator.path.abspath(self.env)
			shutil.move(src,dst)
		except:
			pass
def vala_file(self,node):
	valatask=getattr(self,"valatask",None)
	if not valatask:
		valatask=self.create_task('valac')
		self.valatask=valatask
		self.includes=Utils.to_list(getattr(self,'includes',[]))
		self.uselib=self.to_list(self.uselib)
		valatask.packages=[]
		valatask.packages_private=Utils.to_list(getattr(self,'packages_private',[]))
		valatask.vapi_dirs=[]
		valatask.target=self.target
		valatask.threading=False
		valatask.install_path=self.install_path
		valatask.profile=getattr(self,'profile','gobject')
		valatask.target_glib=None
		packages=Utils.to_list(getattr(self,'packages',[]))
		vapi_dirs=Utils.to_list(getattr(self,'vapi_dirs',[]))
		includes=[]
		if hasattr(self,'uselib_local'):
			local_packages=Utils.to_list(self.uselib_local)
			seen=[]
			while len(local_packages)>0:
				package=local_packages.pop()
				if package in seen:
					continue
				seen.append(package)
				package_obj=self.name_to_obj(package)
				if not package_obj:
					raise Utils.WafError("object '%s' was not found in uselib_local (required by '%s')"%(package,self.name))
				package_name=package_obj.target
				package_node=package_obj.path
				package_dir=package_node.relpath_gen(self.path)
				for task in package_obj.tasks:
					for output in task.outputs:
						if output.name==package_name+".vapi":
							valatask.set_run_after(task)
							if package_name not in packages:
								packages.append(package_name)
							if package_dir not in vapi_dirs:
								vapi_dirs.append(package_dir)
							if package_dir not in includes:
								includes.append(package_dir)
				if hasattr(package_obj,'uselib_local'):
					lst=self.to_list(package_obj.uselib_local)
					lst.reverse()
					local_packages=[pkg for pkg in lst if pkg not in seen]+local_packages
		valatask.packages=packages
		for vapi_dir in vapi_dirs:
			try:
				valatask.vapi_dirs.append(self.path.find_dir(vapi_dir).abspath())
				valatask.vapi_dirs.append(self.path.find_dir(vapi_dir).abspath(self.env))
			except AttributeError:
				Logs.warn("Unable to locate Vala API directory: '%s'"%vapi_dir)
		self.includes.append(node.bld.srcnode.abspath())
		self.includes.append(node.bld.srcnode.abspath(self.env))
		for include in includes:
			try:
				self.includes.append(self.path.find_dir(include).abspath())
				self.includes.append(self.path.find_dir(include).abspath(self.env))
			except AttributeError:
				Logs.warn("Unable to locate include directory: '%s'"%include)
		if valatask.profile=='gobject':
			if hasattr(self,'target_glib'):
				Logs.warn('target_glib on vala tasks is deprecated --vala-target-glib=MAJOR.MINOR from the vala tool options')
			if getattr(Options.options,'vala_target_glib',None):
				valatask.target_glib=Options.options.vala_target_glib
			if not'GOBJECT'in self.uselib:
				self.uselib.append('GOBJECT')
		if hasattr(self,'threading'):
			if valatask.profile=='gobject':
				valatask.threading=self.threading
				if not'GTHREAD'in self.uselib:
					self.uselib.append('GTHREAD')
			else:
				Logs.warn("Profile %s does not have threading support"%valatask.profile)
		if hasattr(self,'gir'):
			valatask.gir=self.gir
	env=valatask.env
	output_nodes=[]
	c_node=node.change_ext('.c')
	output_nodes.append(c_node)
	self.allnodes.append(c_node)
	if env['VALAC_VERSION']<(0,7,0):
		output_nodes.append(node.change_ext('.h'))
	else:
		if not'cprogram'in self.features:
			output_nodes.append(self.path.find_or_declare('%s.h'%self.target))
	if not'cprogram'in self.features:
		output_nodes.append(self.path.find_or_declare('%s.vapi'%self.target))
		if env['VALAC_VERSION']>(0,7,2):
			if hasattr(self,'gir'):
				output_nodes.append(self.path.find_or_declare('%s.gir'%self.gir))
		elif env['VALAC_VERSION']>(0,3,5):
			output_nodes.append(self.path.find_or_declare('%s.gir'%self.target))
		elif env['VALAC_VERSION']>(0,1,7):
			output_nodes.append(self.path.find_or_declare('%s.gidl'%self.target))
		if valatask.packages:
			output_nodes.append(self.path.find_or_declare('%s.deps'%self.target))
	valatask.inputs.append(node)
	valatask.outputs.extend(output_nodes)
def detect(conf):
	min_version=(0,1,6)
	min_version_str="%d.%d.%d"%min_version
	valac=conf.find_program('valac',var='VALAC',mandatory=True)
	if not conf.env["HAVE_GOBJECT"]:
		pkg_args={'package':'gobject-2.0','uselib_store':'GOBJECT','args':'--cflags --libs'}
		if getattr(Options.options,'vala_target_glib',None):
			pkg_args['atleast_version']=Options.options.vala_target_glib
		conf.check_cfg(**pkg_args)
	if not conf.env["HAVE_GTHREAD"]:
		pkg_args={'package':'gthread-2.0','uselib_store':'GTHREAD','args':'--cflags --libs'}
		if getattr(Options.options,'vala_target_glib',None):
			pkg_args['atleast_version']=Options.options.vala_target_glib
		conf.check_cfg(**pkg_args)
	try:
		output=Utils.cmd_output(valac+" --version",silent=True)
		version=output.split(' ',1)[-1].strip().split(".")[0:3]
		version=[int(x)for x in version]
		valac_version=tuple(version)
	except Exception:
		valac_version=(0,0,0)
	conf.check_message('program version','valac >= '+min_version_str,valac_version>=min_version,"%d.%d.%d"%valac_version)
	conf.check_tool('gnu_dirs')
	if valac_version<min_version:
		conf.fatal("valac version too old to be used with this tool")
		return
	conf.env['VALAC_VERSION']=valac_version
	conf.env['VALAFLAGS']=''
def set_options(opt):
	valaopts=opt.add_option_group('Vala Compiler Options')
	valaopts.add_option('--vala-target-glib',default=None,dest='vala_target_glib',metavar='MAJOR.MINOR',help='Target version of glib for Vala GObject code generation')

extension(EXT_VALA)(vala_file)
