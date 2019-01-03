//
// Created by renana on 1/3/19.
//

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H

#include <iosfwd>

using namespace std;
class ClientHandler {

public:
    virtual void handleClient(istream &in, ostream &out) = 0;
};
#endif //MILESTONE2_CLIENTHANDLER_H
