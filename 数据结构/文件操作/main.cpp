#include <stdio.h>


int main() {
	// �ļ�ָ��
	FILE* fp;
	// ���ļ� ��
	fp = fopen("c:\\test.txt", "r");

	// �ر��ļ�ָ��
	fclose(fp);

	return 0;
}