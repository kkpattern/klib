#include "klist.h"

#include <stdlib.h>


// Allocate a KNode and initialize the data, prev, next attributes NULL.
// @return: Pointer to the new allocated KNode.
KNode *k_node_alloc() {
  KNode *node = (KNode *) malloc(sizeof(KNode));
  node->data = NULL;
  node->prev = NULL;
  node->next = NULL;
  return node;
}


// Free a allocated KNode
// @param node: Pointer to the KNode that needs to be freed.
// @return: NULL used to clear the pointer. E.g. node = k_node_free(node);
KNode *k_node_free(KNode *node) {
  free(node);
  return NULL;
}


// Initialize a KList.
KList k_list_init() {
  KList list;
  list.head = NULL;
  list.tail = NULL;
  list.length = 0;
  return list;
}


// Prepend a KNode to KList with data.
// @return: Pointer to the new prepended KNode.
KNode *k_list_prepend(KList *list, void *data) {
  KNode *new_node = k_node_alloc();
  new_node->data = data;

  if (list->head != NULL) {
    list->head->prev = new_node;
    new_node->next = list->head;
    list->head = new_node;
  } else {
    // First node in the list, point both list->tail and list->head to it.
    list->tail = new_node;
    list->head = new_node;
  }

  list->length += 1;
  return new_node;
}


// Append a KNode to KList with data.
// @return: Pointer to the new appended KNode.
KNode *k_list_append(KList *list, void *data) {
  KNode *new_node = k_node_alloc();
  new_node->data = data;

  if (list->tail != NULL) {
    list->tail->next = new_node;
    new_node->prev = list->tail;
    list->tail = new_node;
  } else {
    // First node in the list, point both list->tail and list->head to it.
    list->tail = new_node;
    list->head = new_node;
  }

  list->length += 1;
  return new_node;
}


// Free a KList.
void k_list_free(KList *list) {
  KNode *node = list->head;
  while (node) {
    KNode *tmp = node->next;
    k_node_free(node);
    node = tmp;
  }
  list->head = list->tail = NULL;
  list->length = 0;
}
