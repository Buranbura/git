#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

char find_first_not_in_y(Node* x, Node* y) {
    // 遍历链表x中的每个节点
    while (x != NULL) {
        char current = x->data;
        Node* y_ptr = y;
        int found = 0;

        // 在链表y中查找当前字符
        while (y_ptr != NULL) {
            if (y_ptr->data == current) {
                found = 1;
                break;
            }
            y_ptr = y_ptr->next;
        }

        // 若未找到则立即返回该字符
        if (!found) {
            return current;
        }

        x = x->next;
    }

    // 所有字符都存在于y中则返回空字符
    return '\0';
}

/* 辅助函数：创建链表节点 */
Node* create_node(char c) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = c;
    new_node->next = NULL;
    return new_node;
}

/* 示例用法 */
int main() {
    // 创建示例链表 x: a->b->c
    Node* x = create_node('a');
    x->next = create_node('b');
    x->next->next = create_node('c');

    // 创建示例链表 y: d->b->e
    Node* y = create_node('d');
    y->next = create_node('b');
    y->next->next = create_node('e');

    char result = find_first_not_in_y(x, y);
    if (result != '\0') {
        printf("第一个不在y中的字符：%c\n", result);  // 输出 a
    } else {
        printf("所有字符都在y中存在\n");
    }

    // 释放内存（实际使用时需完整遍历链表释放）
    free(x->next->next);
    free(x->next);
    free(x);
    free(y->next->next);
    free(y->next);
    free(y);

    return 0;
}
