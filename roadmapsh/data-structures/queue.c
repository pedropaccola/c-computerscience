#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//
// CIRCULAR QUEUE
//

#define MAX_QUEUE_SIZE 10

// Without using a size control variable, the empty/full states can be
// controlled only with the front and rear pointers, however the effective queue
// size will be N-1 (check is_full function). In order to utilize the whole size
// N, a size pointer must be utilized.
// Commented code uses the size variable.
typedef struct queue {
  size_t front;
  size_t rear;
  // int size;
  int elements[MAX_QUEUE_SIZE];
} queue_t;

queue_t *new_queue() {
  queue_t *queue = malloc(sizeof(queue_t));
  if (!queue) {
    printf("Could not create queue");
    exit(EXIT_FAILURE);
  }
  queue->front = 0;
  queue->rear = 0;
  // queue->size = 0;
  return queue;
}

void destroy_queue(queue_t *queue) { free(queue); }

// bool is_empty(const queue_t *queue) { return queue->size == 0; }
//
// bool is_full(const queue_t *queue) { return queue->size == MAX_QUEUE_SIZE; }

bool is_empty(const queue_t *queue) { return queue->front == queue->rear; }

bool is_full(const queue_t *queue) {
  return (queue->rear + 1) % MAX_QUEUE_SIZE == queue->front;
}

void enqueue(queue_t *queue, int value) {
  if (is_full(queue)) {
    printf("Can't enqueue, queue is full\n");
    return;
  }

  printf("Enqueuing %d\n", value);
  queue->elements[queue->rear] = value;

  queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
  // queue->size++;
  return;
}

int dequeue(queue_t *queue) {
  if (is_empty(queue)) {
    printf("Can't dequeue, queue is empty\n");
    return 0;
  }

  int value = queue->elements[queue->front];
  printf("Dequeuing %d\n", value);
  queue->elements[queue->front] = -1;

  queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
  // queue->size--;
  return value;
}

void print_queue(const queue_t *queue) {
  if (is_full(queue)) {
    printf("Queue is Full\n");
  }
  if (is_empty(queue)) {
    printf("Queue is Empty\n");
  }
  // printf("Size: %d,Front index: %zu, Rear index: %zu\n", queue->size,
  //        queue->front, queue->rear);
  printf("Front index: %zu, Rear index: %zu\n", queue->front, queue->rear);
  printf("Elements: ");
  for (size_t i = 0; i < MAX_QUEUE_SIZE; i++) {
    printf("%d, ", queue->elements[i]);
  }
  printf("\n\n");
}

int main() {
  queue_t *queue = new_queue();
  int value;
  print_queue(queue);

  // Queue 10, test full, dequeue 10, test empty
  for (size_t i = 0; i < MAX_QUEUE_SIZE; i++) {
    enqueue(queue, (i + 1) * 2);
    print_queue(queue);
  }
  enqueue(queue, 1000);
  print_queue(queue);
  for (size_t i = 0; i < MAX_QUEUE_SIZE; i++) {
    value = dequeue(queue);
    print_queue(queue);
  }
  dequeue(queue);
  print_queue(queue);

  // Queue 3, dequeue 2, 7 times
  printf("\n\nTESTING CIRCULARITY\n\n");
  for (int i = 0; i < 7; i++) {
    for (size_t i = 0; i < 3; i++) {
      enqueue(queue, (i + 1) * 2);
      print_queue(queue);
    }
    for (size_t i = 0; i < 2; i++) {
      value = dequeue(queue);
      print_queue(queue);
    }
  }
}
