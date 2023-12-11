#include <stdio.h>

#define BUFFER_SIZE7    7

/* 暴力算法排序 */
int main()
{
    int nums[BUFFER_SIZE7] = {7, 1, 4, 9, 2, 3, 11};
    int temp = 0;
    int node = 0;
    int sortCount = 0;

    /* 外层循环取出基准值，用内层循环寻找比基准值小的数 */
    for(int idx = 0; idx < BUFFER_SIZE7 - 1; idx++)
    {
        temp = nums[idx];
        for(int sub = idx; sub < BUFFER_SIZE7; sub++)
        {
            if(nums[sub] < nums[idx])
            {
                nums[idx] = nums[sub];
                node = sub;      //取出此时比基准值小的数字所在的结点
                sortCount++;
            }
            if(sub == BUFFER_SIZE7 - 1)
            {
                if(sortCount == 0)    //sortCount等于0，即基准值后面的数字没有比基准值小的数，则不交换位置
                {
                    continue;
                }
                nums[node] = temp;   //将基准值与它后面最小的数字交换位置
                sortCount = 0;       //每次循环开始，都让sortCount置0，重新计算，以防影响结果
            }
        }
    }

    /* 打印排序后的数组 */
    for(int idx = 0; idx < BUFFER_SIZE7; idx++)
    {
        printf("%d",nums[idx]);
    }

    printf("\n");

    return 0;
}