#include <Windows.h>
#include <tchar.h>

void Test();
void Test1();
void Test2();

int main() {
	Test2();
	return 0;
}

// �����հ��ļ�
void Test() {
	HANDLE hFile = CreateFile(TEXT("1.txt"), 
		GENERIC_READ | GENERIC_WRITE,// ��д�ļ�
		FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,//�����ļ�
		FILE_ATTRIBUTE_NORMAL,//�ļ���������
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("�ļ������ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("�ļ�����ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}

// ��һ���Ѵ��ڵ��ļ�
void Test1() {
	HANDLE hFile = CreateFile(TEXT("1.txt"),
		GENERIC_READ | GENERIC_WRITE,// ��д�ļ�
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,//���Ѵ��ڵ��ļ�
		FILE_ATTRIBUTE_NORMAL,//�ļ���������
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("�ļ��򿪳ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("�ļ���ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}

// ��һ���ļ����ļ����ڣ��򿪡��ļ������ڣ��½�һ���ļ���
void Test2() {
	HANDLE hFile = CreateFile(TEXT("12.txt"),
		GENERIC_READ | GENERIC_WRITE,// ��д�ļ�
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,//���ļ����ļ������ڣ�����һ�����ļ���
		FILE_ATTRIBUTE_NORMAL,//�ļ���������
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("�ļ��򿪳ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("�ļ���ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}

// ��һ���ļ����ļ����ڣ��򿪲�����ļ����ļ������ڣ��½�һ���ļ���
void Test2() {
	HANDLE hFile = CreateFile(TEXT("12.txt"),
		GENERIC_READ | GENERIC_WRITE,// ��д�ļ�
		FILE_SHARE_READ,
		NULL,
		OPEN_ALWAYS,//���ļ�
		FILE_ATTRIBUTE_NORMAL,//�ļ���������
		NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		MessageBox(NULL, TEXT("�ļ��򿪳ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("�ļ���ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}