/*
Henry Xu
C++
11/13/24
student.h
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
 public:
  Student();//constructor
  ~Student();//destructor
  void makestudent(char* nfirst, char* nlast, int nID, float NGPA);//adding in student stuff
  char* getfirst();//get first name
  char* getlast();//get last name
  int getID();//get id
  float getGPA();//get gpa
 private:
  char* first;//first name
  char* last;//last name
  int ID;//id
  float GPA;//gpa
};

#endif
