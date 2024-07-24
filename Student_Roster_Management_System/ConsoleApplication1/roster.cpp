#include "roster.h"
#include "degree.h"
#include "student.h"
#include <iostream>
#include <sstream> 
#include <vector>

using namespace std;

const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Shiv,Patel,spatel@wgu.edu,22,14,15,16,SOFTWARE"
};

Roster::Roster() {
    for (int i = 0; i < sizeof(studentData) / sizeof(studentData[0]); i++) {
        vector<string> v;
        stringstream ss(studentData[i]);
        string token;

        while (getline(ss, token, ',')) {
            v.push_back(token);
        }

        DegreeProgram dp;
        if (v[8] == "NETWORK") {
            dp = NETWORK;
        }
        else if (v[8] == "SECURITY") {
            dp = SECURITY;
        }
        else if (v[8] == "SOFTWARE") {
            dp = SOFTWARE;
        }

        add(v[0], v[1], v[2], v[3], stoi(v[4]), stoi(v[5]), stoi(v[6]), stoi(v[7]), dp);
    }
}

void Roster::add(string studentID, string firstName, string lastName,
    string emailAddress, int age, int daysInCourse1, int daysInCourse2,
    int daysInCourse3, DegreeProgram degreeProgram) {
    classRosterArray[currentSize] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    currentSize++;
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i < currentSize; i++) {
        if (classRosterArray[i]->getStudentId() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[currentSize - 1];
            classRosterArray[currentSize - 1] = nullptr;
            currentSize--;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student with ID: " << studentID << " not found." << endl << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < currentSize; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < currentSize; i++) {
        if (studentID == classRosterArray[i]->getStudentId()) {
            cout << "Average days in course for student " << studentID << ": "
                << ((classRosterArray[i]->getDaysInCourse()[0] +
                    classRosterArray[i]->getDaysInCourse()[1] +
                    classRosterArray[i]->getDaysInCourse()[2]) / 3)
                << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < currentSize; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
            cout << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < currentSize; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
Student** Roster::getClassRosterArray() {
    return classRosterArray;
}

Roster::~Roster() {
    cout << "Destructor called to deallocate memory taken up by student roster" << endl;
    for (int i = 0; i < currentSize; i++) {
        cout << "Student " << i + 1 << " destroyed!" << endl;
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}
