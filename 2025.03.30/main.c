#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int id;
    int password;
    struct node *next;
}Node;

//��ʼ��
Node *createList(int ids[], int passwords[], int n)
{
    if(n == 0)
        return NULL;

    Node *head = NULL, *tail = NULL;

    //�����׽ڵ�
    head = (Node*)malloc(sizeof(Node));
    head ->id = ids[0];
    head ->password = passwords[0];
    head ->next =NULL;
    tail = head;

    //����ʣ��ڵ�
    for(int i = 1; i < n; i++)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode ->id = ids[i];
        newNode ->password = passwords[i];
        newNode ->next = NULL;
        tail ->next = newNode;
        tail = newNode;
    }

    //ͷβ�������γ�ѭ������
    tail ->next = head;

    return head;//�����׽ڵ�
}

//Լɪ��
void josephus(Node *head, int initia1M)
{
    if(head == NULL)
        return;

    Node *current = head, *prev = NULL;
    int m = initia1M;

    //��β�ڵ㣨��prev��ʼ��Ϊβ�ڵ㣩
    while(prev == NULL || prev ->next != head)
    {
        prev = (prev == NULL) ? head : prev ->next;
    }

    while(current ->next != current)//ֻʣһ���ڵ�ʱ��ֹ
    {
        //������m-1��ͣ�ڴ�ɾ���Ľڵ��ǰ��
        for(int i = 1; i < m; i++)
        {
            prev = current;
            current = current ->next;
        }

        //��������ߵı��
        printf("%d ", current ->id);

        //����m
        m = current ->password;

        //ɾ����ǰ�ڵ�
        prev ->next = current ->next;
        free(current);
        current = prev ->next;
    }

    //������ʣ�µ���
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
    printf("����˳��");
    josephus(list, initia1M);

    return 0;
}
