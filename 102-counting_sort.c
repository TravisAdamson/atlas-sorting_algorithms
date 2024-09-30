#include "sort.h"

/**
 * counting_sort - Implements a Count Sort
 * @array: array to sort
 * @size: size of array
*/
void counting_sort(int *array, size_t size)
{
	int high = 0, *sorting, *result;
	size_t i;

	if (!array || !size || size == 1)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > high)
			high = array[i];
	}
	sorting = calloc(high + 1, sizeof(int));
	if (!sorting)
		return;
	for (i = 0; i < size; i++)
		sorting[array[i]]++;
	for (i = 1; i < (size_t)high + i; i++)
		sorting[i] += sorting[i - 1];
	print_array(sorting, (size_t)high + 1);
	result = calloc(size, sizeof(int));
	if (!result)
		return;
	for (i = 0; i < size; i++)
	{
		result[sorting[array[i]] - 1] = array[i];
		sorting[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = result[i];
	free(sorting);
	free(result);
}
