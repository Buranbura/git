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

    printf("������һ��������");
    scanf("%d", &x);
    int nearest = nearest_fibo(x);
    printf("��ӽ�%d��Fibonacci���ǣ�%d\n", x, nearest);

    return 0;
}*/




/*#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// ��ֵջ�ṹ
typedef struct {
    double items[MAX_SIZE];
    int top;
} NumStack;

// ������ջ�ṹ
typedef struct {
    char items[MAX_SIZE];
    int top;
} OpStack;

// ��ʼ����ֵջ
void initNumStack(NumStack *s) {
    s->top = -1;
}

// ��ʼ��������ջ
void initOpStack(OpStack *s) {
    s->top = -1;
}

// ѹ����ֵջ
void pushNum(NumStack *s, double num) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = num;
    } else {
        printf("Number stack overflow\n");
        exit(1);
    }
}

// ѹ�������ջ
void pushOp(OpStack *s, char op) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++s->top] = op;
    } else {
        printf("Operator stack overflow\n");
        exit(1);
    }
}

// ����ֵջ������ֵ
double popNum(NumStack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    } else {
        printf("Number stack underflow\n");
        exit(1);
    }
}

// �Ӳ�����ջ����������
char popOp(OpStack *s) {
    if (s->top >= 0) {
        return s->items[s->top--];
    } else {
        printf("Operator stack underflow\n");
        exit(1);
    }
}

// ��ȡ���������ȼ�
int getPrecedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0; // �ǲ�������δ֪������
    }
}

// �����������ı��ʽ
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

// ������
int main() {
    NumStack numStack;
    OpStack opStack;
    initNumStack(&numStack);
    initOpStack(&opStack);

    char op;
    double num;
    printf("����������������ʽ��");
    while ((op = getchar()) != '\n' && op != EOF) {
        if (isdigit(op) || op == '.') {
            ungetc(op, stdin); // ���ַ��Ż�������
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

    // ����ʣ��Ĳ�����
    while (opStack.top >= 0) {
        double val2 = popNum(&numStack);
        double val1 = popNum(&numStack);
        char op1 = popOp(&opStack);
        pushNum(&numStack, evaluate(val1, val2, op1));
    }

    // ���ս����numStack�Ķ���
    printf("����ǣ�%lf\n", popNum(&numStack));

    return 0;
}*/





/*#include <stdio.h>
#include <ctype.h>

#define MAX_EXPR_LENGTH 100

// ��������
int checkExpression(const char *expr);
int checkOperands(const char *expr, int start, int *end);
int checkOperators(const char *expr, int start, int *end);

int main() {
    char expression[MAX_EXPR_LENGTH];

    printf("������һ���򵥵�����������ʽ��");
    fgets(expression, MAX_EXPR_LENGTH, stdin); // ��ȡһ������
    expression[strcspn(expression, "\n")] = 0; // ȥ�����з�

    if (checkExpression(expression)) {
        printf("���ʽ��ȷ��\n");
    } else {
        printf("���ʽ����ȷ��\n");
    }

    return 0;
}

// �����ʽ�Ƿ���ȷ
int checkExpression(const char *expr) {
    int operandCount = 0, operatorCount = 0;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (isdigit(expr[i])) {
            operandCount++;
        } else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            operatorCount++;
        }
    }
    // ���������Ͳ������������Ƿ�ƥ��
    if (operandCount != operatorCount + 1) {
        printf("��������ƥ�䡣\n");
        return 0;
    }
    // ���������Ƿ�ƥ��
    int end = 0;
    if (!checkOperators(expr, 0, &end)) {
        printf("��������ƥ�䡣\n");
        return 0;
    }
    // ���������Ƿ�ƥ��
    if (!checkOperands(expr, 0, &end)) {
        printf("��������ƥ�䡣\n");
        return 0;
    }
    return 1;
}

// ���������Ƿ�ƥ��
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

// ���������Ƿ�ƥ��
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

// ��������
int isLeapYear(int year);
int getDaysInMonth(int year, int month);
int calculateDays(int year, int month, int day);
int calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay);
int calculateDaysToNextBirthday(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay);

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;
    int age, daysToNextBirthday;

    // ��ȡ�û��ĳ���������
    printf("���������ĳ��������գ���ʽ��YYYY MM DD����");
    scanf("%d %d %d", &birthYear, &birthMonth, &birthDay);

    // ��ȡ��ǰ����
    printf("�����뵱ǰ���ڣ���ʽ��YYYY MM DD����");
    scanf("%d %d %d", &currentYear, &currentMonth, &currentDay);

    // ��������;�����һ�����յ�����
    age = calculateAge(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);
    daysToNextBirthday = calculateDaysToNextBirthday(birthYear, birthMonth, birthDay, currentYear, currentMonth, currentDay);

    // ������
    printf("�������������ǣ�%d\n", age);
    printf("��������һ�����ջ��У�%d ��\n", daysToNextBirthday);

    return 0;
}

// �ж��Ƿ�Ϊ����
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ��ȡ�·ݵ�����
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

// ����������ָ�����ڵ�����
int calculateDays(int year, int month, int day) {
    int days = 0;
    for (int i = 1; i < month; ++i) {
        days += getDaysInMonth(year, i);
    }
    days += day;
    return days;
}

// ������������
int calculateAge(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

// ���������һ�����յ�����
int calculateDaysToNextBirthday(int birthYear, int birthMonth, int birthDay, int currentYear, int currentMonth, int currentDay) {
    int currentDays = calculateDays(currentYear, currentMonth, currentDay);
    int nextBirthdayDays = calculateDays(currentYear, birthMonth, birthDay);

    if (currentMonth > birthMonth || (currentMonth == birthMonth && currentDay >= birthDay)) {
        // �������������Ѿ����ˣ����㵽�������յ�����
        nextBirthdayDays = calculateDays(currentYear + 1, birthMonth, birthDay);
    }

    // ���������һ�����յ�����
    int daysToNextBirthday = nextBirthdayDays - currentDays;
    if (daysToNextBirthday < 0) {
        // ���������Ϊ������˵����������ջ�û������Ҫ���Ͻ���ʣ�������
        daysToNextBirthday += 365 + isLeapYear(currentYear);
    }
    return daysToNextBirthday;
}*/





























