#include <iostream>
#include "student.h"
#include <vector>
#include <sstream>
#include "degree.h"
#include "roster.h"

using namespace std;

vector<std::string> split(const std::string &s, char splitAt) {
    vector<string> vect;
    string character;
    istringstream ts(s);
    while (getline(ts, character, splitAt)) {
        vect.push_back(character);
    }
    return vect;
}

int main() {
    cout << "Course Title: Scripting and Programming - Applications – C867 - Task JYM1" << endl;
    cout << "Language used: C++" << endl;;
    cout << "WGU Student ID: #2123" << endl;
    cout << "Student Name: Joshua Smith" << endl;
    cout << endl;
    const string studentData[] =

            {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
             "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
             "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
             "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
             "A5,Josh,Smith,123@yahoo.com,28,14,30,88,SOFTWARE"};


    // Parse the data!
    auto classRoster = new Roster();
    for (auto i = 0; i < 5; i++) {
        auto b1 = split(studentData[i], ',');

        string studentID = b1[0];
        string firstName = b1[1];
        string lastName = b1[2];
        string email = b1[3];
        int age = stoi(b1[4]);
        int daysInCourse1 = stoi(b1[5]);
        int daysInCourse2 = stoi(b1[6]);
        int daysInCourse3 = stoi(b1[7]);

        string degreeProgramString = b1[8];
        DegreeProgram degreeProgram{};
        if (degreeProgramString == "SECURITY") {
            degreeProgram = SECURITY;
        } else if (degreeProgramString == "NETWORK") {
            degreeProgram = NETWORK;
        } else if (degreeProgramString == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }
        classRoster->add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3,
                         degreeProgram);
    } // end parse

    classRoster->printAll();
    classRoster->printInvalidEmails();

    //loop through classRoster and for each element:
    for (auto &student : classRoster->students) {
        classRoster->printAverageDaysInCourse(student->getStudentId());
    }

    classRoster->printByDegreeProgram(SOFTWARE);

    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");

    //expected: the above line should print a message saying such a student with this ID was not found.
    return 0;
};
