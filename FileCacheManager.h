//
// Created by renana on 1/3/19.
//

#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H


#include "CacheManager.h"

class FileCacheManager : public CacheManager{
public:
    bool hasSolution();
    string getSolution();

};


#endif //MILESTONE2_FILECACHEMANAGER_H
