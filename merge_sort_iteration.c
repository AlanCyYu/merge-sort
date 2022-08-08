#include "merge_sort_iteration.h"

#include <stdint.h>

static void SortTwoArray(int16_t* arrIn, uint16_t arrSize1, uint16_t arrSize2);

void MergeSortIteration(int16_t* arr, uint16_t arrSize)
{
    uint16_t i,arrSize2, mergeSize = 1;
    uint16_t lastLoop = 0;
    
    while (1)
    {
        for (i = 0; (i+mergeSize) < arrSize; i+=(mergeSize*2))
        {
            if ((i+(mergeSize*2)) >= arrSize)
            {
                arrSize2 = arrSize - (i+mergeSize);
            }
            else 
            {
                arrSize2 = mergeSize;
            }
            
            SortTwoArray(&arr[i], mergeSize,  arrSize2);
        }
        
        mergeSize*=2;

        if (lastLoop == 1)
        {
            break;
        }
        else if ((mergeSize*2) >= arrSize)
        {
            lastLoop = 1;
        }
    }
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
            *p = arr1[i1];
            i1++;
        }
        else
        {
            *p = arr2[i2];
            i2++;
        }
        
        p++;
    }

    if (i1 == arrSize1)
    {
        for ( ; i2 < arrSize2; i2++)
        {
            *p = arr2[i2];
            p++;
        }
    }
    else
    {
        for ( ; i1 < arrSize1; i1++)
        {
            *p = arr1[i1];
            p++;
        }
    }

    for (uint8_t i = 0; i < (arrSize1+arrSize2); i++)
    {
        arrIn[i] = arrTemp[i];
    }
}



