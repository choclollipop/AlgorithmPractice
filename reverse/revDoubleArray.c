#include <stdio.h>
#include <string.h>

#define ROW     3
#define COLUMN  3

/* 将二维数组的行列交换 */
int main()
{
    int num[ROW][COLUMN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    short col = 0;
    short row = 0;
    short count = 0;
    int tmpNum = 0;

    /* 打印二维数组 */
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int pos = 0; pos < COLUMN; pos++)
        {
            printf("num[%d][%d]:%d\t", idx, pos, num[idx][pos]);
        }
        printf("\n");
    }

    /* 翻转数组 */
    /* 原地翻转 */
    while(count < ROW)
    {
        tmpNum = num[row][col];
        num[row][col] = num[col][row];
        num[col][row] = tmpNum;
        col++;
        if(col == COLUMN)
        {
            count++;
            row = count;
            col = count;
        }
       
    }


    /* 打印翻转后的数组 */
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int pos = 0; pos < COLUMN; pos++)
        {
            printf("reverse[%d][%d]:%d\t", idx, pos, num[idx][pos]);
        }
        printf("\n");
    }

    return 0;
}