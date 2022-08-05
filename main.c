#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "merge_sort.h"

int main() 
{

    int16_t arr[] = {9,5,1,3,2,4,7,9,8,4,1,3,5,7,9,1,2,3,5,7};
    uint16_t arrSize = sizeof(arr)/sizeof(arr[0]);

    MergeSort(arr, arrSize);

    for (int i = 0; i < arrSize; i++) {
     printf("%d,", arr[i]);   
    }

    return 0;

}




