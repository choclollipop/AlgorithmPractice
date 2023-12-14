#include <stdio.h>
#include <stdlib.h>

/* 判断输入的字符串除去空格后是回文字符串，回文字符串：即字符串反转后对应位置的字母相同，可以是一个字母的大小写 */
#define DIFFERENCE 32

typedef enum STATUS_CODE
{
    ON_MALLOCERROR = -2,
    ON_FREE_ERROR = -1,
}STATUS_CODE;

int main()
{
    int count = 0;
    int pos = 0;
    int space = 0;
    char * array = NULL;

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
    pos = pos - 1;

    /* 直接判断删除空格后的字符串是否是回文串，前后相减 */
    for(int idx = 0; idx < count; idx++)
    {
        if((array[idx] - array[pos] == 0) || (array[idx] - array[pos] == DIFFERENCE) || (array[idx] - array[pos] == -DIFFERENCE))
        {
            if(idx + 1 == pos || idx == pos)
            {
                printf("输入的字符串是回文串\n");
            }
        }
        else
        {
            printf("输入的字符串不是回文串\n");
            break;
        }
        pos--;
    }


    free(array);
    if(!array)
    {
        return ON_FREE_ERROR;
    }

    return 0;
}