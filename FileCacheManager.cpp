
#include <fstream>
#include "FileCacheManager.h"

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
        chunks = split(buffer, "$");
        data.insert(pair<string, string>(chunks[0], chunks[1]));
    }
    file.close();

}

vector<string> FileCacheManager::split(string line, string delimiter) {
    vector<string> data;
    size_t pos = 0;
    while ((pos = line.find(delimiter)) != string::npos) {
        if (!line.substr(0, pos).empty()) {
            data.push_back(line.substr(0, pos));
        }
        line.erase(0, pos + delimiter.length());
    }
    data.push_back(line.substr(0, pos));
    return data;

}

void FileCacheManager::updateData(string prob, string solution) {

    data.insert(pair<string, string>(prob, solution));
}

void FileCacheManager::writeToFile(string prob, string solution) {
    ofstream file;
    file.open("solutions.txt" , ofstream::out | ostream::app);
    if(!file){
        throw "failed opening file";
    }
    file << prob << "$" << solution << endl;
    file.close();
}