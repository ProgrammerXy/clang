#include <stdio.h>

void getArray(int *p)
{
    *(p + 4) = 520;
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n", i, *(p + i));
    }
}

int main(void)
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    getArray(a);
    printf("在main函数中再打印一次......\n");
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}