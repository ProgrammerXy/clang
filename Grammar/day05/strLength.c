#include <stdio.h>

int main()
{
    char str[] = "I LOVE FishC.com!";
    char *pointerStr = str;
    int count = 0;
    printf("%s \n", pointerStr);
    while (*pointerStr++ != '\0')
    {
        count++;
    }
    printf("总共有%d个字符! \n", count);
    return 0;
}