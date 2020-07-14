#include <Windows.h>
#include <tchar.h>

#pragma comment(lib, "Urlmon.lib")

int main() {
	HRESULT hret = URLDownloadToFile(NULL, TEXT("http://n.sinaimg.cn/sinacn12/0/w1024h576/20180729/9a15-hfxsxzh3889063.jpg"), TEXT("./123.jpg"), 0, NULL);
	if (hret == S_OK) {
		MessageBox(NULL, TEXT("下载成功"), TEXT("提示"), MB_OK);
	}
	else {
		MessageBox(NULL, TEXT("下载失败"), TEXT("提示"), MB_OK);
	}

	SHELLEXECUTEINFO ShellInfo = {0};
	ShellInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShellInfo.lpVerb = TEXT("open");
	ShellInfo.lpFile = TEXT("calc.exe");
	ShellInfo.nShow = SW_SHOW;
	BOOL bRet = ShellExecuteEx(&ShellInfo);
	return 0;
}