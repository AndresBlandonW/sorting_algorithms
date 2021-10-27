#include "sort.h"

/**
 * quick_sort - sorts an array using the quick_sort
 * @array: the array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t i;

	if (size < 2 || array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			quickSort(array, size, 0, (int)(size - 1));
		}
	}
}

/**
 * quickSort - the quickSort
 * @array: array to sort
 * @size: size of array
 * @low: start of sub-array
 * @high: end of sub-array
 */
void quickSort(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);

		quickSort(array, size, low, pi - 1);
		quickSort(array, size, pi + 1, high);
	}
}

/**
 * partition - Lomuto partition scheme
 * @array: array
 * @size: size array
 * @low: start of sub-array
 * @high: end of sub-array
 *
 * Return: index of pivot
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
