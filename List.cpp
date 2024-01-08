// This is a program that makes a linked list with students
// Last edited: 1/5/24
// Author: Nikaansh S.

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void deleteNode(node* &head, node* current, node* previous, float studentID);
void addNode(node* &head, node* current, node* newNode, node* previous);
void searchNode(node* current);
void deleteNodes(node* &head, node* current);
void average(node* current, float total, float count);
void searchSpecif(node* head, float ID);

main (void) {

    // Declaring head where first node in list will be stored
    node* head = NULL;
    char* input = new char(15);

    while (true) { // Running until break
        cout << "What do you want to do (add, search, print, delete, average, quit)?" << endl;
        cin >> input;

        if (strcmp(input, "quit") == 0) { // If user wants to quit
            deleteNodes(head, head);
            break; // Breaks out of loop
        }
        else if (strcmp(input, "add") == 0) { // If user wants to add to list
            char* firstName = new char(20);
            char* lastName = new char(20);
            float gpa;
            int studentId;
            cout << "\nPlease enter first name of the student: " << endl;
            cin >> firstName;
            cout << "Please enter last name of the student: " << endl;
            cin >> lastName;
            cout << "Please enter the student ID of the student: " << endl;
            cin >> studentId;
            cout << "Please enter the GPA of the student: " << endl;
            cin >> gpa;
            cout << endl;

            // Creating node with user input
            node* newNode = new node(new student(firstName, lastName, gpa, studentId));
            addNode(head, head, newNode, head);
        }
        else if (strcmp(input, "print") == 0) { // If user wants to print all nodes in list
            if (head != NULL) { // Checking list is not empty
                cout << endl;
                searchNode(head);
            }
            else {
                cout << "\nThere are no students in the list\n" << endl;
            }
        }
        else if (strcmp(input, "search") == 0) { // If user want to search for specific node
            if (head != NULL) { // Checking list is not empty
                cout << "\nWhat is the ID of the student you want to search for?" << endl;
                float ID = 0;
                cin >> ID;
                cout << endl;
                searchSpecif(head, ID);
                cout << endl;
            }
            else {
                cout << "\nThere are no students in the list\n" << endl;
            }
        }
        else if (strcmp(input, "delete") == 0) { // If user wants to delete specific node
            if (head != NULL) { // Checking list is not empty
                float studentID = 0;
                cout << "\nWhat is the student ID of the student you want to delete?" << endl;
                cin >> studentID;
                deleteNode(head, head, head, studentID);
                cout << endl;
            }
            else {
                cout << "\nThere are no students in the list\n" << endl;
            }
        }
        else if (strcmp(input, "average") == 0) { // If user wants to take the average of all gps's
            if (head != NULL) { // Checking list is not null
                cout << endl;
                average(head, 0, 0);
                cout << endl;
            }
            else {
                cout << "\nThere are no students in the list\n" << endl;
            }
        }
    }

    cout << "List has been deleted" << endl;
    searchNode(head);
}

// Function to delete all nodes in list
void deleteNodes(node* &head, node* current) {
    if (head->getNext() != NULL) { // Gets ID of the next node in the list and deletes it
        float ID = head->getStudent()->getStudentID();
        deleteNode(head, head, head, ID);
        deleteNodes(head, head);
    }
    else { // Stops recursion when it is on last node
        float ID = head->getStudent()->getStudentID();
        deleteNode(head, head, head, ID);
    }
}

// Adds a node to the list
void addNode(node* &head, node* current, node* newNode, node* previous) {
    if (head == NULL) { // If adding first node
        head = newNode;
    }
    else if (newNode->getStudent()->getGPA() < current->getStudent()->getGPA() && newNode->getStudent()->getGPA() >= previous->getStudent()->getGPA()) { // If new node is bigger than the next and smaller than the previous
        newNode->setNext(current);
        previous->setNext(newNode);
    }
    else if (current->getStudent()->getGPA() > newNode->getStudent()->getGPA()) {
        head = newNode;
        newNode->setNext(current);
    }
    else if (current->getNext() == NULL) { // If last node in list is still smaller than new node
        current->setNext(newNode);
    }
    else { // Looks if next node in list is bigger
        addNode(head, current->getNext(), newNode, current);
    }
}

// Prints all nodes in the list
void searchNode(node* current) {
    if (current->getNext() == NULL) { // If last node in list
        current->getStudent()->printAll();
    }
    else { // Print and go to next node
        current->getStudent()->printAll();
        searchNode(current->getNext());
    }
}

// Looks for a specific node
void searchSpecif(node* head, float ID) {
    if (head->getStudent()->getStudentID() == ID) { // If node is the one looking for
        head->getStudent()->printAll();
    }
    else if (head->getNext() == NULL) { // Reached end of the list and node is not in the list
        cout << "Student is not in list" << endl;
    }
    else { // Looks at next node
        searchSpecif(head->getNext(), ID);
    }
}

// Looks for specific node in list to delete
void deleteNode(node* &head, node* current, node* previous, float studentID) {
    if (head->getStudent()->getStudentID() == studentID) { // If head is the node that has to be deleted
        node* tmp = head->getNext();
        delete head;
        head = tmp;
    }
    else if (current->getStudent()->getStudentID() == studentID && previous->getNext()->getStudent()->getStudentID() == studentID) { // If current is the node that has to be deleted
        previous->setNext(current->getNext());
        delete current;
        current = previous->getNext();
    }
    else if (current->getStudent()->getStudentID() == studentID && current->getNext() == NULL) {
        delete current;
        previous->setNext(NULL);
    }
    else { // Checks if next node had to be deleted
        deleteNode(head, current->getNext(), current, studentID);
    }
}

// Takes the average of all GPSs
void average(node* current, float total, float count) {
    if (current->getNext() == NULL) { // If reached the end of the list
        total = total + current->getStudent()->getGPA();
        count++;
        cout << "The average grade is: " << total/count << endl;
    }
    else { // Adds gpa to total and adds one to the count before giving information to the next node
        total = total + current->getStudent()->getGPA();
        count++;
        average(current->getNext(), total, count);
    }
}