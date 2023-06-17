#include <assert.h>
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
  node_t *new = (node_t *)malloc(sizeof(node_t));
  if (!new) {
    printf("Failed to create Node");
    return NULL;
  }
  new->data = value;
  return new;
}

stack_t *new_stack() {
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  if (!stack) {
    printf("Failed to create Stack");
  }
  stack->head = NULL;
  return stack;
}

void push(stack_t *stack, int value) {
  printf("Push element %d\n", value);

  node_t *new = new_node(value);

  new->next = stack->head;
  stack->head = new;
}

int pop(stack_t *stack) {
  if (!stack->head) {
    printf("Stack is empty\n");
    return 0;
  }

  printf("Pop element %d\n", stack->head->data);
  int value = stack->head->data;
  node_t *del = stack->head;
  stack->head = stack->head->next;
  free(del);
  return value;
}

int peek(stack_t *stack) {
  if (!stack->head) {
    printf("Stack is empty\n");
    return 0;
  }

  return stack->head->data;
}

void print_stack(stack_t *stack) {
  printf("Printing stack:\n");
  if (!stack->head) {
    assert(stack->head == NULL);
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
}
