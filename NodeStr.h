#ifndef NODESTR_H
#define NODESTR_H

#include <string>
using namespace std;

class NodeStr {
public:
    string word;
    NodeStr* next;

    explicit NodeStr(const string& word);
};

#endif //NODESTR_H
