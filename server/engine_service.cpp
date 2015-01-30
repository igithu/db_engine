/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file engine_service.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/10 15:51:48
 * @brief 
 *  
 **/

#include "engine_service.h"

#include <stdio.h>
#include <string>

#include "../engine_db/level_db.h"
#include "../include/inter_include.h"

namespace db_engine {

using std::string;

EngineServiceImpl::EngineServiceImpl():
   common_db_ptr_(NULL) {
       EngineServiceInit();
}

EngineServiceImpl::~EngineServiceImpl() {
    if (NULL != common_db_ptr_) {
        delete common_db_ptr_;
    }
}

bool EngineServiceImpl::EngineServiceInit() {
    const char* db_path = DB_SYS_CONF.IniGetString(
            "db_storage:storage_path");
    common_db_ptr_ = new LeveDB(db_path);
    return true;
}

void EngineServiceImpl::Put(RpcController* controller,
                            const DBRequest* request,
                            DBResponse* response,
                            Closure* done) {
    const string& key = request->db_key();
    const string& value = request->db_value();
    if ("" == key || "" == value) {
        return;
    }
    if (NULL == common_db_ptr_ || !common_db_ptr_->Put(key.c_str(), value.c_str())) {
        DB_LOG(ERROR, "EngineService put the key : %s, value: %s failed!",
               key.c_str(), value.c_str());
        response->set_code(ERR);
    }
    //response->set_db_res("null");
}

void EngineServiceImpl::Get(RpcController* controller,
                            const DBRequest* request,
                            DBResponse* response,
                            Closure* done) {
    const string& key = request->db_key();
    if ("" == key) {
        return;
    }
    string value;
    if (!common_db_ptr_->Get(key.c_str(), value)) {
        DB_LOG(ERROR, "EngineService get the key : %s failed!", key.c_str());
        response->set_code(ERR);
    }

    if ("" == value) {
        response->set_code(NOFOUND);
        return;
    }
    response->set_db_res(value);
}

void EngineServiceImpl::Delete(RpcController* controller,
                               const DBRequest* request,
                               DBResponse* response,
                               Closure* done) {
    const string& key = request->db_key();
    if ("" == key) {
        return;
    }
    if (!common_db_ptr_->Delete(key.c_str())) {
        DB_LOG(ERROR, "EngineService del the key : %s failed!", key.c_str());
        response->set_code(ERR);
    }
}

}  // end of namespace db_engine





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
