#include "roster.h"

bool isValidEmail(std::string email) {
    char requiredItems[] = {'@', '.'};
    char bannedItems[] = {' '};

    // returns false if all elements aren't found in email
    for (auto reqItem: requiredItems) {
        if (email.find(reqItem) == std::string::npos) return false;
    }
    // if it has banned item
    for (auto banItem: bannedItems) {
        if (email.find(banItem) != std::string::npos) return false;
    }

    return true;
};

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    std::array<int, 3> daysToComplete = {daysInCourse1, daysInCourse2, daysInCourse3};
    auto newStudent = new Student{studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram};

    for (auto &student : students) {
        if (student == nullptr) {
            student = newStudent;
            return;
        }
    }
}

void Roster::remove(std::string studentID) {
    bool found = false;
    for (auto &student : students) {
        if (student == nullptr) continue;
        if (student->getStudentId() == studentID) {
            delete student;
            student = nullptr;
            found = true;
        }
    }
    if (!found) {
        std::cout << "That student was not found!" << std::endl;
    }
}

void Roster::printAll() {
    for (auto &student : students) {
        if (student != nullptr) {
            student->print();
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentID) {
    for (auto &student : students) {
        if (student == nullptr) continue;
        if (student->getStudentId() == studentID) {
            double avg{0};
            for (auto days : student->getNumOfDaysToComplete()) {
                avg += days;
            }
            std::cout << student->getStudentId() << ": "
            << (avg / 3)
            << " average days"
            << std::endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (auto &student : students) {
        if (student == nullptr) continue;
        bool isValid = isValidEmail(student->getEmailAddress());
        if (!isValid) {
            std::cout
            << "Invalid Email: "
            << student->getEmailAddress()
            << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (auto &student : students) {
        if (student == nullptr) continue;
        if (student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }
}

Roster::~Roster() {
    for (auto &student : students) {
        if (student == nullptr) continue;
        delete student;
    }
}
