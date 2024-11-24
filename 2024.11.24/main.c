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





#include <stdio.h>
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
}








