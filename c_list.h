#ifndef CLIST
#define CLIST

#include <stdlib.h> 

using namespace std;

struct List {
  List *previous;
  List *next;
  int data;
  int list_index;
  size_t list_size;
};

List *create_list();

int add_list_element(List*);

int remove_list_element(List*, int);

int delete_list(List*);
#endif
