#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 15

/* 将字符串中的单词翻转过来 */
int main()
{
    char * str = "I am from china";
    char reverse[BUFFER_SIZE + 1];
    char * result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    memset(reverse, 0, sizeof(reverse));
    int len = strlen(str);
    int pos = 0;
    int tmp = 0;
    
    /* 先将原始字符串翻转 */
    for(int idx = BUFFER_SIZE; idx >= 0; idx--)
    {
        reverse[pos] = str[idx];
        pos++;
    }

    pos = 0;

    for(int idx = 1  ; idx <= len; idx++)
    {
        if(reverse[idx] == ' ' || idx == len)
        {
            /* 若此时idx走到最后，则直接将最后一个字符赋值给结果数组即可,并退出 */
            if(idx == len)
            {
                result[pos] = reverse[idx];
                break;
            }
            /* 没有走到最后的时候，进行按位反向赋值 */
            int tmp1 =idx;
            for(int sub = pos; sub <= idx - 2; sub++)
            {
                result[sub] = reverse[tmp1 - 1];
                tmp1--;
                tmp++;
            }

            pos = idx - 1;

            /* 没有走到最后的时候，需要给每个单词中间加空格*/
            if(tmp != len)
            {
                result[pos] = 32;
                pos++;
                tmp++;
            }
            
        }
    }

    printf("result: %s\n", result);

    return 0;
}