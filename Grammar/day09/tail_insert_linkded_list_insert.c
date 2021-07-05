#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

void insertNode(struct Node **head, int input);
void printNode(struct Node *head);

void insertNode(struct Node **head, int input)
{
    struct Node *pervious, *current, *new;

    current = *head;
    pervious = NULL;
    // 如果当前结构体不为空并且输入的值大于当前结构体的值
    while (current != NULL && input > current->value)
    {
        //当前节点保存
        pervious = current;
        //下一个节点信息存入当前节点
        current = current->next;
    }
    new = (struct Node *)malloc(sizeof(struct Node));
    if (new == NULL)
    {
        printf("内存分配失败!");
        exit(1);
    }
    new->value = input;
    new->next = current;
    if (pervious == NULL)
    {
        *head = new;
    }
    else
    {
        pervious->next = new;
    }
}

void printNode(struct Node *head)
{
    struct Node *current;
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    putchar('\n');
}

int main(void)
{
    struct Node *head = NULL;
    int input;
    while (1)
    {
        printf("请输入一个整数(输入-1表示结束) ");
        scanf("%d", &input);
        if (input == -1)
        {
            break;
        }
        else
        {
            insertNode(&head, input);
            printNode(head);
        }
    }

    return 0;
}