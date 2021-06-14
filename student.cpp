#include "student.h"
#include <iostream>

using namespace std;

//constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int* numDays, Degree degree) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress;
    this->age = age;
    this->numDays[0] = numDays[0];
    this->numDays[1] = numDays[1];
    this->numDays[2] = numDays[2];
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
    cout << "Student ID: " << this->getStudentId();
    cout << "\nFirst Name: " << this->getFirstName();
    cout << "\nLast Name: " << this->getLastName();
    cout << "\nEmail Address: " << this->getEmailAddress();
    cout << "\nAge: " + this->getAge();
    int* numDays = this->getNumDays();
    cout << "\nDays to complete courses: " << numDays[0] << ", " << numDays[1] << ", " << numDays[2];
    cout << "Degree: " << this->getDegree();
}

//destructor
Student::~Student() = default;