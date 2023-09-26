#include "sort.h"
/**
 * swap - Swap 2 integers in an array.
 * @array: int array to sort
 * @size: size of array
 * @s1: first int to swap.
 * @s2: second int to swap.
 */
void swap(int *array, size_t size, int *s1, int *s2)
{
	if (*s1 != *s2)
	{
		*s1 = *s1 + *s2;
		*s2 = *s1 - *s2;
		*s1 = *s1 - *s2;
		print_array((const int *)array, size);
	}
}

/**
 * lomuto_partition - the partitions array
 * @array: Array of int.
 * @size: Size of array.
 * @low: Starting index of the subset to order.
 * @high: Ending index of the subset to order.
 *
 * Return: The index size_t.
 */
int lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quicksort - Quicksorts using lomuto partitioning scheme.
 * @array: An array of integers.
 * @size: Size of the array.
 * @low: Starting index of the subset to order.
 * @high: Ending index of the subset to order.
 *
 * Return: viod
 */

void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t p = lomuto_partition(array, size, low, high);

		quicksort(array, size, low, p - 1);
		quicksort(array, size, p + 1, high);
	}
}

/**
 * quick_sort - Calls the quicksort
 * @array : An array of integers.
 * @size: Size of the array.
 *
 * Return: viod
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
