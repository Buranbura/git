//��дһ�㷨���Ե�����ʵ�־͵����á�

#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;


//��ʼ��
Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("�ڴ�ֲ�ʧ��\n");
        exit(1);
    }
    head ->data = 0;
    head ->next = NULL;
    return head;
}

//ͷ�巨
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p ->data = e;
    p ->next = L ->next;
    L ->next = p;
    return 1;
}


//�͵�����
Node *reverseList(Node *head)
{
    if(head == NULL || head ->next == NULL)
    {
        return;
    }
    Node *prev = NULL;//ǰһ���ڵ�
    Node *curr = head ->next;//��ǰ�ڵ�
    Node *next = NULL;//��һ���ڵ�

    while(curr != NULL)
    {
        next = curr ->next;
        curr ->next = prev;
        prev = curr;
        curr = next;
    }
    head ->next = prev;
}


//����
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
