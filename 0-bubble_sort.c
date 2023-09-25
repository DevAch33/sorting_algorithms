#include "sort.h"

/**
  * bubble_sort - Sorts an array of int in ascending
  * order using Bubble sort algorithm.
  *
  * @array: array of int to sort
  * @size: size of the array of int
  *
  * Return: Nothing
  */

void bubble_sort(int *array, size_t size)
{
    int temp;
    size_t i, k;
    bool swapped;

    if (!array || !size)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (k = 0; k < size - i - 1; k++)
        {
            if (array[k] > array[k + 1])
            {
                temp = array[k];
                array[k] = array[k + 1];
                array[k + 1] = temp;
                swapped = true;
                print_array(array, size);
            }
        }
        if (!swapped)
            break; // Array is already sorted
    }
}
