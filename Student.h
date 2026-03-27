#ifndef STUDENT_H
#define STUDENT_H

#include "UniversityMember.h"

class Student : virtual public UniversityMember {
private:
    double cgpa;

public:
    Student(string n, int id, double g)
        : UniversityMember(n, id), cgpa(g) {}

    double getCGPA() { return cgpa; }

    void updateCGPA(double newCGPA) {
        cgpa = newCGPA;
    }

    void displayRole() override {
        cout << "Role: Student" << endl;
    }
};

#endif