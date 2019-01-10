//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H

#include "State.h"
#include <vector>
#include <iostream>
#include <algorithm>

template <class T>
class Searchable {
protected:
    std::vector<State<T>*> structure;
    State<T>* initialState;
    State<T>* goal;
public:
    State<T>* getInitialState() { return initialState; }
    State<T>* getGoalState() { return goal; }
    std::vector<State<T>*> getAllPossibleStates(State<T>* s) { return structure; }
    virtual vector<State<T>*> getNeighbors(State<T>* s) = 0;
    string getPath(){
        State<T> * current = getGoalState();
        string path;
        //end when at the father
        while (current->getComaFrom() != nullptr) {
            for (State<T> *state:structure) {
                if (state->getComaFrom() != nullptr) {
                    //find father node of current
                    if (current->getComaFrom()->Equals(state)) {
                        path += current->getState().move(state->getState());
                        break;
                    }
                }
            }
            current = current->getComaFrom();
            //when the current is the initial state
            if (current->getComaFrom()->Equals(getInitialState()) ){
                break;
            }
        }
        //find the last move to the initial state
        path += current->getState().move(getInitialState()->getState());
        reverse(path.begin(), path.end());
        return path;
    }

};
#endif //MILESTONE2_SEARCHABLE_H
