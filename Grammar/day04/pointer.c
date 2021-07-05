#include <stdio.h>

int main()
{
    char a = 'F';
    int f = 123;

    char *pa = &a;
    int *pf = &f;
    printf("a = %c , f = %d \n", *pa, *pf);

    *pa = 'C';
    *pf += 1;
    printf("a = %c , f = %d \n", *pa, *pf);
    printf("sizeof pa = %lu \n", sizeof(*pa));
    printf("sizeof pf = %lu \n", sizeof(*pf));
    printf("pa address is -> %p \n", pa);
    printf("pf address is -> %p \n", pf);
    return 0;
}