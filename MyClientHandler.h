
#ifndef MILESTONE2_MYCLIENTHANDLER_H
#define MILESTONE2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Searchable.h"
#include "Point.h"

class MyClientHandler : public ClientHandler{
private:
    Solver<Searchable<Point>*,string>* solver;
    CacheManager* cacheManager;
public:
    MyClientHandler(Solver<Searchable<Point>*,string>* solver,CacheManager* cacheManager);
    void handleClient(int socketId);
};


#endif //MILESTONE2_MYCLIENTHANDLER_H
