/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file test_gkey.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/31 13:52:14
 * @brief 
 *  
 **/

#include <stdio.h>
#include "iniparser.h"

int main(int argc,char** argv){

    dictionary* ini = iniparser_load("file.ini");

    char* tmp = iniparser_getstring(ini, "startup:timestamp", "null");
    printf("Test %s\n", tmp);
    int ret_int = iniparser_getint(ini, "startup:timestamp", -1);
    printf("Test int %d\n", ret_int);


    printf("Test, %d\n", iniparser_getsecnkeys(ini, "startup"));
    printf("Tesk, %s\n", iniparser_getsecname(ini, 0));

    iniparser_freedict(ini);

    return 0;
}

















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
