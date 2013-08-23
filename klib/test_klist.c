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


// k_list_init() initialize a list. Allocate a KNode to list.sentinel .Set
// list.head and list.last to list.sentinel. Set list.length to 0; Set
// list.sentinel.data, sentinel.prev, sentinel.next to NULL.
void test_k_list_init() {
  KList list = k_list_init();
  assert(list.sentinel->data == NULL);
  assert(list.sentinel->prev == NULL);
  assert(list.sentinel->next == NULL);
  assert(list.head == list.sentinel);
  assert(list.last == list.sentinel);
  assert(list.length == 0);
  k_list_free(&list);
}


// k_list_free() append a new KNode to the KList, return the pointer to the
// KNode and return it.
void test_k_list_append() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_append(&list, data1);
  assert(node1->data == data1);
  assert(list.length == 1);
  assert(node1->next == NULL);

  void *data2 = (void *)2;
  KNode *node2 = k_list_append(&list, data2);
  assert(list.length == 2);
  assert(node2->prev == node1);
  assert(node1->next == node2);
  k_list_free(&list);
}


// k_list_free() frees a list. Set sentinel, head, last attributes to NULL. Set
// length to 0.
void test_k_list_free() {
  KList list = k_list_init();
  k_list_free(&list);
  assert(list.sentinel == NULL);
  assert(list.head == NULL);
  assert(list.last == NULL);
  assert(list.length == 0);
}

int main() {
  test_k_node_alloc();
  test_k_node_free();
  test_k_list_init();
  test_k_list_append();
  test_k_list_free();
  return 0;
}
