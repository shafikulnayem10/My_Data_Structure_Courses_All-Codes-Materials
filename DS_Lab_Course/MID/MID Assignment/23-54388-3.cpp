#include <iostream>
using namespace std;

struct Applicant {
    string visaType;
    int tokenNumber;
    bool served;
};

struct Counter {
    string primaryVisa;
    int served_primary;
    int servedOthers;
};

int main() {
    const int max_appli = 100;
    const int max_visa_types = 4;
    const int counters = 4;

    Applicant applicants[max_appli];
    Counter counters_arr[counters] = {
        {"TR", 0, 0},
        {"MED", 0, 0},
        {"BS", 0, 0},
        {"GO", 0, 0}
    };

    int visaCounts[max_visa_types] = {0};
    int totalApplicants = 0;
    int currentToken = 1;
    string input;

    cout << "Token Issuing Phase (Enter '0' to end issuing tokens)" << endl;
    while(true) {
        cout << "\nRequest token for (Tourist/Medical/Business/Government): ";
        cin >> input;

        if(input == "0") {
                break;
        }

        if(totalApplicants >= max_appli) {
            cout << "Maximum daily applicant limit reached (100)." << endl;
            break;
        }

        string visaType = "";
        if(input == "Tourist" || input == "TR") {
            visaType = "TR";
            if(visaCounts[0] >= 25) {
                cout << "Daily limit for Tourist Visa reached." << endl;
                continue;
            }
            visaCounts[0]++;
        }
        else if(input == "Medical" || input == "MED") {
            visaType = "MED";
            if(visaCounts[1] >= 25) {
                cout << "Daily limit for Medical Visa reached." << endl;
                continue;
            }
            visaCounts[1]++;
        }
        else if(input == "Business" || input == "BS") {
            visaType = "BS";
            if(visaCounts[2] >= 25) {
                cout << "Daily limit for Business Visa reached." << endl;
                continue;
            }
            visaCounts[2]++;
        }
        else if(input == "Government" || input == "GO") {
            visaType = "GO";
            if(visaCounts[3] >= 25) {
                cout << "Daily limit for Government Officials Visa reached." << endl;
                continue;
            }
            visaCounts[3]++;
        }
        else {
            cout << "Invalid visa type. Please enter: Tourist, Medical, Business, or Government" << endl;
            continue;
        }

        applicants[totalApplicants].visaType = visaType;
        applicants[totalApplicants].tokenNumber = currentToken;
        applicants[totalApplicants].served = false;

        cout << "Your token is: " << visaType << "-" << currentToken << endl;
        currentToken++;
        totalApplicants++;
    }

    cout << "\nCounter Processing Phase (Enter counter number 1-4 or '0' to end)" << endl;
    while(true) {
        cout << "\nCall next customer at counter (1-4): ";
        cin >> input;

        if(input == "0") {
                break;
        }

        bool validCounter = false;
        int counterNum = 0;

        if(input.length() == 1 && input[0] >= '1' && input[0] <= '4') {
            counterNum = input[0] - '0';
            validCounter = true;
        }

        if(!validCounter) {
            cout << "Invalid counter number. Please enter 1-4." << endl;
            continue;
        }

        int counterIndex = counterNum - 1;
        string primaryType = counters_arr[counterIndex].primaryVisa;

        bool found = false;
        for(int i = 0; i < totalApplicants; i++) {
            if(!applicants[i].served && applicants[i].visaType == primaryType) {
                cout << "Counter " << counterNum << " (" << primaryType << "), Please serve the token number "
                     << applicants[i].visaType << "-" << applicants[i].tokenNumber << endl;
                applicants[i].served = true;
                counters_arr[counterIndex].served_primary++;
                found = true;
                break;
            }
        }

        if(!found) {
            for(int i = 0; i < totalApplicants; i++) {
                if(!applicants[i].served) {
                    cout << "Counter " << counterNum << " (" << primaryType << "), Please serve the token number "
                         << applicants[i].visaType << "-" << applicants[i].tokenNumber << endl;
                    applicants[i].served = true;
                    counters_arr[counterIndex].servedOthers++;
                    found = true;
                    break;
                }
            }
        }

        if(!found) {
            cout << "No more applicants to serve at this counter." << endl;
        }
    }

    cout << "\nDaily Summary Report" << endl;
    cout << "--------------------" << endl;

    cout << " Applicants served by Visa Type:" << endl;
    int trServed = 0, medServed = 0, bsServed = 0, goServed = 0;
    for(int i = 0; i < totalApplicants; i++) {
        if(applicants[i].served) {
            if(applicants[i].visaType == "TR") {
                    trServed++;
            }
            else if(applicants[i].visaType == "MED") {
                    medServed++;

            }
            else if(applicants[i].visaType == "BS") {
                    bsServed++;
            }
            else if(applicants[i].visaType == "GO") {
                    goServed++;
            }
        }
    }
    cout << "- TR (Tourist): " << trServed << endl;
    cout << "- MED (Medical): " << medServed << endl;
    cout << "- BS (Business): " << bsServed << endl;
    cout << "- GO (Government Officials): " << goServed << endl;

    cout << " Applicants served by Counter:" << endl;
    for(int i = 0; i < counters; i++) {
        cout << "- Counter " << (i+1) << " (" << counters_arr[i].primaryVisa << "): "
             << counters_arr[i].primaryVisa << ": " << counters_arr[i].served_primary
             << ", Others: " << counters_arr[i].servedOthers << endl;
    }

    cout << " Idle Counter:" << endl;
    bool idleFound = false;
    for(int i = 0; i < counters; i++) {
        if(counters_arr[i].served_primary == 0 && counters_arr[i].servedOthers == 0) {
            cout << "- " << counters_arr[i].primaryVisa << endl;
            idleFound = true;
        }
    }
    if(!idleFound) {
        cout << "- None" << endl;
    }

    int totalServed = trServed + medServed + bsServed + goServed;
    cout << "\nTotal Applicants Served: " << totalServed << "/" << totalApplicants << endl;

    return 0;
}
