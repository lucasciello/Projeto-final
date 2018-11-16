#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

using namespace std;

class Node {

    string val;
    Node* next;

  public:

    Node(string dat, Node* nxt);
    string getVal();
    Node* getNext();
    void setVal(string dat);
    void setNext(Node* nxt);
};

// Constructor - initializes the node
//
Node::Node(string dat, Node* nxt){
       val = dat;
       next = nxt;
}

// getVal returns the integer value stored in the node
//
string Node::getVal(){
     return val;
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

// setVal stores the integer value in the node
//
void Node::setVal(string dat){
     val = dat;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
       next = nxt;
}

#endif // NODE_H_INCLUDED
