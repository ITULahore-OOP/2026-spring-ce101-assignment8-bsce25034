#ifndef UNIVERSITYMEMBER_H
#define UNIVERSITYMEMBER_H

#include <iostream>
using namespace std;

class UniversityMember {
protected:
    string name;
    int memberID;

public:
    UniversityMember(string n, int id) : name(n), memberID(id) {}
    virtual ~UniversityMember() {}

    string getName() { return name; }
    int getMemberID() { return memberID; }

    virtual void displayRole() = 0;
};

#endif