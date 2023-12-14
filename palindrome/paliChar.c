#include <stdio.h>
#include <stdlib.h>

/* 判断输入的字符串除去空格后是回文字符串，回文字符串：即字符串反转后对应位置的字母相同，可以是一个字母的大小写 */
#define DIFFERENCE 32

typedef enum STATUS_CODE
{
    ON_MALLOCERROR = -1,
}STATUS_CODE;

int main()
{
    int count = 0;
    int pos = 0;
    int space = 0;
    char * array = NULL;
    char * reverse = NULL;

    printf("请输入你想判断的字符串的个数：\n");
    scanf("%d", &count);
    array = (char *)malloc(sizeof(char) * (count + 1));
    if(!array)
    {
        return ON_MALLOCERROR;
    }

    getc(stdin);
    printf("请输入你想判断的字符串：\n");
    fgets(array, count + 1, stdin);


    /* 删除空格 */
    for(int idx = 0; idx < count; idx++)
    {
        if(array[idx] != 32)
        {
            array[pos] = array[idx];
            pos++;
        }
        else
        {
            space++;
        }
        
    }

    /* 新的长度 */
    count = count - space;

    pos = 0;
    /* 给倒置后的数组分配空间 */
    reverse = (char *)malloc(sizeof(char) * (count + 1));
    if(!reverse)
    {
        return ON_MALLOCERROR;
    }

    for(int idx = count - 1; idx >= 0; idx--)
    {
        reverse[pos] = array[idx];
        pos++;
    }

    /* 判断对应位置是否相同或是否是同一字母的大小写 */
    for(int idx = 0; idx < count; idx++)
    {
        if((array[idx] - reverse[idx] == 0) || array[idx] - reverse[idx] == DIFFERENCE || array[idx] - reverse[idx] == -DIFFERENCE)
        {
            if(idx == count - 1)
            {
                printf("输入的字符串是回文字符串\n");
            }
        }
        else
        {
            printf("输入的字符不是回文字符串\n");
            break;
        }
    }


    free(array);
    free(reverse);

    return 0;
}