/*
Henry Xu
c++
11/29/2024
hashtables.cpp for hashtables assignment
*/

//imports
#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"
#include "hashtables.h"
#include <vector>

using namespace std;

hashtables::hashtables(int size){//initializing function
  hashsize = size;
  table = new Node*[hashsize];//set the entire array to NULL
  for (int x = 0; x < hashsize; x++){
    table[x] = NULL;
  }
}

hashtables::~hashtables() {//desturctor
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


int hashtables::hashkey(int key){// function for calculating the key
  int nkey = key % hashsize;
  return nkey;
}

void hashtables::rehash(){//function for rehashing
  Node** otable = table;//create a new array called otable and make it the same as the current table
  int osize = hashsize;// same with size

  hashsize = hashsize*2;// update hashsize and hash table to new size
  table = new Node*[hashsize];
  for (int x = 0; x < hashsize; x++){
    table[x] = NULL;
  }

  for(int x = 0; x < osize; x++){//go through otable and take everything and put it into table
    Node* currentnode = otable[x];

    if (currentnode != NULL){//if the current node in otable isn't NULL
      while(currentnode != NULL){
        int nkey = hashkey(currentnode->getstudent()->getID());
        Node* nnode = new Node(currentnode->getstudent());
        Node* ncurrentnode = table[nkey];

      if(table[nkey] == NULL){ // take the node from otable and put it into table
        table[nkey] = nnode;
      }
      else{
        while(ncurrentnode->getNext() != NULL){
        ncurrentnode = ncurrentnode->getNext();
      } 
        ncurrentnode->setNext(nnode);//put it into table
    }
    currentnode = currentnode->getNext();//keep going until we go through entire otable
    }
  }
  }
  for (int x = 0; x < osize; x++) {//delete otable incase if we missed anything
    Node* currentnode = otable[x];
    while (currentnode != NULL) {
        Node* nextnode = currentnode->getNext();
        delete currentnode;
        currentnode = nextnode;
    }
  }
    delete[] otable;
}

void hashtables::insert(int key, Student* nstudent){//inserting
  int nkey = hashkey(key);//get the key
  studentnum = studentnum + 1;
  Node* currentnode = table[nkey];
  Node* nNode = new Node(nstudent);

  int rehashnum = 0;
  if(table[nkey] == NULL){//if the slot on the array is empty then put it there 
    table[nkey] = nNode;
  }
  else{//otherwise go through the linkedlist until we find a empty spot
    while(currentnode->getNext() != NULL){
      currentnode = currentnode->getNext();
      rehashnum = rehashnum + 1;
    }
    currentnode->setNext(nNode);
  }
  if (studentnum > hashsize/2 || rehashnum > 3) {
    // if total students is bigger then half of hash size or there is more\
    then 3 in one linked list then rehash everything.
    rehash();
  }
 }

Student* hashtables::info(int key){//get info about the student function
  int nkey = hashkey(key);//get hash key
  Node* currentnode = table[nkey];

  while (currentnode != NULL && currentnode->getstudent()->getID() != key){
    currentnode = currentnode->getNext();
  }//if the current node isn't the same id as the student then keep searching

  if(currentnode == NULL){//if current node is null meaning there is nothing left then return null
    return NULL;
  }
  else{//if there is something there then return the student
    return currentnode->getstudent();
  }
}

void hashtables::remove(int key){//function for removing students
  int nkey = hashkey(key);//get the hash key
  Node* currentnode = table[nkey];
  
  if (currentnode == NULL) {//if it doens't exist then do nothing
    return;
  }
  
  Node* beforenode = NULL;
  bool Firstnode = true;

  while (currentnode->getstudent()->getID() != key){
    beforenode = currentnode;
    currentnode = currentnode->getNext();
    Firstnode = false;
  }


  if(Firstnode == true){//if it is first node then set the node after it to the node on the array
    table[nkey] = currentnode->getNext();
  }
  else{//if it isn't then set the node before it to the node after it
    beforenode->setNext(currentnode->getNext());
  }
  delete currentnode;  //delete the current node
}