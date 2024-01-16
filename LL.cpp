#include "LL.h"
//#include "Node.h"
#include <sstream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <iomanip>

using namespace std;

//LL::LL() {
//}

Node *LL::insert(Fan fan){
    //cout << "insert called HERE" << endl;
    Node *newnode = new Node(fan);
    //cout << "HERE" << endl;
    /*if (head == nullptr && tail == nullptr) {
        head = tail = newnode;
        num_elements++;
        return true;
    }
    else if (head == tail) {
        tail->next = newnode;
        num_elements++;
        return true;
    }*/
    //newnode->data = fan;
    newnode->next = head;
    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
    /*while (newnode!=nullptr){
        newnode = new Node;
    }
    newnode->data = fan;
    newnode->next = nullptr;*/
    return newnode;
}

void LL::show(){
    //cout << "got CALLED" << endl;
    for (Node *np = head; np!=nullptr; np = np->next) {
        //cout << np->data.getSeat() << endl;
    }
    cout << endl;
}

bool LL::find(Fan fan){
    for (Node *np = head; np!= nullptr; np=np->next) {
        if (fan.getFirst() == np->data.getFirst()) {
            return true;
        }
    return false;
    }
}

void LL::traverse(std::string outputfilename) {
    ofstream outfile;
    outfile.open(outputfilename);
    for (Node *np = head; np!= nullptr; np=np->next) {
        outfile << np->data.getLast() << " " << np->data.getFirst() << " " << np->data.getActualPhone() << " " << np->data.getActualEmail() << " " << np->data.getSeat() << " " << np->data.getConcessions() << endl;
        //outfile << np->data.getLast() << " " << np->data.getFirst() << np->data.getSeat() << endl;
    }
}

LL::~LL() {
    Node* curr = head;
    while (curr != 0) {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    head = 0;
}