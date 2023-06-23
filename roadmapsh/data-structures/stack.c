#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
// STACK
//

typedef struct stack {
  size_t top;
  size_t capacity;
  int *elements;
} stack_t;

stack_t *new_stack(size_t capacity) {
  stack_t *stack = malloc(sizeof(stack_t));
  if (!stack) {
    printf("Failed to create stack");
    exit(EXIT_FAILURE);
  }
  stack->top = 0;
  stack->capacity = capacity;
  stack->elements = malloc(sizeof(int) * capacity);
  if (!stack->elements) {
    printf("Failed to create stack");
    free(stack);
    exit(EXIT_FAILURE);
  }
  return stack;
}

void destroy_stack(stack_t *stack) {
  free(stack->elements);
  free(stack);
  return;
}

bool is_empty(const stack_t *stack) { return stack->top == 0; }

bool is_full(const stack_t *stack) { return stack->top == stack->capacity; }

int peek(const stack_t *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return 0;
  }

  return stack->elements[stack->top - 1];
  // OR:
  // int *ptr = stack->elements;
  // return *(ptr + stack->top);
}

void push(stack_t *stack, int value) {
  printf("Push element %d\n", value);

  if (is_full(stack)) {
    printf("Stack is full\n");
    return;
  }
  stack->elements[stack->top] = value;
  stack->top++;
  // OR:
  // int *ptr = stack->elements;
  // *(ptr + stack->top) = value;
}

int pop(stack_t *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty\n");
    return 0;
  }

  stack->top--;
  int popped_element = stack->elements[stack->top];
  stack->elements[stack->top] = 0;
  printf("Pop element %d\n", popped_element);
  // OR:
  // int *ptr = stack->elements;
  // printf("Pop element %d\n", *(ptr + stack->top));
  // *(ptr + stack->top) = 0;
  return popped_element;
}

void print_stack(const stack_t *stack) {
  printf("top: %zu, elements: ", stack->top);

  for (size_t i = 0; i < stack->top; i++) {
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
  destroy_stack(stack);
}
