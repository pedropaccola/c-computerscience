#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
// DOUBLY LINKED LIST
//

typedef struct node_t {
  int data;
  struct node_t *next;
  struct node_t *prev;
} node_t;

typedef struct linked_list_t {
  node_t *head;
  node_t *tail;
} linked_list_t;

node_t *new_node(int value) {
  node_t *new = malloc(sizeof(node_t));
  if (!new) {
    printf("Failed to create Node");
    exit(EXIT_FAILURE);
  }
  new->data = value;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

linked_list_t *new_linked_list() {
  linked_list_t *list = malloc(sizeof(linked_list_t));
  if (!list) {
    printf("Failed to create List");
    exit(EXIT_FAILURE);
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void destroy_list(linked_list_t *list) {
  node_t *ptr = list->head;
  while (ptr) {
    node_t *temp = ptr;
    ptr = ptr->next;
    free(temp);
  }
  free(list);
  return;
}

bool is_empty(const linked_list_t *list) { return (!list->head); }

void insert_after(linked_list_t *list, node_t *node, int value) {
  printf("Insert Before: %d\n", node->data);

  node_t *new = new_node(value);
  new->prev = node;

  // If last element
  if (node->next == NULL) {
    new->next = NULL;
    list->tail = new;
  } else {
    new->next = node->next;
    node->next->prev = new;
  }
  node->next = new;
}

void insert_before(linked_list_t *list, node_t *node, int value) {
  printf("Insert Before: %d\n", node->data);

  node_t *new = new_node(value);
  new->next = node;

  // If first element
  if (node->prev == NULL) {
    new->prev = NULL;
    list->head = new;
  } else {
    new->prev = node->prev;
    node->prev->next = new;
  }
  node->prev = new;
}

void push(linked_list_t *list, int value) {
  printf("PushFront: %d\n", value);

  node_t *new = new_node(value);

  // empty list before insertion
  if (is_empty(list)) {
    // head and tail will point to the node
    list->head = new;
    list->tail = new;
    // new node next will be null
    new->next = NULL;
    new->prev = NULL;
  } else {
    insert_before(list, list->head, value);
  }
}

void push_back(linked_list_t *list, int value) {
  printf("PushBack: %d\n", value);

  node_t *new = new_node(value);

  // empty list before insertion
  if (is_empty(list)) {
    // head and tail will point to the node
    list->head = new;
    list->tail = new;
    // new node prev will be null
    new->next = NULL;
    new->prev = NULL;
  } else {
    insert_after(list, list->tail, value);
  }
}

int pop(linked_list_t *list) {
  if (is_empty(list)) {
    printf("List is empty");
    return 0;
  }

  int value = list->head->data;
  printf("PopFront: %d\n", value);
  node_t *del = list->head;

  if (list->head == list->tail) { // only 1 element, update both head and tail
    list->head = NULL;
    list->tail = NULL;
  } else {
    // update the head to the next node
    list->head = list->head->next;
    list->head->prev = NULL;
  }
  free(del);
  return value;
}

int pop_back(linked_list_t *list) {
  if (is_empty(list)) {
    printf("List is empty");
    return 0;
  }

  int value = list->tail->data;
  printf("PopBack: %d\n", value);
  node_t *del = list->tail;

  if (list->head == list->tail) { // only 1 element, update both head and tail
    list->head = NULL;
    list->tail = NULL;
  } else {
    // update the tail to the previous node
    list->tail = list->tail->prev;
    list->tail->next = NULL;
  }

  free(del);
  return value;
}

void print_elements(const linked_list_t *list) {
  printf("Printing List:\n");
  if (is_empty(list)) {
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
  int value;
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
  value = pop(list);
  print_elements(list);
  value = pop_back(list);
  print_elements(list);
  value = pop_back(list);
  print_elements(list);
  value = pop(list);
  print_elements(list);
  push_back(list, 5);
  print_elements(list);
  value = pop_back(list);
  print_elements(list);
  destroy_list(list);
}
