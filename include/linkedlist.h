#ifndef BLASTEROIDS_LINKED_LIST
#define BLASTEROIDS_LINKED_LIST
#include "blast.h"

//Связный список. Пока для снарядов.

typedef struct Node{
  Blast *data;
  Node *next;
  Node *previous;
} Node;

typedef struct LinkedList{
  int size;
  Node *begin;
  Node* end;
} LinkedList;

LinkedList* create_linked_list();

Node* insert_new_node(LinkedList* list, Node* before);

Node* add_new_node(LinkedList* list);

void delete_node(LinkedList* list, Node* which);

void destroy_list(LinkedList* list);

#endif
