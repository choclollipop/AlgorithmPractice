#include <stdio.h>
#include <string.h>

#define ROW     3
#define COLUMN  3

int main()
{
    int num[ROW][COLUMN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int reverse[ROW][COLUMN];
    memset(reverse, 0, sizeof(reverse));

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
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int pos = 0; pos < COLUMN; pos++)
        {
            reverse[idx][pos] = num[pos][idx];
        }
    }

    /* 打印翻转后的数组 */
    for(int idx = 0; idx < ROW; idx++)
    {
        for(int pos = 0; pos < COLUMN; pos++)
        {
            printf("reverse[%d][%d]:%d\t", idx, pos, reverse[idx][pos]);
        }
        printf("\n");
    }

    return 0;
}