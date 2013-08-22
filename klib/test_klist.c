#include "klist.h"

#include <assert.h>
#include <stdlib.h>


// k_node_alloc() allocates a KNode and set the data, prev, next attributes
// NULL.
void test_k_node_alloc() {
  KNode *node = k_node_alloc();
  assert(node->data == NULL);
  assert(node->prev == NULL);
  assert(node->next == NULL);
  k_node_free(node);
}


// k_node_free() frees a KNode and return NULL.
void test_k_node_free() {
  KNode *node = k_node_alloc();
  // TODO(kaizhang): test the node is actually freed.
  node = k_node_free(node);
  assert(node == NULL);
}

int main() {
  return 0;
}
