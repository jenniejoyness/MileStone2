
#include <iostream>
#include "Solver.h"
#include "BestFirstSearch.h"
#include "SearcherSolver.h"
#include "MyClientHandler.h"
#include "A_Star.h"
#include "MyParallelServer.h"
#include "FileCacheManager.h"

namespace boot {
    class Main {
    public:
        int main(int argc, char *argv[]) {
            return 0;
        }
    };
}

int main(int argc, char *argv[]) {
    boot::Main m;
    m.main(argc, argv);
    server_side::Server *server = new MyParallelServer();
    Solver<Searchable<Point> *, string> *solver = new SearcherSolver(new A_Star<Point>());
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MyClientHandler(solver, cacheManager);
    server->open(stoi(argv[1]), clientHandler);
    delete server;
    delete solver;
    delete cacheManager;
    delete clientHandler;

    return 0;
}