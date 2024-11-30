/*
Henry Xu
C++
11/13/24
student.cpp
*/
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(){//constructing student
  first = new char[50];
  last = new char[50];
  ID = 0;
  GPA = 0.0;
}

Student::~Student(){//destructing student
  delete[] first;
  delete[] last;
}

void Student::makestudent(char* nfirst, char* nlast, int nID, float NGPA){//adding in stuff for student
  strcpy(first, nfirst);
  strcpy(last, nlast);
  ID = nID;
  GPA = NGPA;
}

char* Student::getfirst(){//getting student first name
  return first;
}
char* Student::getlast(){//getting student last name
  return last;
}
int Student::getID(){//getting student id
  return ID;
}
float Student::getGPA(){//getting student gpa
  return GPA;
}
