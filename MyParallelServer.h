//
// Created by jennie on 1/14/19.
//

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H


#include <vector>
#include "Server.h"
#include <pthread.h>
class MyParallelServer : public Server {
private:
    vector<pthread_t> threads;
    struct params {
        ClientHandler* clientHandler;
        int sockfd;
    };

public:
void open(int port, ClientHandler *c);
void stop();
static void* parallelService (void* params);
};


#endif //MILESTONE2_MYPARALLELSERVER_H
