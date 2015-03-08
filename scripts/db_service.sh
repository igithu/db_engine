#!/bin/sh
#
# chkconfig: 2345  80 50
# description: db_server is for testing how to write service in Linux 
#              
# processname: db_server
# 
# Source function library.
. /etc/rc.d/init.d/functions

ret=0

start() {
    # check fdb status
    echo "start db_server"
    ./db_server &
    ret=$?
} 

stop() {
    echo "stop db_server" 
    kill -9 $(ps -ef | grep db_server | grep -v grep | awk '{print $2}')
    ret=$?
} 

status() {
    local result
    echo "check status of db_server..."
    result=$( ps -ef | grep -v db_server | grep -v grep | wc -l )
    if [ $result -gt 0 ] ; then
        echo "db_server is up"
        ret=0
    else
        echo "db_server is down"
        ret=1
    fi
    echo "check status of db_server...done."
} 

# See how we were called.
case "$1" in
  start)
        start
        ;;
  stop)
        stop
        ;;
  status)
        status 
        ;;
  restart)
        stop
        start
        ;;
  *)
        echo $"Usage: $0 {start|stop|status}"
        exit 1
esac

exit $ret
