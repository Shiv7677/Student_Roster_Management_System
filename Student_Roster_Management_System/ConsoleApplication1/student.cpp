#include "student.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Student::Student(string newStudentID, string newFirstName, string newLastname,
    string newEmailAddress, int newAge, int newDaysInCourse1,
    int newDaysInCourse2, int newDaysInCourse3,
    DegreeProgram newDegreeProgram)
{
    studentId = newStudentID;
    firstName = newFirstName;
    lastName = newLastname;
    emailAddress = newEmailAddress;
    age = newAge;
    daysInCourse[0] = newDaysInCourse1;
    daysInCourse[1] = newDaysInCourse2;
    daysInCourse[2] = newDaysInCourse3;
    degreeProgram = newDegreeProgram; 
}
// Setters
void Student::setStudentId(string newStudentId) {
    studentId = newStudentId;
}

void Student::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Student::setLastname(string newLastname) {
    lastName = newLastname;
}

void Student::setEmailAddress(string newEmailAddress) {
    emailAddress = newEmailAddress;
}

void Student::setAge(int newAge) {
    age = newAge;
}

void Student::setDaysInCourse(const int newDaysInCourse[]) {
    for (int i = 0; i < 3; ++i) {
        daysInCourse[i] = newDaysInCourse[i];
    }
}

void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {
    degreeProgram = newDegreeProgram;
}

void Student::print() {
    cout << studentId << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Email: " << emailAddress << "\t";
    cout << "Age: " << age << "\t";
    cout << "Days In Course: ";
    for (int i = 0; i < 3; ++i) {
        cout << daysInCourse[i];
        if (i < 2) cout << ", ";
    }
    cout << "\t";
    switch (degreeProgram) {
    case SECURITY:
        cout << "Degree Program: SECURITY" << endl;
        break;
    case NETWORK:
        cout << "Degree Program: NETWORK" << endl;
        break;
    case SOFTWARE:
        cout << "Degree Program: SOFTWARE" << endl;
        break;
    default:
        cout << "Degree Program: UNKNOWN" << endl;
        break;
    }
}
// Getters
string Student::getStudentId() {
    return studentId;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastname() {
    return lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

const int* Student::getDaysInCourse() {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}
