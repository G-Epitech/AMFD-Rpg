/*
** EPITECH PROJECT, 2022
** my_sort_int_array.c
** File description:
** Day 04, Task 06
*/

#include "include/my.h"

static void sort_array(int min_nb, int x, int size, int *array)
{
    int addr = 0;

    for (int y = x + 1; y < size; y++) {
        addr = x;
        if (*(array + y) < min_nb) {
            min_nb = *(array + y);
            addr = y;
        }
        my_swap(array + addr, array + x);
    }
}

void my_sort_int_array(int *array , int size)
{
    int min_nb = 0;

    for (int x = 0; x < size - 1; x++) {
        min_nb = *(array + x);
        sort_array(min_nb, x, size, array);
    }

}
