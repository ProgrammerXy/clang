#include <stdio.h>

int main()
{
    char *p1[] = {
        "ONE MORE THING --- APPLE",
        "JUST DO IT -- NIKE"};
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("%s \n", p1[i]);
    }
    return 0;
}