#include <stdio.h>
#include <stdlib.h>

#include <limits.h>

int main(int argc, char *argv[]) {
	//puts("hello world");

	//int $hello = 1;

	//printf����%d,%f���������Ǹ����ͣ������ܽ�����
	printf("%d\n", 10.3);
	printf("%lf\n", 10);

	//�����ݳ����й�ϵ
	//unsigned short sh = 65535;//65535
	unsigned short sh = 65535+1;//0 �������
	printf("%d\n", sh);

	short num = -1;
	printf("%d\n", num);
	printf("%u\n", num);
	system("pause");
	return 0;
}