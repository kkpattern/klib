// Tree implementations.
#ifndef KLIB_KTREE_H
#define KLIB_KTREE_H


typedef struct _KTreeNode {
  void *key;
  void *value;
  struct _KTree *left;
  struct _KTree *right;
} KTreeNode;


// Create a new KTreeNode with key and value. Set its left and right child to
// NULL
// @in key: The key of the node.
// @in value: The value of the node.
// @return: Pointer to the new created KTreeNode. If there is only error on
//   allocating memory, returns NULL.
KTreeNode *k_tree_new_node(void *key, void *value);


// Free a KTreeNode.
// @in node: The node to free.
// @return: NULL to clear the variable. E.g. node = k_tree_new_node(node);
KTreeNode *k_tree_free_node(KTreeNode *node);


typedef int KeyCompareFunction(void *key1, void *key1);
typedef int ValueCompareFunction(void *value1, void *value2);


typedef struct _KTree {
  KTreeNode *root;
  KeyCompareFunction *key_compare_function;
  ValueCompareFunction *value_compare_function;
} KTree;


// Initialize a KTree
// @in key_compare_function: The key compare function.
// @in value_compare_function: The value compare function.
// @out tree: Pointer to the tree that needs to be initialized.
// @return: The new created KTree.
int k_tree_init(KeyCompareFunction *key_compare_function,
                ValueCompareFunction *value_compare_function);


#endif
