//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <vector>
#include <iostream>
using namespace std;

template <class T>
class State {
private:
    T state;
    double cost;
    double trailCost;
    State<T>* comeFrom;

public:
    State() {}
    State<T> (T state, double cost):state(state), cost(cost), trailCost(cost), comeFrom(nullptr) {}
    double getCost() const { return cost; }
    bool Equals(State<T>* s) { return this->state == s->state; }
    void setComeFrom(State<T>* comeFrom) { this->comeFrom = comeFrom; }
    void addCost(double c) {trailCost += c; }
    double getTrailCost() const { return trailCost; }
    void setTrailCost(double trailCost) { this->trailCost = trailCost; }
    State<T> *getComeFrom() const { return comeFrom; }
    string toString() { return to_string(T) }


    //void setComeFrom(const State<T> &comeFrom);
};


#endif //MILESTONE2_STATE_H
