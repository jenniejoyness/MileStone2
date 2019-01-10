
#include <string>
#include <cstring>
#include <unistd.h>
#include "MyClientHandler.h"
#include "SplitClass.h"
#include "Matrix.h"

MyClientHandler::MyClientHandler(Solver<Searchable<Point>*,string>* solver,CacheManager* cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyClientHandler::handleClient(int socketId) {
    int flag = 0;
    int col;
    int row;
    int i = 0;
    bool matrixEnd = false;
    string prob;
    State<Point> *initialState;
    State<Point> *goalState;
    vector<string> temp;
    vector<State<Point> *> searchable;
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
        if (strcmp(buffer, "end") == 0) {
            break;
        }
        switch (flag) {
            //size of matrix
            //????todo - will he give size
            case 0:
                prob += buffer;
                temp = SplitClass::split(buffer, ",");
                //set matrix size
                if (temp.size() == 1) {
                    row = col = stoi(temp[0]);
                } else {
                    row = stoi(temp[0]), col = stoi(temp[1]);
                }
                temp.clear();
                flag++;
                break;
                //initial state
            case 1:
                prob += buffer;
                temp = SplitClass::split(buffer, ",");
                initialState = new State<Point>(Point(stoi(temp[0]), stoi(temp[1])), 0);
                temp.clear();
                flag++;
                break;
                //goal state
            case 2:
                prob += buffer;
                temp = SplitClass::split(buffer, ",");
                goalState = new State<Point>(Point(stoi(temp[0]), stoi(temp[1])), 0);
                temp.clear();
                flag++;
                break;
                //matrix
            case 3:
                temp = SplitClass::split(buffer, ",");
                for (int j = 0; j < col; ++j) {
                    if (i == initialState->getState().getX() && j == initialState->getState().getY()) {
                        initialState->setCost(stod(temp[j]));
                        searchable.push_back(initialState);
                    } else if (i == goalState->getState().getX() && j == goalState->getState().getY()) {
                        goalState->setCost(stod(temp[j]));
                        searchable.push_back(goalState);
                    } else {
                        searchable.push_back(new State<Point>(Point(i, j), stod(temp[j])));
                    }

                }
                prob += buffer;
                i++;
                if (i == row) {
                    matrixEnd = true;
                }
                break;
        }
        //solve matrix
        if (matrixEnd) {
            Searchable<Point> *matrix = new Matrix(searchable, initialState, goalState);
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
            cout << "in myclienthandler:" + solution << endl;

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
            flag = 0;
            prob = "";
        }
    }

}

