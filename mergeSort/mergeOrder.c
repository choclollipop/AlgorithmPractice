#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE8 8
#define BUFFER_SIZE5 5

int * bubbleSort(int * ptr, int size)
{
    /* 冒泡排序 */
    for(int idx = 0; idx < size; idx++)
    {
        for(int pos = 0; pos < size - 1 - idx; pos++)
        {
            if(ptr[pos] > ptr[pos + 1])
            {
                int temp = ptr[pos];
                ptr[pos] = ptr[pos + 1];
                ptr[pos + 1] = temp;
            }
        }
    }

    return ptr;
}

int * mergeOrder(int * num1, int num1Size, int * num2, int num2Size, int * newNumSize)
{
    int * newNum = (int *)malloc(sizeof(int) * (*newNumSize));
    if(!newNum)
    {
        return 0;
    }
    /* 拼接字符串 */
    for(int idx = 0; idx < num1Size; idx++)
    {
        newNum[idx] = num1[idx];
    }

    for(int idx = 0; idx < num2Size; idx++)
    {
        newNum[idx + num1Size] = num2[idx];
    }

    /* 打印拼接好的数组 */
    for(int idx = 0; idx < *newNumSize; idx++)
    {
        printf("%d ", newNum[idx]);
    }

    printf("\n");

    newNum = bubbleSort(newNum, *newNumSize);
    
    return newNum;
}

int main()
{
    int num[BUFFER_SIZE8] = {1, 1, 2, 3, 3, 5, 7, 19};
    int nums[BUFFER_SIZE5] = {2, 7, 9, 12, 17};
    int newNumSize = BUFFER_SIZE5 + BUFFER_SIZE8;

    int * newNum = mergeOrder(num, BUFFER_SIZE8, nums, BUFFER_SIZE5, &newNumSize);

    for(int idx = 0; idx < newNumSize; idx++)
    {
        printf("%d ", newNum[idx]);
    }

    printf("\n");

    return 0;
}