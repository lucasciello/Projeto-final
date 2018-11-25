#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "node.h"
#include <iostream>

using namespace std;


class List {

  Node* head;

public:
  List();
  ~List();
  void insertBeforeFirst(string dat);
  void insertAfterLast(string dat);
  string readFirst();
  string removeFirst();
  void insertionSort(string value);
  string removeNode(string dat);
  void listAll();
};

List::List() {
   head = 0;
}

List::~List() {
  Node* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

void List::insertBeforeFirst(string dat) {
  head = new Node(dat, head);
}

void List::insertAfterLast(string dat) {
  Node* p = head;
  Node* q = head;

  if (head == 0)
     head = new Node(dat, head);
  else {
     while (q != 0) {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node(dat,0));
  }
}

string List::readFirst() {
   return head->getVal();
}

string List::removeFirst() {
  string retval;
  if (head != 0){
     cout << "Removendo: " << head << endl;
     cout << "e fica:" << head->getVal() << endl;
     retval = head->getVal();
     Node* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
  return retval;
}


void List::insertionSort(string value) {
  Node* p = head;
  Node* q = head;

  if (head == 0)
  {
     head = new Node(value,head);
	 string i;
	 i = head->getVal();
  }
  else
  {
	  string pint;
	  string auxint;
	  pint = q->getVal();
	  auxint = pint;
	  while ((q != 0) && (auxint < value))
	  {
		  p = q;
		  q = p->getNext();
		  if (q != 0)
		  {
			pint = q->getVal();
			auxint = pint;
		  }
	  }
	  if (p == q)
		  head = new Node(value,head);
	  else
			p->setNext(new Node(value,q));
  }
}


string List::removeNode(string dat) {
  Node* p = head;
  Node* q = head;
  string result;

  if (head == 0)
     result = "0";
  else {
	  while ((q != 0) && (q->getVal() != dat)){  // Error!! the addresses will always be different!
		  p = q;
		  q = p->getNext();
	  }
	  if (q != 0) {
		  if (q == head){	// it is the first node
			  result = q->getVal();
			  head = q->getNext();
			  delete q;
		  }
		  else{				// the node is in the middle
			  result = q->getVal();
			  p->setNext(q->getNext());
			  delete q;
		  }
	  }
	  else
		  result = "0";		// node not found!
  }

  return result;
}

void List::listAll() {
  Node* aux = head;
  while (aux != 0){
     cout << aux->getVal() << endl;
     aux = aux->getNext();
  }
}

#endif // LISTA_H_INCLUDED
