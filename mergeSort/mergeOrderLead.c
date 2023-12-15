#include <stdio.h>

int * mergeOrder(int * num1, int num1Size, int *num2, int num2Size, int *newSize)
{
    int pos = 0;
    int idx1 = 0;
    int idx2 = 0;
    int *newArray = (int *)malloc(sizeof(int) * (*newSize));
    if(!newArray)
    {
        return NULL;
    }

    /* 两个数组都没有走到最后的时候我们进行排序合并
       若有一个走到最后，且放置最后一个数值完毕，则直接将另一个数组剩余的数值按位填充即可
    */
    while(idx1 < num1Size && idx2 < num2Size)
    {
        /* todo ...... */
    }

    return 0;
}

int main()
{
    int num1[] = {1, 1, 2, 15, 67};
    int num2[] = {1, 2, 2, 7, 19, 156, 231};

    int num1Size = sizeof(num1) / sizeof(int);
    int num2Size = sizeof(num2) / sizeof(int);

    int newNumSize = 0;

    int * newArray = mergeOrder(num1, num1Size, num2, num2Size, &newNumSize);

    for(int idx = 0; idx < newNumSize; idx++)
    {
        printf("newArray[%d] = %d\n", idx, newArray[idx]);
    }

    return 0;
}