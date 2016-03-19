/***************************************************************************
 *
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 *
 **************************************************************************/



/**
 * @file shell_client.h
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/24 15:04:55
 * @brief
 *
 **/




#ifndef  __SHELL_CLIENT_H_
#define  __SHELL_CLIENT_H_

#include <string>
#include <vector>
#include <unordered_map>  // C++ 11

#include "thread.h"
#include "engine_client.h"


namespace db_engine {

struct Params {
    //bool is_success;
    std::vector<std::string> params_vec;
};

class ShellClient;
typedef bool (ShellClient::*DoCmd)(Params& params);
typedef std::unordered_map<std::string, DoCmd> HashMap;

class ShellClient : public PUBLIC_UTIL::Thread {
    public:
        ShellClient();
        ~ShellClient();

        bool InitCmd();
        virtual void Run();

    private:
        bool ParseCmd(std::string& cmd_str, std::string& do_cmd_str, Params& params);
        bool DoCmdSet(Params& params);
        bool DoCmdGet(Params& params);
        bool DoCmdDelete(Params& params);
        bool DoCmdQuit(Params& params);

    private:
        HashMap do_cmd_map_;

        EngineClient engine_client_;
        bool running_;
};

}  // end of namespace db_engine





#endif  //__SHELL_CLIENT_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
