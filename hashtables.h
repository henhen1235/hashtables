File Edit Options Buffers Tools C++ Help
#include <iostream>
#include <cstring>
#include "node.h"
#include <vector>

using namespace std;

class hash(){
 public:
  hash(int size);
  ~hash();
  void insert(int key, student*);
  student* info(int key);
  void remove(int key);
  int hashkey(int key);
 public:
  vector<student*> table;
}
