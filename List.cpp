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
    node* head = NULL;
    char* input = new char(15);

    while (true) {
        cout << "What do you want to do (add, search, print, delete, average, quit)?" << endl;
        cin >> input;

        if (strcmp(input, "quit") == 0) {
            deleteNodes(head, head);
            break;
        }
        else if (strcmp(input, "add") == 0) {
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
            node* newNode = new node(new student(firstName, lastName, gpa, studentId));
            addNode(head, head, newNode, head);
        }
        else if (strcmp(input, "print") == 0) {
            if (head != NULL) {
                cout << endl;
                searchNode(head);
            }
            else {
                cout << "\nThere are no students in the list\n" << endl;
            }
        }
        else if (strcmp(input, "search") == 0) {
            if (head != NULL) {
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
        else if (strcmp(input, "delete") == 0) {
            if (head != NULL) {
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
        else if (strcmp(input, "average") == 0) {
            if (head != NULL) {
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

void deleteNodes(node* &head, node* current) {
    if (head->getNext() != NULL) {
        float ID = head->getStudent()->getStudentID();
        deleteNode(head, head, head, ID);
        deleteNodes(head, head);
    }
    else {
        float ID = head->getStudent()->getStudentID();
        deleteNode(head, head, head, ID);
    }
}

void addNode(node* &head, node* current, node* newNode, node* previous) {
    if (head == NULL) {
        head = newNode;
    }
    else if (newNode->getStudent()->getGPA() < current->getStudent()->getGPA() && newNode->getStudent()->getGPA() > previous->getStudent()->getGPA()) {
        newNode->setNext(current);
        previous->setNext(newNode);
    }
        else if (current->getStudent()->getGPA() > newNode->getStudent()->getGPA()) {
        head = newNode;
        newNode->setNext(current);
    }
    else if (current->getNext() == NULL) {
        current->setNext(newNode);
    }
    else {
        addNode(head, current->getNext(), newNode, current);
    }
}

void searchNode(node* current) {
    if (current->getNext() == NULL) {
        current->getStudent()->printAll();
    }
    else {
        current->getStudent()->printAll();
        searchNode(current->getNext());
    }
}

void searchSpecif(node* head, float ID) {
    if (head->getStudent()->getStudentID() == ID) {
        head->getStudent()->printAll();
    }
    else if (head->getNext() == NULL) {
        cout << "Student is not in list" << endl;
    }
    else {
        searchSpecif(head->getNext(), ID);
    }
}

void deleteNode(node* &head, node* current, node* previous, float studentID) {
    if (head == NULL) {
        cout << "There are no students in the list" << endl;
    }
    else if (head->getStudent()->getStudentID() == studentID) {
        node* tmp = head->getNext();
        delete head;
        head = tmp;
    }
    else if (current->getStudent()->getStudentID() == studentID && previous->getNext()->getStudent()->getStudentID() == studentID) {
        previous->setNext(current->getNext());
        delete current;
        current = previous->getNext();
    }
    else if (current->getStudent()->getStudentID() == studentID && current->getNext() == NULL) {
        delete current;
        previous->setNext(NULL);
    }
    else {
        deleteNode(head, current->getNext(), current, studentID);
    }
}

void average(node* current, float total, float count) {

    if (current->getNext() == NULL) {
        total = total + current->getStudent()->getGPA();
        count++;
        cout << "The total grade is: " << total << endl;
        cout << "The count grade is: " << count << endl;
        cout << "The average grade is: " << total/count << endl;
    }
    else {
        total = total + current->getStudent()->getGPA();
        count++;
        average(current->getNext(), total, count);
    }
}