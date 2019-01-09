#include <fstream>
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
    vector<string> chunks;
    ifstream file;
    file.open("solutions.txt", ifstream::in | istream::app);
    if (!file) {
        throw "Failed opening file";
    }
    while (getline(file, buffer)) {
        chunks = SplitClass::split(buffer, "$");
        data.insert(pair<string, string>(chunks[0], chunks[1]));
    }
    file.close();

}



void FileCacheManager::updateData(string prob, string solution) {

    data.insert(pair<string, string>(prob, solution));
}

void FileCacheManager::saveToDisk(string prob, string solution) {
    ofstream file;
    file.open("solutions.txt" , ofstream::out | ostream::app);
    if(!file){
        throw "failed opening file";
    }
    file << prob << "$" << solution << endl;
    file.close();
}