#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    int index = 0;
    this->classRosterArray[index++] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::remove(string studentId) {
    for (int i = 0; i < size(this->classRosterArray); i++) {
        if (this->classRosterArray[i]->getStudentId() == studentId) {
            this->classRosterArray[i] = nullptr;
            cout << "Removed student with id " << studentId;
            return;
        }
    }
    cout << "Did not find student with id " << studentId;
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        this->classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentId) {
    for (int i = 0; i < size(this->classRosterArray); i++) {
        if (this->classRosterArray[i]->getStudentId() == studentId) {
            int* numDays = this->classRosterArray[i]->getNumDays();
            double average = (double) (numDays[0] + numDays[1] + numDays[2] / 3);
            cout << "Student with id " << studentId << " takes an average of " << average << " days to complete a course.";
        }
    }
    cout << "Did not find student with id " << studentId;
}

void Roster::printInvalidEmails() {
    string email;
    for (int i = 0; i < size(this->classRosterArray); i++) {
        email = this->classRosterArray[i]->getEmailAddress();
        if (email.find("@") == string::npos) {
            cout << "Invalid email (no '@' found): ";
            cout << email;
        }
        else if (email.find(".") == string::npos) {
            cout << "Invalid email (no '.' found): ";
            cout << email;
        }
        else if (email.find(" ") != string::npos) {
            cout << "Invalid email (' ' found): ";
            cout << email;
        }
    }
}

void Roster::printByDegreeProgram(Degree degree) {
    for (int i = 0; i < size(this->classRosterArray); i++) {
        Student student = reinterpret_cast<const Student &>(this->classRosterArray[i]);
        if (student.getDegree() == degree) {
            student.print();
        }
    }
}

//constructor
Roster::Roster() {}

//destructor
Roster::~Roster() {}
