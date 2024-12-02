/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    int *p1=&i;
    int *p2=&j;
    int result;

    for(*p1 = 1; *p1 <= 9; (*p1)++)
    {
        for (*p2 = 1;*p2 <= *p1; (*p2)++)
        {
            result = *p1 * *p2;
            printf("%d*%d=%d\t",*p1, *p2, result);
        }
        printf("\n");
    }

    return 0;
}*/



/*#include <stdio.h>

int main()
{
    float fun1 (float,float,float);
    float a = 3.8, b = 3.7, c = 2.4, maxnum;
    maxnum = fun1(a, b, c);
    printf("Max number is %.2f\n", maxnum);
    return 0;
}
float fun1(float x,float y,float z)
{
    float max;
    if(x > y)max = x;
    else max = y;
    if(z > max)max = z;
    return max;
}*/





#include <stdio.h>

int fun2(float x)
{
    int t;
    if(x >= 0 && x<= 100)
        t=1;
    else
        t=0;
    return t;
}

int main()
{
    int i,s;
    float a,sum=0.0;
    float ave;

    for(i = 1; i <= 20; i++)
    {

        printf("请输入学生成绩:");
        scanf("%f", &a);
        s=fun2(a);
        if(s == 0)
            printf("成绩无效，请重新输入");
        else
            sum=sum+a;
    }

    ave=sum/20;
    printf("平均成绩为：%f\n",ave);

    return 0;
}






