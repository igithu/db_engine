/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file common_db.h
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/08 13:44:56
 * @brief 
 *  
 **/




#ifndef  __COMMON_DB_H_
#define  __COMMON_DB_H_

#include <string>

namespace db_engine {

// key-value db
class CommonDB {

    public:

        CommonDB() {
        }

        ~CommonDB() {
        }

        //virtual bool DBInit() = 0;

        virtual bool Put(const char* key, const char* value) = 0;

        virtual bool Get(const char* key, std::string& value) = 0;

        virtual bool Delete(const char* key) = 0;
};

}  // end of namespace db_engine




#endif  //__COMMON_DB_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
