#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>
#include "student.h"

using namespace std;

class hashtables{
 public:
  hashtables(int size);//constructor
  ~hashtables();//destructor
  void insert(int key, Student* nstudent);//inserting student
  Student* info(int key);//getting student
  void remove(int key);//removing student
  void rehash();//rehashing if needed
  int hashkey(int key);//hashing the key
 public:
  Node** table;//table for storage
  int hashsize = 0;//size of the hash table
  int studentnum = 0;//amount of students added
};
