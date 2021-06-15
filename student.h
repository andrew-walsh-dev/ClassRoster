#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

using namespace std;

class Student {

private:

    //class attributes
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
    Degree degree;

public:

    //constructor
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);

    //accessors
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int*  getNumDays();
    Degree getDegree();

    //mutators
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setNumDays(int* numDays);
    void setDegree(Degree degree);

    //printer
    void print();

    //destructor
    ~Student();

};

#endif