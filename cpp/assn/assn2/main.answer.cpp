#include <iostream>
#include "helper.h"
#include "election.h"
#include "party.h"

using namespace std;

string provinces[16] = {"Seoul", "Busan", "Incheon", "Gwangju", 
                      "Daejeon", "Ulsan", "Sejong", "Kyungki", 
                      "Kwangwon", "Chungbuk", "Chungnam", "Jeonbuk", 
                      "Jeonnam", "Kyungbuk", "Kyungnam", "Jeju"};



int main() {
    cout << "You can be the Representative of political party..." << endl;
    cout << "You must win the election!!" << endl;
    cout << "Select your party" << endl;
    cout << "1. Together party" << endl;
    cout << "2. Integration party" << endl;

    int party;
    cout << "INPUT: ";
    cin >> party;
    while(party != 1 && party != 2) {
        cout << "Select again!!" << endl;
        cout << "INPUT: ";
        cin >> party;
    }
    
    string partyName = party == 1 ? "Together" : "Integration";
    cout << "Okay!! Now you're the representative of " << partyName << " party!!" << endl;
    cout << "You have 10 weeks to win the election!!" << endl;
    cout << "Each week, you can check the status and select the week's policy." << endl;
    cout << "Good Luck!!" << endl;

    Election* election = new Election();

    Party* userParty = new Party(partyName, true);
    Party* aiParty = new Party(party != 1 ? "Together" : "Integration", false);
    
    int weekly_input;
    string province_input;
    int noise;
    int tP, tM, tC, iP, iM, iC;

    for(int i = 0; i < 10; i++) {
        cout << "\nWeek " << (i + 1) << endl;

        do {
            cout << "==== Menu ====" << endl;
            cout << "1. Show status" << endl;
            cout << "2. Show province status" << endl;
            cout << "3. Set policy and end week" << endl;
            cout << "INPUT: ";
            cin >> weekly_input;

            switch (weekly_input) {
                case 1:
                    election->printCurrentStatus();
                    break;
                case 2:
                    cout << "Possible Provinces:" << endl;
                    cout << "Seoul, Busan, Incheon, Gwangju" << endl;
                    cout << "Daejeon, Ulsan, Sejong, Kyungki" << endl;
                    cout << "Kwangwon, Chungbuk, Chungnam, Jeonbuk" << endl;
                    cout << "Jeonnam, Kyungbuk, Kyungnam, Jeju" << endl;
                    cout << "INPUT: ";
                    cin >> province_input;
                    election->printCurrentProvinceStatus(province_input);
                    break;
                case 3:
                    if (userParty->getName() == "Together") {
                        // User: Together
                        // AI: Integration
                        
                        cout << "== Together Party's policy ==" << endl;
                        cout << "distribute 60 points to each distinct type!!" << endl;
                        cout << "Progressive? ";
                        cin >> tP;
                        cout << "Moderate? ";
                        cin >> tM;
                        tC = 60 - tP - tM;

                        cout << "Progressive: " << tP << " points" << endl;
                        cout << "Moderate: " << tM << " points" << endl;
                        cout << "Conservative: " << tC << " points" << endl << endl;

                        cout << "== Together Party's policy ==" << endl;
                        aiParty->generatePolicy(&iP, &iM, &iC);
                        cout << "Progressive: " << iP << " points" << endl;
                        cout << "Moderate: " << iM << " points" << endl;
                        cout << "Conservative: " << iC << " points" << endl << endl;

                    } else {
                        // User: Integration
                        // AI: Together

                        cout << "== Integration Party's policy ==" << endl;
                        cout << "distribute 60 points to each distinct type!!" << endl;
                        cout << "Progressive? ";
                        cin >> iP;
                        cout << "Moderate? ";
                        cin >> iM;
                        iC = 60 - iP - iM;

                        cout << "Progressive: " << iP << " points" << endl;
                        cout << "Moderate: " << iM << " points" << endl;
                        cout << "Conservative: " << iC << " points" << endl << endl;

                        cout << "== Together Party's policy ==" << endl;
                        aiParty->generatePolicy(&tP, &tM, &tC);
                        cout << "Progressive: " << tP << " points" << endl;
                        cout << "Moderate: " << tM << " points" << endl;
                        cout << "Conservative: " << tC << " points" << endl << endl;
                    }

                    cout << (tP > iP ? "Together" : "Integration") << "party gained " << abs(tP - iP) << " points for progressive districts" << endl;
                    cout << (tC > iC ? "Together" : "Integration") << "party gained " << abs(tC - iC) << " points for conservative districts" << endl;
                    cout << (tM > iM ? "Together" : "Integration") << "party gained " << abs(tM - iM) << " points for moderate districts" << endl;
                    cout << endl;

                    election->performStep(tP,tM, tC, iP, iM, iC);
                    // cout << "Input any key to go to next week...";
                    break;
                default:
                    cout << "Select again!!" << endl << endl;
                    break;
            }
        } while (weekly_input != 3);

    }

    election->printFinalResult();
    election->~Election();

    return 0;
}