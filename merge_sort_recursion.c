#include "merge_sort_recursion.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

static void SortTwoArray(int16_t* arrIn, uint16_t arrSize1, uint16_t arrSize2);

void MergeSortRecursion(int16_t* arr, uint16_t arrSize)
{
    uint16_t size1, size2;

    if (arrSize <= 1)
        return;
        
    size1 = arrSize/2;
    size2 = arrSize - size1;
    
    MergeSortRecursion(arr, size1);
    MergeSortRecursion(arr+size1, size2);
    SortTwoArray(arr, size1, size2);
}


static void SortTwoArray(int16_t* arrIn, uint16_t arrSize1, uint16_t arrSize2)
{
    int16_t arrTemp[128];
    int16_t* p = arrTemp;
    int16_t i1 = 0, i2 = 0;
    int16_t* arr1 = arrIn;
    int16_t* arr2 = arrIn + arrSize1;
    
    while ((i1 < arrSize1) && (i2 < arrSize2))
    {
        if (arr1[i1] < arr2[i2])
        {
            *p++ = arr1[i1++];
        }
        else
        {
            *p++ = arr2[i2++];
        }
    }

    while (i1 < arrSize1)
    {
        *p++ = arr1[i1++];
    }

    while (i2 < arrSize2)
    {
        *p++ = arr2[i2++];
    }

    for (uint8_t i = 0; i < (arrSize1+arrSize2); i++)
    {
        arrIn[i] = arrTemp[i];
    }
}


