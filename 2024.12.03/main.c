#include <stdio.h>
#include <stdlib.h>

int nearest_fibo(int x)
{
    if (x < fibo(1))
        return fibo(1);

    int i = 0;
    int fibo_i = fibo(i);
    int fibo_i_plus_1 = fibo(i + 1);

    while (fibo_i_plus_1 < x)
    {
        i++;
        fibo_i = fibo_i_plus_1;
        fibo_i_plus_1 = fibo(i + 1);
    }

    if(x - fibo_i <= fibo_i_plus_1 - x)
        return fibo_i;
    else
        return fibo_i_plus_1;
}

int fibo(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c,i;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int x;

    printf("请输入一个整数：");
    scanf("%d", &x);
    int nearest = nearest_fibo(x);
    printf("最接近%d的Fibonacci数是：%d\n", x, nearest);

    return 0;
}
