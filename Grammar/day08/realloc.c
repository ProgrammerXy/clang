#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr = NULL;
    int count = 0, i, num;
    do
    {
        printf("请输入任意数字,直到-1结束 :");
        scanf("%d", &num);
        count++;
        ptr = (int *)realloc(ptr, sizeof(int) * count);
        if (ptr == NULL)
        {
            exit(1);
        }
        ptr[count - 1] = num;
    } while (num != -1);

    for (i = 0; i < count - 1; i++)
    {
        printf("输入的数组为: %d \n", ptr[i]);
    }
    free(ptr);
    return 0;
}