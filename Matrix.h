//
// Created by renana on 1/7/19.
//

#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H


#include "Searchable.h"
#include "Point.h"

class Matrix : public Searchable<Point>{

public:
    Matrix(std::vector<State<Point>*> structure, State<Point>* initialState,State<Point>* goal);
    vector<State<Point>*> getNeighbors(State<Point>* s) override;
    ~Matrix() override;
};


#endif //MILESTONE2_MATRIX_H
