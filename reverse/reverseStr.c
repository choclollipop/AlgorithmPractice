#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 将字符串中的单词翻转过来 */
/* 原地翻转 */

/* 翻转字符换函数 */
void reverseStr(char * pStr, int start, int end)
{
    int tmp = 0;
    end = end - 1;
    while(start <= end)
    {
        tmp = pStr[start];
        pStr[start] = pStr[end];
        pStr[end] = tmp;
        start++;
        end--;
    }
}

/* 删除空格函数 */
int removeSpace(char * pStr, int len)
{
    int start = 0;
    int count = 0;
    for(start; start < len; start++)
    {
        if(pStr[start] != ' ')
        {
            break;
        }
    }

    while(start < len)
    {
        /* 先判断是不是空格，是就删除，不是就保留 */
        if(pStr[start] == ' ')
        {
            if(pStr[start - 1] != ' ')
            {
                pStr[count++] = pStr[start++];
            }
            else
            {
                start++;
            }
        }
        else
        {
            pStr[count++] = pStr[start++];
        }
    }

    /* 处理字符串最后是不是空格，是空格删除，长度减一 */
    if(pStr[count - 1] == ' ')
    {
        count--;
    }
    
    /* 删除空格后多余的内存不读取，故在最后赋值结束符 */
    pStr[count] = '\0';

    return count;
}

int main()
{
    char str[] = " I  am    from china";
    int start = 0;
    int len = strlen(str);

    len = removeSpace(str, len);

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

    printf("reverse:%s\n", str);

    return 0;
}