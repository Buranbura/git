/*#include <stdio.h>
#include <stdlib.h>

int fun1(float (*a)[5], int n)
{
    float s;
    int i, j, count = 0;
    for(i = 0; i < n; i++)
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
    float p[3][5] = {{99, 85, 76, 88}, {86, 88, 56, 78}, {91, 92, 97, 87}};
    int count = fun1(p, 3);
    printf("平均成绩在90分以上的小组个数：%d", count);
    return 0;
}*/





/*#include <stdio.h>
#include <stdlib.h>

void fun2(float a[][5], int N)
{
    float t;
    int i, j, k, p;
    for(i = 0; i < N - 1; i++)
    {
        p = i;
        for(k = i + 1; k < N; k++ )
        {
            if(a[k][4] > a[p][4])
            p = k;
        }
        if(p != i)
            for(j = 0; j <= 4; j++)
        {
            t = a[i][j];
            a[i][j] = a[p][j];
            a[p][j] = t;
        }
    }
}

int main()
{
    float f[][5] = {{99, 68, 75, 66, 77}, {89, 78, 86, 97, 87.5}, {77, 96, 85, 69, 81.75}};
    fun2(f, 3);
    float score;
    printf("排序后的成绩如下（平均成绩从高到低）：\n");
    for(int i = 0; i < 3; i++)
    {
        printf("第%d位的同学成绩：",i + 1);
        printf("%f", f[i][4]);
        printf("\n");
    }

    return 0;
}*/





/*#include <stdio.h>
#include <stdlib.h>
#define N 3
int main()
{
    int a[N][N] = {1,2,3,4,5,6,7,8,9};
    int i, s1 = 0, s2 = 0;
    for(i = 0; i< N; i++)
    {
        s1 = s1 + a[i][i];
        s2 = s2 + a[i][2 - i];
    }
    printf("3*3矩阵的对角线元素之和为:%d\n", s1 + s2);

    return 0;
}
*/




#include <stdio.h>
#define N 15

int fun(int *p, int target)
{
    int left = 0;
    int right = N - 1;
    int mid;
    while(left <= right)
    {
        mid = left + (right - left) / 2;
        if(p[mid] == target)
        {
            return mid;
        }
        else if(p[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return NULL;
}

int main()
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int target;
    int *result;
    printf("输入你想要查询的数:");
    scanf("%d", &target);
    result = fun(a, target);
    if(result != NULL)
    {
        printf("数字%d的地址为: %d\n", target, result);
    }
    else
    {
        printf("数字%d在该数组中未找到\n", target);
    }
    return 0;
}













