#! /usr/bin/env python
# encoding: utf-8
import sys
if sys.hexversion < 0x020400f0: from sets import Set as set
import os,re
from Configure import conf
import TaskGen,Task,Utils,Options,Build
from TaskGen import feature,before,taskgen
class_check_source='''
public class Test {
	public static void main(String[] argv) {
		Class lib;
		if (argv.length < 1) {
			System.err.println("Missing argument");
			System.exit(77);
		}
		try {
			lib = Class.forName(argv[0]);
		} catch (ClassNotFoundException e) {
			System.err.println("ClassNotFoundException");
			System.exit(1);
		}
		lib = null;
		System.exit(0);
	}
}
'''
def jar_files(self):
	basedir=getattr(self,'basedir','.')
	destfile=getattr(self,'destfile','test.jar')
	jaropts=getattr(self,'jaropts',[])
	jarcreate=getattr(self,'jarcreate','cf')
	dir=self.path.find_dir(basedir)
	if not dir:raise
	jaropts.append('-C')
	jaropts.append(dir.abspath(self.env))
	jaropts.append('.')
	out=self.path.find_or_declare(destfile)
	tsk=self.create_task('jar_create')
	tsk.set_outputs(out)
	tsk.inputs=[x for x in dir.find_iter(src=0,bld=1)if x.id!=out.id]
	tsk.env['JAROPTS']=jaropts
	tsk.env['JARCREATE']=jarcreate
def apply_java(self):
	Utils.def_attrs(self,jarname='',jaropts='',classpath='',sourcepath='.',srcdir='.',source_re='**/*.java',jar_mf_attributes={},jar_mf_classpath=[])
	if getattr(self,'source_root',None):
		self.srcdir=self.source_root
	nodes_lst=[]
	if not self.classpath:
		if not self.env['CLASSPATH']:
			self.env['CLASSPATH']='..'+os.pathsep+'.'
	else:
		self.env['CLASSPATH']=self.classpath
	srcdir_node=self.path.find_dir(self.srcdir)
	if not srcdir_node:
		raise Utils.WafError('could not find srcdir %r'%self.srcdir)
	src_nodes=[x for x in srcdir_node.ant_glob(self.source_re,flat=False)]
	bld_nodes=[x.change_ext('.class')for x in src_nodes]
	self.env['OUTDIR']=[srcdir_node.abspath(self.env)]
	tsk=self.create_task('javac')
	tsk.set_inputs(src_nodes)
	tsk.set_outputs(bld_nodes)
	if getattr(self,'compat',None):
		tsk.env.append_value('JAVACFLAGS',['-source',self.compat])
	if hasattr(self,'sourcepath'):
		fold=[self.path.find_dir(x)for x in self.to_list(self.sourcepath)]
		names=os.pathsep.join([x.srcpath()for x in fold])
	else:
		names=srcdir_node.srcpath()
	if names:
		tsk.env.append_value('JAVACFLAGS',['-sourcepath',names])
	if self.jarname:
		jtsk=self.create_task('jar_create',bld_nodes,self.path.find_or_declare(self.jarname))
		jtsk.set_run_after(tsk)
		if not self.env.JAROPTS:
			if self.jaropts:
				self.env.JAROPTS=self.jaropts
			else:
				dirs='.'
				self.env.JAROPTS=['-C',''.join(self.env['OUTDIR']),dirs]
Task.simple_task_type('jar_create','${JAR} ${JARCREATE} ${TGT} ${JAROPTS}',color='GREEN',shell=False)
cls=Task.simple_task_type('javac','${JAVAC} -classpath ${CLASSPATH} -d ${OUTDIR} ${JAVACFLAGS} ${SRC}',shell=False)
cls.color='BLUE'
def post_run_javac(self):
	par={}
	for x in self.inputs:
		par[x.parent.id]=x.parent
	inner={}
	for k in par.values():
		path=k.abspath(self.env)
		lst=os.listdir(path)
		for u in lst:
			if u.find('$')>=0:
				inner_class_node=k.find_or_declare(u)
				inner[inner_class_node.id]=inner_class_node
	to_add=set(inner.keys())-set([x.id for x in self.outputs])
	for x in to_add:
		self.outputs.append(inner[x])
	return Task.Task.post_run(self)
cls.post_run=post_run_javac
def detect(conf):
	java_path=conf.environ['PATH'].split(os.pathsep)
	v=conf.env
	if'JAVA_HOME'in conf.environ:
		java_path=[os.path.join(conf.environ['JAVA_HOME'],'bin')]+java_path
		conf.env['JAVA_HOME']=[conf.environ['JAVA_HOME']]
	for x in'javac java jar'.split():
		conf.find_program(x,var=x.upper(),path_list=java_path)
		conf.env[x.upper()]=conf.cmd_to_list(conf.env[x.upper()])
	v['JAVA_EXT']=['.java']
	if'CLASSPATH'in conf.environ:
		v['CLASSPATH']=conf.environ['CLASSPATH']
	if not v['JAR']:conf.fatal('jar is required for making java packages')
	if not v['JAVAC']:conf.fatal('javac is required for compiling java classes')
	v['JARCREATE']='cf'
def check_java_class(self,classname,with_classpath=None):
	import shutil
	javatestdir='.waf-javatest'
	classpath=javatestdir
	if self.env['CLASSPATH']:
		classpath+=os.pathsep+self.env['CLASSPATH']
	if isinstance(with_classpath,str):
		classpath+=os.pathsep+with_classpath
	shutil.rmtree(javatestdir,True)
	os.mkdir(javatestdir)
	java_file=open(os.path.join(javatestdir,'Test.java'),'w')
	java_file.write(class_check_source)
	java_file.close()
	Utils.exec_command(self.env['JAVAC']+[os.path.join(javatestdir,'Test.java')],shell=False)
	cmd=self.env['JAVA']+['-cp',classpath,'Test',classname]
	self.log.write("%s\n"%str(cmd))
	found=Utils.exec_command(cmd,shell=False,log=self.log)
	self.check_message('Java class %s'%classname,"",not found)
	shutil.rmtree(javatestdir,True)
	return found
def check_jni_headers(conf):
	if not conf.env.CC_NAME and not conf.env.CXX_NAME:
		conf.fatal('load a compiler first (gcc, g++, ..)')
	if not conf.env.JAVA_HOME:
		conf.fatal('set JAVA_HOME in the system environment')
	javaHome=conf.env['JAVA_HOME'][0]
	b=Build.BuildContext()
	b.load_dirs(conf.srcdir,conf.blddir)
	dir=b.root.find_dir(conf.env.JAVA_HOME[0]+'/include')
	f=dir.ant_glob('**/(jni|jni_md).h',flat=False)
	incDirs=[x.parent.abspath()for x in f]
	dir=b.root.find_dir(conf.env.JAVA_HOME[0])
	f=dir.ant_glob('**/*jvm.(so|dll)',flat=False)
	libDirs=[x.parent.abspath()for x in f]or[javaHome]
	for i,d in enumerate(libDirs):
		if conf.check(header_name='jni.h',define_name='HAVE_JNI_H',lib='jvm',libpath=d,includes=incDirs,uselib_store='JAVA',uselib='JAVA'):
			break
	else:
		conf.fatal('could not find lib jvm in %r (see config.log)'%libDirs)

feature('jar')(jar_files)
before('apply_core')(jar_files)
feature('javac')(apply_java)
before('apply_core')(apply_java)
conf(check_java_class)
conf(check_jni_headers)
