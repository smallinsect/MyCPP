
#include "menu.h"


bool MyAdd();//输入两个整数，求两个整数和
bool MySub();//输入两个整数，求两个整数差
bool MyMul();//输入两个整数，求两个整数积
bool MyDiv();//输入两个整数，求两个整数商

int main(int argc, char* argv[]) {

	MenuAdd(MyAdd, "相加");
	MenuAdd(MySub, "相减");
	MenuAdd(MyMul, "相乘");
	MenuAdd(MyDiv, "相除");

	MenuShow();

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