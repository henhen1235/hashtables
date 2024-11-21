File Edit Options Buffers Tools C++ Help
#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include "student.h"

using namespace std;

class hash{
 public:
  hash(int size);
  ~hash();
  void insert(int key, Student* nstudent);
  Student* info(int key, Student* nstudent);
  void remove(int key, Student* nstudent);
  int hashkey(int key);
 public:
  node* table[];
  int hashsize = 0;
};
