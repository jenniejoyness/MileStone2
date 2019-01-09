
#ifndef MILESTONE2_SEARCHERSOLVER_H
#define MILESTONE2_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "Point.h"


class SearcherSolver : public Solver<Searchable<Point>*,string>{
private:
    Searcher<Point>* searcher;
public:
    string solve(Searchable<Point>* p) override;
};


#endif //MILESTONE2_SEARCHERSOLVER_H
