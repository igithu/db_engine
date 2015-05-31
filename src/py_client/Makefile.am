top_dir=../../..
proj_rootdir= ${top_srcdir}/src
client_rootdir = ${proj_rootdir}/client
third_dir=${top_dir}/third-32
pub_dir=${top_dir}/pub_util


AM_CPPFLAGS=-I${top_srcdir}/src \
			-I${third_dir}/protobuf/include/ \
			-I${third_dir}/boost/include/ \
			-I${third_dir}/glog/include/ \
			-I${third_dir}/iniparser/include/ \
			-I${pub_dir}	

AM_LDFLAGS=-fPIC -shared
LDADD=$(top_builddir)/src/proto/libproto.a \
	  $(top_builddir)/src/rpc/librpc.a \
      $(top_builddir)/src/common/libcommon.a \
	  ${third_dir}/protobuf/lib/*.a \
	  ${third_dir}/boost/lib/*.a \
	  ${third_dir}/iniparser/lib/*.a \
	  ${third_dir}/glog/lib/*.a 


CLIENT_SRC=${client_rootdir}/engine_client.h ${client_rootdir}/engine_client.cpp

lib_LTLIBRARIES=libdbclient.la



libdbclient_la_SOURCES=${CLIENT_SRC}

