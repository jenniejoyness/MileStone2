#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    MySerialServer* d = new MySerialServer;
    Solver<string,string>* solver = new StringReverser();
    FileCacheManager* fileCacheManager = new FileCacheManager();
    ClientHandler* ds = new MyTestClientHandler(solver, fileCacheManager);
    d->open(5400,ds);
    while(true){}
    return 0;
}