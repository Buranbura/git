//已知由一个线性链表表示的线性表中含有三类字符的数据元素（如：字母字符、数字字符和其他字符）
//试编写算法将该线性表分割为三个循环链表，其中每个循环链表表示的线性表中均只含一类字符

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef char ElemType;

//结构指针
typedef struct node
{
    ElemType data;
    struct node *next;//next是指向下一节点的指针
}Node;

//初始化
Node *initList()
{
    Node *head = (Node*)malloc(sizeof(Node));//分配堆内存
    //判断内存是否分配成功
    if(head == NULL)
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    head ->data = 0;// 将分配的节点的data成员初始化为0，这里表示链表头节点的值
    head ->next = NULL;// 将分配的节点的next指针初始化为NULL，表示链表的起始节点没有指向下一个节点
    return head;// 返回分配的头节点的指针，用于后续操作链表
}

//头插法插入数据
int insertHead(Node *L, ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));// 分配一个Node类型的节点空间，将其存储在堆内存中，并将指针赋值给p
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return 0;
    }
    p ->data = e;
    p ->next = L ->next;// 将新分配的节点的next指针指向头节点L的下一个节点
    L ->next = p;// 将头节点L的next指针指向新分配的节点p，完成头插操作
    return 1;
}

//将线性链表分割为三个循环链表
void splitList(Node *head, Node **letters, Node **digits, Node **others)
{
    //1.判断原链表是否为空
    if(head == NULL)
    {
        printf("原链表为空\n");
        return;
    }
    //2.初始化三个新链表
    *letters = initList();
    *digits = initList();
    *others = initList();
    //3.遍历原链表，识别分配插入到新链表
    Node *current = head ->next;// 当前节点
    Node *prev = head;// 前一个节点
    while(current != NULL)
    {
        Node *next = current ->next;// 保存下一个节点
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
    //4.释放原链表（要逐个释放）
    Node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head ->next;
        free(temp);
    }
    //5.将新链表改为循环链表
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


//输出
void printCircularList(Node *head)
{
    if(head == NULL)
    {
        printf("链表为空\n");
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
    printf("字母链表\n");
    printCircularList(letters);
    printf("数字链表\n");
    printCircularList(digits);
    printf("其他字符链表\n");
    printCircularList(others);
    return 0;
}

