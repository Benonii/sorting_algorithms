#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using the bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Retrun: None
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp, swap;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		swap = 0;
		for (j = 0; j < size; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap++;
			}
		}
		print_array(array, size);
		if (swap == 0)
			break;
	}
}
