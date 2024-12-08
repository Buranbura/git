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





/*#include <stdio.h>
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
}*/





/*#include <stdio.h>

// 函数声明
int isLeapYear(int year);
int getDaysInMonth(int year, int month);
int calculateDays(int year, int month, int day);
int calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay);
int calculateDaysToNextBirthday(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay);

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;
    int age, daysToNextBirthday;

    // 获取用户的出生年月日
    printf("请输入您的出生年月日（格式：YYYY MM DD）：");
    scanf("%d %d %d", &birthYear, &birthMonth, &birthDay);

    // 获取当前日期
    printf("请输入当前日期（格式：YYYY MM DD）：");
    scanf("%d %d %d", &currentYear, &currentMonth, &currentDay);

    // 计算年龄和距离下一次生日的天数
    age = calculateAge(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);
    daysToNextBirthday = calculateDaysToNextBirthday(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);

    // 输出结果
    printf("您的周岁年龄是：%d\n", age);
    printf("您距离下一次生日还有：%d 天\n", daysToNextBirthday);

    return 0;
}

// 判断是否为闰年
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取月份的天数
int getDaysInMonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// 计算从年初到指定日期的天数
int calculateDays(int year, int month, int day) {
    int days = 0;
    for (int i = 1; i < month; ++i) {
        days += getDaysInMonth(year, i);
    }
    days += day;
    return days;
}

// 计算周岁年龄
int calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

// 计算距离下一次生日的天数
int calculateDaysToNextBirthday(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    int currentDays = calculateDays(currentYear, currentMonth, currentDay);
    int nextBirthdayDays = calculateDays(currentYear, birthMonth, birthDay);

    if (currentMonth > birthMonth || (currentMonth == birthMonth && currentDay >= birthDay)) {
        // 如果今年的生日已经过了，计算到明年生日的天数
        nextBirthdayDays = calculateDays(currentYear + 1, birthMonth, birthDay);
    }

    // 计算距离下一次生日的天数
    int daysToNextBirthday = nextBirthdayDays - currentDays;
    if (daysToNextBirthday < 0) {
        // 如果计算结果为负数，说明今年的生日还没到，需要加上今年剩余的天数
        daysToNextBirthday += 365 + isLeapYear(currentYear);
    }
    return daysToNextBirthday;
}*/





























