#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#include <windows.h>


int main(int argc, char *argv[]) {
	//#�����Գ����ڱ���������
	//$���Գ����ڱ���������
	//int #abc1234 = 3;
	//int $hello = 1;

	//�����������ִ�Сд
	int abc = 5;
	int ABC = 6;

	//������C���Թؼ�����Ϊ������

	int scanf = 10;
	printf("%d\n", scanf);

	puts("hello world");

	printf("sizeof char     = %d\n", sizeof(char));
	printf("sizeof short    = %d\n", sizeof(short));
	printf("sizeof int      = %d\n", sizeof(int));
	printf("sizeof float    = %d\n", sizeof(float));
	printf("sizeof double   = %d\n", sizeof(double));
	printf("sizeof long     = %d\n", sizeof(long));
	printf("sizeof long long= %d\n", sizeof(long long));

	int *arr = (int*)malloc(100000000*sizeof(int));

	printf("%X\n", 0xf & 1);

	//char *str1 = "hello";//"hello"�����ַ��������洢��ֻ��ջ����
	//char str2[] = "hello";//����ջ��

	printf("%s\n", strchr("hello wolrd", 'w'));

	char str[] = "hello wolrd";
	printf("%s\n", strstr(str, "wo"));

	system("pause");
	return 0;
}