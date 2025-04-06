/*
//��дһ�㷨ʵ���ڷǵݼ���˳����ϲ�������Ԫ��X����ʹ��˳���������״̬��

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//˳����壨˳��������ݺͳ��ȣ�
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//˳����ʼ������ʼ����Ϊ�㣩
//L��SeqList���͵�ָ��
void initList(SeqList *L)
{
    L -> length = 0;
}

//����������Ԫ��x
void insertElement(SeqList *L, ElemType x)
{
    int i;
    for(i = 0; i < L ->length; i++)
    {
        if(L ->data[i] > x)
        {
            break;
        }
    }
    for(int j = L ->length; j > i; j--)
    {
        L ->data[j] = L ->data[j - 1];
    }
    L ->data[i] = x;
    L ->length++;
}

//����
void listElem(SeqList *L)
{
    for(int i = 0; i < L ->length; i++)
    {
        printf("%d ", L ->data[i]);
    }
    printf("\n");
}


int main()
{
    SeqList list;//����һ��˳���
    initList(&list);//���ó�ʼ������
    ElemType data[] = {1, 3, 5, 7, 9};
    int length = (sizeof(data) / sizeof(data[0]));
    int x = 6;
    for(int i = 0; i < length; i++)
    {
        insertElement(&list,data[i]);
    }
    insertElement(&list, x);
    listElem(&list);
    return 0;
}

*/


/*
//��̣�ɾ��˳���a�е�i��Ԫ�����k��Ԫ��
#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//����˳���ṹ��
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//��ʼ��
void initList(SeqList *L)
{
    L ->length = 0;
}

//����Ԫ��
void insertElements(SeqList *L, ElemType e)
{
    if(L ->length >= MAXSIZE)
    {
        printf("˳����������޷����룡\n");
        return;
    }
    L ->data[L ->length++] = e;
}

//ɾԪ��
void deleteElements(SeqList *L, int i, int k)
{
    //����������Ч��
    if(i < 0 || i >= L->length)
    {
        printf("ɾ��λ����Ч��\n");
        return;
    }
    if(k <= 0)
    {
        printf("ɾ��λ����Ч��\n");
        return;
    }
    if(i + k > L ->length)
    {
        printf("ɾ����Χ����˳����ȣ�\n");
        return;
    }
    //��Ԫ�أ����ǵ�Ҫɾ����Ԫ�أ�������ʣ��Ԫ���������³���
    for(int j = i + k; j < L ->length; j++)
    {
        L ->data[j - k - 1] = L ->data[j - 1];
    }
    L ->length -=k;
}

int main()
{
    SeqList list;
    initList(&list);
    ElemType data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int length = (sizeof(data) / sizeof(data[0]));
    for(int i = 0; i < length; i++)
    {
        insertElements(&list, data[i]);
    }
    deleteElements(&list, 5, 3);
    for(int i = 0; i < list.length; i++)
    {
        printf("%d", list.data[i]);
    }
    return 0;
}
*/


//��дһ�㷨��ʵ��˳���ľ͵����ã�������ԭ��Ĵ洢�ռ佫���Ա�a1,a2,a3....an����Ϊan....a3,a2,a1��
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//����
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//��ʼ��
void initList(SeqList *L)
{
    L ->length = 0;
}

//����
void insertElements(SeqList *L, ElemType e)
{
    if(L ->length >= MAXSIZE)
    {
        printf("˳���������\n");
        return;
    }
    L ->data[L ->length] = e;
    L ->length++;
}

//���ã�����ʱ�临�Ӷ�С��
void reverseSeqList(SeqList *L)
{
    int left = 0;
    int right = L ->length - 1;
    while(left < right)
    {
        ElemType temp = L ->data[left];
        L ->data[left] = L ->data[right];
        L ->data[right] = temp;
        left++;
        right--;
    }
}

void listElem(SeqList *L)
{
    for(int i = 0; i < L ->length; i++)
    {
        printf("%d ", L ->data[i]);
    }
    printf("\n");
}

int main()
{
    SeqList list;
    initList(&list);
    ElemType data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = (sizeof(data) / sizeof(data[0]));
    for(int i = 0; i < length; i++)
    {
        insertElements(&list, data[i]);
    }
    reverseSeqList(&list);
    printf("���ú��˳���Ϊ��\n");
    listElem(&list);
    return 0;
}









