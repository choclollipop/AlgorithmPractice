#include <stdio.h>

#define BUFFER_SIZE8    8

/* 将不连续递增的数组修改为连续递增的数组 */
/* 暴力算法 */
int main()
{
    int array[BUFFER_SIZE8] = {1, 1, 2, 3, 7, 9, 9, 11};
    int temp;

    /* 寻找与temp相同的数字，将后面的数据以此向前挪动一个，并在最后的空间赋值0 */
    for(int idx = 0; idx < BUFFER_SIZE8; idx++)
    {
        temp = array[idx];
        for(int sub = idx + 1; sub < BUFFER_SIZE8; sub++)
        {
            if(temp == array[sub])
            {
                for(int move = sub + 1; move < BUFFER_SIZE8; move++)
                {
                    array[move - 1] = array[move];
                    if(move == BUFFER_SIZE8 - 1)
                    {
                        array[move] = 0;
                    }
                }
            }
        }
    }

    for(int idx = 0; idx < BUFFER_SIZE8; idx++)
    {
        printf("%d\t",array[idx]);
    }

    printf("\n");

    return 0;
}