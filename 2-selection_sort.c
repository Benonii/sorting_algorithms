#include "sort.h"

/**
 * selection_sort - sorts an array of integers using the selection algorithm.
 * @array: The array to be sorted
 * @size: The size of @array
 *
 * Return: None
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int min_value, temp, swap = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min_value = array[i];
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min_value)
			{
				min_index = j;
				min_value = array[j];
				swap = 1;
			}
		}

		if (min_index != i)
		{
			temp = array[i];
			array[i] = min_value;
			array[min_index] = temp;
		}
		array[i] = min_value;

		if (swap == 1)
			print_array(array, size);
	}
}
