#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"

class Roster {
private:
    Student* classRosterArray[5];

public:
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
    void remove(string studentId);
    void printAll();
    void printAverageDaysInCourse(string studentId);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degree);
    //constructor
    Roster();

    //destructor
    ~Roster();
};

#endif
