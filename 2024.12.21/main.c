#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    long long int x = 1, y = 1, z;

    printf("������Ҫ��ڼ���쳲���������");
    scanf("%d", &n);

    if(n == 1 || n == 2)
    {
        printf("��%d��쳲���������%d��", n, x);
    }

    else if(n > 2)
    {
        for(int i = 1; i <= n - 2; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        printf("��%d��쳲���������%lld��", n, z);
    }

    return 0;
}
