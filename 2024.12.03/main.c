/*#include <stdio.h>
#include <stdlib.h>

int nearest_fibo(int x)
{
    if (x < fibo(1))
        return fibo(1);

    int i = 0;
    int fibo_i = fibo(i);
    int fibo_i_plus_1 = fibo(i + 1);

    while (fibo_i_plus_1 < x)
    {
        i++;
        fibo_i = fibo_i_plus_1;
        fibo_i_plus_1 = fibo(i + 1);
    }

    if(x - fibo_i <= fibo_i_plus_1 - x)
        return fibo_i;
    else
        return fibo_i_plus_1;
}

int fibo(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c,i;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int x;

    printf("请输入一个整数：");
    scanf("%d", &x);
    int nearest = nearest_fibo(x);
    printf("最接近%d的Fibonacci数是：%d\n", x, nearest);

    return 0;
}*/




/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// 数值栈结构
typedef struct {
    double items[MAX_SIZE];
    int top;
} NumStack;

// 操作符栈结构
typedef struct {
    char items[MAX_SIZE];
    int top;
} OpStack;

// 初始化数值栈
void initNumStack(NumStack *s) {
    s->top = -1;
}

// 初始化操作符栈
void initOpStack(OpStack *s) {
    s->top = -1;
}

// 压入数值栈
void pushNum(NumStack *s, double num) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = num;
    } else {
        printf("Number stack overflow\n");
        exit(1);
    }
}

// 压入操作符栈
void pushOp(OpStack *s, char op) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = op;
    } else {
        printf("Operator stack overflow\n");
        exit(1);
    }
}

// 从数值栈弹出数值
double popNum(NumStack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    } else {
        printf("Number stack underflow\n");
        exit(1);
    }
}

// 从操作符栈弹出操作符
char popOp(OpStack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    } else {
        printf("Operator stack underflow\n");
        exit(1);
    }
}

// 获取操作符优先级
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // 非操作符或未知操作符
    }
}

// 计算两个数的表达式
double evaluate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Division by zero\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// 主函数
int main() {
    NumStack numStack;
    OpStack opStack;
    initNumStack(&numStack);
    initOpStack(&opStack);

    char op;
    double num;
    printf("请输入四则运算表达式：");
    while ((op = getchar()) != '\n' && op != EOF) {
        if (isdigit(op) || op == '.') {
            ungetc(op, stdin); // 将字符放回输入流
            scanf("%lf", &num);
            pushNum(&numStack, num);
        } else if (op == '+' || op == '-' || op == '*' || op == '/') {
            while (opStack.top >= 0 && getPrecedence(opStack.items[opStack.top]) >= getPrecedence(op)) {
                double val2 = popNum(&numStack);
                double val1 = popNum(&numStack);
                char op1 = popOp(&opStack);
                pushNum(&numStack, evaluate(val1, val2, op1));
            }
            pushOp(&opStack, op);
        }
    }

    // 处理剩余的操作符
    while (opStack.top >= 0) {
        double val2 = popNum(&numStack);
        double val1 = popNum(&numStack);
        char op1 = popOp(&opStack);
        pushNum(&numStack, evaluate(val1, val2, op1));
    }

    // 最终结果在numStack的顶部
    printf("结果是：%lf\n", popNum(&numStack));

    return 0;
}*/





#include <stdio.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100

// 函数声明
int checkExpression(const char *expr);
int checkOperands(const char *expr, int start, int *end);
int checkOperators(const char *expr, int start, int *end);

int main() {
    char expression[MAX_EXPR_LENGTH];

    printf("请输入一个简单的四则运算表达式：");
    fgets(expression, MAX_EXPR_LENGTH, stdin); // 读取一行输入
    expression[strcspn(expression, "\n")] = 0; // 去除换行符

    if (checkExpression(expression)) {
        printf("表达式正确。\n");
    } else {
        printf("表达式不正确。\n");
    }

    return 0;
}

// 检查表达式是否正确
int checkExpression(const char *expr) {
    int operandCount = 0, operatorCount = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            operandCount++;
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            operatorCount++;
        }
    }
    // 检查操作数和操作符的数量是否匹配
    if (operandCount != operatorCount + 1) {
        printf("操作数不匹配。\n");
        return 0;
    }
    // 检查操作符是否匹配
    int end = 0;
    if (!checkOperators(expr, 0, &end)) {
        printf("操作符不匹配。\n");
        return 0;
    }
    // 检查操作数是否匹配
    if (!checkOperands(expr, 0, &end)) {
        printf("操作数不匹配。\n");
        return 0;
    }
    return 1;
}

// 检查操作符是否匹配
int checkOperators(const char *expr, int start, int *end) {
    int opCount = 0;
    int i;
    for (i = start; expr[i] != '\0'; i++) {
        if (!isdigit(expr[i]) && expr[i] != ' ') {
            opCount++;
            if (opCount > 1) {
                *end = i;
                return 0;
            }
        }
    }
    *end = i;
    return 1;
}

// 检查操作数是否匹配
int checkOperands(const char *expr, int start, int *end) {
    int numCount = 0;
    int i;
    for (i = start; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            numCount++;
            if (numCount > 1 && (expr[i-1] != '+' && expr[i-1] != '-' && expr[i-1] != '*' && expr[i-1] != '/')) {
                *end = i;
                return 0;
            }
        }
    }
    *end = i;
    return 1;
}













