/***************************************************************************
 * 
 * Copyright (c) 2015 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_conf.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2015/01/07 16:01:14
 * @brief 
 *  
 **/

#include <string>

#include "common/config_manager.h"

using namespace db_engine;

#define DB_CONF ConfigManager::GetInstance()

int main() {

    // const char *addr = ConfigManager::GetInstance().IniGetString("host:addr");
    //std::string addr = DB_SYS_CONF.IniGetString("host:addr");
    //printf("addr : %s\n", addr);

     
    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
