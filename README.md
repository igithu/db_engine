# db_engine

该项目主要提供对levedb等底层数据存储的网络包装

主要模块如下

1.rpc

    主要实现RPC功能框架，为client/server提供RPC连接服务 
  
    a.Protobuf: protobuf提供了RPC的框架，基于protobuf的RPC框架等，定义RPC实现的逻辑，定义RPC C/S服务协议
    
    b.IOthread: 使用epoll实现基本的IO复用功能，用来接收远程RPC client请求，
  
    c.ThreadPool：基于Linux pthread库实现的线程池的功能，接收来自IOThread的请求后，将请求放在请求队列中，然后线程池会选取一个线程会fetch出请求，最后执行按照指定函数逻辑对该请求进行服务相应
    
    d.RpcServer：rpc Server主干实现，启动IOThread， ThreadPool，接收请求后 ，find到相应的service，调用相应的逻辑
  

 
2.db

    内部主要提供底层数据存储的直接接口调用，可以在这里增加其他存储的代码 例如：redis，memcache
    
    a.提供数据直接的接口调用，封装判断调用错误等逻辑
    
    b.提供抽象的父类 供外部统一调用
    

3.server

    服务的最上层实现，负责服务的启动
    
    a.服务整体的 初始化
    
    b.按照RPC框架 实现service中的函数实现，最后运行前注册所有的service逻辑实现
    


4.client

    提供对protobuf RPC client的包装，客户端shell模式的直接访问与读取写入 
    
    这里shell_client编译后可以直接运行，进入交互页面，现在只提供 set get del 接口 例如 写入数据（以空格分开）:set keytest valuetest 同理get，del接口
    
    
    
5.config

    主要负责对配置的文件的读取解析，配置文件中可以指定IP，端口，RPC Server线程池的个数，日志存储目录，数据存储目录
    
    a.ConfigManager：负责解析读取工作，该类提供是单例服务，同时为线程安全的
    
    b.ConfigLoader: 负责动态配置的加载服务，现阶段还未实现
    

6.log

    主要实现系统需要的log接口，这里暂时封装glog，可以根据自己的需要改log为其他接口

7.build

    主要编译工具都放在这个目录下，automake等工具搭建好后，可以直接运行build.sh 进行编译
