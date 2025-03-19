/*//题目一
#include <stdio.h>

// 函数声明：在非递减顺序表中插入元素X
void insertElement(int arr[], int *length, int X) {
    // 找到插入位置
    int i;
    for (i = 0; i < *length; i++) {
        if (arr[i] > X) {
            break;
        }
    }

    // 从数组尾部开始，将元素向后移动一位，为插入元素腾出空间
    for (int j = *length; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    // 插入元素X
    arr[i] = X;

    // 更新顺序表的长度
    (*length)++;
}

int main() {
    // 示例顺序表
    int arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(arr[0]); // 顺序表当前长度
    int X = 6; // 要插入的元素

    // 调用插入函数
    insertElement(arr, &length, X);

    // 输出插入后的顺序表
    printf("插入后的顺序表为：\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
*/


/*
//题目二
#include <stdio.h>

// 函数声明：删除顺序表中从第i个元素开始的k个元素
void deleteElements(int arr[], int *length, int i, int k) {
    // 检查输入参数的有效性
    if (i < 0 || i >= *length) {
        printf("删除位置无效！\n");
        return;
    }
    if (k <= 0) {
        printf("删除数量无效！\n");
        return;
    }
    if (i + k > *length) {
        printf("删除范围超出顺序表长度！\n");
        return;
    }

    // 将第i+k个元素及其之后的元素向前移动k个位置
    for (int j = i + k; j < *length; j++) {
        arr[j - k] = arr[j];
    }

    // 更新顺序表的长度
    *length -= k;
}

int main() {
    // 示例顺序表
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]); // 顺序表当前长度

    // 输入删除的起始位置i和删除的元素个数k
    int i, k;
    printf("请输入删除的起始位置i和删除的元素个数k：");
    scanf("%d %d", &i, &k);

    // 调用删除函数
    deleteElements(arr, &length, i, k);

    // 输出删除后的顺序表
    printf("删除后的顺序表为：\n");
    for (int j = 0; j < length; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}

*/





//题目三
#include <stdio.h>

// 函数声明：就地逆置顺序表
void reverseArray(int arr[], int length) {
    int left = 0;          // 左指针指向数组的起始位置
    int right = length - 1; // 右指针指向数组的末尾位置

    // 交换左右指针所指向的元素，直到两个指针相遇
    while (left < right) {
        // 交换arr[left]和arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // 左指针向右移动，右指针向左移动
        left++;
        right--;
    }
}

int main() {
    // 示例顺序表
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]); // 顺序表的长度

    // 打印逆置前的顺序表
    printf("逆置前的顺序表为：\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 调用逆置函数
    reverseArray(arr, length);

    // 打印逆置后的顺序表
    printf("逆置后的顺序表为：\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

