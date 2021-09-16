#ifndef JYM1_STUDENT_H
#define JYM1_STUDENT_H

#include <string>
#include <array>
#include "degree.h"

class Student {
private:
    std::string studentId,
            firstName,
            lastName,
            emailAddress;
    int age;
    std::array<int, 3> numOfDaysToComplete;
    int degreeProgram;
public:
    Student(std::string &studentId, std::string &firstName, std::string &lastName,
            std::string &emailAddress, int age, std::array<int, 3> &numOfDaysToComplete, int degreeProgram);

    std::string &getStudentId();

    void setStudentId(std::string &studentId);

    std::string &getFirstName();

    void setFirstName(std::string &firstName);

    std::string &getLastName();

    void setLastName(std::string &lastName);

    std::string &getEmailAddress();

    void setEmailAddress(std::string &emailAddress);

    int getAge();

    void setAge(int age);

    std::array<int, 3> &getNumOfDaysToComplete();

    void setNumOfDaysToComplete(std::array<int, 3> &numOfDaysToComplete);

    int getDegreeProgram();

    void setDegreeProgram(int degreeProgram);

    std::string getDegreeProgramString();

    std::string getNumOfDaysToCompleteAsString();
    
    void print();

    

};


#endif //JYM1_STUDENT_H
