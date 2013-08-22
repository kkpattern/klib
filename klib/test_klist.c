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


// k_list_init() initialize a list. Set list.head and list.last to NULL. Set
// list.length to 0; Set list.sentinel.data, sentinel.prev, sentinel.next to
// NULL.
void test_k_list_init() {
  KList list = k_list_init();
  assert(list.head == NULL);
  assert(list.last == NULL);
  assert(list.sentinel.data == NULL);
  assert(list.sentinel.prev == NULL);
  assert(list.sentinel.next == NULL);
  assert(list.length == 0);
}

int main() {
  test_k_node_alloc();
  test_k_node_free();
  test_k_list_init();
  return 0;
}
