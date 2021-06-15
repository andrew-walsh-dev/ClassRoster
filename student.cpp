#include "student.h"
#include <iostream>

using namespace std;

//constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->numDays[0] = daysInCourse1;
    this->numDays[1] = daysInCourse2;
    this->numDays[2] = daysInCourse3;
    this->degree = degree;
}

//accessors
string Student::getStudentId() {
    return this->studentId;
}

string Student::getFirstName() {
    return this->firstName;
}

string Student::getLastName() {
    return this->lastName;
}

string Student::getEmailAddress() {
    return this->emailAddress;
}

int Student::getAge() {
    return this->age;
}

int* Student::getNumDays() {
    return this->numDays;
}

Degree Student::getDegree() {
    return this->degree;
}

//mutators
void Student::setStudentId(string studentId) {
    this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setNumDays(int* numDays) {
    this->numDays[0] = numDays[0];
    this->numDays[1] = numDays[1];
    this->numDays[2] = numDays[2];
}

void Student::setDegree(Degree degree) {
    this->degree = degree;
}

//printer
void Student::print() {
    cout << getStudentId();
    cout << "\tFirst Name: " << getFirstName();
    cout << "\tLast Name: " << getLastName();
    cout << "\tAge: " << getAge();
    cout << endl;
    int* numberDays = getNumDays();
    cout << "\tDays to complete courses: {" << numberDays[0] << ", " << numberDays[1] << ", " << numberDays[2] << "}\t";
    string degree;
    if (getDegree() == 0) {
        degree = "SECURITY";
    }
    else if (getDegree() == 1) {
        degree = "NETWORK";
    }
    else {
        degree = "SOFTWARE";
    }
    cout << "Degree Program: " << degree << endl;
}

//destructor
Student::~Student() = default;