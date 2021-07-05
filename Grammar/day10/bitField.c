#include "stdio.h"
#include "limits.h"

int main(void){

    struct Test{
        unsigned int a:1;
        unsigned int b:1;
        unsigned int c:2;
    };
    struct Test test;
    test.a = 0;
    test.b = 1;
    test.c = 2;
    printf("test.a = %d\n",test.a);
    printf("test.b = %d\n",test.b);
    printf("test.c = %d\n",test.c);
    printf("size of test %lu\n",sizeof (test));
    printf("一个字节占多少位 %d \n",CHAR_BIT);
    return 0;
}