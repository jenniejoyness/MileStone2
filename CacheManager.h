
#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H

#include <string>

using namespace std;


class CacheManager {

public:
    virtual bool hasSolution() = 0;
    virtual string getSolution() = 0;

};
#endif //MILESTONE2_CACHEMANAGER_H
