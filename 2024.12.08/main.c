/*#include <stdio.h>
#include <stdlib.h>

int fun1(float (*a)[5], int n)
{
    float s;
    int i, j, count = 0;
    for(i = 0;i < n; i++)
    {
        for(s = 0, j = 0; j < 4; j++)
        {
            s = s + a[i][j];
        }
        a[i][4] = s / 4;
        if(a[i][4] >= 90)
            count++;
    }
    return count;
}

int main()
{
    float p[3][4] = { {90,98,90,99},{100,80,70,89},{30,60,80,90} };
    int count = fun1(p, 3);
    printf("平均成绩在90分以上的小组个数：%d", count);
    return 0;
}*/


#include <stdio.h>
   void main( )
   { int x,y,z;
    scanf("%d,%d,%d",&x,&y,&z);
    if (x<y)
        if (y<z)printf("%d\n",z);
        else printf("%d\n",y);
   else if (x<z)printf("%d\n",z);
         else printf("%d\n",x);
   }
