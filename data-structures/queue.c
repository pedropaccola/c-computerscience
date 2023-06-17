#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
// QUEUE
//

#define MAX_QUEUE_SIZE 10

typedef struct queue {
  int front;
  int rear;
  int elements[MAX_QUEUE_SIZE];
} queue_t;

queue_t *new_queue(int capacity) {
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  stack->top = -1;
  stack->capacity = capacity;
  stack->elements = (int *)malloc(sizeof(int) * capacity);
  return stack;
}

bool is_empty(stack_t *stack) { return stack->top == -1; }

bool is_full(stack_t *stack) {
  int top = stack->top + 1;
  return top == stack->capacity;
}

void push(stack_t *stack, int value) {
  printf("Push element %d\n", value);

  if (is_full(stack)) {
    printf("Stack is full\n");
    return;
  }
  stack->top++;

  stack->elements[stack->top] = value;
  // OR:
  // int *ptr = stack->elements;
  // *(ptr + stack->top) = value;
}

int pop(stack_t *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return 0;
  }

  printf("Pop element %d\n", stack->elements[stack->top]);
  return stack->elements[stack->top];
  stack->elements[stack->top] = 0;
  // OR:
  // int *ptr = stack->elements;
  // printf("Pop element %d\n", *(ptr + stack->top));
  // *(ptr + stack->top) = 0;
  stack->top--;
}

int peek(stack_t *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return 0;
  }

  return stack->elements[stack->top];
  // OR:
  // int *ptr = stack->elements;
  // return *(ptr + stack->top);
}

void print_stack(stack_t *stack) {
  printf("top: %d, elements: ", stack->top);

  for (int i = 0; i <= stack->top; i++) {
    printf("%d, ", stack->elements[i]);
    // OR:
    // printf("%d, ", *(stack->elements + i));
  }

  printf("\n\n");
}

int main() {
  int capacity = 10;
  stack_t *stack = new_stack(capacity);
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
