#include "election.h"
#include "district.h"
#include "helper.h"

#include <fstream>

Election :: Election() {
    districts = new District[250];

    string filePath = "district_info.txt";

    ifstream openFile(filePath.data());
    if (openFile.is_open()) {
            string province;
            string name;
            string spectrum;
            int togetherApproval;
        
        for (int i = 0; i < 250; i++) {
            getline(openFile, province, '\t');
            getline(openFile, name, ' ');
            getline(openFile, spectrum, '\n');
            togetherApproval = spectrum == "progressive" ? 66 : (spectrum == "moderate" ? 50 : 33);
            
            districts->setDistrictInfo(name, province, spectrum, togetherApproval);
        }
    
        openFile.close();
    }

}
Election :: ~Election() {
    // TODO

    return;
}

void Election :: printCurrentStatus() {
   // TODO
    
   return;
}
void Election :: printCurrentProvinceStatus(string province) {
    // TODO

    return; 
}
void Election :: performStep(int tP, int tM, int tC, int iP, int iM, int iC) {
    // TODO

    return;
}

void Election :: printFinalResult() {
    //TODO     

    return;
}
