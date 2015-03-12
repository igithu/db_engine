top_dir = ${top_srcdir}/..
third_dir = ${top_dir}/third-64
db_rootdir = ${top_srcdir}/src/engine_db
pub_dir = ${top_dir}/pub_util

AM_CPPFLAGS = -I${top_srcdir}/src \
              -I${third_dir}/leveldb/include/ \
              -I${third_dir}/glog/include/ \
			  -I${third_dir}/boost/include/ \
			  -I${third_dir}/iniparser/include/ \
			  -I${pub_dir}

AM_LDFLAGS = -lz -lrt -rdynamic

LDADD = $(top_builddir)/src/common/libcommon.a \
        ${third_dir}/leveldb/lib/*.a \
	    ${third_dir}/boost/lib/*.a \
        ${third_dir}/glog/lib/libglog.a 

AM_CXXFLAGS = -Werror


COMMON_SRC = ${db_rootdir}/common_db.h \
			 ${db_rootdir}/level_db.h \
			 ${db_rootdir}/level_db.cpp 

noinst_LIBRARIES = libdb.a

libdb_a_SOURCES = ${COMMON_SRC}

