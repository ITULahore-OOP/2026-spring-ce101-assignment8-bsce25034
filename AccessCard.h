#ifndef ACCESSCARD_H
#define ACCESSCARD_H

#include <iostream>
using namespace std;

class AccessCard {
private:
    string cardID;
    int accessLevel;

public:
    AccessCard(string id = "", int level = 0) {
        cardID = id;
        accessLevel = level;
    }

    string getCardID() { return cardID; }
    int getAccessLevel() { return accessLevel; }

    void displayCardInfo() {
        cout << "Card ID: " << cardID << ", Access Level: " << accessLevel << endl;
    }
};

#endif