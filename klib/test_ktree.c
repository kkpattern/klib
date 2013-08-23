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


int test_key_compare(void *a, void *b) {
  return a-b;
}


int test_value_compare(void *a, void *b) {
  return a-b;
}


// k_tree_init() initialize a KTree. Set key_compare_function and
// value_compare_function attributes and set root to NULL.
void test_k_tree_init() {
  KTree tree;
  k_tree_init(&test_key_compare, &test_value_compare, &tree);
  assert(tree.key_compare_function == &test_key_compare);
  assert(tree.value_compare_function == &test_value_compare);
  assert(tree.root == NULL);
}


int main() {
  test_k_tree_new_node();
  test_k_tree_free_node();
  test_k_tree_init();
  return 0;
}
