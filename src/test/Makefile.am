
#SUBDIRS=src
#DIST_SUBDIRS=src

top_dir=${top_srcdir}/..
test_rootdir = ${top_srcdir}/src/test
third_dir=${top_dir}/third-64
pub_dir=${top_dir}/pub_util

AM_CPPFLAGS=-I${top_srcdir}/src \
			-I${third_dir}/protobuf/include/ \
			-I${third_dir}/boost/include/ \
			-I${third_dir}/glog/include/ \
			-I${third_dir}/iniparser/include/ \
			-I${pub_dir}    

#AM_LDFLAGS=-lpthread -lz -ldl -lrt -lrt -rdynamic -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -fpermissive
AM_LDFLAGS=-lz -lrt -rdynamic

LDADD=$(top_builddir)/src/common/libcommon.a \
	  ${third_dir}/protobuf/lib/*.a \
	  ${third_dir}/boost/lib/*.a \
	  ${third_dir}/glog/lib/*.a \
	  ${third_dir}/iniparser/lib/*.a

TESTCONF_SRC = ${test_rootdir}/test_conf.cpp 

bin_PROGRAMS = test_conf

test_conf_SOURCES=${TESTCONF_SRC}


