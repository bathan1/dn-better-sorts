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
  int length = 50;
  int* arr = genarr(length);

  printf("Array before merge_sort:\n");
  printarr(arr, length); 

  int* merged = merge_sort(arr, length);

  printf("Array after merge_sort:\n");
  printarr(merged, length);

  return 0;
}
