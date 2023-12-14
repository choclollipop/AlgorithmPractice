#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 5
#define COLUMN sizeof("zhangsan")

int main()
{
    /* 这是一个名为array3的二级指针，也可以理解为二维数组 */
    char * array3[BUFFER_SIZE] = {"hello", "world", "nihao", "zhangsan", "lisi"};

    /* 另前后两个字符串比较大小 */
    for(int idx = 0; idx < BUFFER_SIZE - 1; idx++)
    {
        for(int pos = 0; pos < BUFFER_SIZE - 1 -idx; pos++)
        {
                int ret = strcmp(*(array3 + idx), *(array3 + idx + 1));
            if(ret > 0)
            {
                /* 后一个字符串小于前一个字符串，所以交换两个字符串的地址，即交换二维数组的行地址 */
                char * temp = array3[idx];
                array3[idx] = array3[idx + 1];
                array3[idx + 1] = temp;
            }
        }
        
    }

    /* 排序后的数组 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("排序后数组array3[%d] = %s\n", idx, array3[idx]);
    }

    return 0;
}