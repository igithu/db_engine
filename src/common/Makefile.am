
common_rootdir = ${top_srcdir}/src/common
top_dir=../../..
third_dir=../../../third-64
pub_dir=${top_dir}/pub_util

AM_CPPFLAGS=-I${third_dir}/glog/include/ \
			-I${third_dir}/iniparser/include/ \
			-I${third_dir}/boost/include/ \
			-I${pub_dir}

AM_LDFLAGS=-lz -lrt -rdynamic

LDADD=$(top_builddir)/src/proto/libproto.a \
      ${third_dir}/glog/lib/libglog.a \
	  ${third_dir}/iniparser/lib/*.a \
	  ${third_dir}/boost/lib/*.a 

AM_CXXFLAGS=-Werror

include_HEADERS=${common_rootdir}/db_log.h \
				${common_rootdir}/tools.h \
				${common_rootdir}/config_manager.h


COMMON_SRC= ${common_rootdir}/db_log.h \
			${common_rootdir}/db_log.cpp \
			${common_rootdir}/tools.h \
			${common_rootdir}/tools.cpp \
			${common_rootdir}/config_manager.h \
			${common_rootdir}/config_manager.cpp

noinst_LIBRARIES=libcommon.a

libcommon_a_SOURCES=${COMMON_SRC}

