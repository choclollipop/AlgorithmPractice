#include <stdio.h>

#define BUFFER_SIZE    10

/* 快速排序 */
void fastSort(int *array, int start, int end)
{
    if(start < end)
    {
        int base = array[start];
        int left = start;
        int right = end;
        while(left < right)
        {
            /* 从右边开始找 */
            while((left < right) && (array[right] >= base))
            {
                right--;
            }
            array[left] = array[right];

            while((left < right) && (array[left] <= base))
            {
                left++;
            }
            array[right] = array[left];
        }
        array[left] = base;

        /* 递归排序 */
        fastSort(array, start, left - 1);
        fastSort(array, left + 1, end);
    }
    
}

int main()
{
    int nums[BUFFER_SIZE] = {3, 5, 8, 1, 2, 6, 9, 10 ,15, 19};
    int lenth = BUFFER_SIZE;

    fastSort(nums, 0, lenth - 1);

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("%d\t",nums[idx]);
    }

    printf("\n");

    return 0;
}