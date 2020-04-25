#ifndef PARTY_H
#define PARTY_H

#include <string>

using namespace std;

class Party {
private:
    string name;   //"together" or "integration"
    bool isUser;

public:
    Party(string name, bool isUser);
    string getName();
    void generateInput(int* P, int* M, int* C);

};

#endif