server_rootdir = ${top_srcdir}/src/server
top_dir=../../..
third_dir=${top_dir}/third-64
pub_dir=${top_dir}/pub_util

AM_CPPFLAGS=-I${top_srcdir}/src \
			-I${third_dir}/protobuf/include/ \
			-I${third_dir}/boost/include/ \
			-I${third_dir}/glog/include/ \
			-I${third_dir}/libev/include/ \
			-I${third_dir}/iniparser/include/ \
			-I${third_dir}/leveldb/include/ \
			-I${pub_dir}	

AM_LDFLAGS=-lz -lrt -rdynamic

LDADD=$(top_builddir)/src/rpc/librpc.a \
      $(top_builddir)/src/common/libcommon.a \
	  $(top_builddir)/src/engine_db/libdb.a \
	  $(top_builddir)/src/proto/libproto.a \
	  ${third_dir}/libev/lib/*.a \
	  ${third_dir}/protobuf/lib/*.a \
	  ${third_dir}/boost/lib/*.a \
	  ${third_dir}/glog/lib/*.a \
	  ${third_dir}/iniparser/lib/*.a \
	  ${third_dir}/leveldb/lib/*.a


SERVER_SRC= ${server_rootdir}/db_server.cc \
		    ${server_rootdir}/db_service.h \
		    ${server_rootdir}/db_service.cpp 

bin_PROGRAMS = db_server

db_server_SOURCES=${SERVER_SRC}

