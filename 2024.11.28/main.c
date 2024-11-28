/*#include <stdio.h>

int main()
{
    int n;
    int a,b,c;
    int n1,n2;

    printf("请输入n的值：");
    scanf("%d",&n);

    for(a=0;a<=9;a++)
    {
        for(b=0;b<=9;b++)
        {
            for(c=0;c<=9;c++)
            {
                n1=a*100+b*10+c;
                n2=c*100+b*10+a;
                if(n1+n2==n)
                {
                    printf("a=%d,b=%d,c=%d\n",a,b,c);
                }
            }
        }
    }

    return 0;
}*/





#include <stdio.h>

int main()
{
    int male,female,kid;
    int sum=100;
    for(male=0;male<=100;male++)
    {
        for(female=0;female<=100;female++)
        {
            for(kid=0;kid<=100;kid++)
            {
                if(male*3+female*2+kid/3.0==sum)
                {
                    printf("公鸡有%d只，母鸡有%d只，小鸡有%d只\n",male,female,kid);
                }
            }
        }
    }

    return 0;
}











