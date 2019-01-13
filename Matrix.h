//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H


#include "Searchable.h"
#include "Point.h"
#pragma once

//todo - set structure -gets inout from user
class Matrix : public Searchable<Point>{

public:
    Matrix(std::vector<State<Point>*> structure, State<Point>* initialState,State<Point>* goal);
    vector<State<Point>*> getNeighbors(State<Point>* s) override;
};


#endif //MILESTONE2_MATRIX_H
