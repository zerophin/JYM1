#ifndef JYM1_ROSTER_H
#define JYM1_ROSTER_H
#include <array>
#include <string>
#include "student.h"
#include "degree.h"
#include <iostream>

class Roster {
public:
    Student *students[5];

    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student getAllStudents();
    ~Roster();
};


#endif //JYM1_ROSTER_H
