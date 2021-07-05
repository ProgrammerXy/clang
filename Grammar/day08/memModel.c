#include <stdio.h>
#include <stdlib.h>

int global_unint_var;
int global_init_var1 = 520;
int global_init_var2 = 880;

void func(void);

void func(void)
{
    ;
}

int main(void)
{
    int local_var1;
    int local_var2;

    static int static_unint_var;
    static int static_init_var = 456;

    char *str1 = "I Love FishC.com!";
    char *str2 = "You are right!";

    int *malloc_var = (int *)malloc(sizeof(int));

    printf("addr of func ->%p \n", func);
    printf("addr of str1 ->%p \n", str1);
    printf("addr of str2 ->%p \n", str2);
    printf("addr of global_init_var1 -> %p \n", &global_init_var1);
    printf("addr of global_init_var2 -> %p \n", &global_init_var2);
    printf("addr of static_init_var -> %p \n", &static_init_var);
    printf("addr of static_unint_var -> %p \n", &static_unint_var);
    printf("addr of global_unint_var -> %p \n", &global_unint_var);
    printf("addr of malloc_var -> %p \n", malloc_var);
    printf("addr of local_var1 -> %p \n", &local_var1);
    printf("addr of local_var2 -> %p \n", &local_var2);

    return 0;
}