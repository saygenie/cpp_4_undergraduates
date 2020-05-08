#include "district.h"


District :: District() {
    this->name = "";
    this->province = "";
    this->spectrum = "";
    this->togetherApproval = -1;
}

void District :: setDistrictInfo(string name, string province, string spectrum, int togetherApproval) {
    this->name = name;
    this->province = province;
    this->spectrum = spectrum;
    this->togetherApproval = togetherApproval;
}

int District :: getTogetherApproval() {
    return this->togetherApproval;
}

string District :: getName() {
    return this->name;
}

string District :: getProvince() {
    return this->province;
}

string District :: getSpectrum() {
    return this->spectrum;
}

void District :: setTogetherApproval(int newApproval) {
    this->togetherApproval = newApproval; 
}