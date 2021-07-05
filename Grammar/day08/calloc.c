#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr1 = NULL;
    int *ptr2 = NULL;
    //第一次申请内存空间
    ptr1 = (int *)malloc(10 * sizeof(int));
    //进行若干操作后发现ptr1申请的内存空间不够用
    //第二次申请内存空间
    ptr2 = (int *)malloc(20 * sizeof(int));
    //将ptr1的数据拷贝到ptr2中
    //target source copySize
    memcpy(ptr2, ptr1, 10 * sizeof(int));
    free(ptr1);
    //对ptr2申请的内存空间进行若干操作...
    free(ptr2);
    return 0;
}