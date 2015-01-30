/***************************************************************************
 * 
 * Copyright (c) 2015 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file config_loader.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2015/01/02 14:30:26
 * @brief 
 *  
 **/

#include "config_loader.h"

#include <stdio.h>
#include <unistd.h>

#include "iniparser.h"
#include "../log/db_log.h"

using std::string;

ConfigLoader::ConfigLoader() :
    ini_file_path_("./db.ini")file_path_("./db.conf"), latest_load_time_(0){
}

ConfigLoader::~ConfigLoader() {
}

bool ConfigLoader::ConfigIni() {
    dictionary* ini_conf = iniparser_load(ini_file_path_.c_str());

}

void ConfigLoader::Run() {

    while(true) {

        if (!IsFileReady()) {
            sleep(60);
        }
        ReLoader()

    }
}

bool ConfigLoader::ReLoader() {

    return true;
}

bool ConfigLoader::IsFileReady() {
    try {
        if (access(file_path_.c_str(), F_OK) == -1) {
            DB_LOG(ERROR, "The file %s does no exist!", file_path_.c_str());
            return false;
        }

        struct stat file_stat;
        if (stat(file_path_.c_str(), &file_stat) == -1) {
            DB_LOG(ERROR, "Stat failed when stat the file : %s!", 
                    file_path_.c_str());
            return false;
        }

        time_t new_changed_time = file_stat.st_mtime;
        if (new_changed_time <= latest_load_time_) {
            DB_LOG(ERROR, "The file : %s is old, skip it.", file_path_.c_str());
            return false;
        }

        latest_load_time_ = new_changed_time;
    } catch(const std::exception& e) {
        DB_LOG(ERROR, "Exception when checking conf file %s, Exception : %s",
                file_path_.c_str(), e.what());
        return false;
    }
    return true;
}























/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
