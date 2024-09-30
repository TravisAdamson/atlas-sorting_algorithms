#include "sort.h"

/**
 * merge_sort - Sorts an array using the merge-sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	if (!array || size == 1)
		return;
	recursive_sort(array, 0, size - 1);
}

/**
 * recursive_sort - Recursivly divides and sorts array
 * @array: array to be split and sorted
 * @left: first index of array
 * @right: last index of array
*/
void recursive_sort(int *array, size_t left, size_t right)
{
	size_t mid = left + (right - left - 1) / 2;

	if (left < right)
	{
		recursive_sort(array, left, mid);
		recursive_sort(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

/**
 * merge - merges the sorted split arrays
 * @array: array to sort
 * @left: first index of array
 * @mid: middle index of array
 * @right: last index of array
*/
void merge(int *array, size_t left, size_t mid, size_t right)
{
	size_t left_size = mid - left + 1, right_size = right - mid;
	size_t i = 0, j = 0, index = left;
	int left_array[1024], right_array[1024];

	printf("Merging...\n");
	for (i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for (i = 0; i < right_size; i++)
		right_array[i] = array[mid + 1 + i];
	printf("[left]: ");
	print_array(left_array, left_size);
	printf("[right]: ");
	print_array(right_array, right_size);
	i = 0;
	for (; index <= right; index++)
	{
		if (i < left_size && (j >= right_size || left_array[i] <= right_array[j]))
		{
			array[index] = left_array[i];
			i++;
		}
		else
		{
			array[index] = right_array[i];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(&array[left], right - left + 1);
}
