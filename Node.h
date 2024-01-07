#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>
#include "Student.h"

class node {
    public:
        node(student* currentStudent); // creating the node requires passing in a student
        ~node(); // destructor for the node
        node* getNext(); // returns the pointer to the next node
        student* getStudent(); // returns the pointer to the student for this node
        void setNext(node* nextNode); // sets the pointer to the next node for linked list
    private:

        node* nextNode; // pointer to the next node in the list
        student* currentStudent; // pointer to the student for the current node 
};

#endif