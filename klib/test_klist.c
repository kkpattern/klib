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
// list.length to 0;
void test_k_list_init() {
  KList list = k_list_init();
  assert(list.head == NULL);
  assert(list.tail == NULL);
  assert(list.length == 0);
  k_list_free(&list);
}


// k_list_append() append a new KNode to the KList, return the pointer to the
// KNode and return it.
void test_k_list_append() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_append(&list, data1);
  assert(node1->data == data1);
  assert(list.length == 1);
  assert(node1->next == NULL);
  assert(list.head == node1);
  assert(list.tail == node1);

  void *data2 = (void *)2;
  KNode *node2 = k_list_append(&list, data2);
  assert(list.length == 2);
  assert(node2->prev == node1);
  assert(node1->next == node2);
  assert(list.head == node1);
  assert(list.tail == node2);
  k_list_free(&list);
}


// k_list_prepend() prepend a new KNode to the KList, return the pointer to the
// KNode and return it.
void test_k_list_prepend() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_prepend(&list, data1);
  assert(node1->data == data1);
  assert(list.length == 1);
  assert(node1->next == NULL);
  assert(list.head == node1);
  assert(list.tail == node1);

  void *data2 = (void *)2;
  KNode *node2 = k_list_prepend(&list, data2);
  assert(list.length == 2);
  assert(node2->next == node1);
  assert(node1->prev == node2);
  assert(list.head == node2);
  assert(list.tail == node1);
  k_list_free(&list);
}


// k_list_pop_head() pop out the head KNode of a KList, return the data pointer
void test_k_list_pop_head() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_append(&list, data1);
  void *data2 = (void *)2;
  KNode *node2 = k_list_append(&list, data2);
  void *popped_data = k_list_pop_head(&list);
  assert(list.length == 1);
  assert(popped_data == data1);
  assert(list.head == node2);

  popped_data = k_list_pop_head(&list);
  assert(list.length == 0);
  assert(popped_data == data2);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  popped_data = k_list_pop_head(&list);
  assert(popped_data == NULL);
}


// k_list_pop_tail() pop out the tail KNode of a KList, return the data pointer
void test_k_list_pop_tail() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_append(&list, data1);
  void *data2 = (void *)2;
  KNode *node2 = k_list_append(&list, data2);
  void *popped_data = k_list_pop_tail(&list);
  assert(list.length == 1);
  assert(popped_data == data2);
  assert(list.tail == node1);

  popped_data = k_list_pop_tail(&list);
  assert(list.length == 0);
  assert(popped_data == data1);
  assert(list.head == NULL);
  assert(list.tail == NULL);

  popped_data = k_list_pop_tail(&list);
  assert(popped_data == NULL);
}


// k_list_remove() removes the first encounter of data in a KList.
void test_k_list_remove() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_append(&list, data1);
  void *data2 = (void *)2;
  KNode *node2 = k_list_append(&list, data2);
  KNode *node3 = k_list_append(&list, data2);
  k_list_remove(&list, data2);
  assert(list.length == 2);
  assert(list.tail == node3);
  k_list_remove(&list, data2);
  k_list_remove(&list, data1);
  assert(list.length == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);
}


// k_list_remove_all() removes all the encounter of data in a KList.
void test_k_list_remove_all() {
  KList list = k_list_init();
  void *data1 = (void *)1;
  KNode *node1 = k_list_append(&list, data1);
  void *data2 = (void *)2;
  KNode *node2 = k_list_append(&list, data2);
  KNode *node3 = k_list_append(&list, data2);
  k_list_remove_all(&list, data2);
  assert(list.length == 1);
  assert(list.tail == node1);
  k_list_remove_all(&list, data1);
  assert(list.length == 0);
  assert(list.head == NULL);
  assert(list.tail == NULL);
}


// k_list_free() frees a list. Set head, last attributes to NULL. Set length to
// 0.
void test_k_list_free() {
  KList list = k_list_init();
  k_list_free(&list);
  assert(list.head == NULL);
  assert(list.tail == NULL);
  assert(list.length == 0);
}


int main() {
  test_k_node_alloc();
  test_k_node_free();
  test_k_list_init();
  test_k_list_append();
  test_k_list_prepend();
  test_k_list_pop_head();
  test_k_list_pop_tail();
  test_k_list_remove();
  test_k_list_remove_all();
  test_k_list_free();
  return 0;
}
