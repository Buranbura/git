/*//��Ŀһ
#include <stdio.h>

// �����������ڷǵݼ�˳����в���Ԫ��X
void insertElement(int arr[], int *length, int X) {
    // �ҵ�����λ��
    int i;
    for (i = 0; i < *length; i++) {
        if (arr[i] > X) {
            break;
        }
    }

    // ������β����ʼ����Ԫ������ƶ�һλ��Ϊ����Ԫ���ڳ��ռ�
    for (int j = *length; j > i; j--) {
        arr[j] = arr[j - 1];
    }

    // ����Ԫ��X
    arr[i] = X;

    // ����˳���ĳ���
    (*length)++;
}

int main() {
    // ʾ��˳���
    int arr[] = {1, 3, 5, 7, 9};
    int length = sizeof(arr) / sizeof(arr[0]); // ˳���ǰ����
    int X = 6; // Ҫ�����Ԫ��

    // ���ò��뺯��
    insertElement(arr, &length, X);

    // ���������˳���
    printf("������˳���Ϊ��\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
*/


/*
//��Ŀ��
#include <stdio.h>

// ����������ɾ��˳����дӵ�i��Ԫ�ؿ�ʼ��k��Ԫ��
void deleteElements(int arr[], int *length, int i, int k) {
    // ��������������Ч��
    if (i < 0 || i >= *length) {
        printf("ɾ��λ����Ч��\n");
        return;
    }
    if (k <= 0) {
        printf("ɾ��������Ч��\n");
        return;
    }
    if (i + k > *length) {
        printf("ɾ����Χ����˳����ȣ�\n");
        return;
    }

    // ����i+k��Ԫ�ؼ���֮���Ԫ����ǰ�ƶ�k��λ��
    for (int j = i + k; j < *length; j++) {
        arr[j - k] = arr[j];
    }

    // ����˳���ĳ���
    *length -= k;
}

int main() {
    // ʾ��˳���
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]); // ˳���ǰ����

    // ����ɾ������ʼλ��i��ɾ����Ԫ�ظ���k
    int i, k;
    printf("������ɾ������ʼλ��i��ɾ����Ԫ�ظ���k��");
    scanf("%d %d", &i, &k);

    // ����ɾ������
    deleteElements(arr, &length, i, k);

    // ���ɾ�����˳���
    printf("ɾ�����˳���Ϊ��\n");
    for (int j = 0; j < length; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");

    return 0;
}

*/





//��Ŀ��
#include <stdio.h>

// �����������͵�����˳���
void reverseArray(int arr[], int length) {
    int left = 0;          // ��ָ��ָ���������ʼλ��
    int right = length - 1; // ��ָ��ָ�������ĩβλ��

    // ��������ָ����ָ���Ԫ�أ�ֱ������ָ������
    while (left < right) {
        // ����arr[left]��arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        // ��ָ�������ƶ�����ָ�������ƶ�
        left++;
        right--;
    }
}

int main() {
    // ʾ��˳���
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int length = sizeof(arr) / sizeof(arr[0]); // ˳���ĳ���

    // ��ӡ����ǰ��˳���
    printf("����ǰ��˳���Ϊ��\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �������ú���
    reverseArray(arr, length);

    // ��ӡ���ú��˳���
    printf("���ú��˳���Ϊ��\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

