#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

struct Address {
    char name[40];
    char phoneNumber[20];
    struct Address *next;
};

struct Address *pool = NULL;
int count;

void addPerson(struct Address **head);

struct Address *findPerson(struct Address *head, char *input);

void printAddress(struct Address *address);

void changePerson(struct Address **head, char *input);

void delPerson(struct Address **head, char *target);

void displayContacts(struct Address **head);

void inputAddress(struct Address *new);

void releasePool();

void releaseLibrary(struct Address **head) {
    struct Address *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void releasePool() {
    struct Address *temp;
    while (pool != NULL) {
        temp = pool;
        pool = pool->next;
        free(temp);
    }
}

void printAddress(struct Address *address) {
    printf("姓名 -> %s \n", address->name);
    printf("号码 -> %s \n", address->phoneNumber);
}

void inputAddress(struct Address *new) {
    printf("请输入名字: ");
    scanf("%s", new->name);
    printf("请输入电话号码: ");
    scanf("%s", new->phoneNumber);
}

void addPerson(struct Address **head) {
    struct Address *new, *current, *previous;
    previous = NULL;
    current = *head;
    //如果内存池非空,则直接从里面获取空间
    if (pool != NULL) {
        new = pool;
        pool = pool->next;
        count--;
    } else {
        //如果内存池为空,则调用malloc函数申请新的内存空间
        new = (struct Address *) malloc(sizeof(struct Address));
    }
    if (new == NULL) {
        printf("申请内存空间失败!");
        exit(1);
    }
    inputAddress(new);
    while (current != NULL) {
        previous = current;
        current = current->next;
    }
    // previous为NULL,new赋值为当前头节点
    if (previous == NULL) {
        *head = new;
        new->next = NULL;
    } else {
        // current为NULL,此时current为最后一个节点
        previous->next = new;
    }
    printf("添加联系人成功!\n");
}

struct Address *findPerson(struct Address *head, char *input) {
    struct Address *current;
    current = head;
    while (current != NULL) {
        if (!(strcmp(current->name, input)) || !(strcmp(current->phoneNumber, input))) {
            break;
        }
        current = current->next;
    }
    return current;
}

void changePerson(struct Address **head, char *input) {
    struct Address *target = NULL;
    target = findPerson(*head, input);
    if (target != NULL) {
        printf("已找到要修改的对象!\n");
        printf("请重新录入该对象的值!\n");
        inputAddress(target);
    } else {
        printf("未找到要修改的对象!");
        return;
    }
}

void delPerson(struct Address **head, char *value) {
    struct Address *previous, *current, *temp;
    current = *head;
    previous = NULL;
    // current不为空,并且没有找到就继续找,找到的话current=target,previous=target的上一个节点
    while (current != NULL && strcmp(current->name, value)) {
        previous = current;
        current = current->next;
    }
    // 没有找到要删除的元素
    if (current == NULL) {
        printf("没有找到联系人!");
        return;
    } else {
        if (previous == NULL) {
            //要删除的节点为头结点时,把target的next节点指向头结点
            *head = current->next;
        } else {
            //要删除的节点为正常节点,把target节点的next节点赋值为上一个节点的next节点.
            previous->next = current->next;
        }
        //判断内存池是否有空位
        if (count < MAX) {
            if (pool != NULL) {
                temp = pool;
                pool = current;
                current->next = temp;
            } else {
                pool = current;
                current->next = NULL;
            }
            count++;
        } else {
            //释放target本身
            free(current);
        }
    }
    printf("删除已有联系人成功!\n");
}

void displayContacts(struct Address **head) {
    printf("显示当前通讯录\n");
    struct Address *current;
    current = *head;
    int num = 1;
    while (current != NULL) {
        printf("通讯表 第%d位 \n", num);
        printf("姓名 %s \n", current->name);
        printf("电话号码 %s \n", current->phoneNumber);
        num++;
        current = current->next;
    }
    printf("\n ****显示当前通讯录完成**** \n");
}

int main(void) {
    struct Address *head = NULL;
    struct Address *address;
    int options;
    while (1) {
        printf(""
               "|-欢迎使用通讯录管理程序-|\n"
               "|--  1.插入新的联系人 ---|\n"
               "|--- 2.查找已有联系人 ---|\n"
               "|--- 3.更改已有联系人 ---|\n"
               "|--- 4.删除已有联系人 ---|\n"
               "|--- 5.显示当前通讯录 ---|\n"
               "|-Powered by XiaoYan -|\n"
        );
        printf("请输入操作指令 :");
        scanf("%d", &options);
        if (options == -1) {
            releaseLibrary(&head);
            releasePool();
            break;
        }
        if (options == 1) {
            addPerson(&head);
        }
        if (options == 2) {
            char input[40];
            printf("请输入您要查找的联系人姓名或号码 :");
            scanf("%s", input);
            address = findPerson(head, input);
            if (address == NULL) {
                printf("很抱歉,没有查询到该联系人!\n");
            } else {
                printf("已找到符合条件的联系人....\n");
                do {
                    printAddress(address);
                } while ((findPerson(address->next, input)) != NULL);
            }
        }
        if (options == 3) {
            printf("请输入想更改目标的姓名:");
            char input[40];
            scanf("%s", input);
            changePerson(&head, input);
        }
        if (options == 4) {
            printf("请输入想删除目标的姓名:");
            char input[40];
            scanf("%s", input);
            delPerson(&head, input);
        }
        if (options == 5) {
            displayContacts(&head);
        }
    }
    return 0;
}