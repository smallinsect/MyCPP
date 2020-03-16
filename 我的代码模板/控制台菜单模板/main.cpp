#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

bool MyAdd();//输入两个整数，求两个整数和
bool MySub();//输入两个整数，求两个整数差
bool MyMul();//输入两个整数，求两个整数积
bool MyDiv();//输入两个整数，求两个整数商

int main(int argc, char* argv[]) {
	int iSelect = 0;
	while (1) {
		printf("+------------------------------------------+\n");
		printf("| 0.退出                                   |\n");
		printf("| 1.相加                                   |\n");
		printf("| 2.相减                                   |\n");
		printf("| 3.相乘                                   |\n");
		printf("| 4.相除                                   |\n");
		printf("+------------------------------------------+\n");
		printf(">>");
		int num = scanf("%d", &iSelect);
		int ch = getchar();
		switch (iSelect)
		{
		case 0:
			printf("退出程序");
			system("pause");
			return 0;
			break;
		case 1:
			MyAdd();
			break;
		case 2:
			MySub();
			break;
		case 3:
			MyMul();
			break;
		case 4:
			MyDiv();
			break;
		default:
			printf("输入有误\n");
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//输入两个整数，求两个整数和
bool MyAdd() {
	int a, b;
	printf("输入两个整数，两个数空格隔开，回车结束输入：\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d+%d=%d\n", a, b, a + b);
	}
	else {
		printf("输入有误\n");
	}
	return true;
}
//输入两个整数，求两个整数差
bool MySub() {
	int a, b;
	printf("输入两个整数，两个数空格隔开，回车结束输入：\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d-%d=%d\n", a, b, a - b);
	}
	else {
		printf("输入有误\n");
	}
	return true;
}
//输入两个整数，求两个整数积
bool MyMul() {
	int a, b;
	printf("输入两个整数，两个数空格隔开，回车结束输入：\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d*%d=%d\n", a, b, a * b);
	}
	else {
		printf("输入有误\n");
	}
	return true;
}
//输入两个整数，求两个整数商
bool MyDiv() {
	int a, b;
	printf("输入两个整数，两个数空格隔开，回车结束输入：\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d/%d=%d\n", a, b, a / b);
	}
	else {
		printf("输入有误\n");
	}
	return true;
}