
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

       /* std::cout << "Hello, World!" << std::endl;
         Server* d = new MyParallelServer();
         Solver<Searchable<Point>*,string>* solver = new SearcherSolver(new A_Star<Point>());
         CacheManager* cacheManager = new FileCacheManager();
         ClientHandler* ds = new MyClientHandler(solver, cacheManager);
         d->open(5400,ds);
*/
        vector<State<Point> *> searchable;
        /*
        State<Point> *initial = new State<Point>(Point(0, 0), 2);
        searchable.push_back(new State<Point>(Point(0, 1), 3));
        searchable.push_back(new State<Point>(Point(0, 2), 100));
        searchable.push_back(new State<Point>(Point(0, 3), 100));
        searchable.push_back(new State<Point>(Point(0, 4), 1));
        searchable.push_back(new State<Point>(Point(0, 5), 2));
        searchable.push_back(new State<Point>(Point(0, 6), 2));
        searchable.push_back(new State<Point>(Point(0, 7), 3));
        searchable.push_back(new State<Point>(Point(0, 8), 2));
        searchable.push_back(new State<Point>(Point(0, 9), 2));
        searchable.push_back(new State<Point>(Point(0, 10), 3));
        searchable.push_back(new State<Point>(Point(0, 11), 2));
        searchable.push_back(new State<Point>(Point(0, 12), 2));
        searchable.push_back(new State<Point>(Point(0, 13), 2));
        searchable.push_back(new State<Point>(Point(0, 14), 2));

        searchable.push_back(new State<Point>(Point(1, 0), 3));
        searchable.push_back(new State<Point>(Point(1, 1), 100));
        searchable.push_back(new State<Point>(Point(1, 2), 100));
        searchable.push_back(new State<Point>(Point(1, 3), 1));
        searchable.push_back(new State<Point>(Point(1, 4), 2));
        searchable.push_back(new State<Point>(Point(1, 5), 2));
        searchable.push_back(new State<Point>(Point(1, 6), 3));
        searchable.push_back(new State<Point>(Point(1, 7), 3));
        searchable.push_back(new State<Point>(Point(1, 8), 3));
        searchable.push_back(new State<Point>(Point(1, 9), 2));
        searchable.push_back(new State<Point>(Point(1, 10), 2));
        searchable.push_back(new State<Point>(Point(1, 11), 2));
        searchable.push_back(new State<Point>(Point(1, 12), 2));
        searchable.push_back(new State<Point>(Point(1, 13), 2));
        searchable.push_back(new State<Point>(Point(1, 14), 2));

        searchable.push_back(new State<Point>(Point(2, 0), 3));
        searchable.push_back(new State<Point>(Point(2, 1), 100));
        searchable.push_back(new State<Point>(Point(2, 2), 100));
        searchable.push_back(new State<Point>(Point(2, 3), 1));
        searchable.push_back(new State<Point>(Point(2, 4), 2));
        searchable.push_back(new State<Point>(Point(2, 5), 2));
        searchable.push_back(new State<Point>(Point(2, 6), 3));
        searchable.push_back(new State<Point>(Point(2, 7), 3));
        searchable.push_back(new State<Point>(Point(2, 8), 3));
        searchable.push_back(new State<Point>(Point(2, 9), 2));
        searchable.push_back(new State<Point>(Point(2, 14), 2));
        searchable.push_back(new State<Point>(Point(2, 14), 2));
        searchable.push_back(new State<Point>(Point(2, 14), 2));
        searchable.push_back(new State<Point>(Point(2, 14), 2));
        searchable.push_back(new State<Point>(Point(2, 14), 2));

        searchable.push_back(new State<Point>(Point(3, 0), 3));
        searchable.push_back(new State<Point>(Point(3, 1), 100));
        searchable.push_back(new State<Point>(Point(3, 2), 100));
        searchable.push_back(new State<Point>(Point(3, 3), 1));
        searchable.push_back(new State<Point>(Point(3, 4), 2));
        searchable.push_back(new State<Point>(Point(3, 5), 2));
        searchable.push_back(new State<Point>(Point(3, 6), 3));
        searchable.push_back(new State<Point>(Point(3, 7), 3));
        searchable.push_back(new State<Point>(Point(3, 8), 3));
        searchable.push_back(new State<Point>(Point(3, 9), 2));
        searchable.push_back(new State<Point>(Point(3, 10), 2));
        searchable.push_back(new State<Point>(Point(3, 11), 2));
        searchable.push_back(new State<Point>(Point(3, 12), 2));
        searchable.push_back(new State<Point>(Point(3, 13), 2));
        searchable.push_back(new State<Point>(Point(3, 14), 2));

        searchable.push_back(new State<Point>(Point(4, 0), 3));
        searchable.push_back(new State<Point>(Point(4, 1), 100));
        searchable.push_back(new State<Point>(Point(4, 2), 100));
        searchable.push_back(new State<Point>(Point(4, 3), 1));
        searchable.push_back(new State<Point>(Point(4, 4), 2));
        searchable.push_back(new State<Point>(Point(4, 5), 2));
        searchable.push_back(new State<Point>(Point(4, 6), 3));
        searchable.push_back(new State<Point>(Point(4, 7), 3));
        searchable.push_back(new State<Point>(Point(4, 8), 3));
        searchable.push_back(new State<Point>(Point(4, 9), 2));
        searchable.push_back(new State<Point>(Point(4, 10), 2));
        searchable.push_back(new State<Point>(Point(4, 11), 2));
        searchable.push_back(new State<Point>(Point(4, 12), 2));
        searchable.push_back(new State<Point>(Point(4, 13), 2));
        searchable.push_back(new State<Point>(Point(4, 14), 2));

        searchable.push_back(new State<Point>(Point(5, 0), 3));
        searchable.push_back(new State<Point>(Point(5, 1), 100));
        searchable.push_back(new State<Point>(Point(5, 2), 100));
        searchable.push_back(new State<Point>(Point(5, 3), 1));
        searchable.push_back(new State<Point>(Point(5, 4), 2));
        searchable.push_back(new State<Point>(Point(5, 5), 2));
        searchable.push_back(new State<Point>(Point(5, 6), 3));
        searchable.push_back(new State<Point>(Point(5, 7), 3));
        searchable.push_back(new State<Point>(Point(5, 8), 3));
        searchable.push_back(new State<Point>(Point(5, 9), 2));
        searchable.push_back(new State<Point>(Point(5, 10), 2));
        searchable.push_back(new State<Point>(Point(5, 11), 2));
        searchable.push_back(new State<Point>(Point(5, 12), 2));
        searchable.push_back(new State<Point>(Point(5, 13), 2));
        searchable.push_back(new State<Point>(Point(5, 14), 2));

        searchable.push_back(new State<Point>(Point(6, 0), 3));
        searchable.push_back(new State<Point>(Point(6, 1), 100));
        searchable.push_back(new State<Point>(Point(6, 2), 100));
        searchable.push_back(new State<Point>(Point(6, 3), 1));
        searchable.push_back(new State<Point>(Point(6, 4), 2));
        searchable.push_back(new State<Point>(Point(6, 5), 2));
        searchable.push_back(new State<Point>(Point(6, 6), 3));
        searchable.push_back(new State<Point>(Point(6, 7), 3));
        searchable.push_back(new State<Point>(Point(6, 8), 3));
        searchable.push_back(new State<Point>(Point(6, 9), 2));
        searchable.push_back(new State<Point>(Point(6, 10), 2));
        searchable.push_back(new State<Point>(Point(6, 11), 2));
        searchable.push_back(new State<Point>(Point(6, 12), 2));
        searchable.push_back(new State<Point>(Point(6, 13), 2));
        searchable.push_back(new State<Point>(Point(6, 14), 2));

        searchable.push_back(new State<Point>(Point(7, 0), 3));
        searchable.push_back(new State<Point>(Point(7, 1), 100));
        searchable.push_back(new State<Point>(Point(7, 2), 100));
        searchable.push_back(new State<Point>(Point(7, 3), 1));
        searchable.push_back(new State<Point>(Point(7, 4), 2));
        searchable.push_back(new State<Point>(Point(7, 5), 2));
        searchable.push_back(new State<Point>(Point(7, 6), 3));
        searchable.push_back(new State<Point>(Point(7, 7), 3));
        searchable.push_back(new State<Point>(Point(7, 8), 3));
        searchable.push_back(new State<Point>(Point(7, 9), 2));
        searchable.push_back(new State<Point>(Point(7, 10), 2));
        searchable.push_back(new State<Point>(Point(7, 11), 2));
        searchable.push_back(new State<Point>(Point(7, 12), 2));
        searchable.push_back(new State<Point>(Point(7, 13), 2));
        searchable.push_back(new State<Point>(Point(7, 14), 2));

        searchable.push_back(new State<Point>(Point(8, 0), 3));
        searchable.push_back(new State<Point>(Point(8, 1), 100));
        searchable.push_back(new State<Point>(Point(8, 2), 100));
        searchable.push_back(new State<Point>(Point(8, 3), 1));
        searchable.push_back(new State<Point>(Point(8, 4), 2));
        searchable.push_back(new State<Point>(Point(8, 5), 2));
        searchable.push_back(new State<Point>(Point(8, 6), 3));
        searchable.push_back(new State<Point>(Point(8, 7), 3));
        searchable.push_back(new State<Point>(Point(8, 8), 3));
        searchable.push_back(new State<Point>(Point(8, 9), 2));
        searchable.push_back(new State<Point>(Point(8, 10), 2));
        searchable.push_back(new State<Point>(Point(8, 11), 2));
        searchable.push_back(new State<Point>(Point(8, 12), 2));
        searchable.push_back(new State<Point>(Point(8, 13), 2));
        searchable.push_back(new State<Point>(Point(8, 14), 2));

        searchable.push_back(new State<Point>(Point(9, 0), 3));
        searchable.push_back(new State<Point>(Point(9, 1), 100));
        searchable.push_back(new State<Point>(Point(9, 2), 100));
        searchable.push_back(new State<Point>(Point(9, 3), 1));
        searchable.push_back(new State<Point>(Point(9, 4), 2));
        searchable.push_back(new State<Point>(Point(9, 5), 2));
        searchable.push_back(new State<Point>(Point(9, 6), 3));
        searchable.push_back(new State<Point>(Point(9, 7), 3));
        searchable.push_back(new State<Point>(Point(9, 8), 3));
        searchable.push_back(new State<Point>(Point(9, 9), 2));
        searchable.push_back(new State<Point>(Point(9, 10), 2));
        searchable.push_back(new State<Point>(Point(9, 11), 2));
        searchable.push_back(new State<Point>(Point(9, 12), 2));
        searchable.push_back(new State<Point>(Point(9, 13), 2));
        searchable.push_back(new State<Point>(Point(9, 14), 2));

        searchable.push_back(new State<Point>(Point(10, 0), 3));
        searchable.push_back(new State<Point>(Point(10, 1), 100));
        searchable.push_back(new State<Point>(Point(10, 2), 100));
        searchable.push_back(new State<Point>(Point(10, 3), 1));
        searchable.push_back(new State<Point>(Point(10, 4), 2));
        searchable.push_back(new State<Point>(Point(10, 5), 2));
        searchable.push_back(new State<Point>(Point(10, 6), 3));
        searchable.push_back(new State<Point>(Point(10, 7), 3));
        searchable.push_back(new State<Point>(Point(10, 8), 3));
        searchable.push_back(new State<Point>(Point(10, 9), 2));
        State<Point> *goal = new State<Point>(Point(10, 10), 1);
        searchable.push_back(new State<Point>(Point(10, 11), 2));
        searchable.push_back(new State<Point>(Point(10, 12), 2));
        searchable.push_back(new State<Point>(Point(10, 13), 2));
        searchable.push_back(new State<Point>(Point(10, 14), 2));

        searchable.push_back(new State<Point>(Point(11, 0), 2));
        searchable.push_back(new State<Point>(Point(11, 1), 2));
        searchable.push_back(new State<Point>(Point(11, 2), 2));
        searchable.push_back(new State<Point>(Point(11, 3), 2));
        searchable.push_back(new State<Point>(Point(11, 4), 2));
        searchable.push_back(new State<Point>(Point(11, 5), 2));
        searchable.push_back(new State<Point>(Point(11, 6), 2));
        searchable.push_back(new State<Point>(Point(11, 7), 2));
        searchable.push_back(new State<Point>(Point(11, 8), 2));
        searchable.push_back(new State<Point>(Point(11, 9), 2));
        searchable.push_back(new State<Point>(Point(11, 10), 2));
        searchable.push_back(new State<Point>(Point(11, 11), 2));
        searchable.push_back(new State<Point>(Point(11, 12), 2));
        searchable.push_back(new State<Point>(Point(11, 13), 2));
        searchable.push_back(new State<Point>(Point(11, 14), 2));

        searchable.push_back(new State<Point>(Point(12, 0), 2));
        searchable.push_back(new State<Point>(Point(12, 1), 2));
        searchable.push_back(new State<Point>(Point(12, 2), 2));
        searchable.push_back(new State<Point>(Point(12, 3), 2));
        searchable.push_back(new State<Point>(Point(12, 4), 2));
        searchable.push_back(new State<Point>(Point(12, 5), 2));
        searchable.push_back(new State<Point>(Point(12, 6), 2));
        searchable.push_back(new State<Point>(Point(12, 7), 2));
        searchable.push_back(new State<Point>(Point(12, 8), 2));
        searchable.push_back(new State<Point>(Point(12, 9), 2));
        searchable.push_back(new State<Point>(Point(12, 10), 2));
        searchable.push_back(new State<Point>(Point(12, 11), 2));
        searchable.push_back(new State<Point>(Point(12, 12), 2));
        searchable.push_back(new State<Point>(Point(12, 13), 2));
        searchable.push_back(new State<Point>(Point(12, 14), 2));

        searchable.push_back(new State<Point>(Point(13, 0), 2));
        searchable.push_back(new State<Point>(Point(13, 1), 2));
        searchable.push_back(new State<Point>(Point(13, 2), 2));
        searchable.push_back(new State<Point>(Point(13, 3), 2));
        searchable.push_back(new State<Point>(Point(13, 4), 2));
        searchable.push_back(new State<Point>(Point(13, 5), 2));
        searchable.push_back(new State<Point>(Point(13, 6), 2));
        searchable.push_back(new State<Point>(Point(13, 7), 2));
        searchable.push_back(new State<Point>(Point(13, 8), 2));
        searchable.push_back(new State<Point>(Point(13, 9), 2));
        searchable.push_back(new State<Point>(Point(13, 10), 2));
        searchable.push_back(new State<Point>(Point(13, 11), 2));
        searchable.push_back(new State<Point>(Point(13, 12), 2));
        searchable.push_back(new State<Point>(Point(13, 13), 2));
        searchable.push_back(new State<Point>(Point(13, 14), 2));

        searchable.push_back(new State<Point>(Point(14, 0), 2));
        searchable.push_back(new State<Point>(Point(14, 1), 2));
        searchable.push_back(new State<Point>(Point(14, 2), 2));
        searchable.push_back(new State<Point>(Point(14, 3), 2));
        searchable.push_back(new State<Point>(Point(14, 4), 2));
        searchable.push_back(new State<Point>(Point(14, 5), 2));
        searchable.push_back(new State<Point>(Point(14, 6), 2));
        searchable.push_back(new State<Point>(Point(14, 7), 2));
        searchable.push_back(new State<Point>(Point(14, 8), 2));
        searchable.push_back(new State<Point>(Point(14, 9), 2));
        searchable.push_back(new State<Point>(Point(14, 10), 2));
        searchable.push_back(new State<Point>(Point(14, 11), 2));
        searchable.push_back(new State<Point>(Point(14, 12), 2));
        searchable.push_back(new State<Point>(Point(14, 13), 2));
        searchable.push_back(new State<Point>(Point(14, 14), 2));

        searchable.push_back(goal);
        searchable.push_back(initial);*/
        int size = 37;
        string buffer;
        ifstream fileSolutions;
        fileSolutions.open("tests.txt", ifstream::in | istream::app);
        if (!fileSolutions) {
            throw "Failed opening file";
        }
        State<Point> *initialState = new State<Point>(Point(0,0),0);
        State<Point> *goalState = new State<Point>(Point(size-1, size-1),0);
        while (getline(fileSolutions, buffer)) {

            for (int i = 0; i < size ;++i) {
                vector<string> chopped = SplitClass::split(buffer,",");
                for (int j = 0; j < size; ++j) {
                    if (i == 0 && j == 0) {
                        initialState->setCost(stod(chopped[j]));
                        searchable.push_back(initialState);
                        //set goal state cost
                    } else if (i == size -1 && j == size -1 ) {
                        goalState->setCost(stod(chopped[j]));
                        searchable.push_back(goalState);
                        //make states
                    }else{
                        searchable.push_back(new State<Point>(Point(i,j),stoi(chopped[j])));
                    }

                }

            }
        }






        //Searchable<Point> *m = new Matrix(searchable, initial, goal);

        Searchable<Point>* matrix = new Matrix(searchable,initialState,goalState);
        string s;
        Searcher<Point> *b = new BestFirstSearch<Point>;
        string x = b->search(matrix);
        cout << "solution:"<<x << endl;
        cout << "trail cost:"<<matrix->getGoalState()->getTrailCost() << endl;

        return 0;
    }