#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

//结构体
typedef struct node
{
    ElemType number;
    ElemType password;
    struct node *next;
}Node;

//初始化
Node *createList(ElemType passwords[], int n)
{
    //先判断人数是否为零
    if(n == 0)
    {
        return NULL;
    }

    //声明
    Node *head = NULL, *tail = NULL;

    //初始化头节点
    head = (Node *)malloc(sizeof(Node));
    head ->number = 1;
    head ->password = passwords[0];
    head ->next = NULL;
    tail = head;

    //插入剩余节点
    for(int i = 2; i <= n; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode ->number =i;
        newNode ->password = passwords[i - 1];
        newNode ->next = NULL;
        tail ->next = newNode;//将newNode接入链表
        tail = newNode;//设newNode为新的尾节点
    }

    tail ->next = head;//头尾相连

    return head;
}

//约瑟夫环
void josephus(Node *head, int initia1M)
{
    if(head == NULL)
    {
        printf("空表，没有人参与游戏\n");
        return;
    }

    //声明
    Node *current = head, *prev = NULL;
    int m = initia1M;

    //将prev初始化为尾节点
    while(prev == NULL || prev ->next != head)
    {
        prev = (prev == NULL)? head: prev ->next;
    }

    while(current ->next != current)//当只剩下一个节点时停止
    {
        for(int i = 1; i < m; i++)//current停在目标位置，prev记录其前驱
            {
                prev = current;
                current = current->next;
            }

        //输出出列者的编号
        printf("%d ", current ->number);

        //更新m
        m = current ->password;

        //删除当前节点
        prev ->next = current ->next;
        free(current);
        current = prev ->next;
    }

    //输出最后一个人
    printf("%d\n", current ->number);
    free(current);
}

int main()
{
    int n;
    printf("请输入人数n（n <= 30）：");
    scanf("%d", &n);

    if(n <= 0 || n > 30)
    {
        printf("人数必须在1~30之间\n");
        return 1;
    }

    int passwords[n];
    printf("请依次输入%d个人的密码:", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &passwords[i]);
    }
    int initia1M;
    printf("请输入初始报数上限值m：");
    scanf("%d", &initia1M);

    Node *list = createList(passwords, n);
    printf("出列顺序：");
    josephus(list, initia1M);

    return 0;
}
