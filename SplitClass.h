//
// Created by jennie on 1/9/19.
//

#ifndef MILESTONE2_SPLITCLASS_H
#define MILESTONE2_SPLITCLASS_H

#include <vector>
#include <string>

using namespace std;
class SplitClass{
public:
    static vector<string> split(string line, string delimiter) {
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
};

#endif //MILESTONE2_SPLITCLASS_H
