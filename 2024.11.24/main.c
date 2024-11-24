/*#include <stdio.h>
#define N 5

int main()
{
    int num,i,j,p;
    for(i=1,p=1,num=1;i<=N;i++,p++,num++)
    {
        for(j=1;j<=5-p;j++)
            printf(" ");
        for(j=1;j<=p;j++)
            printf("%d",num);
        printf("\n");
    }
    return 0;
}*/





/*#include <stdio.h>
#define N 5

int main()
{
    int i,j,p;
    char c;
    for(i=1,p=5,c='A';i<=N;i++,p--,c++)
    {
        for(j=1;j<=5-p;j++)
            printf(" ");
        for(j=1;j<=p;j++)
            printf("%c",c);
        printf("\n");
    }
    return 0;
}*/





/*#include <stdio.h>
int main()
{
    int i,x=0,j=1;
    while(1)
    {
        x=j;
        for(i=1;i<10;i++)
        {
            if(i%2==1)
                x=x/2-1;
            else if(i%2==0)
                x=x/2-2;
        }

        if(x==1)
        {
            printf("第一天共摘了%d个桃子\n",j);
            break;
        }
        j++;
    }
    return 0;
}*/



/*#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    double a,v,sum;
    sum=0;

    for(i=1;i<=64;i++)
    {
        a=pow(2,i-1);
        sum=sum+a;
    }

    v=sum/(1.42*pow(10,8));
    printf("他将得到%lf立方米的麦子\n",v);
    return 0;
}*/




#include <stdio.h>
int main()
{
    int a,n,i,j;
    double s=0;

    printf("请输入a的值和计算几个数相加");
    scanf("%d %d",&a,&n);
    j=a;
    for(i=1;i<=n;i++)
    {
        if(i==1)
            a=a;
        else
            a=a*10+j;
        s=s+a;
    }
    printf("%lf",s);

    return 0;
}
















