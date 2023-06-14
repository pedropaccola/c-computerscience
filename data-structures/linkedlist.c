#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
  struct node *prev;
} node_t;

typedef struct LinkedList {
  node_t *head;
  node_t *tail;
} linked_list_t;

node_t *NewNode(int value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (!new_node) {
    printf("Failed to create Node");
    return NULL;
  }
  new_node->data = value;
  return new_node;
}

linked_list_t *NewLinkedList() {
  linked_list_t *list = (linked_list_t *)malloc(sizeof(linked_list_t));
  if (!list) {
    printf("Failed to create List");
    return NULL;
  }
  return list;
}

void PushFront(linked_list_t *list, int value) {
  printf("PushFront: %d\n", value);

  node_t *new_node = NewNode(value);
  new_node->prev = NULL;

  // empty list before insertion
  if (!list->head) {
    // head and tail will point to the node
    list->head = new_node;
    list->tail = new_node;
    // new node next will be null
    new_node->next = NULL;
  } else {
    // previous head node will point to the new node
    list->head->prev = new_node;
    // new node next will point to the head
    new_node->next = list->head;
    list->head = new_node; // update head
  }
}

void PushBack(linked_list_t *list, int value) {
  printf("PushBack: %d\n", value);

  node_t *new_node = NewNode(value);
  new_node->next = NULL;

  // empty list before insertion
  if (!list->tail) {
    // head and tail will point to the node
    list->head = new_node;
    list->tail = new_node;
    // new node prev will be null
    new_node->prev = NULL;
  } else {
    // previous tail node will point to the new node
    list->tail->next = new_node;
    // new node previous will point to the tail
    new_node->prev = list->tail;
    list->tail = new_node; // update tail
  }
}

void PopFront(linked_list_t *list) {
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
    list->head->prev = NULL;
    free(del); // delete node
  }
}

void PopBack(linked_list_t *list) {
  printf("PopBack: %d\n", list->tail->data);

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
    node_t *del = list->tail;
    // update the tail to the previous node
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    free(del); // delete node
  }
}

void AddAfter(linked_list_t *list, node_t *node, int value) {
  printf("Add after %d: %d\n", node->data, value);

  node_t *new_node = NewNode(value);
  new_node->next = node->next;
  new_node->prev = node;

  node->next = new_node;

  if (new_node->next != NULL) {
    // if there's a next node, update its prev pointer
    new_node->next->prev = new_node;
  }

  if (list->tail == node) {
    // if inserted after the last element, update tail
    list->tail = new_node;
  }
}

void AddBefore(linked_list_t *list, node_t *node, int value) {
  printf("Add before %d: %d\n", node->data, value);

  node_t *new_node = NewNode(value);
  new_node->next = node;
  new_node->prev = node->prev;

  node->prev = new_node;

  if (new_node->prev != NULL) {
    // if there's a previous node, update its next pointer
    new_node->prev->next = new_node;
  }

  if (list->head == node) {
    // if inserted before the first element, update head
    list->head = new_node;
  }
}

void PrintElements(linked_list_t *list) {
  printf("Printing List:\n");
  if (!list->head) {
    assert(list->head == NULL);
    assert(list->tail == NULL);
    printf("--No elements\n\n");
    return;
  }

  node_t *ptr;
  ptr = list->head;
  printf("--Head -> %d / Tail -> %d\n", list->head->data, list->tail->data);
  printf("--Elements: ");
  while (ptr) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n\n");
}

int main() {
  linked_list_t *list = NewLinkedList();
  PrintElements(list);
  PushFront(list, 1);
  PrintElements(list);
  PushBack(list, 2);
  PrintElements(list);
  PushFront(list, 3);
  PrintElements(list);
  PushBack(list, 4);
  PrintElements(list);
  PopFront(list);
  PrintElements(list);
  PopBack(list);
  PrintElements(list);
  PopBack(list);
  PrintElements(list);
  PopFront(list);
  PrintElements(list);
  PushBack(list, 5);
  PrintElements(list);
  PopBack(list);
  PrintElements(list);
}
