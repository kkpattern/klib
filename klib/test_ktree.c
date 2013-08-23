#include "ktree.h"

#include <assert.h>
#include <stdlib.h>


// k_tree_new_node() creates a new KTreeNode with key and value and sets left
// and right child to NULL.
void test_k_tree_new_node() {
  void *key = (void *) 1;
  void *value = (void *) 2;
  KTreeNode *node = k_tree_new_node(key, value);
  assert(node->key == key);
  assert(node->value == value);
  assert(node->left == NULL);
  assert(node->right == NULL);
  k_tree_free_node(node);
}


// k_tree_free_node() frees a KTreeNode and return NULL.
void test_k_tree_free_node() {
  void *key = (void *) 1;
  void *value = (void *) 2;
  KTreeNode *node = k_tree_new_node(key, value);
  node = k_tree_free_node(node);
  assert(node == NULL);
}


int main() {
  test_k_tree_new_node();
  test_k_tree_free_node();
  return 0;
}
