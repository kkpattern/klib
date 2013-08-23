#include "ktree.h"

#include <assert.h>
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


// Initialize a KTree
// @in key_compare_function: The key compare function, the value can't be NULL.
// @in value_compare_function: The value compare function, the value can't be
//   NULL.
// @out tree: Pointer to the tree that needs to be initialized.
void k_tree_init(KeyCompareFunction *key_compare_function,
                 ValueCompareFunction *value_compare_function,
                 KTree *ktree) {
  assert(key_compare_function != NULL);
  assert(value_compare_function != NULL);
  ktree->root = NULL;
  ktree->key_compare_function = key_compare_function;
  ktree->value_compare_function = value_compare_function;
}


// Free a KTree. Used by k_tree_free().
// @in node: The root node of the KTree.
void _k_tree_free(KTreeNode *node) {
  if (node == NULL) {
    return;
  } else {
    _k_tree_free(node->left);
    _k_tree_free(node->right);
    k_tree_free_node(node);
  }
}


// Free a KTree
// @in tree: Pointer to the tree that needs to be freed.
void k_tree_free(KTree *ktree) {
  _k_tree_free(ktree->root);
  ktree->root = NULL;
}
