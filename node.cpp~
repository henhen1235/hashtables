/*
Henry Xu
C++
11/13/24
Node.cpp
*/
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node(Student* nstudent) {
  student = nstudent; // set student as student pointer
  nextnode = NULL;//set next node to null for now
}

Node::~Node(){
  student = NULL;//set student and next node to null
  nextnode = NULL;//keep in mind that since the code doens't actually destruct student you need to do that also manually in main.cpp
}

Student* Node::getstudent(){// if the student exists then return it
  if(student != NULL){
    return student;
  }
  else{
    return NULL;
  }
}

void Node::setNext(Node* newnode){
  nextnode = newnode; //setting the next node up
}

Node* Node::getNext(){
  return nextnode;//returning the node
}
