#include <stdio.h>

#define BUFFER_SIZE 7

/* 获取数组内数据的最大差值是多少 */
int main()
{
    int arr[BUFFER_SIZE] = {7, 2, 3, 8, 10, 7, 6};
    int min = 0;
    int minbuy = 0;
    int minsell = 0;

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        for(int pos = 1;pos < BUFFER_SIZE; pos++)
        {
            if(arr[idx] - arr[pos] < min && idx < pos)
            {
                min = arr[idx] - arr[pos];
                minbuy = idx;
                minsell = pos;
            }
        }
    }

    printf("在周%d买入,周%d卖出利润最大\n", minbuy + 1, minsell + 1);

    return 0;
}