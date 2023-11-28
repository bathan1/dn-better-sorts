#include "dn_sorts.h"
#include <stdlib.h>
#include <stdio.h>

int* merge(int* left, int* right, int left_size, int right_size) {
  int* merged = (int*) malloc((left_size + right_size) * sizeof(int));
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < left_size && j < right_size) {
    if (left[i] < right[j]) {
      merged[k] = left[i];
      i++;
    } else {
      merged[k] = right[j];
      j++;
    }
    k++;
  }

  if (i == left_size) {
    for (; j < right_size; j++) {
      merged[k] = right[j];
      k++;
    }
  } else {
    for (; i < left_size; i++) {
      merged[k] = left[i];
      k++;
    }
  }
  return merged;
}

int* merge_sort(int* data, int length) {
  if (length == 1) {
    return data;
  }

  int mid = length / 2;

  int* left = merge_sort(data, mid);
  int* right = merge_sort(data + mid, length - mid);

  return merge(left, right, mid, length - mid);
}

