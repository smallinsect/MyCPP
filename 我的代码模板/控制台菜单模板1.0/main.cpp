
#include "menu.h"


bool MyAdd();//��������������������������
bool MySub();//��������������������������
bool MyMul();//��������������������������
bool MyDiv();//��������������������������

int main(int argc, char* argv[]) {

	MenuAdd(MyAdd, "���");
	MenuAdd(MySub, "���");
	MenuAdd(MyMul, "���");
	MenuAdd(MyDiv, "���");

	MenuShow();

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