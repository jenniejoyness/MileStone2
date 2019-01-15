//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include <string>
#include "Searchable.h"
template <class T>
class Searcher {
protected:
    Searchable<T>* searchable;
    int numOfNodesEvaluated = 0;

public:
    virtual string search (Searchable<T>* searchable) = 0;
    double getTrailCost() {
        return searchable->getGoalState()->getTrailCost();
    }
    virtual int getNumOfNodesEvaluated() { return numOfNodesEvaluated;}
    virtual ~Searcher(){ delete searchable;}

};
#endif //MILESTONE2_SEARCHER_H
