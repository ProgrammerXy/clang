#include <stdio.h>

struct Date
{
    int year;
    int month;
    int day;
};

struct Book
{
    char title[128];
    char author[40];
    float price;
    struct Date date;
    char publisher[40];
} book = {
    "<带你学C带你飞>",
    "小甲鱼",
    48.8,
    {2021, 07, 04},
    "清华大学出版社"};
int main(void)
{
    struct Book *ptr;
    ptr = &book;

    printf("书名 : %s\n", ptr->title);
    printf("作者 : %s\n", ptr->author);
    printf("价格 : %.2f\n", ptr->price);
    printf("出版日期 : %d-%d-%d\n", ptr->date.year, ptr->date.month, ptr->date.day);
    printf("出版社 : %s\n", ptr->publisher);
    return 0;
}