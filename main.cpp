
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
#include "MyParallelServer.h"
#include "SplitClass.h"
#include <fstream>

using namespace std;


#include <queue>

int main() {

    /*    std::cout << "Hello, World!" << std::endl;
         Server* d = new MyParallelServer();
         Solver<Searchable<Point>*,string>* solver = new SearcherSolver(new A_Star<Point>());
         CacheManager* cacheManager = new FileCacheManager();
         ClientHandler* ds = new MyClientHandler(solver, cacheManager);
         d->open(5400,ds);*/

    int size = 5;
    vector<State<Point> *> searchable;
    string buffer;
    ifstream fileSolutions;
    fileSolutions.open("tests.txt", ifstream::in | istream::app);
    if (!fileSolutions) {
        throw "Failed opening file";
    }
    State<Point> *initialState = new State<Point>(Point(0, 0), 0);
    State<Point> *goalState = new State<Point>(Point(size - 1, size - 1), 0);
    int i = 0;
    while (getline(fileSolutions, buffer)) {
        vector<string> chopped = SplitClass::split(buffer, ",");
        for (int j = 0; j < size; ++j) {
            if (i == 0 && j == 0) {
                initialState->setCost(stod(chopped[j]));
                searchable.push_back(initialState);
                continue;
                //set goal state cost
            } else if (i == (size - 1) && j == (size - 1)) {
                goalState->setCost(stod(chopped[j]));
                searchable.push_back(goalState);
                continue;
                //make states
            } else {
                searchable.push_back(new State<Point>(Point(i, j), stoi(chopped[j])));
            }

        }
        i++;
    }

    Searchable<Point> *matrix = new Matrix(searchable, initialState, goalState);
    string s;
    Searcher<Point> *b = new A_Star<Point>;
    string x = b->search(matrix);
    cout << "solution:" << x << endl;
    cout << "trail cost:" << matrix->getGoalState()->getTrailCost() << endl;
    return 0;
}