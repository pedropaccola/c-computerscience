#include <stdio.h>
#include <stdlib.h>

//
// ARRAY
//

typedef struct Custom_Int_Array {
  int *array;
  int capacity;
} int_array;

int_array *new_int_array(int capacity) {
  int_array *ptr = (int_array *)malloc(sizeof(int_array));
  if (!ptr) {
    printf("Failed to initialize array struct\n");
    return NULL;
  }
  ptr->array = (int *)malloc(sizeof(int) * capacity);
  if (!ptr->array) {
    printf("%s\n", "Failed to initialize array");
    return NULL;
  }
  ptr->capacity = capacity;
  return ptr;
}

void update_element_at_index(int_array *arr, int element, int index) {
  if (index < 0 || index >= arr->capacity) {
    printf("%s\n", "Index out of bounds");
  }
  int *ptr = arr->array;
  *(ptr + index) = element;
  // or arr->array[index] = element;
}

void destroy_array(int_array *arr) {
  free(arr->array);
  free(arr);
}

int main() {
  printf("Arrays in C\n");

  int capacity = 5;

  int_array *array = new_int_array(capacity);
  printf("array address %p\n", array);

  for (int i = 0; i < capacity; i++) {
    update_element_at_index(array, i + 1, i);
    // or array->array[i] = i + 1;
    printf("%dth element: %d\n", i, *(array->array + i));
    // or printf("%dth element: %d", i, array->array[i]);
  }

  destroy_array(array);
  printf("-------------");
}
