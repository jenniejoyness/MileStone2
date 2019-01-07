
#ifndef MILESTONE2_SERVER_H
#define MILESTONE2_SERVER_H

#include "ClientHandler.h"

class Server {

protected:
bool shouldStop = false;

public:
virtual void open(int port, ClientHandler c) = 0;
virtual void stop() = 0;

};

#endif //MILESTONE2_SERVER_H
