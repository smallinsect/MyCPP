#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "Urlmon.lib")

void Test();

int main() {
	Test();
	return 0;
}

// 创建文件
void Test() {
	CreateFile();
}