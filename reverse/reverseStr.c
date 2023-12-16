#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 15

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

int main()
{
    char str[] = "I am from china";
    int start = 0;
    int len = strlen(str);

    len = strlen(str);

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