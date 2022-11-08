#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * using selection sort
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int min, tmp;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		idx = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (idx != i)
		{
			tmp = array[i];
			array[i] = min;
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
