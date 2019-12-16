
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <process.h>
#include <Windows.h>

#include "detours.h"
#include "detver.h"

#pragma comment(lib, "detours.lib")

//定义旧函数指针指向原来的函数
static int (WINAPI* OLD_MessageBoxW)(
	HWND hWnd,
	LPCWSTR lpText,
	LPCWSTR lpCaption,
	UINT uType) = MessageBoxW;

int WINAPI NEW_MessageBoxW(
	HWND hWnd,
	LPCWSTR lpText,
	LPCWSTR lpCaption,
	UINT uType) 
{
	printf("已经被拦截了\n");
	return 0;
}
//开始拦截
VOID Hook(){
	DetourRestoreAfterWith();//恢复原来状态
	DetourTransactionBegin();//拦截开始
	DetourUpdateThread(GetCurrentThread());//刷新当前线程
	//这里可以连续多次调用DetourAttach，表明HOOK多个函数
	DetourAttach((void **)&OLD_MessageBoxW, NEW_MessageBoxW);//实现函数拦截
	DetourTransactionCommit();
}
//取消拦截
VOID UnHook(){
	DetourTransactionBegin();//拦截开始
	DetourUpdateThread(GetCurrentThread());//舒心当前线程
	//这里可以连续多次调用DetourDetach,表明撤销多个函数HOOK
	DetourDetach((void **)&OLD_MessageBoxW, NEW_MessageBoxW);//撤销拦截函数
	DetourTransactionCommit();
}

int main(int argc, char *argv[]) {
	MessageBoxW(NULL, L"爱白菜的小昆虫", L"HH", MB_OK);
	Hook();
	MessageBoxW(NULL, L"爱白菜的小昆虫", L"HH", MB_OK);
	system("pause");
	return 0;
}