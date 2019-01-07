//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

template <class T>
class State {
private:
    T state;
    double cost;
    State<T> comeFrom;

public:
     bool Equals(State<T> s);
};


#endif //MILESTONE2_STATE_H
