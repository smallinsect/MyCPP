#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "Urlmon.lib")

void Test();
void Test1();
void Test2();
void Test3();

int main() {
	Test3();
	return 0;
}

// �����ļ����򿪳���
void Test() {
	HRESULT hret = URLDownloadToFile(NULL, TEXT("http://n.sinaimg.cn/sinacn12/0/w1024h576/20180729/9a15-hfxsxzh3889063.jpg"), TEXT("./123.jpg"), 0, NULL);
	if (hret == S_OK) {
		MessageBox(NULL, TEXT("���سɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("����ʧ��"), TEXT("��ʾ"), MB_OK);
	}

	SHELLEXECUTEINFO ShellInfo = { 0 };
	ShellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShellInfo.lpVerb = TEXT("open");
	ShellInfo.lpFile = TEXT("calc.exe");
	ShellInfo.nShow = SW_SHOW;
	BOOL bRet = ShellExecuteEx(&ShellInfo);
}

// ɾ���ļ�
void Test1() {
	BOOL bRet = DeleteFile(TEXT("222.jpg"));
	if (bRet) {
		MessageBox(NULL, TEXT("ɾ���ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("ɾ��ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}

//�����ļ�
void Test2() {
	BOOL bRet = CopyFile(TEXT("123.jpg"), TEXT("222.jpg"), FALSE);
	if (bRet) {
		MessageBox(NULL, TEXT("�����ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("����ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}

// �ļ��ƶ�
void Test3() {
	BOOL bRet = MoveFile(TEXT("123.jpg"), TEXT("333.jpg"));
	if (bRet) {
		MessageBox(NULL, TEXT("�ƶ��ɹ�"), TEXT("��ʾ"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("�ƶ�ʧ��"), TEXT("��ʾ"), MB_OK);
	}
}