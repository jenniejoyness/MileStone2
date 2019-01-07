
#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H

#include <string>
#include <map>

using namespace std;


class CacheManager {
protected:
    map <string,string> data;

public:
    virtual bool hasSolution(string prob) = 0;
    virtual string getSolution(string prob) = 0;
    virtual void updateData(string prob, string solution) = 0;
};
#endif //MILESTONE2_CACHEMANAGER_H
