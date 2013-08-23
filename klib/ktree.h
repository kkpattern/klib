// Tree implementations.
#ifndef KLIB_KTREE_H
#define KLIB_KTREE_H


typedef struct _KTreeNode {
  void *key;
  void *value;
  struct _KTreeNode *left;
  struct _KTreeNode *right;
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


typedef int KeyCompareFunction(void *key1, void *key2);
typedef int ValueCompareFunction(void *value1, void *value2);


typedef struct _KTree {
  KTreeNode *root;
  KeyCompareFunction *key_compare_function;
  ValueCompareFunction *value_compare_function;
} KTree;


// Initialize a KTree
// @in key_compare_function: The key compare function, the value can't be NULL.
// @in value_compare_function: The value compare function, the value can't be
//   NULL.
// @out tree: Pointer to the tree that needs to be initialized.
void k_tree_init(KeyCompareFunction *key_compare_function,
                 ValueCompareFunction *value_compare_function,
                 KTree *ktree);


// Free a KTree
// @in tree: Pointer to the tree that needs to be freed.
void k_tree_free(KTree *ktree);


#endif
