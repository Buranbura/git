#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int id;
    int password;
    struct node *next;
}Node;

//初始化
Node *createList(int ids[], int passwords[], int n)
{
    if(n == 0)
        return NULL;

    Node *head = NULL, *tail = NULL;

    //创建首节点
    head = (Node*)malloc(sizeof(Node));
    head ->id = ids[0];
    head ->password = passwords[0];
    head ->next =NULL;
    tail = head;

    //插入剩余节点
    for(int i = 1; i < n; i++)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode ->id = ids[i];
        newNode ->password = passwords[i];
        newNode ->next = NULL;
        tail ->next = newNode;
        tail = newNode;
    }

    //头尾相连，形成循环链表
    tail ->next = head;

    return head;//返回首节点
}

//约瑟夫环
void josephus(Node *head, int initia1M)
{
    if(head == NULL)
        return;

    Node *current = head, *prev = NULL;
    int m = initia1M;

    //找尾节点（将prev初始化为尾节点）
    while(prev == NULL || prev ->next != head)
    {
        prev = (prev == NULL) ? head : prev ->next;
    }

    while(current ->next != current)//只剩一个节点时终止
    {
        //报数到m-1，停在待删除的节点的前驱
        for(int i = 1; i < m; i++)
        {
            prev = current;
            current = current ->next;
        }

        //输出出列者的编号
        printf("%d ", current ->id);

        //更新m
        m = current ->password;

        //删除当前节点
        prev ->next = current ->next;
        free(current);
        current = prev ->next;
    }

    //输出最后剩下的人
    printf("%d\n", current ->id);
    free(current);
}

int main()
{
    int n = 7;
    int ids[] = {1, 2, 3, 4, 5, 6, 7};
    int passwords[] = {3, 1, 7, 2, 4, 8, 4};
    int initia1M = 20;

    Node *list = createList(ids, passwords, n);
    printf("出列顺序：");
    josephus(list, initia1M);

    return 0;
}
