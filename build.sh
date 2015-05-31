#!/bin/sh
#!/bin/bash

#build the db_engine
#must have the bootstrap.sh file or be failed for sure
#must install automake

BUILD_ROOT=$PWD

SRC_ROOT=$BUILD_ROOT/src
CLIENT_SRC_PATH=$SRC_ROOT/client
SERVER_SRC_PATH=$SRC_ROOT/server

BUILD_DB=$BUILD_ROOT/db_engine
START_FILE=$BUILD_ROOT/scripts/db_service.sh
CLIENT_PATH=$BUILD_DB/client
CLIENT_BIN_PATH=$CLIENT_PATH/bin
SERVER_PATH=$BUILD_DB/server
SERVER_BIN_PATH=$SERVER_PATH/bin
CONF_PATH=$BUILD_ROOT/share/conf
CONF_FILE=$CONF_PATH/db_sys.ini 


echo $BUILD_ROOT

# check the bootstrap exist.
if [ ! -f $BUILD_ROOT/bootstrap.sh ]
then
    echo "the bootstrap.sh does not exist!"
    exit -1
fi

# clean the .o file in order to make the proj
if [ -d $BUILD_DB ] 
then
    rm -rf $BUILD_DB
fi
make distclean && ./bootstrap.sh clean
./bootstrap.sh

# check the configure file
if [ ! -f $BUILD_ROOT/configure ]
then
    echo "the configure does not exist!"
    exit -1
fi

# make the project
./configure --disable-dependency-tracking && make
if [ $? -ne 0 ]
then
    echo "make the project failed!"
    exit -1
fi



#start to collect the project file 

# make sure the config file exist
if [ ! -f $CONF_FILE ]
then
    echo "the config file does not exist"
    exit -1
fi

if [ ! -f $START_FILE ]
then
    echo "the $START_FILE file does not exist"
    exit -1
fi


# make sure the path CLIENT_BIN_PATH and SERVER_BIN_PATH exist
echo $CLIENT_BIN_PATH
if [ ! -d $CLIENT_BIN_PATH ]
then
    mkdir -p $CLIENT_BIN_PATH
    echo "Test"
fi 

if [ ! -d $SERVER_BIN_PATH ]
then
    mkdir -p $SERVER_BIN_PATH
fi 


#mv engine_client $CLIENT_BIN_PATH && \
mv $CLIENT_SRC_PATH/shell_client $CLIENT_BIN_PATH && \
mv $SERVER_SRC_PATH/db_server $SERVER_BIN_PATH && \
cp -r $CONF_PATH $CLIENT_PATH && \
cp -r $CONF_PATH $SERVER_PATH && \
cp $START_FILE $SERVER_BIN_PATH

if [ $? -ne 0 ]
then
    echo "build the clint bin failed"
    exit -1
fi


make distclean && ./bootstrap.sh clean

echo ""
echo "*****************************************"
echo "build the db engine successfully!!"
echo "*****************************************"
echo ""

