#include "c_list.h"

// Create empty list, returns anchor.
List *create_list() {
  List *anchor = new List;
  anchor->previous = NULL;
  anchor->next = NULL;
  anchor->list_index = 0;
  anchor->list_size++;
  return anchor;
}

// If we create a List we have to delete is at some point.
int delete_list(List *anchor) {
  // Fuck! I implemented the list as one way list. But there are
  // previous var aswell so fuck it. Lets quickly iterate to the
  // end of the list.
  List *last = anchor;
  while(last->next != NULL) {
    last = last->next;
  }

  while(last != NULL) {
    last = last->previous;
    delete last->next;
  }

  return 0;
}

// Add new element with data to the list.
int add_list_element(List *anchor, int new_data) {
  List *new_element = new List;
  new_element->data = new_data;
  new_element->next = NULL;
  List *prev = NULL;
  List *act = anchor;
  while(act != NULL) {
    act = act->next;
    prev = act;
  }
  act = new_element;
  act->previous = prev;
  if(act == NULL || act->previous == NULL) return 1;
  return 0;
}

// Remove an element from list at the given index.
int remove_list_element(List *anchor, int list_index) {
  List *act = anchor;
  while(act->list_index != list_index && act = NULL) {
    act = act->next;
  }

  // Element at index not found, returns -1.
  if(act == NULL) return -1;

  // Element is the anchor. Pass the anchorness to the next element
  // in the line. KEKW
  if(act == anchor) {
    anchor = anchor->next;
    anchor->list_size = act->list_size - 1;
    delete act;
    return 0;
  }

  // There is an element at the given index. It should be terminated
  List *prev = act->previous;
  List *next = act->next;
  prev->next = next;
  next->previous = prev;
  delete act;
  
  // Now that we have terminated the wanted element, we should
  // decrement the indexes across the list. (Fuck yeah)
  while(next != NULL) {
    next->list_index--;
    next = next->next;
  }

  // Decrement the list_size by 1.
  acnhor->list_size--;

  return 0;
}
