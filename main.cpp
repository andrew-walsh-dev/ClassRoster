#include <string>
#include <map>
#include "roster.h"
#include <iostream>
#include<stdio.h>
#include "degree.h"

using namespace std;

Roster classRoster;

enum Degree parseDegree(string degreeStr) {
    if (degreeStr == "SECURITY") {
        return Degree::SECURITY;
    } else if (degreeStr == "NETWORK") {
        return Degree::NETWORK;
    } else {
        return Degree::SOFTWARE;
    }
}

//using parsing method 1 from the lectures
void parseAndAddStudent(string studentData) {

    //parse the data for a student
    int rhs = studentData.find(",");
    string studentId = studentData.substr(0, rhs);
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int numDays1 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int numDays2 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int numDays3 = stoi(studentData.substr(lhs, rhs - lhs));
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    Degree degree = parseDegree(studentData.substr(lhs, rhs - lhs));

    //add the new student to the roster
    classRoster.add(studentId, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degree);
}

int main() {

    const string studentData[] =
            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Andrew,Walsh,awals62@wgu.edu,20,2,3,3,SOFTWARE"};

    for (int i = 0; i < 5; i++) {
        parseAndAddStudent(studentData[i]);
    }

    cout << "Printing all students...\n";
    classRoster.printAll();

    cout << "Printing invalid emails...\n";
    classRoster.printInvalidEmails();

    cout << "Printing the average days in a course for each student...\n";
    string id;
    for (int i = 1; i < 6; i++) {
        id = "A" + to_string(i);
        classRoster.printAverageDaysInCourse(id);
    }

    cout << "Printing all software students...\n";
    classRoster.printByDegreeProgram(SOFTWARE);

    cout << "Trying to remove student with id A3...\n";
    classRoster.remove("A3");

    cout << "Printing all students...\n";
    classRoster.printAll();

    cout << "Trying to remove student with id A3 again...\n";
    classRoster.remove("A3");

    cout << "Deconstructing the roster...\n";
    classRoster.~Roster();
    return 0;
}

