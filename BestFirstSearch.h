//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "Searcher.h"

template <class T>
class BestFirstSearch : public Searcher<T> {
T search(Searchable<T> searchable) override;
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
