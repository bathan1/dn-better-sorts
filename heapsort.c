#include "dn_sorts.h"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Helper function declarations
void swap(int* data, int i, int j);
void premove(int* data, int num_nodes, bool is_asc); 
void maxsink(int* data, int index, int num_nodes);
void maxheapify(int* data, int num_nodes);
void minsink(int* data, int index, int num_nodes);
void minheapify(int* data, int num_nodes);

void swap(int data[], int i, int j) {
  int temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

void premove(int data[], int num_nodes, bool is_asc) {
  swap(data, 0, num_nodes - 1); 
  // After we swap, the 'total' number of nodes decreases by 1 because we don't want to have our sorted portion be apart of the sink. 
  if (is_asc) {
    maxsink(data, 0, num_nodes - 1); 
  } else {
    minsink(data, 0, num_nodes - 1);
  }
}

void maxsink(int data[], int index, int num_nodes) {
  int left_index = (2 * index) + 1;
  int right_index = (2 * index) + 2;

  if (right_index < num_nodes) {
    int max;

    if (data[left_index] > data[right_index]) {
      max = left_index;
    } else {
      max = right_index;
    }

    if (data[index] < data[max]) {
      swap(data, index, max);
      maxsink(data, max, num_nodes);
    }
  } else if (left_index < num_nodes) {
    if (data[left_index] > data[index]) {
      swap(data, index, left_index);
      maxsink(data, left_index, num_nodes);
    }
  } else {
    return;
  }
}

void minsink(int data[], int index, int num_nodes) {
  int left_index = (2 * index) + 1;
  int right_index = (2 * index) + 2;

  if (right_index < num_nodes) {
    int min;

    if (data[left_index] < data[right_index]) {
      min = left_index;
    } else {
      min = right_index;
    }

    if (data[index] > data[min]) {
      swap(data, index, min);
      minsink(data, min, num_nodes);
    }
  } else if (left_index < num_nodes) {
    if (data[left_index] < data[index]) {
      swap(data, index, left_index);
      minsink(data, left_index, num_nodes);
    }
  } else {
    return;
  }
}

void minheapify(int data[], int num_nodes) {
  int numleaves = ceil(num_nodes / 2);

  for (int i = num_nodes - numleaves - 1; i > -1; i--) {
    minsink(data, i, num_nodes);
  }
}

void maxheapify(int data[], int num_nodes) {
  int numleaves = ceil(num_nodes / 2);

  for (int i = num_nodes - numleaves - 1; i > -1; i--) {
    maxsink(data, i, num_nodes);
  }
}

void asc_heapsort(int data[], int num_nodes) {
  maxheapify(data, num_nodes);

  for (int i = 0; i < num_nodes - 1; i++) {
    premove(data, num_nodes - i, true);
  }
}

void desc_heapsort(int data[], int num_nodes) {
  minheapify(data, num_nodes);

  for (int i = 0; i < num_nodes - 1; i++) {
    premove(data, num_nodes - i, false);
  }
}
