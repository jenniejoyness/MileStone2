#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "Solver.h"
#include "StringReverser.h"
#include "State.h"
#include "BestFirstSearch.h"
#include "SearcherSolver.h"
#include "MyClientHandler.h"
#include "Matrix.h"
#include "BFS.h"
#include "DFS.h"
#include "A_Star.h"

using namespace std;
void foo(int* blah, int size, int d);
#include <queue>
int main() {
 typedef pair<int, int> Pair;
 typedef pair<double, Pair> pPair;
 vector<pPair> pairs;
   std::cout << "Hello, World!" << std::endl;
   /* MySerialServer* d = new MySerialServer();
    Solver<Searchable<Point>*,string>* solver = new SearcherSolver(new A_Star<Point>());
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* ds = new MyClientHandler(solver, cacheManager);
    d->open(5400,ds);*/


    State<Point>* initial = new State<Point>(Point(0, 0), 1);
    State<Point>* goal = new State<Point>(Point(1, 2), 1);

    vector<State<Point> *> searchable;
    searchable.push_back(initial);
    searchable.push_back(new State<Point>(Point(0, 1), -1));
    searchable.push_back(new State<Point>(Point(0, 2), 1));
    searchable.push_back(new State<Point>(Point(1, 0), 1));
    searchable.push_back(new State<Point>(Point(1, 1), 1));
    searchable.push_back(goal);

    pairs.emplace_back(pPair(1,Pair(0,0)));
 pairs.emplace_back(pPair(-1,Pair(0,1)));
 pairs.emplace_back(pPair(1,Pair(0,2)));
 pairs.emplace_back(pPair(1,Pair(1,0)));
 pairs.emplace_back(pPair(1,Pair(1,1)));
 pairs.emplace_back(pPair(1,Pair(1,2)));






    Searchable<Point>* m = new Matrix(searchable, initial, goal);
    string s;
    m->setStateLocations(pairs);
    m->setRowAndCol(2,3);
    m->setSrcsAndDest(Pair(m->getInitialState()->getState().getX(),m->getInitialState()->getState().getY()),
                           Pair(m->getGoalState()->getState().getX(), m->getGoalState()->getState().getY()));
/*    if (cacheManager->hasSolution(prob)) {
        s = cacheManager->getSolution(prob);
        cout<<"found in file"<<endl;
    } else {
        cout<<"solved"<<endl;
        s = solver->solve(m);
        //solution = to_string(matrix->getGoalState()->getTrailCost());
        cacheManager->updateData(prob, s);
        cacheManager->saveToDisk(prob, s);
    }*/
    A_Star<Point> * b = new A_Star<Point>;
    string x = b->search(m);
    cout << x << endl;
/*
 State<Point>* initial = new State<Point>(Point(0, 0), 3);
 State<Point>* goal = new State<Point>(Point(2, 2), 6);

 vector<State<Point> *> searchable;
 searchable.push_back(initial);
 searchable.push_back(new State<Point>(Point(0, 1), 2));
 searchable.push_back(new State<Point>(Point(0, 2), 2));
 searchable.push_back(new State<Point>(Point(1, 0), 1));
 searchable.push_back(new State<Point>(Point(1, 1), 7));
 searchable.push_back(new State<Point>(Point(1, 2), 5));
 searchable.push_back(new State<Point>(Point(2, 0), 100));
 searchable.push_back(new State<Point>(Point(2, 1), 4));
 searchable.push_back(goal);



 Searchable<Point>* m = new Matrix(searchable, initial, goal);
 DFS<Point> * b = new DFS<Point>;
 string x = b->search(m);
 cout << x << endl;*/

    while(true){}


    return 0;
}
