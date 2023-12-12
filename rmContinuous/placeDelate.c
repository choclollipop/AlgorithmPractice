#include <stdio.h>

#define MAX_BUFFER 10

/* 原地工作删除数组内指定元素 */
int main()
{  
    int nums[MAX_BUFFER] = {1, 2, 5, 3, 7, 9, 2, 10, 11, 5};
    int target = 2;
    int pos = 0;
    int idx = 0;

    while(idx < MAX_BUFFER)
    {
        if(nums[idx] != target)
        {
            nums[pos] = nums[idx];
            idx++;
            pos++;
        }
        else
        {
            idx++;
        } 
    }

    for(int idx = 0; idx < pos; idx++)
    {
        printf("%d ", nums[idx]);
    }

    printf("\n");

    return 0;
}