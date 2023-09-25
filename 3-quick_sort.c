#include "sort.h"

/**
 * partition - divides the array and returns the pivot index
 * @array: The array to be sorted
 * @low: The lower bound of the array
 * @high: The upper bound of the array
 * @size: Size of @array
 *
 * Return: The pivot index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * recursive_call - Handles the recursion of quick_sort
 * @array: The array to sort
 * @lower: The lower bound of the array
 * @upper: The upper bound of the array
 * @size: Size of @array
 *
 * Return: None
 */

void recursive_call(int *array, int lower, int upper, size_t size)
{
	int pivot;

	if (lower < upper)
	{
		pivot = partition(array, lower, upper, size);
		recursive_call(array, lower, pivot - 1, size);
		recursive_call(array, pivot + 1, upper, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the quick sort algorithm
 * @array: The array to be sorted
 * @size: size of @array
 *
 * Return: None
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_call(array, 0, size - 1, size);
}
