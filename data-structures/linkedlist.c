#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//
// LINKED LIST
//

typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

typedef struct linked_list_t {
  node_t *head;
  node_t *tail;
} linked_list_t;

node_t *new_node(int value) {
  node_t *new = (node_t *)malloc(sizeof(node_t));
  if (!new) {
    printf("Failed to create Node");
    return NULL;
  }
  new->data = value;
  return new;
}

linked_list_t *new_linked_list() {
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  if (!list) {
    printf("Failed to create List");
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void push(linked_list_t *list, int value) {
  printf("PushFront: %d\n", value);

  node_t *new = new_node(value);

  // empty list before insertion
  if (!list->head) {
    // head and tail will point to the node
    list->head = new;
    list->tail = new;
    // new node next will be null
    new->next = NULL;
  } else {
    // new node next will point to the head
    new->next = list->head;
    list->head = new; // update head
  }
}

void push_back(linked_list_t *list, int value) {
  printf("PushBack: %d\n", value);

  node_t *new = new_node(value);
  new->next = NULL;

  // empty list before insertion
  if (!list->tail) {
    // head and tail will point to the node
    list->head = new;
    list->tail = new;
    // new node prev will be null
  } else {
    // previous tail node will point to the new node
    list->tail->next = new;
    // new node previous will point to the tail
    list->tail = new; // update tail
  }
}

void pop(linked_list_t *list) {
  printf("PopFront: %d\n", list->head->data);

  if (!list->head) {
    printf("List is empty");
    return;
  }

  if (list->head == list->tail) { // only 1 element, update both head and tail
    node_t *del = list->head;
    list->head = NULL;
    list->tail = NULL;
    free(del); // delete node
  } else {
    node_t *del = list->head;
    // update the head to the next node
    list->head = list->head->next;
    free(del); // delete node
  }
}

void pop_back(linked_list_t *list) {
  printf("PopBack: %d\n", list->tail->data);

  if (!list->tail) {
    printf("List is empty");
    return;
  }

  if (list->head == list->tail) { // only 1 element, update both head and tail
    node_t *del = list->head;
    list->head = NULL;
    list->tail = NULL;
    free(del); // delete node
  } else {
    node_t *del = list->tail;
    // update the tail to the previous node
    node_t *ptr = list->head;
    // iterate through the whole list to find the previous to last element
    while (ptr->next->next != NULL) {
      ptr = ptr->next;
    }
    list->tail = ptr;
    list->tail->next = NULL;
    free(del); // delete node
  }
}

void print_elements(linked_list_t *list) {
  printf("Printing List:\n");
  if (!list->head) {
    assert(list->head == NULL);
    assert(list->tail == NULL);
    printf("--No elements\n\n");
    return;
  }

  node_t *ptr = list->head;
  printf("--Head -> %d / Tail -> %d\n", list->head->data, list->tail->data);
  printf("--Elements: ");
  while (ptr) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n\n");
}

int main() {
  linked_list_t *list = new_linked_list();
  print_elements(list);
  push(list, 1);
  print_elements(list);
  push_back(list, 2);
  print_elements(list);
  push(list, 3);
  print_elements(list);
  push_back(list, 4);
  print_elements(list);
  pop(list);
  print_elements(list);
  pop_back(list);
  print_elements(list);
  pop_back(list);
  print_elements(list);
  pop(list);
  print_elements(list);
  push_back(list, 5);
  print_elements(list);
  pop_back(list);
  print_elements(list);
}
