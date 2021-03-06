#include "party.h"

#include <iostream>
#include <string>

using namespace std;

Party :: Party(string name, bool isUser) {
    this->name = name;
    this->isUser = isUser;

    return;
}

string Party :: getName() {
    return this->name;
}


void Party :: generatePolicy(int* P, int* M, int* C) {
    if (this->isUser) return;

    if (this->getName() == "Together") {
        *P = 15;
        *M = 40;
        *C = 5;
    } else {
        *P = 5;
        *M = 40;
        *C = 15;
    }
}