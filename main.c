#include "dn_sorts.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void printarr(int arr[], size_t length) {
  printf("{ ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("}\n");
}

int* genarr(size_t length) {
  int* arr_ptr = malloc(length * sizeof(int));

  for (int i = 0; i < length; i++) {
    *(arr_ptr + i) = rand() % 1000;
  }
  return arr_ptr;
}

int main() {
  srand(time(NULL));
  int* arr = genarr(50);
  int num_nodes = 50;

  printf("Array before ascending heapsort:\n");
  printarr(arr, num_nodes);  
  
  asc_heapsort(arr, num_nodes);

  printf("Array after ascending heapsort:\n");
  printarr(arr, num_nodes);
  
  printf("\n");

  int* arr2 = genarr(50);
  printf("Array before descending heapsort:\n");
  printarr(arr2, num_nodes);

  desc_heapsort(arr2, num_nodes);

  printf("Array after descending heapsort:\n");
  printarr(arr2, num_nodes);

  return 0;
}
