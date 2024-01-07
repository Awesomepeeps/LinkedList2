#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

void deleteNode(node* &head, node* current, node* previous, float studentID);
void addNode(node* &head, node* current, node* newNode, node* previous);
void searchNode(node* current);
void deleteNodes(node* &head, node* current, node* previous);
void average(node* current, float total, float count);

main (void) {
    node* head = NULL;
    char* input = new char(15);

    while (true) {
        node* current = head;
        node* previous = NULL;
        cout << "What do you want to do (add, search, delete, average, quit)?" << endl;
        cin >> input;

        if (strcmp(input, "quit") == 0) {
            deleteNodes(head, current, NULL);
            break;
        }
        else if (strcmp(input, "add") == 0) {
            char* firstName = new char(20);
            char* lastName = new char(20);
            float gpa;
            int studentId;
            cout << "Please enter first name of the student: " << endl;
            cin >> firstName;
            cout << "Please enter last name of the student: " << endl;
            cin >> lastName;
            cout << "Please enter the student ID of the student: " << endl;
            cin >> studentId;
            cout << "Please enter the GPA of the student: " << endl;
            cin >> gpa;
            node* newNode = new node(new student(firstName, lastName, gpa, studentId));
            addNode(head, current, newNode, previous);
        }
        else if (strcmp(input, "search") == 0) {
            searchNode(head);
        }
        else if (strcmp(input, "delete") == 0) {
            float studentID = 0;
            cout << "What is the student ID of the student you want to delete?" << endl;
            cin >> studentID;
            deleteNode(head, current, NULL, studentID);
        }
        else if (strcmp(input, "average") == 0) {
            average(head, 0, 0);
        }
    }
}

void deleteNodes(node* &head, node* current, node* previous) {

}

void addNode(node* &head, node* current, node* newNode, node* previous) {
    cout << "Here" << endl;
    if (head == NULL) {
        head = newNode;
        cout << "Here1" << endl;
    }
    else if (newNode->getStudent()->getGPA() < current->getStudent()->getGPA()) {
        cout << "Here2" << endl;
        node* tmp = current;
        cout << "Tmp ID: " << tmp->getStudent()->getStudentID() << endl;
        previous->setNext(newNode);
        cout << "Previous next id: " << previous->getNext()->getStudent()->getStudentID() << endl;
        newNode->setNext(current);
        cout << "Ned node next id: " << newNode->getNext()->getStudent()->getStudentID() << endl;
        cout << "Current next id: " << current->getNext()->getStudent()->getStudentID() << endl;
    }
    else if (current->getNext() == NULL && previous != NULL) {
        cout << "Here NULL2" << endl;
        previous->setNext(newNode);
        newNode->setNext(current);
    }
    else {
        cout << "Here3" << endl;
        if (current == NULL) {
            cout << "Here4" << endl;
            addNode(head, current->getNext(), newNode, head);
        }
        else {
            cout << "Here5" << endl;
            addNode(head, current->getNext(), newNode, previous->getNext());
        }
    }
}

void searchNode(node* current) {
    if (current->getNext() != NULL) {
        current->getStudent()->printAll();
        searchNode(current->getNext());
    }
    else {
        current->getStudent()->printAll();
    }
}

void deleteNode(node* &head, node* current, node* previous, float studentID) {
    if (head == NULL) {
        return;
    }
    else if (studentID == current->getStudent()->getGPA()) {
        node* tmp = current;
        //cout << tmp->getStudent()->getStudentID() << endl;
        previous->setNext(tmp->getNext());
        delete tmp;
        //cout << previous->getNext()->getStudent()->getStudentID() << endl;
        //newNode->setNext(tmp);
        //cout << newNode->getNext()->getStudent()->getStudentID() << endl;
        //cout << "Here2" << endl;
        //cout << current->getNext()->getStudent()->getStudentID() << endl;
    }
    else {
        cout << "Here3" << endl;
        if (current == NULL) {
            deleteNode(head, current->getNext(), previous, studentID);
            cout << "Here4" << endl;
        }
        else {
            deleteNode(head, current->getNext(), previous->getNext(), studentID);
            cout << "Here5" << endl;
        }
    }
}

void average(node* current, float total, float count) {
    while (current->getNext() != NULL) {
        //cout << "Total bfr: " << total << endl;
        total = total + current->getStudent()->getGPA();
        //cout << "Total aft: " << total << endl;
        //cout << "GPA std: " << current->getStudent()->getGPA() << endl;
        count++;
        //cout << "Count is: " << count << "\nAverage is : " << total/count << endl;
        average(current->getNext(), total, count);
    }
}