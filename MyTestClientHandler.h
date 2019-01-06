
#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver solver;
    FileCacheManager cacheManager;
public:
    MyTestClientHandler(Solver solver, FileCacheManager fileCacheManager);
    void handleClient(int socket);
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
