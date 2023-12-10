#include <stdio.h>
#include <stdlib.h>

/* 寻找数组中两个数相加的和等于目标值，并返回这两个数的对应下标 */
int main()
{
    int * p_num;
    int target;
    int count;
    int pair = 0;

    printf("请输入你要输入的数据个数：\n");
    scanf("%d",&count);
    /* 动态分配数组的长度，并判断长度不能小于2 */
    p_num = (int *)malloc(sizeof(int) * count);
    if(count < 2)
    {
        printf("输入数据不合法\n");
    }

    printf("请输入你需要的相加数据和的值：\n");
    scanf("%d",&target);

    printf("请输入你要计算的数据：\n");
    for(int idx = 0; idx < count; idx++)
    {
        scanf("%d", (p_num + idx));
    }

    /* 通过循环遍历数组，寻找相加等于目标值的数组下标 */
    for(int idx = 0; idx < count; idx++)
    {
        for(int sub = 1; sub <= count - 1; sub++)
        {
            if ((*(p_num + idx) + *(p_num + sub) == target) && (idx < sub))
            {
                printf("%d,%d\n", idx, sub);
                pair++;
            }
        }
    }

    if(pair == 0)
    {
        printf("并没有找到符合要求的数据\n");
    }

    free(p_num);

    return 0;
}