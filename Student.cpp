#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

student::student(const char* firstnametmp, const char* lastnametmp, float gpatmp, int studentIDtmp) : firstname(firstnametmp), lastname(lastnametmp), gpa(gpatmp), studentID(studentIDtmp) {}

student::~student() {}

const char* student::getFirstname(void) {
    return firstname;
}

const char* student::getLastname(void) {
    return lastname;
}

float student::getGPA(void) {
    return gpa;
}

int student::getStudentID(void) {
    return studentID;
}

void student::printAll(void) {
    cout << "First name is: " << firstname << endl;
    cout << "Last name is: " << lastname << endl;
    cout << "GPA is: " << gpa << endl;
    cout << "Student ID is: " << studentID << endl;
    cout << endl;
}