/*#include <stdio.h>
int main()
{
    char c;
    int d;
    scanf("%c",&c);

    if(c<32 && c>=0)
        printf("���ַ�Ϊ�����ַ�");
    else if(c<=57 && c>=48)
        printf("���ַ�Ϊ�����ַ�");
    else if(c<=90 && c>=65)
        printf("���ַ�Ϊ��д��ĸ");
    else if(c<=122 && c>=97)
        printf("���ַ�ΪСд��ĸ");
    else
        printf("���ַ�Ϊ�����ַ�");
    return 0;
}*/






/*#include <stdio.h>
int main()
{
    int x,y;
    scanf("%d",&x);

    if(x<-5)
        y=-3*x+10;
    else if(x>=-5 && x<0)
        y=x;
    else if(x==0)
        y=0;
    else if(x>0 && x<=5)
        y=2*x;
    else
        y=4*x-10;

    printf("%d",y);
    return 0;
}*/




#include <stdio.h>
int main()
{
     int a[3];
     int i,j,p;

     for(i=0;i<=3;i++)
     {
         scanf("%d",&a[i]);
     }
     for(j=0;j<=3;j++)
     {
         for(i=0;i<=3-j;i++)
         {
           if(a[i]<a[i+1])
                {
                    p=a[i];
                    a[i]=a[i+1];
                    a[i+1]=a[i];
                }
         }
     }
     for(i=0;i<=3;i++)
        {
            printf("%d\n",a[i]);
        }

     return 0;

}




