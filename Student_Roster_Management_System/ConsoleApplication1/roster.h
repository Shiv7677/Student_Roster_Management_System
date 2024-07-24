#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <vector> 
using namespace std;

class Roster {
private:
    int currentSize = 0;
    Student* classRosterArray[5]; // Assuming a fixed size of 5 based on studentData array size

public:
    // Constructor
    Roster();
    ~Roster();
    void add(string studentID, string firstName, string lastName,
        string emailAddress, int age, int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student** getClassRosterArray(); // Getter to access the class roster array
};

#endif // ROSTER_H
