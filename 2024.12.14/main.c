/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // ����ͷ�ļ��������ַ���������toupper

int main() {
    FILE* fp;
    char ch[30]; // �����ַ����飬���ڴ洢������ַ���

    // ���Դ��ļ���׼��д��
    if ((fp = fopen("D:\\file1.txt", "w")) == NULL) {
        printf("�ļ�����ʧ�ܣ�");
        exit(0);
    }

    printf("�������ı�������'exit'�˳�����\n");
    while (1) {
        if (fgets(ch, sizeof(ch), stdin) == NULL) {
            break; // �����ȡʧ�ܣ��˳�ѭ��
        }
        // �Ƴ��ַ���ĩβ�Ļ��з�
        ch[strcspn(ch, "\n")] = 0;

        if (strcmp(ch, "exit") == 0) { // ����������"exit"�����˳�
            break;
        }

        for (int i = 0; ch[i] != '\0'; i++) {
            // ʹ��toupper������Сд��ĸת��Ϊ��д
            if (islower(ch[i])) {
                ch[i] = toupper(ch[i]);
            }
            fputc(ch[i], fp); // ����ǰ�ַ�д���ļ�
        }
        fputc('\n', fp); // д�뻻�з�����ʼ�µ�һ��
    }

    fclose(fp); // �ر��ļ�
    return 0; // ����������0����ʾ������������
}*/





/*#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE* fp, *fp2;
	char str[1024];
	char ch;
	int i = 0;
	if ((fp = fopen("D:\\file1.txt","r")) == NULL)
	{
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}
	if ((fp2 = fopen("D:\\file2.txt","w")) == NULL)
	{
		printf("�ļ�����ʧ�ܣ�");
		exit(0);
	}
	while ((ch = fgetc(fp))!=EOF)
	{
		str[i++] = ch;
		if (ch == '\n')
		{
			for (int k = i-2; k >= 0; k--)
				fputc(str[k], fp2);
			fputc('\n', fp2);
			i = 0;
		}
	}
	if (i != 0)
		for (int k = i - 2; k >= 0; k--)
			fputc(str[k], fp2);
	fclose(fp);
	fclose(fp2);
	return 0;
}*/




#include <stdio.h>
#include <stdlib.h>

#define STUDENT_COUNT 3
#define COURSE_COUNT 3

// ����ѧ���ṹ��
typedef struct {
    char name[20];
    char id[10];
    int scores[COURSE_COUNT];
} Student;

int main() {
    FILE* fp; // �ļ�ָ��
    Student students[STUDENT_COUNT]; // ѧ������
    char filename[] = "students.bin"; // �ļ���

    // ���ļ���׼��д��
    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("�޷����ļ�����д�룡\n");
        return 1;
    }

    // ����ѧ����Ϣ
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("������� %d λѧ����������", i + 1);
        scanf("%19s", students[i].name); // �������볤�ȣ���ֹ���
        printf("������� %d λѧ����ѧ�ţ�", i + 1);
        scanf("%9s", students[i].id);
        printf("������� %d λѧ������ѧ��Ӣ�C���Գɼ���", i + 1);
        for (int j = 0; j < COURSE_COUNT; j++) {
            scanf("%d", &students[i].scores[j]);
        }
    }

    // ��ѧ����Ϣд��������ļ�
    fwrite(students, sizeof(Student), STUDENT_COUNT, fp);

    // �ر��ļ�
    fclose(fp);

    printf("ѧ����Ϣ�ѳɹ�д�� %s �ļ���\n", filename);

    return 0;
}












