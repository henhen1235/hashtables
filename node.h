/*
Henry Xu
C++
11/13/24
Node.h
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "student.h"//this is a parent libary that uses student.h's child libaries

using namespace std;

class Node{
 public:
  Node(Student* nstudent);//create a node with a student pointer in it
  ~Node();//destuctor
  Student* getstudent();//getting the student
  void setNext(Node* newnode);//setting the next node
  Node* getNext();//getting the next node
 private:
  Student* student;//student pointer
  Node* nextnode;//node pointer
};
#endif