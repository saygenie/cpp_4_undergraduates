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
    // TODO


    return;
}