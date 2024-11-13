#include <stdio.h>  //包含标准输入输出头文件，使得程序可以使用printf、scanf等函数

int main()
{
    int sum,i;  //声明两个int型的变量sum,i

    sum=0;  //初始化sum为0，因为累加的初始值是0

    for(i=1;i<=100;i++)  //开始for循环，i从1开始，每次循环i增加1，当i小于等于100时执行循环体
    {
        sum+=i;  //将i的值累加到sum中，等价于sum=sum+i
    }

    printf("1+2+...+100=%d\n",sum);  //输出从1累加到100的值

    return 0;

}
