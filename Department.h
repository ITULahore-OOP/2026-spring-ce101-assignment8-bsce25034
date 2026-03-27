#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "UniversityMember.h"

class Department {
private:
    string departmentName;
    UniversityMember* members[50];
    int memberCount;

public:
    Department(string name) {
        departmentName = name;
        memberCount = 0;
    }

    void addMember(UniversityMember* member) {
        if (memberCount < 50) {
            members[memberCount++] = member;
        }
    }

    void displayAllRoles() {
        for (int i = 0; i < memberCount; i++) {
            members[i]->displayRole();
        }
    }
};

#endif