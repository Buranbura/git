/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, amax;
    scanf("%d", &a);
    amax = a;
    for(int i = 1; i <= 2; i++)
    {
        scanf("%d", &a);
        if(a > amax)
            amax = a;
    }
    printf("最大的数是：%d", amax);
    return 0;
}
*/




/*#include <stdio.h>

int main()
{
    int i;
    int count = 0;
    for(i = 1900; i <= 2000; i++)
    {
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
        {
            printf("%d\t", i);
            count++;
            if(count % 3 == 0)
                printf("\n");
        }
    }
    if(count % 3 != 0)
        printf("\n");

    return 0;
}*/




#include <stdio.h>
#include <math.h>

int fun(int a)
{
    int count = 0;
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
            count++;
    }
    if(count == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int main()
{
    int A;
    int b;
    scanf("%d", &A);
    b = fun(A);
    if(b == 1)
        printf("数字%d是素数", A);
    else
        printf("数字%d不是素数", A);
    return 0;
}






