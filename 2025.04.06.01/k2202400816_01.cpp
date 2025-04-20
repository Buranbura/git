#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

//�ṹ��
typedef struct node
{
    ElemType number;
    ElemType password;
    struct node *next;
}Node;

//��ʼ��
Node *createList(ElemType passwords[], int n)
{
    //���ж������Ƿ�Ϊ��
    if(n == 0)
    {
        return NULL;
    }

    //����
    Node *head = NULL, *tail = NULL;

    //��ʼ��ͷ�ڵ�
    head = (Node *)malloc(sizeof(Node));
    head ->number = 1;
    head ->password = passwords[0];
    head ->next = NULL;
    tail = head;

    //����ʣ��ڵ�
    for(int i = 2; i <= n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode ->number =i;
        newNode ->password = passwords[i - 1];
        newNode ->next = NULL;
        tail ->next = newNode;//��newNode��������
        tail = newNode;//��newNodeΪ�µ�β�ڵ�
    }

    tail ->next = head;//ͷβ����

    return head;
}

//Լɪ��
void josephus(Node *head, int initia1M)
{
    if(head == NULL)
    {
        printf("�ձ�û���˲�����Ϸ\n");
        return;
    }

    //����
    Node *current = head, *prev = NULL;
    int m = initia1M;

    //��prev��ʼ��Ϊβ�ڵ�
    while(prev == NULL || prev ->next != head)
    {
        prev = (prev == NULL)? head: prev ->next;
    }

    while(current ->next != current)//��ֻʣ��һ���ڵ�ʱֹͣ
    {
        for(int i = 1; i < m; i++)//currentͣ��Ŀ��λ�ã�prev��¼��ǰ��
            {
                prev = current;
                current = current->next;
            }

        //��������ߵı��
        printf("%d ", current ->number);

        //����m
        m = current ->password;

        //ɾ����ǰ�ڵ�
        prev ->next = current ->next;
        free(current);
        current = prev ->next;
    }

    //������һ����
    printf("%d\n", current ->number);
    free(current);
}

int main()
{
    int n;
    printf("����������n��n <= 30����");
    scanf("%d", &n);

    if(n <= 0 || n > 30)
    {
        printf("����������1~30֮��\n");
        return 1;
    }

    int passwords[n];
    printf("����������%d���˵�����:", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &passwords[i]);
    }
    int initia1M;
    printf("�������ʼ��������ֵm��");
    scanf("%d", &initia1M);

    Node *list = createList(passwords, n);
    printf("����˳��");
    josephus(list, initia1M);

    return 0;
}
