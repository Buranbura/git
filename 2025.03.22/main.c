//��֪��һ�����������ʾ�����Ա��к��������ַ�������Ԫ�أ��磺��ĸ�ַ��������ַ��������ַ���
//�Ա�д�㷨�������Ա�ָ�Ϊ����ѭ����������ÿ��ѭ�������ʾ�����Ա��о�ֻ��һ���ַ�

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef char ElemType;

//�ṹָ��
typedef struct node
{
    ElemType data;
    struct node *next;//next��ָ����һ�ڵ��ָ��
}Node;

//��ʼ��
Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));//������ڴ�
    //�ж��ڴ��Ƿ����ɹ�
    if(head == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    head ->data = 0;// ������Ľڵ��data��Ա��ʼ��Ϊ0�������ʾ����ͷ�ڵ��ֵ
    head ->next = NULL;// ������Ľڵ��nextָ���ʼ��ΪNULL����ʾ�������ʼ�ڵ�û��ָ����һ���ڵ�
    return head;// ���ط����ͷ�ڵ��ָ�룬���ں�����������
}

//ͷ�巨��������
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));// ����һ��Node���͵Ľڵ�ռ䣬����洢�ڶ��ڴ��У�����ָ�븳ֵ��p
    if (p == NULL)
    {
        printf("�ڴ����ʧ�ܣ�\n");
        return 0;
    }
    p ->data = e;
    p ->next = L ->next;// ���·���Ľڵ��nextָ��ָ��ͷ�ڵ�L����һ���ڵ�
    L ->next = p;// ��ͷ�ڵ�L��nextָ��ָ���·���Ľڵ�p�����ͷ�����
    return 1;
}

//����������ָ�Ϊ����ѭ������
void splitList(Node *head, Node **letters, Node **digits, Node **others)
{
    //1.�ж�ԭ�����Ƿ�Ϊ��
    if(head == NULL)
    {
        printf("ԭ����Ϊ��\n");
        return;
    }
    //2.��ʼ������������
    *letters = initList();
    *digits = initList();
    *others = initList();
    //3.����ԭ����ʶ�������뵽������
    Node *current = head ->next;// ��ǰ�ڵ�
    Node *prev = head;// ǰһ���ڵ�
    while(current != NULL)
    {
        Node *next = current ->next;// ������һ���ڵ�
        if(isalpha(current ->data))
        {
            current ->next = (*letters) ->next;
            (*letters) ->next = current;
        }
        else if(isdigit(current ->data))
        {
            current ->next = (*digits) ->next;
            (*digits) ->next = current;
        }
        else
        {
            current ->next = (*others) ->next;
            (*others) ->next = current;
        }
        prev ->next = next;
        current = next;
    }
    //4.�ͷ�ԭ����Ҫ����ͷţ�
    Node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head ->next;
        free(temp);
    }
    //5.���������Ϊѭ������
    Node *last = *letters;
    while (last ->next != NULL)
        last = last ->next;
    last ->next = *letters;

    last = *digits;
    while (last ->next != NULL)
        last = last ->next;
    last ->next = *digits;

    last = *others;
    while (last ->next != NULL)
        last = last ->next;
    last ->next = *others;
}


//���
void printCircularList(Node *head)
{
    if(head == NULL)
    {
        printf("����Ϊ��\n");
        return;
    }

    Node *current = head ->next;
    do{
        printf("%c", current ->data);
        current = current ->next;
    }while(current != head ->next);
    printf("\n");
}


int main()
{
    Node *list = initList();
    insertHead(list, 'a');
    insertHead(list, '$');
    insertHead(list, '6');
    insertHead(list, '!');
    insertHead(list, 'd');
    insertHead(list, 'f');
    insertHead(list, '5');
    insertHead(list, '?');
    insertHead(list, '1');
    Node *letters, *digits, *others;
    splitList(list, &letters, &digits, &others);
    printf("��ĸ����\n");
    printCircularList(letters);
    printf("��������\n");
    printCircularList(digits);
    printf("�����ַ�����\n");
    printCircularList(others);
    return 0;
}

