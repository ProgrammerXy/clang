#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char title[128];
    char author[40];
    struct Book *next;
};

void addBook(struct Book **library);
void getInput(struct Book *book);
void printBook(struct Book *book);
struct Book *searchBook(struct Book *library, char *target);
void getInput(struct Book *book)
{
    printf("请输入书名 : ");
    scanf("%s", book->title);
    printf("请输入作者 : ");
    scanf("%s", book->author);
}
void addBook(struct Book **library)
{
    struct Book *book;
    static struct Book *tail;
    //申请一个Book结构体类型的指针
    book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL)
    {
        printf("申请内存空间失败!");
        exit(1);
    }
    //利用指针进行Book类型结构体的赋值操作
    getInput(book);
    //如果头结点不为空
    if (*library != NULL)
    {
        tail->next = book;
        book->next = NULL;
    }
    //如果头结点为空
    else
    {
        /*
        将新节点的指针指向头节点
        并且将next指针置为NULL;
        */
        *library = book;
        book->next = NULL;
    }
    tail = book;
};

void printLibrary(struct Book *library)
{
    struct Book *book;
    int count = 1;
    book = library;
    while (book != NULL)
    {
        printf("Book%d: \n", count);
        printf("书名 %s \n", book->title);
        printf("作者 %s \n", book->author);
        book = book->next;
        count++;
    }
}

void releaseLibrary(struct Book **library)
{
    struct Book *temp;
    while (*library != NULL)
    {
        temp = *library;
        *library = (*library)->next;
        free(temp);
    }
}

struct Book *searchBook(struct Book *library, char *target)
{
    struct Book *book;
    book = library;
    while (book != NULL)
    {
        if (!strcmp(book->title, target) || !strcmp(book->author, target))
        {
            break;
        };
        book = book->next;
    }
    return book;
}

void printBook(struct Book *book)
{
    printf("书名 : %s", book->title);
    printf("作者 : %s", book->author);
}

int main(void)
{
    //library是指向Book的指针
    struct Book *library = NULL;
    struct Book *book;
    int ch;
    char input[128];

    while (1)
    {
        printf("请问是否需要录入书籍信息 (Y/N) :");
        do
        {
            ch = getchar();
        } while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n');
        if (ch == 'Y' || ch == 'y')
        {
            addBook(&library);
        }
        else
        {
            break;
        }
    }
    printf("请问是否需要打印图书信息? (Y/N)");
    do
    {
        ch = getchar();
    } while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n');

    if (ch == 'Y' || ch == 'y')
    {
        printLibrary(library);
    }
    printf("\n 请输入书名或作者 :");
    scanf("%s", input);
    book = searchBook(library, input);
    if (book == NULL)
    {
        printf("抱歉,没能索引到您所需的书籍 \n");
    }
    else
    {
        printf("已找到符合条件的书籍....\n");
        do
        {
            printBook(book);
        } while ((book = searchBook(book->next, input)) != NULL);
    }

    releaseLibrary(&library);
    return 0;
}