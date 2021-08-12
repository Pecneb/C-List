#ifndef CLIST
#define CLIST

#include <stdlib.h> 

using namespace std;

struct List {
  List *previous;
  List *next;
};

List *create_list();

List *add_list_element(List*);

List *remove_list_element(List*, int);

#endif
