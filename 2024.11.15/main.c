/*#include <stdio.h>
int main()
{
     int a[3];
     int i,j,p;

     for(i=0;i<3;i++)
     {
         scanf("%d",&a[i]);
     }
     for(j=0;j<3;j++)
     {
         for(i=0;i<3-j;i++)
         {
           if(a[i]<a[i+1])
                {
                    p=a[i];
                    a[i]=a[i+1];
                    a[i+1]=p;
                }
         }
     }
     for(i=0;i<3;i++)
        {
            printf("%d ",a[i]);
        }

     return 0;

}*/







/*#include <stdio.h>
int main()
{
    int arr[20];
    int a=0,b=0,c=0,d=0,e=0;
    int i;

    for (i=0;i<20;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (i=0;i<20;i++)
    {
        if(arr[i]>=90)
            a++;
        else if(arr[i]>=80 && arr[i]<90)
            b++;
        else if(arr[i]>=70 && arr[i]<80)
            c++;
        else if(arr[i]>=60 && arr[i]<70)
            d++;
        else
            e++;
    }

    printf("90��90�����ϵ�����Ϊ��%d\n",a);
    printf("80~89�ֵ�����Ϊ��%d\n",b);
    printf("70~79�ֵ�����Ϊ��%d\n",c);
    printf("60~69�ֵ�����Ϊ��%d\n",d);
    printf("60�����µ�����Ϊ��%d\n",e);
    return 0;
}*/






#include <stdio.h>
int main()
{
    char c[100];
    int i;
    int num=0,grap=0,other=0;

    fgets(c,sizeof(c),stdin);
    for(i=0;c[i]!='\n';i++)
    {
        if(c[i]>=48 && c[i]<=57)
            num++;
        else if((c[i]>=65 && c[i]<=90) || (c[i]>=97 && c[i]<=122))
            grap++;
        else
            other++;
    }

    printf("���ֵĸ���Ϊ��%d\n",num);
    printf("��ĸ�ĸ���Ϊ��%d\n",grap);
    printf("�����ַ��ĸ���Ϊ��%d\n",other);
    return 0;
}







