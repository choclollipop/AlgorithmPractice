#include <stdio.h>

#define BUFFER_SIZE 7

int main()
{
    int nums[BUFFER_SIZE] = {9, 10, 2, 1, 8, 3, 7};
    int temp;

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        for(int sub = 0;sub < BUFFER_SIZE - 1 - idx; sub++)
        {
            if(nums[sub] > nums[sub + 1])
            {
                temp = nums[sub];
                nums[sub] = nums[sub + 1];
                nums[sub + 1] = temp;
            }
        }
    }

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        printf("%d\t",nums[idx]);
    }

    printf("\n");

    return 0;
}