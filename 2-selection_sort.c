#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an array using the Selection sort
 * @array: the array to sort
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, select, tmp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		select = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[select])
			{
				select = j;
			}
		}
		if (i != select)
		{
			tmp = array[i];
			array[i] = array[select];
			array[select] = tmp;
			print_array(array, size);
		}
	}
}
