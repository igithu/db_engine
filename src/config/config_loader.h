/***************************************************************************
 * 
 * Copyright (c) 2015 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file config_loader.h
 * @author aishuyu(asy5178@163.com)
 * @date 2015/01/02 13:49:01
 * @brief 
 *  
 **/




#ifndef  __CONFIG_LOADER_H_
#define  __CONFIG_LOADER_H_

#include <string>

namespace db_engine {

class ConfigLoader : Thread {
    public:
        ConfigLoader();

        ~ConfigLoader();

        virtual void Run();
        
    private:
        // parse the config and load it
        void ReLoader();

        bool IsFileReady();

    private:
        // init config file name
        const std::string ini_file_path_;

        // config file name
        const std::string file_path_;

        // latest load file time
        time_t latest_load_time_;

}; 


}  // end of namespace db_engine













#endif  //__CONFIG_LOADER_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
