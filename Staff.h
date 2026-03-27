#ifndef STAFF_H
#define STAFF_H

#include "UniversityMember.h"
#include "AccessCard.h"

class Staff : virtual public UniversityMember {
private:
    double salary;
    AccessCard card;

public:
    Staff(string n, int id, double s, AccessCard c)
        : UniversityMember(n, id), salary(s), card(c) {}

    double getSalary() { return salary; }

    void displayRole() override {
        cout << "Role: Staff" << endl;
    }

    void displayCard() {
        card.displayCardInfo();
    }
};

#endif