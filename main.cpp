#include <iostream>
#include "AccessCard.h"
#include "Student.h"
#include "Staff.h"
#include "TeachingAssistant.h"
#include "TutoringSession.h"
#include "Department.h"

using namespace std;

int main() {
    Department dept("Computer Science");

    Student* students[10];
    Staff* staffMembers[10];
    TeachingAssistant* tas[10];

    int sCount = 0, stCount = 0, taCount = 0;

    TutoringSession sessions[10];
    int sessionCount = 0;

    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Add Staff\n";
        cout << "3. Add Teaching Assistant\n";
        cout << "4. Display All Roles\n";
        cout << "5. Grade Assignment (TA)\n";
        cout << "6. Create Tutoring Session\n";
        cout << "7. Merge Sessions (+)\n";
        cout << "8. Compare Sessions (>)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            int id;
            double cgpa;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            students[sCount] = new Student(name, id, cgpa);
            dept.addMember(students[sCount]);
            sCount++;

            cout << "Student added!\n";
        }

        else if (choice == 2) {
            string name, cardID;
            int id, access;
            double salary;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter salary: ";
            cin >> salary;

            cout << "Enter Card ID: ";
            cin >> cardID;

            cout << "Enter Access Level: ";
            cin >> access;

            AccessCard card(cardID, access);

            staffMembers[stCount] = new Staff(name, id, salary, card);
            dept.addMember(staffMembers[stCount]);
            stCount++;

            cout << "Staff added!\n";
        }

        else if (choice == 3) {
            string name, cardID;
            int id, access, hours;
            double cgpa, salary;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter CGPA: ";
            cin >> cgpa;

            cout << "Enter salary: ";
            cin >> salary;

            cout << "Enter working hours: ";
            cin >> hours;

            cout << "Enter Card ID: ";
            cin >> cardID;

            cout << "Enter Access Level: ";
            cin >> access;

            AccessCard card(cardID, access);

            tas[taCount] = new TeachingAssistant(name, id, cgpa, salary, card, hours);
            dept.addMember(tas[taCount]);
            taCount++;

            cout << "Teaching Assistant added!\n";
        }

        else if (choice == 4) {
            dept.displayAllRoles();
        }

        else if (choice == 5) {
            if (taCount == 0) {
                cout << "No TA available!\n";
                continue;
            }

            int index, type;
            cout << "Select TA index (0 to " << taCount - 1 << "): ";
            cin >> index;

            cout << "1. Numeric Grade\n2. Letter Grade\nChoice: ";
            cin >> type;

            if (type == 1) {
                int score;
                cout << "Enter score: ";
                cin >> score;
                tas[index]->gradeAssignment(score);
            } else {
                string grade;
                cout << "Enter letter grade: ";
                cin >> grade;
                tas[index]->gradeAssignment(grade);
            }
        }

        else if (choice == 6) {
            if (taCount == 0 || sCount == 0) {
                cout << "Need at least one TA and Student!\n";
                continue;
            }

            int taIndex, sIndex;
            double duration;

            cout << "Select TA index: ";
            cin >> taIndex;

            cout << "Select Student index: ";
            cin >> sIndex;

            cout << "Enter duration: ";
            cin >> duration;

            sessions[sessionCount] = TutoringSession(
                sessionCount + 1,
                duration,
                tas[taIndex],
                students[sIndex]
            );

            sessionCount++;
            cout << "Session created!\n";
        }

        else if (choice == 7) {
            if (sessionCount < 2) {
                cout << "Need at least 2 sessions!\n";
                continue;
            }

            int a, b;
            cout << "Enter two session indices: ";
            cin >> a >> b;

            TutoringSession merged = sessions[a] + sessions[b];

            cout << "Merged Session Duration: "
                 << merged.getDuration() << endl;
        }

        else if (choice == 8) {
            if (sessionCount < 2) {
                cout << "Need at least 2 sessions!\n";
                continue;
            }

            int a, b;
            cout << "Enter two session indices: ";
            cin >> a >> b;

            if (sessions[a] > sessions[b]) {
                cout << "Session " << a << " is longer\n";
            } else {
                cout << "Session " << b << " is longer\n";
            }
        }

    } while (choice != 0);

    cout << "Exiting...\n";

    return 0;
}