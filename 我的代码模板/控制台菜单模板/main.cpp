#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

bool MyAdd();//��������������������������
bool MySub();//��������������������������
bool MyMul();//��������������������������
bool MyDiv();//��������������������������

int main(int argc, char* argv[]) {
	int iSelect = 0;
	while (1) {
		printf("+------------------------------------------+\n");
		printf("| 0.�˳�                                   |\n");
		printf("| 1.���                                   |\n");
		printf("| 2.���                                   |\n");
		printf("| 3.���                                   |\n");
		printf("| 4.���                                   |\n");
		printf("+------------------------------------------+\n");
		printf(">>");
		int num = scanf("%d", &iSelect);
		int ch = getchar();
		switch (iSelect)
		{
		case 0:
			printf("�˳�����");
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
			printf("��������\n");
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
//��������������������������
bool MyAdd() {
	int a, b;
	printf("���������������������ո�������س��������룺\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d+%d=%d\n", a, b, a + b);
	}
	else {
		printf("��������\n");
	}
	return true;
}
//��������������������������
bool MySub() {
	int a, b;
	printf("���������������������ո�������س��������룺\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d-%d=%d\n", a, b, a - b);
	}
	else {
		printf("��������\n");
	}
	return true;
}
//��������������������������
bool MyMul() {
	int a, b;
	printf("���������������������ո�������س��������룺\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d*%d=%d\n", a, b, a * b);
	}
	else {
		printf("��������\n");
	}
	return true;
}
//��������������������������
bool MyDiv() {
	int a, b;
	printf("���������������������ո�������س��������룺\n");
	printf(">>");
	int num = scanf("%d%d", &a, &b);
	if (num == 2) {
		printf("%d/%d=%d\n", a, b, a / b);
	}
	else {
		printf("��������\n");
	}
	return true;
}