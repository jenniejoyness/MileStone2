#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H


#include "CacheManager.h"
#include <vector>

class FileCacheManager : public CacheManager {
public:
    FileCacheManager();
    bool hasSolution(string prob);
    string getSolution(string prob);
    void updateData(string prob, string solution) override;
    void saveToDisk(string prob, string solution) override;
    void loadDataMap();

};


#endif //MILESTONE2_FILECACHEMANAGER_H