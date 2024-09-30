#include "sort.h"

/**
 * shell_sort -  implementation of a shell sort algorithm
 * @array: array to sort
 * @size: size of array
*/
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp;

	if (!array || !size)
		return;
	while (gap < size)
		gap = (3 * gap + 1);

	for (gap /= 3; gap >= 1; gap = gap / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap; j -= gap)
			{
				if (temp <= array[j - gap])
					array[j] = array[j - gap];
				else
					break;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
