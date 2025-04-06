//��Ŀһ
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// ��������ڵ�ṹ
typedef struct Node {
    char data; // ������
    struct Node* next; // ָ����
} Node;

// �����½ڵ�ĺ���
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ����������ָ�Ϊ����ѭ������ĺ���
void splitList(Node* head, Node** letterHead, Node** digitHead, Node** otherHead) {
    if (head == NULL) {
        printf("ԭ����Ϊ��\n");
        return;
    }

    // ��ʼ������ѭ�������ͷ�ڵ��β�ڵ�ָ��
    Node* letterTail = NULL;
    Node* digitTail = NULL;
    Node* otherTail = NULL;

    Node* current = head; // ��ǰ�����Ľڵ�
    while (current != NULL) {
        Node* nextNode = current->next; // ������һ���ڵ�
        current->next = NULL; // �Ͽ���ǰ�ڵ������

        if (isalpha(current->data)) { // ��ĸ�ַ�
            if (*letterHead == NULL) { // �����ĸ����Ϊ��
                *letterHead = current;
                letterTail = current;
            } else {
                letterTail->next = current;
                letterTail = current;
            }
        } else if (isdigit(current->data)) { // �����ַ�
            if (*digitHead == NULL) { // �����������Ϊ��
                *digitHead = current;
                digitTail = current;
            } else {
                digitTail->next = current;
                digitTail = current;
            }
        } else { // �����ַ�
            if (*otherHead == NULL) { // ��������ַ�����Ϊ��
                *otherHead = current;
                otherTail = current;
            } else {
                otherTail->next = current;
                otherTail = current;
            }
        }

        current = nextNode; // �ƶ�����һ���ڵ�
    }

    // ������������Թ����ѭ������
    if (letterTail != NULL) {
        letterTail->next = *letterHead;
    }
    if (digitTail != NULL) {
        digitTail->next = *digitHead;
    }
    if (otherTail != NULL) {
        otherTail->next = *otherHead;
    }
}

// ��ӡѭ������ĺ���
void printCircularList(Node* head) {
    if (head == NULL) {
        printf("����Ϊ��\n");
        return;
    }

    Node* current = head;
    do {
        printf("%c ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    // ����һ��ʾ����������
    Node* head = createNode('a');
    head->next = createNode('1');
    head->next->next = createNode('@');
    head->next->next->next = createNode('B');
    head->next->next->next->next = createNode('7');
    head->next->next->next->next->next = createNode('#');

    Node* letterHead = NULL;
    Node* digitHead = NULL;
    Node* otherHead = NULL;

    // ���ú����ָ�����
    splitList(head, &letterHead, &digitHead, &otherHead);

    // ��ӡ���
    printf("��ĸ�ַ�ѭ������\n");
    printCircularList(letterHead);

    printf("�����ַ�ѭ������\n");
    printCircularList(digitHead);

    printf("�����ַ�ѭ������\n");
    printCircularList(otherHead);

    return 0;
}
*/


//��Ŀ��
/*
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data; // ������
    struct Node* next; // ָ����
} Node;

// �����½ڵ�ĺ���
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����ĺ���
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// �͵����õ�����ĺ���
void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
        return;
    }

    Node* prev = NULL; // ǰһ���ڵ�
    Node* current = *head; // ��ǰ�ڵ�
    Node* next = NULL; // ��һ���ڵ�

    while (current != NULL) {
        next = current->next; // ������һ���ڵ�
        current->next = prev; // ��ת��ǰ�ڵ��ָ��
        prev = current; // �ƶ�prev��current
        current = next;
    }

    *head = prev; // ����ͷָ��
}

int main() {
    // ����һ��ʾ��������
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("ԭʼ����\n");
    printList(head);

    // ���þ͵����ú���
    reverseList(&head);

    printf("���ú������\n");
    printList(head);

    return 0;
}
*/


//��Ŀ��
/*
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data; // ������
    struct Node* next; // ָ����
} Node;

// �����½ڵ�ĺ���
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����ĺ���
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ɾ������������ֵ��ͬ��Ԫ�أ�ֻ����һ��
void removeDuplicates(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // �������Ϊ�ջ�ֻ��һ���ڵ㣬���账��
        return;
    }

    Node* current = *head; // ��ǰ�ڵ�
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // �����ǰ�ڵ����һ���ڵ��ֵ��ͬ
            Node* temp = current->next; // ������һ���ڵ�
            while (temp != NULL && temp->data == current->data) {
                // ����������ֵͬ�Ľڵ�
                temp = temp->next;
            }
            current->next = temp; // ����������ֵͬ�Ľڵ�
        } else {
            current = current->next; // �ƶ�����һ���ڵ�
        }
    }
}

int main() {
    // ����һ��ʾ��������
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("ԭʼ����\n");
    printList(head);

    // ���ú���ɾ���ظ�Ԫ��
    removeDuplicates(&head);

    printf("ɾ���ظ�Ԫ�غ������\n");
    printList(head);

    return 0;
}

*/




//��Ŀ��
/*
#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ
typedef struct Node {
    int data; // ������
    struct Node* next; // ָ����
} Node;

// �����½ڵ�ĺ���
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ��ӡ����ĺ���
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// ���������ڵ������
void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// ������ð������
void bubbleSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
        return;
    }

    int swapped;
    Node* lastNode = NULL; // ָ�����һ��������Ľڵ�

    do {
        swapped = 0; // ����Ƿ����˽���
        Node* current = head; // ��ǰ�ڵ�
        Node* prev = NULL; // ��ǰ�ڵ��ǰһ���ڵ�

        while (current->next != lastNode) {
            if (current->data > current->next->data) {
                // ������ǰ�ڵ����һ���ڵ������
                swapNodes(current, current->next);
                swapped = 1; // �����˽���
            }
            prev = current;
            current = current->next;
        }
        lastNode = current; // �������һ��������Ľڵ�
    } while (swapped); // ���û�з���������˵���Ѿ��������
}

int main() {
    // ����һ��ʾ��������
    Node* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);

    printf("ԭʼ����\n");
    printList(head);

    // ����ð��������
    bubbleSort(head);

    printf("����������\n");
    printList(head);

    return 0;
}
*/




#include <stdio.h>
#include <stdlib.h>

// ����˫��ѭ������ڵ�ṹ
typedef struct Node {
    int data; // ������
    int freq; // ����Ƶ����
    struct Node* pre; // ǰ��ָ��
    struct Node* next; // ���ָ��
} Node;

// �����½ڵ�ĺ���
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->freq = 0;
    newNode->pre = newNode;
    newNode->next = newNode;
    return newNode;
}

// ��ʼ��˫��ѭ������ĺ���
Node* initList() {
    Node* head = createNode(0); // ����ͷ�ڵ�
    return head;
}

// �������в����½ڵ�ĺ���
void insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->pre = head->pre;
    newNode->next = head;
    head->pre->next = newNode;
    head->pre = newNode;
}

// ��ӡ˫��ѭ������ĺ���
void printList(Node* head) {
    if (head->next == head) {
        printf("����Ϊ��\n");
        return;
    }

    Node* current = head->next;
    do {
        printf("data: %d, freq: %d -> ", current->data, current->freq);
        current = current->next;
    } while (current != head);
    printf("head\n");
}

// Locate�����ĺ���
void locate(Node* head, int x) {
    if (head->next == head) {
        printf("����Ϊ��\n");
        return;
    }

    Node* current = head->next;
    int found = 0;

    // ������������ֵΪx�Ľڵ�
    do {
        if (current->data == x) {
            found = 1;
            break;
        }
        current = current->next;
    } while (current != head);

    if (found) {
        // ����ҵ��ýڵ㣬���ӷ���Ƶ��
        current->freq++;

        // �����ǰ�ڵ��Ƶ�ȴ�����ǰ���ڵ��Ƶ�ȣ�����Ҫ����λ��
        while (current->pre != head && current->freq > current->pre->freq) {
            // ������ǰ�ڵ��ǰ���ڵ��λ��
            Node* pre = current->pre;
            Node* next = current->next;

            // ����ָ��
            pre->pre->next = current;
            current->pre = pre->pre;

            current->next = pre;
            pre->pre = current;

            pre->next = next;
            next->pre = pre;
        }
    } else {
        printf("δ�ҵ�ֵΪ %d �Ľڵ�\n", x);
    }
}

int main() {
    // ��ʼ��˫��ѭ������
    Node* head = initList();

    // ����һЩ�ڵ�
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    printf("��ʼ����\n");
    printList(head);

    // ִ��Locate����
    locate(head, 20);
    printf("ִ��Locate(20)�������\n");
    printList(head);

    locate(head, 20);
    printf("ִ��Locate(20)�������\n");
    printList(head);

    locate(head, 30);
    printf("ִ��Locate(30)�������\n");
    printList(head);

    locate(head, 50); // δ�ҵ��Ĳ���
    printf("ִ��Locate(50)�������\n");
    printList(head);

    return 0;
}

