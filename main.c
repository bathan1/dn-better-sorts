#include <stdio.h>
#include <math.h>

void printarr(int arr[], size_t length) {
  printf("{ ");
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf("}\n");
}

void maxsink(int data[], int index, int num_nodes);

void swap(int data[], int i, int j) {
  int temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

void premove(int data[], int index, int num_nodes) {
  swap(data, index, num_nodes - 1); 
  maxsink(data, 0, num_nodes - 1); //After we swap, the 'total' number of nodes decreases by 1 because we don't want to have our sorted portion be apart of the sink. 
}

void maxheapify(int data[], int num_nodes) {
  int numleaves = ceil(num_nodes / 2);

  for (int i = num_nodes - numleaves - 1; i > -1; i--) {
    maxsink(data, i, num_nodes);
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

void asc_heapsort(int data[], int num_nodes) {
  maxheapify(data, num_nodes);

  for (int i = 0; i < num_nodes; i++) {
    premove(data, 0, num_nodes - i);
  }
}

int main() {
  int arr[] = {8, 3, 2, 7, 9, 4};
  int num_nodes = sizeof(arr) / sizeof(arr[0]);
  printf("Array before heapsort:\n");
  printarr(arr, num_nodes);  
  
  asc_heapsort(arr, num_nodes);

  printf("Array after heapify:\n");
  printarr(arr, num_nodes);

  printf("Array after heapsort:\n");
  printarr(arr, num_nodes);
  return 0;
}
