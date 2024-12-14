/*#include <stdio.h>
#include <stdlib.h>

union
{
    char c[2];
    int x;
}
s;

int main()
{
    s.x = 0x4241;
    printf("s.c[0]的十进制值为：%d, s.c[1]的：%d", s.c[0], s.c[1]);
    return 0;
}*/



/*#include <stdio.h>
#include <string.h>

#define STUDENT_COUNT 6

// 定义学生结构体
typedef struct {
    char id[20];
    char name[20];
    int scores[3];
    double average;
} Student;

// 函数声明
void inputStudents(Student students[], int count);
void printReport(const Student students[], int count);
void calculateAverages(Student students[], int count);
void sortStudentsByAverage(Student students[], int count);
void printTopFive(const Student students[], int count);

int main() {
    Student students[STUDENT_COUNT];

    // 输入学生数据
    inputStudents(students, STUDENT_COUNT);

    // 计算平均分
    calculateAverages(students, STUDENT_COUNT);

    // 按平均分排序
    sortStudentsByAverage(students, STUDENT_COUNT);

    // 打印成绩报表
    printReport(students, STUDENT_COUNT);

    // 打印平均分前5名的学生信息
    printTopFive(students, STUDENT_COUNT);

    return 0;
}

// 输入学生数据
void inputStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("请输入第%d个学生的学号：", i + 1);
        scanf("%s", students[i].id);
        getchar(); // 吸收换行符
        printf("请输入学生姓名：");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // 移除换行符
        for (int j = 0; j < 3; j++) {
            printf("请输入第%d门功课成绩：", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
    }
}

// 计算平均分
void calculateAverages(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = sum / 3.0;
    }
}

// 按平均分排序
void sortStudentsByAverage(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// 打印成绩报表
void printReport(const Student students[], int count) {
    printf("\t\t\t成绩报表\n");
    printf("学号\t|姓名\t|第一门课成绩\t|第二门课程绩\t|第三门课成绩\t|平均分\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t|%s\t|%d\t\t|%d\t\t|%d\t\t|%.2f\n",
               students[i].id, students[i].name, students[i].scores[0],
               students[i].scores[1], students[i].scores[2], students[i].average);
    }
}

// 打印平均分前5名的学生信息
void printTopFive(const Student students[], int count) {
    printf("平均分在前5名的学生信息：\n");
    printf("姓名\t|平均分\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t|%.2f\n", students[i].name, students[i].average);
    }
}*/





#include <stdio.h>
#include <string.h>

#define WORKER_COUNT 4

//定义结构体
typedef struct
{
    char id[20];
    char name[20];
    char number[20];
}Worker;

//函数声明
void input(Worker workers[], int count);
void print(Worker workers[], int count);

//输入数据
void input(Worker workers[], int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("请输入第%d个人的工作证号：", i + 1);
        scanf("%s", workers[i].id);

        getchar();      //吸取换行符

        printf("请输入人员姓名：");
        fgets(workers[i].name, sizeof(workers[i].name), stdin);
        workers[i].name[strcspn(workers[i].name, "\n")] = 0;

        printf("请输入电话号码：");
        fgets(workers[i].number, sizeof(workers[i].number), stdin);
        workers[i].number[strcspn(workers[i].number, "\n")] = 0;
    }
}

//打印通讯录
void print(Worker workers[], int count)
{
    printf("\t\t\t通讯录\n");
    printf("工作证号\t\t|姓名\t\t\t|电话号码\n");
    for(int i = 0; i < count; i++)
    {
        printf("%-10s\t\t|%-10s\t\t|%-10s\n", workers[i].id, workers[i].name, workers[i].number);
    }
}

//主函数
int main()
{
    Worker workers[WORKER_COUNT];
    input(workers, WORKER_COUNT);
    print(workers, WORKER_COUNT);

    return 0;

}







