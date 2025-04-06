//试写一算法，对单链表实现就地逆置。

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;


//初始化
Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("内存分布失败\n");
        exit(1);
    }
    head ->data = 0;
    head ->next = NULL;
    return head;
}

//头插法
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p ->data = e;
    p ->next = L ->next;
    L ->next = p;
    return 1;
}


//就地逆置
Node *reverseList(Node *head)
{
    if(head == NULL || head ->next == NULL)
    {
        return;
    }
    Node *prev = NULL;//前一个节点
    Node *curr = head ->next;//当前节点
    Node *next = NULL;//下一个节点

    while(curr != NULL)
    {
        next = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    head ->next = prev;
}


//遍历
void listNode(Node *L)
{
    Node *p = L ->next;
    while(p != NULL)
    {
        printf("%d ", p ->data);
        p = p ->next;
    }
    printf("\n");
}


int main()
{
    Node *list = initList();
    insertHead(list, 6);
    insertHead(list, 5);
    insertHead(list, 4);
    insertHead(list, 3);
    insertHead(list, 2);
    insertHead(list, 1);
    reverseList(list);
    listNode(list);
    return 0;
}
