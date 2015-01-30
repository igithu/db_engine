/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_glog.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/12 12:56:38
 * @brief 
 *  
 **/

#include <stdio.h>

#include <glog/logging.h>

#include "../log/db_log.h"

#define TEST_LOG(severity) LOG(severity)
//COMPACT_GOOGLE_LOG_ ## severity.stream() 

using namespace db_engine;

int main(int argc, char* argv[]) {

//    google::InitGoogleLogging(argv[0]);
//
//    TEST_LOG(ERROR) << "Test";
//    //LOG(ERROR) << "Test";
//    //
//    char aa[10];
//    snprintf(aa, 18, "%s, %s", "1234", "56789000");
//    printf("Test %s\n", aa);
//    TEST_LOG(ERROR) << aa;
      DBLogInit(argc, argv);
      DB_LOG(ERROR, "testt ");
      DBLogShutDown();
     


    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
