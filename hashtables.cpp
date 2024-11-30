#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"
#include "hashtables.h"
#include <vector>

using namespace std;

hashtables::hashtables(int size){
  hashsize = size;
  table = new Node*[size];
  for (int x = 0; x < size; x++){
    table[x] = NULL;
  }
}

hashtables::~hashtables() {
  for (int i = 0; i < hashsize; i++) {
    Node* currentNode = table[i];
    while (currentNode != NULL) {
      Node* nextNode = currentNode->getNext();
      delete currentNode;
      currentNode = nextNode;
    }
  }
  delete[] table;
}


int hashtables::hashkey(int key){
  int nkey = key % hashsize;
  return nkey;
}

void hashtables::insert(int key, Student* nstudent){
  int nkey = hashkey(key);
  Node* currentnode = table[nkey];

  Node* nNode = new Node(nstudent);

  if(table[nkey] == NULL){ 
    table[nkey] = nNode;
  }
  else{
    while(currentnode->getNext() != NULL){
      currentnode = currentnode->getNext();
    }
    currentnode->setNext(nNode);
  }
 }

Student* hashtables::info(int key){
  int nkey = hashkey(key);
  Node* currentnode = table[nkey];

  while (currentnode->getstudent()->getID() != key && currentnode != NULL){
    currentnode = currentnode->getNext();
  }

  if(currentnode == NULL){
    return NULL;
  }
  else{
    return currentnode->getstudent();
  }
}

void hashtables::remove(int key){
  int nkey = hashkey(key);
  Node* currentnode = table[nkey];
  Node* beforenode = NULL;
  bool Firstnode = true;

  while (currentnode->getstudent()->getID() != key){
    beforenode = currentnode;
    currentnode = currentnode->getNext();
    Firstnode = false;
  }

  if(Firstnode == true){
    table[nkey] = currentnode->getNext();
  }
  else{
    beforenode->setNext(currentnode->getNext());
  }
  delete currentnode;  
}