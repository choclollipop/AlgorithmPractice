#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 将字符串中的单词翻转过来 */
/* 原地翻转 */

/* 翻转字符换函数 */
void reverseStr(char * str, int start, int end)
{
    int tmp = 0;
    end = end - 1;
    while(start <= end)
    {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
}

/* 删除空格函数 */
int removeSpace(char * str, int len)
{
    int start = 0;
    int count = 0;
    for(start; start < len; start++)
    {
        if(str[start] != ' ')
        {
            break;
        }
    }

    while(start < len)
    {
        /* 先判断是不是空格，是就删除，不是就保留 */
        if(str[start] == ' ')
        {
            if(str[start - 1] != ' ')
            {
                str[count++] = str[start++];
            }
            else
            {
                start++;
            }
        }
        else
        {
            str[count++] = str[start++];
        }
    }

    /* 处理字符串最后是不是空格，是空格删除，长度减一 */
    if(str[count - 1] == ' ')
    {
        count--;
    }
    
    /* 删除空格后多余的内存不读取，故在最后赋值结束符 */
    str[count] = '\0';

    return count;
}

int main()
{
    char str[] = " I  am    from china";
    int start = 0;
    int len = strlen(str);

    len = removeSpace(str, len);
    printf("len : %d\n", len);

    /* 翻转单词内部字母顺序 */
    for(int end = 0; end <= len; end++)
    {
        if(end == len || str[end] == ' ')
        {
            reverseStr(str, start, end);
            start = end + 1;
        }
    }

    /* 翻转整个字符串 */
    reverseStr(str, 0, len);

    printf("%s\n", str);

    return 0;
}