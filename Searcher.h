//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include "Searchable.h"
template <class T>
class Searcher {
private:

public:
    virtual T search (Searchable<T> searchable) = 0;
};
#endif //MILESTONE2_SEARCHER_H
