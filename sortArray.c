#include <stdio.h>

#define BUFFER_SIZE7    7

/* 暴力算法排序 */
int main()
{
    int nums[BUFFER_SIZE7] = {7, 1, 4, 9, 2, 3, 11};
    int temp = 0;
    int node = 0;
    int sortCount = 0;

    for(int idx = 0; idx < BUFFER_SIZE7 - 1; idx++)
    {
        temp = nums[idx];
        for(int sub = idx; sub < BUFFER_SIZE7; sub++)
        {
            if(nums[sub] < nums[idx])
            {
                nums[idx] = nums[sub];
                node = sub;
                sortCount++;
            }
            if(sub == BUFFER_SIZE7 - 1)
            {
                if(sortCount == 0)
                {
                    continue;
                }
                nums[node] = temp;
                sortCount = 0;
            }
        }
    }

    for(int idx = 0; idx < BUFFER_SIZE7; idx++)
    {
        printf("%d",nums[idx]);
    }

    printf("\n");

    return 0;
}