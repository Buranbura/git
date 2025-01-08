/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("请输入三个整数");
    scanf("%d %d %d", &a, &b, &c);
    if(a < b)
    {
        a = b;
        if(a < c)
        {
            a = c;
        }
    }
    if(a < c)
    {
        a = c;
    }
    printf("%d", a);

    return 0;
}*/




/*#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10];
    int found = 1;
    for(int i = 0; i < 10; i++)
    {
        printf("请输入整数");
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 10; i++)
    {
        if(a[i] % 7 == 0)
        {
            printf("%d", a[i]);
            found = 0;
            break;
        }
    }
    if(found)
        printf("not exist");

    return 0;
}*/



/*#include<stdio.h>
#include<stdlib.h>
#define N 10

float fun(int a[N])
{
    int i;
    float sum = 0;
    float aver = 0;
    for(i = 0; i < N; i++)
    {
        sum += a[i];
    }
    aver = sum / N;
    return aver;
}

int main()
{
    int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("学生的平均成绩是：%.2f", fun(arr));
    return 0;
}*/



/*#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char num[10];
    char sex[10];
    char name[20];
    int score[4];
    double average;
}stu;

void input(stu student[], int N)
{
    for(int i = 0; i < N; i++)
    {
        printf("请输入第%d个学生的学号：", i + 1);
        scanf("%s", student[i].num);
        getchar();
        printf("请输入学生的性别：");
        fgets(student[i].sex, sizeof(student[i].sex), stdin);
        student[i].sex[strcspn(student[i].sex, "\n")] = 0;
        printf("请输入学生的姓名：");
        fgets(student[i].name, sizeof(student[i].name), stdin);
        student[i].name[strcspn(student[i].name, "\n")] = 0;
        for (int j = 0; j < 4; j++)
        {
            printf("请输入第%d门功课的成绩：", j + 1);
            scanf("%d", &student[i].score[j]);
        }
    }
}

void aver(stu student[], int N)
{
    for(int i = 0; i < N; i++)
    {
        double sum = 0;
        for(int j = 0; j < 4; j++)
        {
            sum += student[i].score[j];
        }
        student[i].average = sum / 4.0;
    }
}

void sort(stu student[], int N)
{
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N - 1 - i; j++)
        {
            if(student[j].average < student[j + 1].average)
            {
                stu temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int N = 3;
    stu student[N];
    input(student, N);
    aver(student, N);
    sort(student, N);
    printf("学号\t|性别\t|姓名\t|平均成绩\n");
    printf("%s\t|%s\t|%s\t|%.2lf", student[0].num, student[0].sex, student[0].name, student[0].average);
    return 0;
}*/










