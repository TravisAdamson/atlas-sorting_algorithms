#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t s);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort2(int *array, int low, int high, size_t size);
int high_low(int *array, size_t size, int h_l);
void swap_elem(int *arr_a, int *arr_b);
int make_partition(int *array, int low, int high, size_t size);

#endif
