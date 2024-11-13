
//飞机
/*#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("     **\n");
    printf("************\n");
    printf("************\n");
    printf("    *  *\n");
    printf("    *  *\n");
    return 0;
}*/



//输入多组数，判断是否为天才
/*#include <stdio.h>
int main()
{
    int iq;
    while(scanf("%d",&iq)==1)
    {
        if(iq>=140)
            printf("Genius\n");
    }
    return 0;
}*/




/*#include <stdio.h>
#include <math.h>
int main()
{
    int a,b,c;
    float s,area;
    scanf("%d %d %d",&a,&b,&c);
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("%.3f",area);
    return 0;
}*/




/*#include <stdio.h>
#define PI 3.14
int main()
{
    double r,h;
    float C1,Sb,Vb;
    scanf("%lf %lf",&r,&h);
    C1=2*PI*r;
    Sb=4*PI*r*r;
    Vb=PI*r*r*h;
    printf("C1=%.2f\n",C1);
    printf("Sb=%.2f\n",Sb);
    printf("Vb=%.2f\n",Vb);
    return 0;
}*/





#include <stdio.h>
int main()
{

    int a[100];
    int i,j,p;
    for(i=0;i<100;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<100;i=i+1)
        {
            for(j=0;j<100-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    p=a[j];
                    a[j]=a[j+1];
                    a[j+1]=p;
                }
            }
        }
    for(j=0;j<100;j=j+1)
    {
        printf("%d\n",a[j]);
    }
    return 0;
}












