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
        printf("�������%d��ѧ����ѧ�ţ�", i + 1);
        scanf("%d", &students[i].num);
        getchar(); // ���ջ��з�

        printf("������ѧ���Ա�");
        fgets(students[i].sex, sizeof(students[i].sex), stdin);
        students[i].sex[strcspn(students[i].sex, "\n")] = 0; // �Ƴ����з�

        printf("������ѧ��������");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // �Ƴ����з�

        printf("���������ſεĳɼ���");
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
    printf("ѧ��\t|�Ա�\t|����\t|ƽ���ɼ�\n");
    printf("%d\t|%s\t|%s\t|%.2f\n", topStudent.num, topStudent.sex, topStudent.name, topStudent.average);
}

int main() {
    int N;
    printf("������ѧ������ N��");
    scanf("%d", &N);
    getchar(); // ���ջ��з�

    Student students[MAX_STUDENTS];
    inputStudents(students, N);
    calculateAverages(students, N);
    printTopStudent(students, N);

    return 0;
}
