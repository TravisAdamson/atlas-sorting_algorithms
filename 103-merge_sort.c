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
	size_t l_len = mid - left + 1, r_len = right - mid;
	size_t i = 0, j = 0, idx = left;
	int arr_l[1024], arr_r[1024];

	printf("Merging...\n");
	for (i = 0; i < l_len; i++)
		arr_l[i] = array[left + i];
	for (i = 0; i < r_len; i++)
		arr_r[i] = array[mid + 1 + i];
	printf("[left]: "), print_array(arr_l, l_len);
	printf("[right]: "), print_array(arr_r, r_len);
	i = 0;
	for (; idx <= right; idx++)
	{
		if (i < l_len && (j >= r_len || arr_l[i] <= arr_r[j]))
		{
			array[idx] = arr_l[i];
			i++;
		}
		else
		{
			array[idx] = arr_r[j];
			j++;
		}
	}
	printf("[Done]: "), print_array(&array[left], right - left + 1);
}
