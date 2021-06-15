#include "roster.h"
#include <iostream>
#include <string>

using namespace std;

int index = 0;

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    this->classRosterArray[index++] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

void Roster::remove(string studentId) {
    for (int i = 0; i < 5; i++) {
        if (this->classRosterArray[i] != nullptr && this->classRosterArray[i]->getStudentId() == studentId) {
            this->classRosterArray[i] = nullptr;
            cout << "Removed student with id " << studentId << endl;
            return;
        }
    }
    cout << "Did not find student with id " << studentId << endl;
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (this->classRosterArray[i] != nullptr) {
            this->classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentId) {
    for (int i = 0; i < size(this->classRosterArray); i++) {
        if (this->classRosterArray[i]->getStudentId() == studentId) {
            int* numDays = this->classRosterArray[i]->getNumDays();
            double average = (double) ((numDays[0] + numDays[1] + numDays[2]) / 3.0);
            cout << "Student with id " << studentId << " takes an average of " << average << " days to complete a course." << endl;
            return;
        }
    }
    cout << "Did not find student with id " << studentId << endl;
}

void Roster::printInvalidEmails() {
    string email;
    for (int i = 0; i < size(this->classRosterArray); i++) {
        email = this->classRosterArray[i]->getEmailAddress();
        if (email.find("@") == string::npos) {
            cout << "Invalid email (no '@' found): ";
            cout << email << endl;
        }
        else if (email.find(".") == string::npos) {
            cout << "Invalid email (no '.' found): ";
            cout << email << endl;
        }
        else if (email.find(" ") != string::npos) {
            cout << "Invalid email (' ' found): ";
            cout << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(Degree degree) {
    for (int i = 0; i < size(this->classRosterArray); i++) {
        Student* student = this->classRosterArray[i];
        if (student->getDegree() == degree) {
            student->print();
        }
    }
}

//constructor
Roster::Roster() {}

//destructor
Roster::~Roster() {}
