#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack {
  int top;
  int capacity;
  int *elements;
} stack_t;

stack_t *NewStack(int capacity) {
  stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
  stack->top = -1;
  stack->capacity = capacity;
  stack->elements = (int *)malloc(sizeof(int) * capacity);
  return stack;
}

bool IsEmpty(stack_t *stack) { return stack->top == -1; }

bool IsFull(stack_t *stack) {
  int top = stack->top + 1;
  return top == stack->capacity;
}

void Push(stack_t *stack, int value) {
  printf("Push element %d\n", value);

  if (IsFull(stack)) {
    printf("Stack is full\n");
    return;
  }
  stack->top++;

  stack->elements[stack->top] = value;
  // OR:
  // int *ptr = stack->elements;
  // *(ptr + stack->top) = value;
}

void Pop(stack_t *stack) {
  if (IsEmpty(stack)) {
    printf("Stack is empty\n");
    return;
  }

  printf("Pop element %d\n", stack->elements[stack->top]);
  stack->elements[stack->top] = 0;
  // OR:
  // int *ptr = stack->elements;
  // printf("Pop element %d\n", *(ptr + stack->top));
  // *(ptr + stack->top) = 0;
  stack->top--;
}

int Peek(stack_t *stack) {
  if (IsEmpty(stack)) {
    printf("Stack is empty\n");
    return -1;
  }

  return stack->elements[stack->top];
  // OR:
  // int *ptr = stack->elements;
  // return *(ptr + stack->top);
}

void PrintStack(stack_t *stack) {
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
  stack_t *stack = NewStack(capacity);
  PrintStack(stack);
  for (int i = 0; i <= capacity; i++) {
    Push(stack, i * 2);
    PrintStack(stack);
  }
  int peek = Peek(stack);
  printf("Peeking %d\n", peek);
  for (int i = 0; i <= capacity; i++) {
    Pop(stack);
    PrintStack(stack);
  }
}
