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
void deleteNode(struct Node **head, int input);

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

void deleteNode(struct Node **head, int input)
{
    struct Node *previous;
    struct Node *current;

    current = *head;
    previous = NULL;

    while (current != NULL && current->value != input)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("找不到匹配的节点\n");
        return;
    }
    else
    {
        //要删除的节点就是当前头节点
        if (previous == NULL)
        {
            *head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        free(current);
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
    printf("开始测试插入整数...");
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
    printf("开始测试删除整数...");
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
            deleteNode(&head, input);
            printNode(head);
        }
    }

    return 0;
}