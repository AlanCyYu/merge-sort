#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "merge_sort_recursion.h"
#include "merge_sort_iteration.h"

void CheckFuntion(int16_t arr[], uint16_t arrSize);

int main() 
{
     int16_t arr[] = 
     {880, 1870, 1520, 0, 1540, 2020, 1420, 860, 2400, 1730, 730, 
     2340, 1750, 180, 330, 1140, 1310, 960, 2100, 200, 1630, 1730, 
     1710, 850, 890, 60, 1150, 2140, 1120, 2410, 690, 1040, 660, 
     1790, 1680, 2270, 1920, 2190, 1660, 1850, 1310, 2230, 1050, 
     1290, 700, 2270,1460, 430, 2100, 1370, 60, 2110, 670, 2120, 
     1270, 960, 620,1630, 1360, 2300, 1590, 1070, 1010, 2200, 1360, 
     1090, 460,2150, 750, 650, 1820, 1640, 1750, 1460, 170, 1980, 
     1260, 1890, 190, 50, 260, 1410, 2140, 1280, 70, 350, 2280, 860,
     2120, 1260, 250, 1480, 140, 320, 1970, 1040, 1130, 140, 250, 940};
     
     uint16_t arrSize = sizeof(arr)/sizeof(arr[0]);
     int16_t* arrT1, *arrT2;

     arrT1 = malloc(sizeof(arr));
     arrT2 = malloc(sizeof(arr));
     memcpy(arrT1, arr, sizeof(arr));
     memcpy(arrT2, arr, sizeof(arr));

     MergeSortRecursion(arrT1, arrSize);
     CheckFuntion(arrT1, arrSize);
     
     MergeSortIteration(arrT2, arrSize);
     CheckFuntion(arrT2, arrSize);

     for (int i = 0; i < arrSize; i++)
         printf("%d,", arrT1[i]);   
    
     printf("\n\n");

     return 0;

}


void CheckFuntion(int16_t arr[], uint16_t arrSize)
{
    for (uint16_t i = 1; i < arrSize; i++)
    {
        if (arr[i] < arr[i-1])
        {
            printf("Algorithm failed at index %d.\n", i);
            printf("%d, %d\n", arr[i-1], arr[i]);   
            return;
        }
    }
    printf("Algorithm succeed.\n");
    return;
}


/*

int16_t arr[] = {880, 1870, 1520, 00, 1540, 2020, 
1420, 860, 2400, 1730, 730, 2340, 1750, 180, 330, 1140, 
1310, 960, 2100, 200, 1630, 1730, 1710, 850, 890, 60, 
1150, 2140, 1120, 2410, 690, 1040, 660, 1790, 1680, 2270,
1920, 2190, 1660, 1850, 1310, 2230, 1050, 1290, 700, 2270,
1460, 430, 2100, 1370, 60, 2110, 670, 2120, 1270, 960, 620,
1630, 1360, 2300, 1590, 1070, 1010, 2200, 1360, 1090, 460,
2150, 750, 650, 1820, 1640, 1750, 1460, 170, 1980, 1260,
1890, 190, 50, 260, 1410, 2140, 1280, 70, 350, 2280, 860,
2120, 1260, 250, 1480, 140, 320, 1970, 1040, 1130, 140, 250, 940};

*/

