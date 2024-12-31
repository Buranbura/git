#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define COURSE_COUNT 4

typedef struct {
    int num;
    char sex[10];
    char name[10];
    int scores[COURSE_COUNT];
    double average;
} Student;

void inputStudents(Student students[], int N) {
    for (int i = 0; i < N; i++) {
        printf("请输入第%d个学生的学号：", i + 1);
        scanf("%d", &students[i].num);
        getchar(); // 吸收换行符

        printf("请输入学生性别：");
        fgets(students[i].sex, sizeof(students[i].sex), stdin);
        students[i].sex[strcspn(students[i].sex, "\n")] = 0; // 移除换行符

        printf("请输入学生姓名：");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // 移除换行符

        printf("请输入四门课的成绩：");
        for (int j = 0; j < COURSE_COUNT; j++) {
            scanf("%d", &students[i].scores[j]);
        }
    }
}

void calculateAverages(Student students[], int N) {
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < COURSE_COUNT; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = sum / COURSE_COUNT;
    }
}

void printTopStudent(Student students[], int N) {
    Student topStudent = students[0];
    int topIndex = 0;
    for (int i = 1; i < N; i++) {
        if (students[i].average > topStudent.average) {
            topStudent = students[i];
            topIndex = i;
        }
    }
    printf("学号\t|性别\t|姓名\t|平均成绩\n");
    printf("%d\t|%s\t|%s\t|%.2f\n", topStudent.num, topStudent.sex, topStudent.name, topStudent.average);
}

int main() {
    int N;
    printf("请输入学生数量 N：");
    scanf("%d", &N);
    getchar(); // 吸收换行符

    Student students[MAX_STUDENTS];
    inputStudents(students, N);
    calculateAverages(students, N);
    printTopStudent(students, N);

    return 0;
}
