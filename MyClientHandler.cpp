
#include <string>
#include <cstring>
#include <unistd.h>
#include "MyClientHandler.h"
#include "SplitClass.h"
#include "Matrix.h"
#pragma once

MyClientHandler::MyClientHandler(Solver<Searchable<Point>*,string>* solver,CacheManager* cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyClientHandler::handleClient(int socketId) {
    string prob;
    vector<string> tempProb;
    char buffer[256];
    string solution;
    ssize_t n;
    char *chr;

    if (socketId < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    while (true) {
        /* If connection is established then start communicating */
        bzero(buffer, 256);
        n = read(socketId, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        //solve matrix
        if (strcmp(buffer, "end") == 0) {
            Searchable<Point> *matrix = makeMatrix(tempProb);
            //get solution from disk
            if (this->cacheManager->hasSolution(prob)) {
                solution = this->cacheManager->getSolution(prob);
                cout<<"found in file"<<endl;
            } else {
                cout<<"solved"<<endl;
                solution = solver->solve(matrix);

                //solution = to_string(matrix->getGoalState()->getTrailCost());
                cacheManager->updateData(prob, solution);
                cacheManager->saveToDisk(prob, solution);
            }

            /* Write a response to the client */
            chr = const_cast<char *>(solution.c_str());
            n = write(socketId, chr, strlen(chr));
            cout << "solution:" + solution << endl;
            cout << "trail cost:" + to_string(matrix->getGoalState()->getTrailCost()) << endl;
            delete(matrix);


            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            break;
        }
        tempProb.emplace_back(buffer);
        prob += buffer;

    }

}

Searchable<Point>* MyClientHandler::makeMatrix(vector<string> tempProb) {
    vector<State<Point>*> searchable;
    vector<string> chopped;


    chopped = SplitClass::split(tempProb[tempProb.size() - 2], ",");
    State<Point> *initialState = new State<Point>(Point(stoi(chopped[0]), stoi(chopped[1])),0);
    chopped = SplitClass::split(tempProb[tempProb.size() - 1], ",");
    State<Point> *goalState = new State<Point>(Point(stoi(chopped[0]), stoi(chopped[1])),0);

    long row = tempProb.size() - 2;
    long col = SplitClass::split(tempProb[0],",").size();

    for (int i = 0; i < row ;++i) {
        chopped = SplitClass::split(tempProb[i],",");
        for (int j = 0; j < col; ++j) {
            //set initial state cost
            if (i == initialState->getState().getX() && j == initialState->getState().getY()) {
                initialState->setCost(stod(chopped[j]));
                searchable.push_back(initialState);
                //set goal state cost
            } else if (i == goalState->getState().getX() && j == goalState->getState().getY()) {
                goalState->setCost(stod(chopped[j]));
                searchable.push_back(goalState);
                //make states
            }else{
                searchable.push_back(new State<Point>(Point(i,j),stoi(chopped[j])));
            }
              }

    }
    Searchable<Point>* matrix = new Matrix(searchable,initialState,goalState);
    return matrix;
}

