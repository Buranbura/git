#include <stdio.h>
#include <stdlib.h>

void fail(int arr[5][5])    //两门及以上课程不及格
{
    int i, j;
    int student[5] = {0};
    for(i = 0; i < 5; i++)
    {
        for(j = 1; j < 5; j++)
        {
            if(arr[i][j] < 60)
            {
                student[i]++;

            }
        }
    }
    for(i = 0; i < 5; i++)
    {
        if(student[i] > 1)
        {
            printf("2门及2门以上课程不及格的学生学号为：%d\n", arr[i][0]);
        }

    }
}

float average(int arr[5][5])  //第一门课的全班平均分
{
    int i;
    float sum1 = 0;
    for(i = 0; i < 5; i++)
    {
        sum1 = sum1 + arr[i][1];
    }
    return sum1 / 5.0;
}

void good(int arr[5][5])     //四门平均成绩90及以上，全部大于等于85
{
    int i, j;
    int student[5] = {0};
    float sum2[5] = {0}, ave2[5] = {0};
    for(i = 0; i < 5; i++)
    {
        for(j = 1; j < 5; j++)
        {
            if(arr[i][j] >= 85)
            {
                student[i]++;
            }
            sum2[i] = sum2[i] + arr[i][j];
        }
        ave2[i] = sum2[i] / 4.0;
    }
    for(i = 0; i < 5; i++)
    {
        if(student[i] == 4 || ave2[i] >= 90)
        {
            printf("全部课程成绩都在85分以上（含85分）或4门课程的平均成绩大于等于90的学生学号为：%d\n", arr[i][0]);
            printf("学生%d的全部课程成绩为：%d,%d,%d,%d，平均成绩为：%f\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4], ave2[i]);
        }
    }
}

void rank(int arr[5][5])     //学生成绩排序
{
    int i, j, t, k;
    int s[5] = {0};
    for(i = 0; i < 4; i++)
    {
        for(j = 1; j < 5 - i; j++)
        {
            if(arr[j][1] > arr[j-1][1])
            {
                for(k = 0; k < 5; k++)
                {
                    t = arr[j][k];
                    arr[j][k] = arr[j - 1][k];
                    arr[j - 1][k] = t;
                }
            }

        }
    }

    for(i = 1; i < 5; i++)
    {
        for(j = 1;j < 5; j++)
        {
            if(arr[i][1] == arr[i - 1][1])
            {
                s[i]++;
            }
        }
        if(s[i] == 4 && arr[i][0] < arr[i - 1][0])
        {
            for(j = 0; j < 5; j++)
            {
                t = arr[i][j];
                arr[i][j] = arr[i - 1][j];
                arr[i - 1][j] = t;
            }
        }
        s[i] = 0;
    }

    for(i = 0; i < 5; i++)
    {
        printf("学生%d各门课程成绩为：%d\t%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4]);
    }
}


int main()
{
    int a[5][5] = {{1, 56, 68, 59, 78}, {2, 98, 95, 91, 89}, {3, 85, 86, 92, 88}, {4, 98, 95, 91, 89}, {5, 78, 89, 75, 66}};
    float aver;
    fail(a);
    aver = average(a);
    printf("第一门课的全班平均分为：%f\n", aver);
    good(a);
    rank(a);
    return 0;
}































