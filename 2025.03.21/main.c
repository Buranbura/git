/*
//编写一算法实现在非递减的顺序表上插入数据元素X，并使得顺序表保持有序状态。

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//顺序表定义（顺序表有数据和长度）
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//顺序表初始化（初始长度为零）
//L是SeqList类型的指针
void initList(SeqList *L)
{
    L -> length = 0;
}

//函数：插入元素x
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

//遍历
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
    SeqList list;//声明一个顺序表
    initList(&list);//调用初始化函数
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
//编程：删除顺序表a中第i个元素起的k个元素
#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//声明顺序表结构体
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//初始化
void initList(SeqList *L)
{
    L ->length = 0;
}

//插入元素
void insertElements(SeqList *L, ElemType e)
{
    if(L ->length >= MAXSIZE)
    {
        printf("顺序表已满，无法插入！\n");
        return;
    }
    L ->data[L ->length++] = e;
}

//删元素
void deleteElements(SeqList *L, int i, int k)
{
    //检查参数的有效性
    if(i < 0 || i >= L->length)
    {
        printf("删除位置无效！\n");
        return;
    }
    if(k <= 0)
    {
        printf("删除位置无效！\n");
        return;
    }
    if(i + k > L ->length)
    {
        printf("删除范围超出顺序表长度！\n");
        return;
    }
    //搬元素，覆盖掉要删除的元素，并根据剩余元素数量更新长度
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


//试写一算法，实现顺序表的就地逆置，即利用原表的存储空间将线性表a1,a2,a3....an逆置为an....a3,a2,a1。
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

//声明
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}SeqList;

//初始化
void initList(SeqList *L)
{
    L ->length = 0;
}

//插入
void insertElements(SeqList *L, ElemType e)
{
    if(L ->length >= MAXSIZE)
    {
        printf("顺序表已满！\n");
        return;
    }
    L ->data[L ->length] = e;
    L ->length++;
}

//逆置（这样时间复杂度小）
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
    printf("逆置后的顺序表为：\n");
    listElem(&list);
    return 0;
}









