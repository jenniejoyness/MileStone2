
#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string,string>* solver;
    FileCacheManager* cacheManager;
public:
    MyTestClientHandler(Solver<string,string>* solver, FileCacheManager* cacheManager);
    void handleClient(int socket) override;
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
