#ifndef TEACHINGASSISTANT_H
#define TEACHINGASSISTANT_H

#include "Student.h"
#include "Staff.h"

class TeachingAssistant : public Student, public Staff {
private:
    int workingHours;

public:
    TeachingAssistant(string n, int id, double g, double s, AccessCard c, int h)
        : UniversityMember(n, id),
          Student(n, id, g),
          Staff(n, id, s, c),
          workingHours(h) {}

    void displayRole() override {
        cout << "Role: Teaching Assistant" << endl;
    }

    // EXACT output required for test
    void gradeAssignment(int score) {
        cout << "numeric score: " << score << "/100" << endl;
    }

    void gradeAssignment(string letterGrade) {
        cout << "letter grade: " << letterGrade << endl;
    }
};

#endif