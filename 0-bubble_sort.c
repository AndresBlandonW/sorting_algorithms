#include "sort.h"

/**
 * bubble_sort - sorts an array of integers
 * @array: the array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
