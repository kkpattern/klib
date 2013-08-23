#include "ktree.h"

#include <stdlib.h>


// Create a new KTreeNode with key and value. Set its left and right child to
// NULL
// @in key: The key of the node.
// @in value: The value of the node.
// @return: Pointer to the new created KTreeNode. If there is only error on
//   allocating memory, returns NULL.
KTreeNode *k_tree_new_node(void *key, void *value) {
  KTreeNode *new_node = (KTreeNode *) malloc(sizeof(KTreeNode));
  if (new_node != NULL) {
    new_node->key = key;
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
  }
  return new_node;
}


// Free a KTreeNode.
// @in node: The node to free.
// @return: NULL to clear the variable. E.g. node = k_tree_new_node(node);
KTreeNode *k_tree_free_node(KTreeNode *node) {
  free(node);
  return NULL;
}
