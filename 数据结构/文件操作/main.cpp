#include <stdio.h>


int main() {
	// 文件指针
	FILE* fp;
	// 打开文件 读
	fp = fopen("c:\\test.txt", "r");

	// 关闭文件指针
	fclose(fp);

	return 0;
}