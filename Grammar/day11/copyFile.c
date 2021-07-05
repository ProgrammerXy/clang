#include "stdio.h"
#include "stdlib.h"

int main(void) {
    FILE *fr;
    FILE *fw;
    int ch;

    if ((fr = fopen("hello.txt", "r")) == NULL) {
        printf("打开文件失败! \n");
        exit(EXIT_FAILURE);
    }

    if ((fw = fopen("fishc.txt", "w")) == NULL) {
        printf("打开文件失败! \n");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fr)) != EOF) {
        fputc(ch, fw);
    }

    fclose(fr);
    fclose(fw);
    fr = NULL;
    fw = NULL;
    return 0;
}