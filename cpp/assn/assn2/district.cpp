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
    //TODO
    return this->togetherApproval;
}
string District :: getName() {
    //TODO
    return this->name;
}
string District :: getProvince() {
    //TODO
    return this->province;
}
string District :: getSpectrum() {
    //TODO
    return this->spectrum;
}

void District :: setTogetherApproval(int newApproval) {
    // TODO
    this->togetherApproval = newApproval; 
}