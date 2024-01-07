#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

class student {
    public:
        student(const char* firstname, const char* lastname, float gpa, int studentID);
        ~student();
        const char* getFirstname(void);
        const char* getLastname(void);
        float getGPA(void);
        int getStudentID(void);
        void printAll(void);
    private:
        const char* firstname;
        const char* lastname;
        float gpa;
        int studentID;
};

#endif