/***************************************************************************
 * 
 * Copyright (c) 2014 aishuyu, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file engine_service.h
 * @author aishuyu(asy5178@163.com)
 * @date 2014/12/10 15:45:48
 * @brief 
 *  
 **/




#ifndef  __ENGINE_SERVICE_H_
#define  __ENGINE_SERVICE_H_


#include "../proto/db_engine.pb.h"
#include "../engine_db/common_db.h"

namespace db_engine {

using namespace google::protobuf;

class EngineServiceImpl : public EngineService {
    public:

        EngineServiceImpl();

        ~EngineServiceImpl();

        virtual void Put(RpcController* controller,
                         const DBRequest* request,
                         DBResponse* response,
                         Closure* done);

        virtual void Get(RpcController* controller,
                         const DBRequest* request,
                         DBResponse* response,
                         Closure* done);

        virtual void Delete(RpcController* controller,
                            const DBRequest* request,
                            DBResponse* response,
                            Closure* done);
    private:
        bool EngineServiceInit();

    private:
        CommonDB* common_db_ptr_;
};



}  // end of namespace db_engine













#endif  //__ENGINE_SERVICE_H_

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
