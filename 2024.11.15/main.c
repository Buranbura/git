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

    printf("90及90分以上的人数为：%d\n",a);
    printf("80~89分的人数为：%d\n",b);
    printf("70~79分的人数为：%d\n",c);
    printf("60~69分的人数为：%d\n",d);
    printf("60分以下的人数为：%d\n",e);
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

    printf("数字的个数为：%d\n",num);
    printf("字母的个数为：%d\n",grap);
    printf("其他字符的个数为：%d\n",other);
    return 0;
}*/







/*#include <stdio.h>
int main()
{
    double p,r;

    printf("请输入一个中锋球员平均每场得分p：\n");
	scanf("%lf", &p);
	printf("请输入一中锋球员平均每场篮板球数：\n");
	scanf("%lf", &r);

	if(p>=20 && r>=20)
        printf("该中锋球员的评价结果为：优秀\n");
    else if(p>=15 && r>=15 || p>=20 || r>=20)
        printf("该中锋球员的评价结果为：良好\n");
    else if(p>=10 && r>=10 || p>=15 || r>=15)
        printf("该中锋球员的评价结果为：合格\n");
    else
        printf("该中锋球员的评价结果为：平庸\n");

    return 0;

}*/





/*#include <stdio.h>
int main()
{
    int x,y;
    printf("请输入学生成绩:");
    scanf("%d%d",&x,&y);

    if(x>100 || x<0 || y>100 || y<0)
        printf("Error.\n");
    else if(x>=90 && y>=90)
        printf("优秀\n");
    else if(x>=60 && y>=60)
        printf("合格\n");
    else if((x<60 && y>=60) || (x>=60 && y<60))
        printf("较差\n");
    else
        printf("很差\n");

    return 0;
}*/






/*#include <stdio.h>
int main()
{
    double a,b,m,n,p,q;
    double k1,k2,k3;


    printf("请输入第一个点的坐标：\n");
    scanf("%lf%lf",&a,&b);
    printf("请输入第二个点的坐标：\n");
    scanf("%lf%lf",&m,&n);
    printf("请输入第三个点的坐标：\n");
    scanf("%lf%lf",&p,&q);

    k1=(b-n)/(a-m);
    k2=(b-q)/(a-p);
    k3=(n-q)/(m-p);

    if(k1==k2 && k2==k3)
        printf("三点在同一直线上\n");
    else
        printf("三点不在同一直线上\n");

    return 0;

}*/





#include <stdio.h>
int main() {
	double a, b,c;

	printf("请输入考生的英语成绩：");
	scanf("%lf",&a);
	printf("请输入考生的数学成绩：");
	scanf("%lf",&b);
	c=(a+b)/2;

	if(a>=90 && b>=90)
        printf("优秀考生");
    else if((a>=80 && b>=80) || (a>=60 && a<80 && b>80 && c>=80) || (a>80 && b>=60 && b<80 && c>=80))
        printf("良好考生");
    else if((a>=70 && b>=70) || (a>=60 && a<70 && b>70 && c>=70) || (a>70 && b>=60 && b<70 && c>=70))
        printf("中等考生");
    else if((a>=60 && b>=60) || (a<60 && b>60 && c>=60) || (a>60 && b<60 && c>=60))
        printf("及格考生");
    else
        printf("不及格考生");

	return 0;
}








