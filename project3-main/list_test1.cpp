// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o list_test1 list_test1.cpp; ./list_test1 

#include <iostream>
#include <string>

#include "dlist.h"

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
  std::string name;
  std::string uniqname;
  Job job;
};

int main() {
  // TEST DLIST OF INTS

  Dlist<int> test_list; 
  test_list.InsertFront(2);
  test_list.InsertFront(1);
  test_list.InsertBack(3);
  test_list.InsertBack(4);
  while (!test_list.IsEmpty()) {
    std::cout << test_list.RemoveFront() << std::endl;
  }
  test_list.InsertFront(2);
  test_list.InsertFront(1);
  test_list.InsertBack(3);
  test_list.InsertBack(4);
  while (!test_list.IsEmpty()) {
    std::cout << test_list.RemoveBack() << std::endl;
  }

  // TEST DLIST OF RECORD PTRS

  // Records are big, so create a linked list of pointers 
  // instead of a linked list of Records
  Dlist<Record*> bobcat_access; 

  // Create a new Record and insert to front of bobcat_access
  Record* p = new Record;
  p->name = "Karen Lu";
  p->uniqname = "karenlu";
  p->job = FACULTY;
  bobcat_access.InsertFront(p);

  // You can test other dlist operators on bobcat_access below

  // Don't forget to delete objects on the heap
  while (!bobcat_access.IsEmpty()) {
    Record *r = bobcat_access.RemoveFront();
    std::cout << r->uniqname << std::endl;
    delete r;
  }

  return 0;
}