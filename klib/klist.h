// List implementations.
#ifndef KLIB_KLIST_H
#define KLIB_KLIST_H


typedef struct _KNode {
  void *data;
  struct _KNode *prev;
  struct _KNode *next;
} KNode;


// Allocate a KNode and initialize the data, prev, next attributes NULL.
// @return: Pointer to the new allocated KNode.
KNode *k_node_alloc();


// Free a allocated KNode
// @param node: Pointer to the KNode that needs to be freed.
// @return: NULL used to clear the pointer. E.g. node = k_node_free(node);
KNode *k_node_free(KNode *node);


#endif
