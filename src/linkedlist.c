#include "linkedlist.h"
#include<stdlib.h>

LinkedList* create_linked_list(){
  LinkedList* list = malloc(sizeof(LinkedList));
  list->size = 0;
  list->begin = NULL;
  list->end = NULL;
  return list;
}

Node* add_new_node(LinkedList* list){
  Node* new_node = malloc(sizeof(Node));
  new_node->data = NULL;
  new_node->next = NULL;
  new_node->previous = list->end;
  if(list->size == 0){
    list->start = new_node;
    list->end = new_node;
  } else list->end->next = new_node;
  list->size += 1;
  return new_node;
}

Node* insert_new_node(LinkedList* list, Node* before){
  Node* new_node = malloc(sizeof(Node));
  new_node->data = NULL;
  new_node->next = before;
}
