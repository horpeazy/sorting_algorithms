#include "sort.h"
#include <stdio.h>

/**
 * recursive_quick_sort - sorts an array recursively using quick sort
 * @array: array to sort
 * @low: lower index of array
 * @high: higher index of array
 * @size: size of array
 * Return: int
 */
int recursive_quick_sort(int *array, size_t size, size_t low, size_t high)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);
		if (pi > 0)
			recursive_quick_sort(array, size, low, pi - 1);
		if (pi < size - 1)
			recursive_quick_sort(array, size,  pi + 1, high);
	}

	return (0);
}

/**
 * partition - partitions an array
 * @array: array to partition
 * @low: lower of index of array
 * @high: higher index of array
 * @size: size of array
 * Return: index of the pivot
 */
size_t partition(int *array, size_t size, size_t low, size_t high)
{
	size_t i, j;
	int pivot, tmp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
/**
 * quick_sort - sorts an array using quick sort
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	recursive_quick_sort(array, size, 0, size - 1);
}
