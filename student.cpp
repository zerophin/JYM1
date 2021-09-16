#include "student.h"
#include <iostream>

Student::Student(std::string &studentId, std::string &firstName, std::string &lastName,
                 std::string &emailAddress, int age, std::array<int, 3> &numOfDaysToComplete,
                 int degreeProgram) {
    Student::studentId = studentId;
    Student::firstName = firstName;
    Student::lastName = lastName;
    Student::emailAddress = emailAddress;
    Student::age = age;
    Student::numOfDaysToComplete = {numOfDaysToComplete};
    Student::degreeProgram = degreeProgram;
}

std::string &Student::getStudentId() {
    return studentId;
}

void Student::setStudentId(std::string &studentId) {
    Student::studentId = studentId;
}

std::string &Student::getFirstName() {
    return firstName;
}

void Student::setFirstName(std::string &firstName) {
    Student::firstName = firstName;
}

std::string &Student::getLastName() {
    return lastName;
}

void Student::setLastName(std::string &lastName) {
    Student::lastName = lastName;
}

std::string &Student::getEmailAddress() {
    return emailAddress;
}

void Student::setEmailAddress(std::string &emailAddress) {
    Student::emailAddress = emailAddress;
}

int Student::getAge() {
    return age;
}

void Student::setAge(int age) {
    Student::age = age;
}

std::array<int, 3> &Student::getNumOfDaysToComplete() {
    return Student::numOfDaysToComplete;
}

std::string Student::getNumOfDaysToCompleteAsString() {
    std::string daysAsString{""};
    daysAsString += "{";
    for (auto days: Student::getNumOfDaysToComplete()) {
        daysAsString += std::to_string(days) + ", ";
    }
    // remove last comma and space
    daysAsString.pop_back();
    daysAsString.pop_back();
    daysAsString += "}";
    return daysAsString;
}

void Student::setNumOfDaysToComplete(std::array<int, 3> &numOfDaysToComplete) {
    Student::numOfDaysToComplete = numOfDaysToComplete;
}

int Student::getDegreeProgram()  {
    return degreeProgram;
}

std::string Student::getDegreeProgramString() {
    int currentDegree = this->getDegreeProgram();

//    switch (currentDegree) {
//        case currentDegree == 0:
//            return "Security";
//        case currentDegree == 1:
//            return "NETWORK";
//        case currentDegree == 2:
//            return "Software";
//    }

    if (currentDegree == 0) {
        return "SECURITY";
    } else if (currentDegree == 1) {
        return "NETWORK";
    } else if (currentDegree == 2) {
        return "SOFTWARE";
    } else {
        return "NONE";
    }
}

void Student::setDegreeProgram(int degreeProgram) {
    Student::degreeProgram = degreeProgram;
}

void Student::print() {
    std::cout << Student::getStudentId();
    std::cout << "\tFirst Name: " << Student::getFirstName();
    std::cout << "\tLast Name: " << Student::getLastName();
    std::cout << "\tAge: " << Student::getAge();
    std::cout << "\tdaysInCourse: " << Student::getNumOfDaysToCompleteAsString();
    std::cout << "\tDegree Program: " << Student::getDegreeProgramString();
    std::cout << std::endl;

}

