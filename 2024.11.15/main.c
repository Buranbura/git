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






/*#include <stdio.h>
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
}*/







/*#include <stdio.h>
int main()
{
    double p,r;

    printf("������һ���з���Աƽ��ÿ���÷�p��\n");
	scanf("%lf", &p);
	printf("������һ�з���Աƽ��ÿ������������\n");
	scanf("%lf", &r);

	if(p>=20 && r>=20)
        printf("���з���Ա�����۽��Ϊ������\n");
    else if(p>=15 && r>=15 || p>=20 || r>=20)
        printf("���з���Ա�����۽��Ϊ������\n");
    else if(p>=10 && r>=10 || p>=15 || r>=15)
        printf("���з���Ա�����۽��Ϊ���ϸ�\n");
    else
        printf("���з���Ա�����۽��Ϊ��ƽӹ\n");

    return 0;

}*/





/*#include <stdio.h>
int main()
{
    int x,y;
    printf("������ѧ���ɼ�:");
    scanf("%d%d",&x,&y);

    if(x>100 || x<0 || y>100 || y<0)
        printf("Error.\n");
    else if(x>=90 && y>=90)
        printf("����\n");
    else if(x>=60 && y>=60)
        printf("�ϸ�\n");
    else if((x<60 && y>=60) || (x>=60 && y<60))
        printf("�ϲ�\n");
    else
        printf("�ܲ�\n");

    return 0;
}*/






/*#include <stdio.h>
int main()
{
    double a,b,m,n,p,q;
    double k1,k2,k3;


    printf("�������һ��������꣺\n");
    scanf("%lf%lf",&a,&b);
    printf("������ڶ���������꣺\n");
    scanf("%lf%lf",&m,&n);
    printf("�����������������꣺\n");
    scanf("%lf%lf",&p,&q);

    k1=(b-n)/(a-m);
    k2=(b-q)/(a-p);
    k3=(n-q)/(m-p);

    if(k1==k2 && k2==k3)
        printf("������ͬһֱ����\n");
    else
        printf("���㲻��ͬһֱ����\n");

    return 0;

}*/





#include <stdio.h>
int main() {
	double a, b,c;

	printf("�����뿼����Ӣ��ɼ���");
	scanf("%lf",&a);
	printf("�����뿼������ѧ�ɼ���");
	scanf("%lf",&b);
	c=(a+b)/2;

	if(a>=90 && b>=90)
        printf("���㿼��");
    else if((a>=80 && b>=80) || (a>=60 && a<80 && b>80 && c>=80) || (a>80 && b>=60 && b<80 && c>=80))
        printf("���ÿ���");
    else if((a>=70 && b>=70) || (a>=60 && a<70 && b>70 && c>=70) || (a>70 && b>=60 && b<70 && c>=70))
        printf("�еȿ���");
    else if((a>=60 && b>=60) || (a<60 && b>60 && c>=60) || (a>60 && b<60 && c>=60))
        printf("������");
    else
        printf("��������");

	return 0;
}








