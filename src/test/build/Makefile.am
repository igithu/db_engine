
#SUBDIRS=src
#DIST_SUBDIRS=src

bin_PROGRAMS = test_conf

test_conf_SOURCES = ../test_conf.cpp \
					../../config/config_manager.h \
					../../config/config_manager.cpp \
					../../log/db_log.h \
					../../log/db_log.cpp


#INCLUDES = -I../third-64/libevent/include/
#CXXFLAGS = -std=c++11 -Wall -g -fPIC
test_conflib=
test_conf_CPPFLAGS = -I../../../third-64/iniparser/include/ \
					 -I../../../pub_util/tools/ \
					 -I../../../third-64/glog/include/ \
					 -I../../../third-64/boost/include/
test_conf_LDFLAGS =-DHAVE_INTTYPES_H -DHAVE_NETINET_IN_H -fpermissive 
test_conf_LDADD = -lpthread -lz -ldl -lrt  \
				  ../../../third-64/glog/lib/*.a \
				  ../../../third-64/iniparser/lib/*.a \
				  ../../../third-64/boost/lib/*.a
#http_server_a_LDADD = ../third-64/libevent/lib/*.a

