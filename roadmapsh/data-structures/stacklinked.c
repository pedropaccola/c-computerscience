#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
// STACK W/ LINKED LISTS
//

typedef struct node_t {
  int data;
  struct node_t *next;
} node_t;

typedef struct stack_t {
  node_t *head;
} stack_t;

node_t *new_node(int value) {
  node_t *new = malloc(sizeof(node_t));
  if (!new) {
    printf("Failed to create Node");
    exit(EXIT_FAILURE);
  }
  new->data = value;
  new->next = NULL;
  return new;
}

stack_t *new_stack() {
  stack_t *stack = malloc(sizeof(stack_t));
  if (!stack) {
    printf("Failed to create Stack");
    exit(EXIT_FAILURE);
  }
  stack->head = NULL;
  return stack;
}

void destroy_stack(stack_t *stack) {
  node_t *ptr = stack->head;
  while (ptr) {
    node_t *temp = ptr;
    ptr = ptr->next;
    free(temp);
  }
  free(stack);
  return;
}

bool is_empty(const stack_t *stack) { return (!stack->head); }

int peek(const stack_t *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return 0;
  }

  return stack->head->data;
}

void push(stack_t *stack, int value) {
  printf("Push element %d\n", value);

  node_t *new = new_node(value);

  new->next = stack->head;
  stack->head = new;
}

int pop(stack_t *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return 0;
  }

  int value = stack->head->data;
  printf("Pop element %d\n", value);
  node_t *del = stack->head;
  stack->head = stack->head->next;
  free(del);
  return value;
}

void print_stack(const stack_t *stack) {
  printf("Printing stack:\n");
  if (is_empty(stack)) {
    printf("--No elements\n\n");
    return;
  }

  printf("top: %d, elements: ", stack->head->data);
  node_t *ptr = stack->head;
  while (ptr) {
    printf("%d, ", ptr->data);
    ptr = ptr->next;
  }

  printf("\n\n");
}

int main() {
  int capacity = 10;
  stack_t *stack = new_stack();
  print_stack(stack);
  for (int i = 0; i <= capacity; i++) {
    push(stack, i * 2);
    print_stack(stack);
  }
  int top_element = peek(stack);
  printf("Peeking %d\n", top_element);
  for (int i = 0; i <= capacity; i++) {
    top_element = pop(stack);
    print_stack(stack);
  }
  destroy_stack(stack);
}
