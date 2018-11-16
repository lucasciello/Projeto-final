#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "Node.h"

class fila {
public:
  Node* head;
  fila();
  ~fila();
  void adicionaritem(string dat);
  string mostrar();
  string removeranuncio();
  void listar();
};

fila::fila() {
   head = 0;
}

fila::~fila() {
  Node* cursor = head;
  while(head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0;
}

void fila::adicionaritem(string dat) {
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

string fila::mostrar() {
   return head->getVal();
}

string fila::removeranuncio() {
  if (head != 0){
     Node* oldHead = head;
     head = head->getNext();
     delete oldHead;
  }
}

void fila::listar() {
  Node* aux = head;
  while (aux != 0){
     cout << aux->getVal() << endl;
     aux = aux->getNext();
  }
}

#endif // FILA_H_INCLUDED
