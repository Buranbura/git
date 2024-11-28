#include <stdio.h>

int main()
{
    int n;
    int a,b,c;
    int n1,n2;

    printf("ÇëÊäÈënµÄÖµ£º");
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
}
