#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"
#include "hashtables.h"
#include <vector>


//using namespace std;

hash::hash(int size){
  hashsize = size;
  node* table[size];
  for (int x = 0; x < size; x++){
    table[size] = NULL;
  }
}

int hash::hashkey(int key){
  int nkey = key % hashsize;
  return nkey;
}

void hash::insert(int key, Student* nstudent){
  int nkey = hashkey(key);
  Node* currentnode = table.at(nkey);
  if(currentnode == NULL){ 
    Node* node1 = new node(nstudent);
  }
  else{
    while(currentnode != NULL){
      currentnode = currentnode->getnext();
    }
    Node* node1 = new node(nstudent);
    currentnode->setnext(node1);
  }
 }

Student* hash::info(int key, Student* nstudent){
  int nkey = hashkey(key);
  Node* currentnode = table.at(nkey);
  while (currentnode->getstudent() != nstudent){
    currentnode = currentnode->getnext();
    //   student* tstudent = currentnode->getstudent();
    //int tkey = tstudent->getID();
    //int nkey = hashkey(tkey);
  }
  Student* nstudent = currentnode->getstudent();
  return nstudent;
}

void hash::remove(int key, Student* nstudent){
   int nkey = hashkey(int key);
  Node* currentnode = table.at(nkey);
  while (currentnode->getstudent() != nstudent){
    currentnode = currentnode->getnext();
    //   student* tstudent = currentnode->getstudent();
    //int tkey = tstudent->getID();
    //int nkey = hashkey(tkey);
  }
  delete currentnode;  
}

