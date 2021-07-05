#include "stdio.h"
#include "stdlib.h"

int main(void) {
    FILE *f;
    int ch;

    if ((f = fopen("hello.txt", "r")) == NULL) {
        printf("打开文件失败! \n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(f)) != EOF) {
        putchar(ch);
    }
    fclose(f);
    f = NULL;
    return 0;
}