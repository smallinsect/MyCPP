#include <Windows.h>
#include <tchar.h>

void Test();
void Test1();
void Test2();

int main() {
	Test2();
	return 0;
}

// 创建空白文件
void Test() {
	HANDLE hFile = CreateFile(TEXT("1.txt"), 
		GENERIC_READ | GENERIC_WRITE,// 读写文件
		FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,//创建文件
		FILE_ATTRIBUTE_NORMAL,//文件属性正常
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("文件创建成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("文件创建失败"), TEXT("提示"), MB_OK);
	}
}

// 打开一个已存在的文件
void Test1() {
	HANDLE hFile = CreateFile(TEXT("1.txt"),
		GENERIC_READ | GENERIC_WRITE,// 读写文件
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,//打开已存在的文件
		FILE_ATTRIBUTE_NORMAL,//文件属性正常
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("文件打开成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("文件打开失败"), TEXT("提示"), MB_OK);
	}
}

// 打开一个文件，文件存在，打开。文件不存在，新建一个文件。
void Test2() {
	HANDLE hFile = CreateFile(TEXT("12.txt"),
		GENERIC_READ | GENERIC_WRITE,// 读写文件
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,//打开文件，文件不存在，创建一个空文件。
		FILE_ATTRIBUTE_NORMAL,//文件属性正常
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("文件打开成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("文件打开失败"), TEXT("提示"), MB_OK);
	}
}

// 打开一个文件，文件存在，打开并清空文件。文件不存在，新建一个文件。
void Test2() {
	HANDLE hFile = CreateFile(TEXT("12.txt"),
		GENERIC_READ | GENERIC_WRITE,// 读写文件
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,//打开文件
		FILE_ATTRIBUTE_NORMAL,//文件属性正常
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("文件打开成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("文件打开失败"), TEXT("提示"), MB_OK);
	}
}