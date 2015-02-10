/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file shell_client.cpp
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/22 17:21:56
 * @brief 
 *  
 **/

#include "shell_client.h"

#include <iostream>

#include "../log/db_log.h"
#include "../../pub_util/tools/tools.h"

namespace db_engine {

using std::string;
using std::vector;

#define CMD_MAX_LEN 64

ShellClient::ShellClient() :
    running_(true) {
    InitCmd();
}

ShellClient::~ShellClient() {
}

bool ShellClient::InitCmd() {
    do_cmd_map_["set"] = &ShellClient::DoCmdSet;
    do_cmd_map_["get"] = &ShellClient::DoCmdGet;
    do_cmd_map_["del"] = &ShellClient::DoCmdDelete;
    do_cmd_map_["quit"] = &ShellClient::DoCmdQuit;
    return true;
}

void ShellClient::Run() {

    system("stty erase ^H");

    while (running_) {
        char cmd_buf[CMD_MAX_LEN];
        memset(cmd_buf, '\0', CMD_MAX_LEN);
        if (fprintf(stderr, "DB> ") < 0) {
            break;
        }
        //if (fgets(cmd_buf, CMD_MAX_LEN, stdin) == NULL) { 
        //    break;
        //}
        
        std::cin.getline(cmd_buf, CMD_MAX_LEN);
        
        string do_cmd_str;
        Params params;
        string cmd_buf_str = cmd_buf;
        if (cmd_buf_str.size() == 0) {
            continue;
        }
        if (!ParseCmd(cmd_buf_str, do_cmd_str, params)) {
            fprintf(stderr, "unknow command!\n");
            continue;
        }

        HashMap::iterator do_cmd_iter = do_cmd_map_.find(do_cmd_str.c_str()); 
        if (do_cmd_iter == do_cmd_map_.end()) {
            fprintf(stderr, "Cann't find command %s, unknow command!\n", do_cmd_str.c_str());
            continue;
        }
        DoCmd do_cmd = do_cmd_iter->second;
        bool is_success = (this->*do_cmd)(params);
        if (is_success) {
            fprintf(stderr, "ok!\n");
        } else {
            fprintf(stderr, "failed!\n");
        }
    }
}

bool ShellClient::ParseCmd(string& cmd_str, string& do_cmd_str, Params& params) {

    vector<string> splited_vec;
    //cmd_str[cmd_str.size() - 1] = '\0';
    PUBLIC_UTIL::Split(cmd_str, " ",  splited_vec);
    if (splited_vec.size() == 0) {
        return false;
    }
    vector<string>::iterator vec_iter = splited_vec.begin();
    if (vec_iter != splited_vec.end()) {
        do_cmd_str = *vec_iter;
        ++vec_iter;
    }
    vector<string>& params_vec = params.params_vec;
    for (; vec_iter != splited_vec.end(); ++vec_iter) {
        params_vec.push_back(*vec_iter);
    }

    return true;
}

bool ShellClient::DoCmdSet(Params& params) {
    vector<string>& params_vec = params.params_vec; 
    if (params_vec.size() != 2) {
        DB_LOG(WARNING, "DoCmdSet params is wrong number!");
        return false;
    }
    return engine_client_.Put(params_vec[0].c_str(), params_vec[1].c_str());
}

bool ShellClient::DoCmdGet(Params& params) {
    vector<string>& params_vec = params.params_vec; 
    if (params_vec.size() != 1) {
        DB_LOG(WARNING, "DoCmdGet params is wrong number!");
        return false;
    }
    string response_str;
    if (!engine_client_.Get(params_vec[0].c_str(), response_str)) {
        return false;
    }
    if ("NULL" == response_str) {
        fprintf(stderr, "Empty!\n");
    } else {
        fprintf(stderr, "get value :%s\n", response_str.c_str());
    }
    return true;
}

bool ShellClient::DoCmdDelete(Params& params) {
    vector<string>& params_vec = params.params_vec; 
    if (params_vec.size() != 1) {
        DB_LOG(WARNING, "DoCmdDelete params is wrong number!");
        return false;
    }
    return engine_client_.Delete(params_vec[0].c_str());
}

bool ShellClient::DoCmdQuit(Params& params) {
    if (!Stop()) {
        return false;
    }
    running_ = false;
    return true;
}

}  // end of namespace db_engine















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
