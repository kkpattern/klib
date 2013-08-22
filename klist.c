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
