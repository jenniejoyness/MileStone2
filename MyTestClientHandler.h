//
// Created by renana on 1/3/19.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver solver;
    CacheManager cacheManager;
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
