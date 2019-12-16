
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <process.h>
#include <Windows.h>

void threadA(void *lpParam) {
	//MessageBox(NULL, TEXT("哈哈哈"), TEXT("呵呵呵"), MB_OK);
	int inum = (int)lpParam;
	for (int i = 0; i < 10; ++i) {
		printf("A%d\n", inum);
		Sleep(1000);
	}
	puts("threadA end ...");

	_endthread();
}

void timer(void *lpParam) {
	char buf[64];
	
	for (int i = 0; i < 10; ++i) {
		sprintf(buf, "title %d", i);
		system(buf);
		Sleep(1000);
	}
}

int main(int argc, char *argv[]) {

	_beginthread(timer, 0, NULL);

	HANDLE threadid[5];
	for (int i = 0; i < 5; ++i) {
		threadid[i] = (HANDLE)_beginthread(threadA, 0, (void*)i);
		//WaitForSingleObject(threadid[i], INFINITE);//阻塞模式 等待一个线程
	}

	system("pause");
	return 0;
}