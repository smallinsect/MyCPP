#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "Urlmon.lib")

void Test();

int main() {
	Test();
	return 0;
}

// �����ļ�
void Test() {
	CreateFile();
}