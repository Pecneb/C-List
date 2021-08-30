#ifndef CLIST
#define CLIST

#include <stdlib.h> 

using namespace std;

typedef struct List {
  List *previous;
  List *next;
  List *last;
  int data;
  int list_index;
  size_t list_size;
};

List *create_list();
int add_ele(List*);
int rm_ele(List*, int);
int del_list(List*);
#endif
