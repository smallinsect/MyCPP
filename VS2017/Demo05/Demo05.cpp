
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <process.h>
#include <Windows.h>

#include "detours.h"
#include "detver.h"

#pragma comment(lib, "detours.lib")

//����ɺ���ָ��ָ��ԭ���ĺ���
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
	printf("�Ѿ���������\n");
	return 0;
}
//��ʼ����
VOID Hook(){
	DetourRestoreAfterWith();//�ָ�ԭ��״̬
	DetourTransactionBegin();//���ؿ�ʼ
	DetourUpdateThread(GetCurrentThread());//ˢ�µ�ǰ�߳�
	//�������������ε���DetourAttach������HOOK�������
	DetourAttach((void **)&OLD_MessageBoxW, NEW_MessageBoxW);//ʵ�ֺ�������
	DetourTransactionCommit();
}
//ȡ������
VOID UnHook(){
	DetourTransactionBegin();//���ؿ�ʼ
	DetourUpdateThread(GetCurrentThread());//���ĵ�ǰ�߳�
	//�������������ε���DetourDetach,���������������HOOK
	DetourDetach((void **)&OLD_MessageBoxW, NEW_MessageBoxW);//�������غ���
	DetourTransactionCommit();
}

int main(int argc, char *argv[]) {
	MessageBoxW(NULL, L"���ײ˵�С����", L"HH", MB_OK);
	Hook();
	MessageBoxW(NULL, L"���ײ˵�С����", L"HH", MB_OK);
	system("pause");
	return 0;
}