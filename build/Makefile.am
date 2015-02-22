
#SUBDIRS=src
#DIST_SUBDIRS=src

ROOTDIR=${top_srcdir}/../src
THIRDDIR=../../third-64
PUBDIR=../../pub_util

UTIL_LIB=${PUBDIR}/tools/tools.h ${PUBDIR}/tools/tools.cpp
INCLUDES=-I${ROOTDIR} -I${PUBDIR}

COMM_LIB=${ROOTDIR}/config/config_manager.h \
		 ${ROOTDIR}/config/config_manager.cpp \
		 ${ROOTDIR}/rpc/socket_util.h \
		 ${ROOTDIR}/rpc/socket_util.cpp \
		 ${ROOTDIR}/rpc/rpc_util.h \
		 ${ROOTDIR}/rpc/rpc_util.cpp \
		 ${ROOTDIR}/rpc/rpc_msg.pb.h \
		 ${ROOTDIR}/rpc/rpc_msg.pb.cc \
		 ${ROOTDIR}/proto/db_engine.pb.h \
		 ${ROOTDIR}/proto/db_engine.pb.cc \
		 ${ROOTDIR}/include/inter_include.h \
		 ${ROOTDIR}/include/ext_include.h \
		 ${ROOTDIR}/log/db_log.h \
		 ${ROOTDIR}/log/db_log.cpp 

COMMON_CF =-I${THIRDDIR}/protobuf/include/ \
		   -I${THIRDDIR}/glog/include/ \
		   -I${THIRDDIR}/boost/include/ \
		   -I${THIRDDIR}/iniparser/include/ \
		   -I${THIRDDIR}/libev/include/ \
		   -I${PUBDIR}/tools/include/

COMMON_LD = -lpthread -lz -ldl -lrt \
		   ${THIRDDIR}/protobuf/lib/*.a \
		   ${THIRDDIR}/glog/lib/*.a \
		   ${THIRDDIR}/iniparser/lib/*.a \
		   ${THIRDDIR}/libev/lib/*.a \
		   ${THIRDDIR}/boost/lib/*.a

bin_PROGRAMS = shell_client engine_client engine_server

shell_client_SOURCES = \
		      ${ROOTDIR}/client/shell_client_driver.cc \
		      ${ROOTDIR}/client/shell_client.h \
		      ${ROOTDIR}/client/shell_client.cpp \
		      ${ROOTDIR}/client/engine_client.h \
		      ${ROOTDIR}/client/engine_client.cpp \
			  ${ROOTDIR}/rpc/rpc_channel.h \
			  ${ROOTDIR}/rpc/rpc_channel.cpp \
			  $(COMM_LIB) \
			  $(UTIL_LIB)

shell_client_CPPFLAGS = $(COMMON_CF) -I${PUBDIR}/thread/include/
shell_client_LDFLAGS = -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -fpermissive 
shell_client_LDADD = $(COMMON_LD)


engine_client_SOURCES = \
		      ${ROOTDIR}/client/client.cc \
		      ${ROOTDIR}/client/engine_client.h \
		      ${ROOTDIR}/client/engine_client.cpp \
			  ${ROOTDIR}/rpc/rpc_channel.h \
			  ${ROOTDIR}/rpc/rpc_channel.cpp \
			  $(COMM_LIB)
engine_client_CPPFLAGS = $(COMMON_CF) 
engine_client_LDFLAGS = -DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -fpermissive 
engine_client_LDADD = $(COMMON_LD)




engine_server_SOURCES = \
		      ${ROOTDIR}/server/engine_server.cc \
		      ${ROOTDIR}/server/engine_service.h \
		      ${ROOTDIR}/server/engine_service.cpp \
			  ${ROOTDIR}/engine_db/common_db.h \
			  ${ROOTDIR}/engine_db/level_db.h \
			  ${ROOTDIR}/rpc/libev_connector.h \
			  ${ROOTDIR}/rpc/libev_connector.cpp \
			  ${ROOTDIR}/engine_db/level_db.cpp \
			  ${ROOTDIR}/rpc/rpc_server.h \
			  ${ROOTDIR}/rpc/rpc_server.cpp \
			  ${ROOTDIR}/rpc/io_thread.h \
			  ${ROOTDIR}/rpc/io_thread.cpp \
			  ${ROOTDIR}/rpc/thread_pool.h \
			  ${ROOTDIR}/rpc/thread_pool.cpp \
			  $(COMM_LIB) \
			  $(UTIL_LIB)
engine_server_CPPFLAGS = $(COMMON_CF) \
						 -I${THIRDDIR}/leveldb/include/ \
  						 -I${PUBDIR}/thread/include/
engine_server_LDFLAGS =-DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -fpermissive 
engine_server_LDADD = $(COMMON_LD)  ${THIRDDIR}/leveldb/lib/*.a 
