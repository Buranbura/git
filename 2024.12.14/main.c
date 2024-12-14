/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // 包含头文件，用于字符处理函数如toupper

int main() {
    FILE* fp;
    char ch[30]; // 定义字符数组，用于存储输入的字符串

    // 尝试打开文件，准备写入
    if ((fp = fopen("D:\\file1.txt", "w")) == NULL) {
        printf("文件创建失败！");
        exit(0);
    }

    printf("请输入文本（输入'exit'退出）：\n");
    while (1) {
        if (fgets(ch, sizeof(ch), stdin) == NULL) {
            break; // 如果读取失败，退出循环
        }
        // 移除字符串末尾的换行符
        ch[strcspn(ch, "\n")] = 0;

        if (strcmp(ch, "exit") == 0) { // 如果输入的是"exit"，则退出
            break;
        }

        for (int i = 0; ch[i] != '\0'; i++) {
            // 使用toupper函数将小写字母转换为大写
            if (islower(ch[i])) {
                ch[i] = toupper(ch[i]);
            }
            fputc(ch[i], fp); // 将当前字符写入文件
        }
        fputc('\n', fp); // 写入换行符，开始新的一行
    }

    fclose(fp); // 关闭文件
    return 0; // 主函数返回0，表示程序正常结束
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
		printf("文件打开失败！");
		exit(0);
	}
	if ((fp2 = fopen("D:\\file2.txt","w")) == NULL)
	{
		printf("文件创建失败！");
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

// 定义学生结构体
typedef struct {
    char name[20];
    char id[10];
    int scores[COURSE_COUNT];
} Student;

int main() {
    FILE* fp; // 文件指针
    Student students[STUDENT_COUNT]; // 学生数组
    char filename[] = "students.bin"; // 文件名

    // 打开文件，准备写入
    if ((fp = fopen(filename, "wb")) == NULL) {
        printf("无法打开文件进行写入！\n");
        return 1;
    }

    // 输入学生信息
    for (int i = 0; i < STUDENT_COUNT; i++) {
        printf("请输入第 %d 位学生的姓名：", i + 1);
        scanf("%19s", students[i].name); // 限制输入长度，防止溢出
        printf("请输入第 %d 位学生的学号：", i + 1);
        scanf("%9s", students[i].id);
        printf("请输入第 %d 位学生的数学、英语、C语言成绩：", i + 1);
        for (int j = 0; j < COURSE_COUNT; j++) {
            scanf("%d", &students[i].scores[j]);
        }
    }

    // 将学生信息写入二进制文件
    fwrite(students, sizeof(Student), STUDENT_COUNT, fp);

    // 关闭文件
    fclose(fp);

    printf("学生信息已成功写入 %s 文件。\n", filename);

    return 0;
}












