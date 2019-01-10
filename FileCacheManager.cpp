#include <fstream>
#include <cstring>
#include "FileCacheManager.h"
#include "SplitClass.h"

FileCacheManager::FileCacheManager() {
    loadDataMap();
}

string FileCacheManager::getSolution(string problem) {
    return data.find(problem)->second;
}

bool FileCacheManager::hasSolution(string prob) {
    for (auto problem : data) {
        if (problem.first == prob) {
            return true;
        }
    }
    return false;
}

void FileCacheManager::loadDataMap() {
    string buffer;
    string p;
    string s;
    bool inSol = false;
    ifstream fileSolutions;

    fileSolutions.open("solutions.txt", ifstream::in | istream::app);
    if (!fileSolutions) {
        throw "Failed opening file";
    }
    while (getline(fileSolutions, buffer)) {
        while (strcmp(buffer.c_str(), "$$")  != 0){
            if (strcmp(buffer.c_str(), "$")  == 0) {
                inSol = true;
            }
            else if (!inSol) {
                p += buffer;
            }
            else {
                s += buffer;
            }
            getline(fileSolutions, buffer);
        }
        data.insert(pair<string, string>(p, s));
        inSol = false;
        p = "";
        s = "";
    }
    fileSolutions.close();

}



void FileCacheManager::updateData(string prob, string solution) {

    data.insert(pair<string, string>(prob, solution));
}

void FileCacheManager::saveToDisk(string prob, string solution) {
    ofstream fileSolution;


    fileSolution.open("solutions.txt" , ofstream::out | ostream::app);
    if(!fileSolution){
        throw "failed opening file";
    }
    fileSolution<<prob << endl;
    fileSolution<<"$"<<endl;
    fileSolution << solution << endl;
    fileSolution << "$$" << endl;

    fileSolution.close();
}