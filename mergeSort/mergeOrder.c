#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE8 8
#define BUFFER_SIZE5 5

/* 将两个不连续有序递增数组合并到一起，一边合并一边排序 */
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
    int pos = 0, sub = 0;
    if(!newNum)
    {
        return 0;
    }

    /* 一边排序一边插入到新的数组 */
    for(int idx = 0; idx < *newNumSize; idx++)
    {
        if(num2[pos] < num1[sub])
        {
            /* 进入if语句中表示数组2 来到了最后，则直接将数组1的值依次赋值给新数组 */
            if(num2Size == pos)
            {
                pos = num2Size - 1;
                newNum[idx] = num1[sub];
                sub++;
            }
            else
            {
                newNum[idx] = num2[pos];
                pos++;
            }
        }
        else
        {
            newNum[idx] = num1[sub];
            sub++;
        }
    }

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