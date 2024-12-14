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
    printf("s.c[0]��ʮ����ֵΪ��%d, s.c[1]�ģ�%d", s.c[0], s.c[1]);
    return 0;
}*/



/*#include <stdio.h>
#include <string.h>

#define STUDENT_COUNT 6

// ����ѧ���ṹ��
typedef struct {
    char id[20];
    char name[20];
    int scores[3];
    double average;
} Student;

// ��������
void inputStudents(Student students[], int count);
void printReport(const Student students[], int count);
void calculateAverages(Student students[], int count);
void sortStudentsByAverage(Student students[], int count);
void printTopFive(const Student students[], int count);

int main() {
    Student students[STUDENT_COUNT];

    // ����ѧ������
    inputStudents(students, STUDENT_COUNT);

    // ����ƽ����
    calculateAverages(students, STUDENT_COUNT);

    // ��ƽ��������
    sortStudentsByAverage(students, STUDENT_COUNT);

    // ��ӡ�ɼ�����
    printReport(students, STUDENT_COUNT);

    // ��ӡƽ����ǰ5����ѧ����Ϣ
    printTopFive(students, STUDENT_COUNT);

    return 0;
}

// ����ѧ������
void inputStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("�������%d��ѧ����ѧ�ţ�", i + 1);
        scanf("%s", students[i].id);
        getchar(); // ���ջ��з�
        printf("������ѧ��������");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; // �Ƴ����з�
        for (int j = 0; j < 3; j++) {
            printf("�������%d�Ź��γɼ���", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
    }
}

// ����ƽ����
void calculateAverages(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        double sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = sum / 3.0;
    }
}

// ��ƽ��������
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

// ��ӡ�ɼ�����
void printReport(const Student students[], int count) {
    printf("\t\t\t�ɼ�����\n");
    printf("ѧ��\t|����\t|��һ�ſγɼ�\t|�ڶ��ſγ̼�\t|�����ſγɼ�\t|ƽ����\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t|%s\t|%d\t\t|%d\t\t|%d\t\t|%.2f\n",
               students[i].id, students[i].name, students[i].scores[0],
               students[i].scores[1], students[i].scores[2], students[i].average);
    }
}

// ��ӡƽ����ǰ5����ѧ����Ϣ
void printTopFive(const Student students[], int count) {
    printf("ƽ������ǰ5����ѧ����Ϣ��\n");
    printf("����\t|ƽ����\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t|%.2f\n", students[i].name, students[i].average);
    }
}*/





#include <stdio.h>
#include <string.h>

#define WORKER_COUNT 4

//����ṹ��
typedef struct
{
    char id[20];
    char name[20];
    char number[20];
}Worker;

//��������
void input(Worker workers[], int count);
void print(Worker workers[], int count);

//��������
void input(Worker workers[], int count)
{
    for(int i = 0; i < count; i++)
    {
        printf("�������%d���˵Ĺ���֤�ţ�", i + 1);
        scanf("%s", workers[i].id);

        getchar();      //��ȡ���з�

        printf("��������Ա������");
        fgets(workers[i].name, sizeof(workers[i].name), stdin);
        workers[i].name[strcspn(workers[i].name, "\n")] = 0;

        printf("������绰���룺");
        fgets(workers[i].number, sizeof(workers[i].number), stdin);
        workers[i].number[strcspn(workers[i].number, "\n")] = 0;
    }
}

//��ӡͨѶ¼
void print(Worker workers[], int count)
{
    printf("\t\t\tͨѶ¼\n");
    printf("����֤��\t\t|����\t\t\t|�绰����\n");
    for(int i = 0; i < count; i++)
    {
        printf("%-10s\t\t|%-10s\t\t|%-10s\n", workers[i].id, workers[i].name, workers[i].number);
    }
}

//������
int main()
{
    Worker workers[WORKER_COUNT];
    input(workers, WORKER_COUNT);
    print(workers, WORKER_COUNT);

    return 0;

}







