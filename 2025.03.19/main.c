//题目一
/*
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 定义链表节点结构
typedef struct Node {
    char data; // 数据域
    struct Node* next; // 指针域
} Node;

// 创建新节点的函数
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 将线性链表分割为三个循环链表的函数
void splitList(Node* head, Node** letterHead, Node** digitHead, Node** otherHead) {
    if (head == NULL) {
        printf("原链表为空\n");
        return;
    }

    // 初始化三个循环链表的头节点和尾节点指针
    Node* letterTail = NULL;
    Node* digitTail = NULL;
    Node* otherTail = NULL;

    Node* current = head; // 当前遍历的节点
    while (current != NULL) {
        Node* nextNode = current->next; // 保存下一个节点
        current->next = NULL; // 断开当前节点的链接

        if (isalpha(current->data)) { // 字母字符
            if (*letterHead == NULL) { // 如果字母链表为空
                *letterHead = current;
                letterTail = current;
            } else {
                letterTail->next = current;
                letterTail = current;
            }
        } else if (isdigit(current->data)) { // 数字字符
            if (*digitHead == NULL) { // 如果数字链表为空
                *digitHead = current;
                digitTail = current;
            } else {
                digitTail->next = current;
                digitTail = current;
            }
        } else { // 其他字符
            if (*otherHead == NULL) { // 如果其他字符链表为空
                *otherHead = current;
                otherTail = current;
            } else {
                otherTail->next = current;
                otherTail = current;
            }
        }

        current = nextNode; // 移动到下一个节点
    }

    // 将三个链表各自构造成循环链表
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

// 打印循环链表的函数
void printCircularList(Node* head) {
    if (head == NULL) {
        printf("链表为空\n");
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
    // 创建一个示例线性链表
    Node* head = createNode('a');
    head->next = createNode('1');
    head->next->next = createNode('@');
    head->next->next->next = createNode('B');
    head->next->next->next->next = createNode('7');
    head->next->next->next->next->next = createNode('#');

    Node* letterHead = NULL;
    Node* digitHead = NULL;
    Node* otherHead = NULL;

    // 调用函数分割链表
    splitList(head, &letterHead, &digitHead, &otherHead);

    // 打印结果
    printf("字母字符循环链表：\n");
    printCircularList(letterHead);

    printf("数字字符循环链表：\n");
    printCircularList(digitHead);

    printf("其他字符循环链表：\n");
    printCircularList(otherHead);

    return 0;
}
*/


//题目二
/*
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data; // 数据域
    struct Node* next; // 指针域
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表的函数
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 就地逆置单链表的函数
void reverseList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // 如果链表为空或只有一个节点，无需逆置
        return;
    }

    Node* prev = NULL; // 前一个节点
    Node* current = *head; // 当前节点
    Node* next = NULL; // 下一个节点

    while (current != NULL) {
        next = current->next; // 保存下一个节点
        current->next = prev; // 反转当前节点的指针
        prev = current; // 移动prev和current
        current = next;
    }

    *head = prev; // 更新头指针
}

int main() {
    // 创建一个示例单链表
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原始链表：\n");
    printList(head);

    // 调用就地逆置函数
    reverseList(&head);

    printf("逆置后的链表：\n");
    printList(head);

    return 0;
}
*/


//题目三
/*
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data; // 数据域
    struct Node* next; // 指针域
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表的函数
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 删除链表中所有值相同的元素，只保留一个
void removeDuplicates(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // 如果链表为空或只有一个节点，无需处理
        return;
    }

    Node* current = *head; // 当前节点
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // 如果当前节点和下一个节点的值相同
            Node* temp = current->next; // 保存下一个节点
            while (temp != NULL && temp->data == current->data) {
                // 跳过所有相同值的节点
                temp = temp->next;
            }
            current->next = temp; // 跳过所有相同值的节点
        } else {
            current = current->next; // 移动到下一个节点
        }
    }
}

int main() {
    // 创建一个示例单链表
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(4);
    head->next->next->next->next->next->next = createNode(5);

    printf("原始链表：\n");
    printList(head);

    // 调用函数删除重复元素
    removeDuplicates(&head);

    printf("删除重复元素后的链表：\n");
    printList(head);

    return 0;
}

*/




//题目四
/*
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data; // 数据域
    struct Node* next; // 指针域
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 打印链表的函数
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// 交换两个节点的数据
void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// 单链表冒泡排序
void bubbleSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        // 如果链表为空或只有一个节点，无需排序
        return;
    }

    int swapped;
    Node* lastNode = NULL; // 指向最后一个已排序的节点

    do {
        swapped = 0; // 标记是否发生了交换
        Node* current = head; // 当前节点
        Node* prev = NULL; // 当前节点的前一个节点

        while (current->next != lastNode) {
            if (current->data > current->next->data) {
                // 交换当前节点和下一个节点的数据
                swapNodes(current, current->next);
                swapped = 1; // 发生了交换
            }
            prev = current;
            current = current->next;
        }
        lastNode = current; // 更新最后一个已排序的节点
    } while (swapped); // 如果没有发生交换，说明已经排序完成
}

int main() {
    // 创建一个示例单链表
    Node* head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(8);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);

    printf("原始链表：\n");
    printList(head);

    // 调用冒泡排序函数
    bubbleSort(head);

    printf("排序后的链表：\n");
    printList(head);

    return 0;
}
*/




#include <stdio.h>
#include <stdlib.h>

// 定义双向循环链表节点结构
typedef struct Node {
    int data; // 数据域
    int freq; // 访问频度域
    struct Node* pre; // 前驱指针
    struct Node* next; // 后继指针
} Node;

// 创建新节点的函数
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->freq = 0;
    newNode->pre = newNode;
    newNode->next = newNode;
    return newNode;
}

// 初始化双向循环链表的函数
Node* initList() {
    Node* head = createNode(0); // 创建头节点
    return head;
}

// 在链表中插入新节点的函数
void insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->pre = head->pre;
    newNode->next = head;
    head->pre->next = newNode;
    head->pre = newNode;
}

// 打印双向循环链表的函数
void printList(Node* head) {
    if (head->next == head) {
        printf("链表为空\n");
        return;
    }

    Node* current = head->next;
    do {
        printf("data: %d, freq: %d -> ", current->data, current->freq);
        current = current->next;
    } while (current != head);
    printf("head\n");
}

// Locate操作的函数
void locate(Node* head, int x) {
    if (head->next == head) {
        printf("链表为空\n");
        return;
    }

    Node* current = head->next;
    int found = 0;

    // 遍历链表，查找值为x的节点
    do {
        if (current->data == x) {
            found = 1;
            break;
        }
        current = current->next;
    } while (current != head);

    if (found) {
        // 如果找到该节点，增加访问频度
        current->freq++;

        // 如果当前节点的频度大于其前驱节点的频度，则需要调整位置
        while (current->pre != head && current->freq > current->pre->freq) {
            // 交换当前节点和前驱节点的位置
            Node* pre = current->pre;
            Node* next = current->next;

            // 调整指针
            pre->pre->next = current;
            current->pre = pre->pre;

            current->next = pre;
            pre->pre = current;

            pre->next = next;
            next->pre = pre;
        }
    } else {
        printf("未找到值为 %d 的节点\n", x);
    }
}

int main() {
    // 初始化双向循环链表
    Node* head = initList();

    // 插入一些节点
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    printf("初始链表：\n");
    printList(head);

    // 执行Locate操作
    locate(head, 20);
    printf("执行Locate(20)后的链表：\n");
    printList(head);

    locate(head, 20);
    printf("执行Locate(20)后的链表：\n");
    printList(head);

    locate(head, 30);
    printf("执行Locate(30)后的链表：\n");
    printList(head);

    locate(head, 50); // 未找到的测试
    printf("执行Locate(50)后的链表：\n");
    printList(head);

    return 0;
}

