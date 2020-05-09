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
            togetherApproval = (spectrum == "progressive" ? 66 : (spectrum == "moderate" ? 50 : 33));
            
            districts[i].setDistrictInfo(name, province, spectrum, togetherApproval);
        }
    
        openFile.close();
    }

}
Election :: ~Election() {
    delete[] districts;
}

void Election :: printCurrentStatus() {
    int currentStat[250];

    int progressive_count = 0;
    int moderate_count = 0;
    int conservative_count = 0;


    for (int i = 0; i < 250; i++) {
        int togetherApproval = this->districts[i].getTogetherApproval();
        
        currentStat[i] = togetherApproval >= 52 ? 1 : (togetherApproval > 47 ? 2 : 3);
    }
    printMap(currentStat);
}

void Election :: printCurrentProvinceStatus(string province) {
    bool valid_province_name = false;

    for (int i = 0; i < 250; i++) {
        if (this->districts[i].getProvince() == province) {
            District d = this->districts[i];
            cout << d.getName() << " " << d.getSpectrum() << " T:" << d.getTogetherApproval() << ",I:" << 99 - d.getTogetherApproval() << endl;
            valid_province_name = true;
        }
    }
    cout << endl;

    if (!valid_province_name) cout << "Invalid province name" << endl << endl;
}

void Election :: performStep(int tP, int tM, int tC, int iP, int iM, int iC) {
    int P = tP - iP;
    int M = tM - iM;
    int C = tC - iC;
    int temp;

    for (int i = 0; i < 250; i++) {
        temp = this->districts[i].getTogetherApproval();
        if (this->districts[i].getSpectrum() == "progressive") {
            this->districts[i].setTogetherApproval(temp + P);
        } else if (this->districts[i].getSpectrum() == "moderate") {
            this->districts[i].setTogetherApproval(temp + M);
        } else {
            this->districts[i].setTogetherApproval(temp + C);
        }
    }

}

void Election :: printFinalResult() {
    int together_party_cnt = 0;
    int integration_party_cnt = 0;

    for (int i = 0; i < 250; i++) {
        int together_approval = this->districts[i].getTogetherApproval();

        if (together_approval >= 52) together_party_cnt++;
        else if (together_approval <= 47) integration_party_cnt++;
    }

    cout << "==== Final Result ====" << endl;
    cout << "Together Party: " << together_party_cnt << " districts" << endl;
    cout << "Intagration Party: " << integration_party_cnt << " districts" << endl;
    cout << (together_party_cnt > integration_party_cnt ? "Together" : "Integration") << "party WIN!!" << endl;
}
