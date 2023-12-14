#include <stdio.h>
#include <stdlib.h>

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
        return -1;
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
    reverse = (char *)malloc(sizeof(char) * (count + 1));

    for(int idx = count - 1; idx >= 0; idx--)
    {
        reverse[pos] = array[idx];
        pos++;
    }


    for(int idx = 0; idx < count; idx++)
    {
        if((array[idx] - reverse[idx] == 0) || (array[idx] - reverse[idx] == 32 || array[idx] - reverse[idx] == -32))
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