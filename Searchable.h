//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <vector>

template <class T>
class Searchable {
protected:
    std::vector<State<T>*> structure;
    State<T>* initialState;
    State<T>* goal;
public:
    //todo - set struct,setters
    State<T>* getInitialState() { return initialState; }
    State<T>* getGoalState() { return goal; }
    std::vector<State<T>*> getAllPossibleStates(State<T>* s) { return structure; }
    //todo
    vector<State<T>*> getNeighbors(State<T>* s) {};

};
#endif //MILESTONE2_SEARCHABLE_H
