/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/



/**
 * @file engine_server.cc
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/10 16:43:11
 * @brief 
 *  
 **/

#include <signal.h>
#include <stdio.h>
#include <fcntl.h>

#include "db_service.h"
#include "rpc/rpc_server/rpc_server.h"
#include "common/tools.h"
#include "common/common.h"

using namespace db_engine;
using namespace libevrpc;

inline void InitSignal() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(struct sigaction));

    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    if (-1 == sigaction(SIGPIPE, &sa, NULL)) {
        exit(1);
    }
}

inline void Daemonize() {
    if (0 != fork()) {
        exit(0);
    }
    if (-1 == setsid()) {
        fprintf(stderr, "set sid error!\n");
        exit(-1);
    }
    umask(0);
    int fd = open("/dev/null", O_RDWR, 0);
    if (-1 != fd) {
        dup2(fd, STDIN_FILENO);
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        if (fd > STDERR_FILENO) {
            close(fd);
        }
    }  
}

int main(int argc, char* argv[]) {

    InitSignal();

    if (true) {
         Daemonize();
    }

    // read config data from ini file
    int32_t thread_num = DB_SYS_CONF.IniGetInt("thread:num");
    const char* addr = DB_SYS_CONF.IniGetLocalIPAddr();
    const char* port = DB_SYS_CONF.IniGetString("host:port");
    const char* log_dir = DB_SYS_CONF.IniGetString("log:dir");

    if (!CreateDir(log_dir)) {
        DB_LOG(ERROR, "create log dir: %s faied!", log_dir);
        return 0;
    }
    if (false == DBLogInit(
                argc, argv, DB_SYS_CONF.IniGetString("log:level"), log_dir)) {
        return 0;
    }

    DB_LOG(INFO, "get the rpc sever....");
    RpcServer& rpc_server = RpcServer::GetInstance();
    EngineServiceImpl service;
    rpc_server.RegisteService(&service);
    DB_LOG(INFO, "Start the rpc sevice....");

    rpc_server.Start(addr, port, thread_num);
    rpc_server.Wait();

    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
