#include <stdio.h>

// 因為是接變數的位址，所以要用指針來接
void func1(int *pa)
{
        *pa = 100;
}

// 因為是接受指針變數的位址，所以要用指針的指針來接
void func2(int **ppb)
{
        **ppb = 200;
        // *ppb =pb = &b
}

int main(void)
{
        int a = 10;
        int b = 20;
        int *pb = NULL;
        pb = &b;

        printf("before a = %d\n", a);
        func1(&a); //把變數的位址傳進去
        printf("after a = %d\n", a);

        printf("before pb = %d, b = %d\n", *pb, b);
        func2(&pb); //把指針變數的位址傳進去
        printf("after pb = %d, b = %d\n", *pb, b);


        return 0;
}
