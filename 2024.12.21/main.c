#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long long int x = 1, y = 1, z;

    printf("请输入要求第几个斐波那契数：");
    scanf("%d", &n);

    if(n == 1 || n == 2)
    {
        printf("第%d个斐波那契数是%d：", n, x);
    }

    else if(n > 2)
    {
        for(int i = 1; i <= n - 2; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        printf("第%d个斐波那契数是%lld：", n, z);
    }

    return 0;
}
