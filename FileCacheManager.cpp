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
    vector<string> solutions;
    vector<string> problem;
    vector<string> chunks;
    ifstream fileSolutions;
    ifstream fileProblems;
    fileSolutions.open("solutions.txt", ifstream::in | istream::app);
    if (!fileSolutions) {
        throw "Failed opening file";
    }
    fileProblems.open("graphs.txt", ifstream::in | istream::app);
    if (!fileProblems) {
        throw "Failed opening file";
    }
    while (getline(fileSolutions, buffer)) {
        solutions.push_back(buffer);
    }
    while (getline(fileProblems, buffer)) {
        while(strcmp(buffer.c_str(), "$")  != 0){
            p += buffer + "\r\n";
        }
        problem.push_back(p);
        p = "";
    }
    for (int i = 0; i < solutions.size(); ++i) {
        data.insert(pair<string, string>(problem[i], solutions[i]));
    }
    fileProblems.close();
    fileSolutions.close();

}



void FileCacheManager::updateData(string prob, string solution) {

    data.insert(pair<string, string>(prob, solution));
}

void FileCacheManager::saveToDisk(string prob, string solution) {
    ofstream fileSolution;
    ofstream fileProblem;

    fileSolution.open("solutions.txt" , ofstream::out | ostream::app);
    if(!fileSolution){
        throw "failed opening file";
    }
    fileProblem.open("graphs.txt" , ofstream::out | ostream::app);
    if(!fileProblem){
        throw "failed opening file";
    }

    fileProblem<<prob;
    fileProblem<<"$"<<endl;

    fileSolution << solution << endl;

    fileSolution.close();
    fileProblem.close();
}