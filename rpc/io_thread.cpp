/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file io_thread.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/05 16:02:39
 * @brief 
 *  
 **/

#include "io_thread.h"

//#include <sys/epoll.h>
#include <sys/socket.h>

#include "rpc_server.h"
#include "../log/db_log.h"

namespace db_engine {

#define MAXEVENTS 100

IOThread::IOThread(const char* addr, const char* port) {
    strcpy(addr_ = (char*)malloc(strlen(addr) + 1), addr);
    strcpy(port_ = (char*)malloc(strlen(port) + 1), port);
    printf("Test %s, %s", addr_, port_);
}

IOThread::~IOThread() {
    delete addr_;
    delete port_;
}

void IOThread::Run() {
    RpcServer& rpc_server = RpcServer::GetInstance();
    LibevConnector* libev_connector_ptr = rpc_server.GetLibevConnector();
    if (NULL == libev_connector_ptr) {
        return;
    }
    libev_connector_ptr->Initialize(addr_, port_);
    libev_connector_ptr->LibevLoop();

}

}  // end of namespace db_engine




/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
