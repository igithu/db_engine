/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file shell_client_driver.cc
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/26 15:49:07
 * @brief 
 *  
 **/


#include "shell_client.h"

using namespace db_engine;
    
int main(int argc, char *argv[]) {

    ShellClient shell_client;
    shell_client.Start();
    shell_client.Wait();

    return 0;
}





















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
