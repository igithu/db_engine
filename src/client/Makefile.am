AUTOMAKE_OPTIONS = foreign subdir-objects

top_dir = ${top_srcdir}/..
proj_rootdir = ${top_srcdir}/src
client_rootdir = ${proj_rootdir}/client
third_dir = ${top_dir}/third-64
pub_dir = ${top_dir}/pub_util


AM_CPPFLAGS = -I${proj_rootdir} \
			  -I${proj_rootdir}/rpc/ \
			  -I${third_dir}/protobuf/include/ \
			  -I${third_dir}/boost/include/ \
			  -I${third_dir}/glog/include/ \
			  -I${third_dir}/iniparser/include/ \
			  -I${pub_dir}

AM_LDFLAGS = -lz -lm -lpthread -lstdc++

LDADD = $(top_builddir)/src/rpc/rpc_client/librpc_client.a \
		$(top_builddir)/src/proto/libproto.a \
		$(top_builddir)/src/common/libcommon.a \
		${third_dir}/protobuf/lib/*.a \
		${third_dir}/boost/lib/*.a \
		${third_dir}/iniparser/lib/*.a \
		${third_dir}/glog/lib/*.a


SHELLCLIENT_SRC = ${client_rootdir}/shell_client_driver.cc \
				  ${client_rootdir}/shell_client.h \
				  ${client_rootdir}/shell_client.cpp \
				  ${client_rootdir}/engine_client.h \
				  ${client_rootdir}/engine_client.cpp

bin_PROGRAMS = shell_client

shell_client_SOURCES = ${SHELLCLIENT_SRC}

