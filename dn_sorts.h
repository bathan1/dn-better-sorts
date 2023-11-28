#include <stdbool.h>

#ifndef DN_SORTS_H
#define DN_SORTS_H

/**
 * Heapsort in ascending order.
 * @param data the array to sort.
 * @param num_nodes the number of elements in the array.
 */
void asc_heapsort(int* data, int num_nodes);

/**
 * Heapsort in descending order.
 * @param data the array to sort.
 * @param num_nodes the number of elements in the array.
 */
void desc_heapsort(int* data, int num_nodes);

/**
 * Merge sort in ascending order.
 * @param data the array to sort.
 * @param num_nodes the number of elements in the array.
 * @return the pointer to the sorted array.
 */
int* merge_sort(int* data, int length);

#endif
