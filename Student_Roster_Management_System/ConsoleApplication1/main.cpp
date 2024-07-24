// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;


int main()
{
	string courseTitle = "Scripting and Programming Appication";
	string programmingLanguage = "C++";
	string wguID = "011415280";
	string name = "Shiv Patel";

	cout << courseTitle << endl;
	cout << programmingLanguage << endl;
	cout << "WGU ID: " << wguID << endl;
	cout << name << endl;
	cout << endl;

	Roster roster; // Creating an instance of the Roster class
	cout << "CALLING PRINT ALL:" << endl;
	roster.printAll();
	cout << endl;

	cout << "CALLING INVALID EMAILS:" << endl;
	roster.printInvalidEmails();
	cout << endl;

	// Print Average days for all students
	cout << "CALLING AVERAGE DAYS FOR EACH STUDENT:" << endl;
	for (int i = 0; i < 5; ++i) { 
		roster.printAverageDaysInCourse(roster.getClassRosterArray()[i]->getStudentId());
	}
	cout << endl;

	//  Print students by degree by program
	cout << "CALLING STUDENTS BY DEGREE PROGRAMS:" << endl;
	roster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	// Remove student from roster
	cout << "CALLING REMOVE STUDENT ID:" << endl;
	roster.remove("A3");
	cout << endl;

	cout << "CALLING PRINT ALL:" << endl;
	roster.printAll();
	cout << endl;

	cout << "CALLING REMOVE STUDENT FOR SAME STUDENT ID:" << endl;
	roster.remove("A3");

	// Release Roster memory
	cout << "CALLING DESTRUCTOR ON ROASTER:" << endl;
	roster.~Roster();
	cout << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
