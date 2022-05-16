
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <map>
#include "Json.h"
#include "JsonValue.h"
#include "JsonParse.h"
#include "JsonException.h"

int main(){
    int PORT;
    //同步or异步
    int LOGWrite;
    //触发epoll模式
    int TRIGMode;
    //listen触发模式
    int LISTENTRIGMode;
    //connfd触发模式
    int CONNTRIGMode;
    //优雅关闭连接
    int OPT_LINGER;
    //数据库连接处数量
    int sql_num;
    //线程池内的线程数量
    int thread_num;
    //是否关闭日志
    int close_log;
    //并发模型选择
    int actor_model;
    char * buf;
    buf = (char*)malloc(sizeof(char) *1000);
    int fd = open("WebConfig.json", O_RDONLY);
    int ret = read(fd, buf ,1000);
    if(ret<0){
        printf("error");
        exit(0);
    }

    cocolay::Json parse;
    parse.parse(buf);
    std::map<std::string, int> confi;
    int st = parse.get_obj_size();
    for(int i=0;i<st;++i){
        auto key = parse.get_obj_key(i);
        auto v = parse.get_obj_value(i);
        confi[key] =  v.get_num();
    }
    for(auto num:confi){
        if(num.first=="PORT")PORT = num.second;
        else if(num.first=="LOGWrite") LOGWrite = num.second;
        else if(num.first=="TRIGMode")TRIGMode = num.second;
        else if(num.first=="LISTENTRIGMode")LISTENTRIGMode = num.second;
        else if(num.first=="CONNTRIGMode")CONNTRIGMode = num.second;
        else if(num.first=="OPT_LINGER")OPT_LINGER = num.second;
        else if(num.first=="sql_num")sql_num = num.second;
        else if(num.first=="thread_num")thread_num = num.second;
        else if(num.first=="close_log")close_log = num.second;
        else if(num.first=="actor_model")actor_model = num.second;
    }
    std::cout<<close_log<<"," << sql_num<<std::endl;


    free(buf);
    return 0;
}