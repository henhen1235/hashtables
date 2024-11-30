#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include "student.h"

using namespace std;

class hashtables{
 public:
  hashtables(int size);
  ~hashtables();
  void insert(int key, Student* nstudent);
  Student* info(int key);
  void remove(int key);
  void rehash();
  int hashkey(int key);
 public:
  Node** table;
  int hashsize = 0;
  int studentnum = 0;
};
