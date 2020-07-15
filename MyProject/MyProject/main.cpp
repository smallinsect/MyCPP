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

// 下载文件，打开程序
void Test() {
	HRESULT hret = URLDownloadToFile(NULL, TEXT("http://n.sinaimg.cn/sinacn12/0/w1024h576/20180729/9a15-hfxsxzh3889063.jpg"), TEXT("./123.jpg"), 0, NULL);
	if (hret == S_OK) {
		MessageBox(NULL, TEXT("下载成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("下载失败"), TEXT("提示"), MB_OK);
	}

	SHELLEXECUTEINFO ShellInfo = { 0 };
	ShellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShellInfo.lpVerb = TEXT("open");
	ShellInfo.lpFile = TEXT("calc.exe");
	ShellInfo.nShow = SW_SHOW;
	BOOL bRet = ShellExecuteEx(&ShellInfo);
}

// 删除文件
void Test1() {
	BOOL bRet = DeleteFile(TEXT("222.jpg"));
	if (bRet) {
		MessageBox(NULL, TEXT("删除成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("删除失败"), TEXT("提示"), MB_OK);
	}
}

//复制文件
void Test2() {
	BOOL bRet = CopyFile(TEXT("123.jpg"), TEXT("222.jpg"), FALSE);
	if (bRet) {
		MessageBox(NULL, TEXT("拷贝成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("拷贝失败"), TEXT("提示"), MB_OK);
	}
}

// 文件移动
void Test3() {
	BOOL bRet = MoveFile(TEXT("123.jpg"), TEXT("333.jpg"));
	if (bRet) {
		MessageBox(NULL, TEXT("移动成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("移动失败"), TEXT("提示"), MB_OK);
	}
}