#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <Windows.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define MAX_SIZE_BUF 1024*16

bool g_bExit;

int func(int argc, char* argv[]);

DWORD WINAPI ThreadRecv(PVOID pvParam);//������Ϣ�߳�

int main(int argc, char* argv[]) {

	g_bExit = false;
	func(argc, argv);

	system("pause");
	return 0;
}

int func(int argc, char* argv[]) {
	WSADATA wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0) {
		printf("[client] WSAStartup error ...\n");
		system("pause");
		return -1;
	}
	printf("[client] WSAStartup success ...\n");

	//�����׽���
	SOCKET skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (skt == SOCKET_ERROR) {
		printf("[client] socket error ...\n");
		return -1;
	}
	printf("[client] socket success ...\n");

	//�������Ϣ
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;//IPV4Э��
	addr.sin_port = htons(8000);//�˿�
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//IP��ַ

	//���ӷ�����
	if (connect(skt, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		printf("[client] connect error ...\n");
		return -1;
	}
	printf("[client] connect success ...\n");

	CreateThread(NULL, 0,ThreadRecv, (PVOID)skt, 0, NULL);//�������������߳�

	char msg[MAX_SIZE_BUF];
	while (!g_bExit) {
		scanf("%s", msg);
		if (SOCKET_ERROR == send(skt, msg, strlen(msg)+1, 0)) {
			printf("[client] send error %d ...\n", GetLastError());
			g_bExit = true;
			break;
		}
		printf("[client] send success ...\n");
	}

	closesocket(skt);
	WSACleanup();
	return 0;
}

//������Ϣ�߳�
DWORD WINAPI ThreadRecv(PVOID pvParam) {
	SOCKET skt = (SOCKET)pvParam;
	char msg[MAX_SIZE_BUF];
	while (!g_bExit) {
		if (SOCKET_ERROR == recv(skt, msg, MAX_SIZE_BUF, 0)) {
			printf("[client] recv error %d ...\n", GetLastError());
			return -1;
		}
		printf("[server] msg: %s\n", msg);
	}
	return 0;
}