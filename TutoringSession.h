#ifndef TUTORINGSESSION_H
#define TUTORINGSESSION_H

#include "TeachingAssistant.h"

class TutoringSession {
private:
    int sessionID;
    double durationMinutes;
    TeachingAssistant* ta;
    Student* student;

public:
    TutoringSession(int id = 0, double d = 0,
                    TeachingAssistant* t = nullptr,
                    Student* s = nullptr) {
        sessionID = id;
        durationMinutes = d;
        ta = t;
        student = s;
    }

    double getDuration() { return durationMinutes; }

    void displaySession() {
        cout << "Session ID: " << sessionID
             << ", Duration: " << durationMinutes << endl;
    }

    // +
    TutoringSession operator+(const TutoringSession& other) {
        return TutoringSession(
            0,
            durationMinutes + other.durationMinutes,
            ta,
            student
        );
    }

    // friend >
    friend bool operator>(TutoringSession s1, TutoringSession s2);
};

// >
bool operator>(TutoringSession s1, TutoringSession s2) {
    return s1.getDuration() > s2.getDuration();
}

#endif