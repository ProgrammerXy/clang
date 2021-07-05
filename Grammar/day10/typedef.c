#include "stdio.h"

typedef int integer;

int main(void){
    integer a;
    int b;
    a = 520;
    b = a;
    printf("b -> %d \n",b);
    printf("sizeOf a -> %lu",sizeof(a));
    return 0;
}