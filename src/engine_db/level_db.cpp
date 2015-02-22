/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file level_db.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/08 13:54:31
 * @brief 
 *  
 **/


#include "level_db.h"

#include <stdlib.h>
#include <leveldb/c.h>

#include "include/inter_include.h"
#include "include/ext_include.h"

namespace db_engine {

LeveDB::LeveDB(const char* db_path) : db_ptr_(NULL) {
    LeveDBInit(db_path);
}

LeveDB::~LeveDB() {
}

bool LeveDB::LeveDBInit(const char* db_path) {
    // create the storage dir
    if (!PUBLIC_UTIL::CreateDir(db_path)) {
        DB_LOG(ERROR, "create the dir %s failed!", db_path);
        return false;
    }

    options_.create_if_missing = true;
    w_options_.sync = true;
    leveldb::DB::Open(options_, db_path, &db_ptr_);
    if (NULL == db_ptr_) {
        DB_LOG(ERROR, "level_db init error! db_ptr_ is null!");
        return false;
    }
    DB_LOG(INFO, "init success!");
    return true;
}

bool LeveDB::Put(const char* key, const char* value) {
    //if (NULL == key || NULL == value /*|| "" == *key || "" == *value*/) {
    //    //fprintf(stderr, "put exception key or value is null");
    //    return false;
    //}
    if (NULL == db_ptr_) {
        DB_LOG(ERROR, "level_db put op error! db_ptr_ is null!");
        return false;
    }
    leveldb::Status status = db_ptr_->Put(w_options_, key, value);
    if (!status.ok()) {
        DB_LOG(ERROR, "put op failed!");
        return false;
    }
    return true;
}

bool LeveDB::Get(const char* key, std::string& value) {
    if (NULL == key /*|| "" = *key*/) {
        DB_LOG(ERROR, "key is null");
        return false;
    }
    if (NULL == db_ptr_) {
        DB_LOG(ERROR, "level_db get op error! db_ptr_ is null!");
        return false;
    }

    leveldb::Status status = db_ptr_->Get(leveldb::ReadOptions(), key, &value);
    if (!status.IsNotFound() && !status.ok()) {
        DB_LOG(ERROR, "get op failed!");
        return false;
    } else if (status.IsNotFound()) {
        value = "";
    }

    return true;
}

bool LeveDB::Delete(const char* key) {
    if (NULL == key /*|| "" = *key*/) {
        //fprintf(stderr, "key is null");
        return false;
    }
    if (NULL == db_ptr_) {
        DB_LOG(ERROR, "level_db delete op error! db_ptr_ is null!");
        return false;
    }
    leveldb::Status status = db_ptr_->Delete(w_options_, key);
    if (!status.ok()) {
        DB_LOG(ERROR, "delete op failed!");
        return false;
    }
    return true;
}


}  // end of namespace db_engine






/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
