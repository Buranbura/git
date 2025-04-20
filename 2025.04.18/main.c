#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

char find_first_not_in_y(Node* x, Node* y) {
    // ��������x�е�ÿ���ڵ�
    while (x != NULL) {
        char current = x->data;
        Node* y_ptr = y;
        int found = 0;

        // ������y�в��ҵ�ǰ�ַ�
        while (y_ptr != NULL) {
            if (y_ptr->data == current) {
                found = 1;
                break;
            }
            y_ptr = y_ptr->next;
        }

        // ��δ�ҵ����������ظ��ַ�
        if (!found) {
            return current;
        }

        x = x->next;
    }

    // �����ַ���������y���򷵻ؿ��ַ�
    return '\0';
}

/* ������������������ڵ� */
Node* create_node(char c) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = c;
    new_node->next = NULL;
    return new_node;
}

/* ʾ���÷� */
int main() {
    // ����ʾ������ x: a->b->c
    Node* x = create_node('a');
    x->next = create_node('b');
    x->next->next = create_node('c');

    // ����ʾ������ y: d->b->e
    Node* y = create_node('d');
    y->next = create_node('b');
    y->next->next = create_node('e');

    char result = find_first_not_in_y(x, y);
    if (result != '\0') {
        printf("��һ������y�е��ַ���%c\n", result);  // ��� a
    } else {
        printf("�����ַ�����y�д���\n");
    }

    // �ͷ��ڴ棨ʵ��ʹ��ʱ���������������ͷţ�
    free(x->next->next);
    free(x->next);
    free(x);
    free(y->next->next);
    free(y->next);
    free(y);

    return 0;
}
