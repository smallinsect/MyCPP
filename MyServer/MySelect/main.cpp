#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <Windows.h>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_SIZE_BUF 1024*16

bool g_bExit;

SOCKET init(u_short port);
void start(void *lpParam);
void clear(SOCKET skt);
void dispatch_msg(fd_set *pfds, SOCKET skt, char *buf, int len);

int main(int argc, char* argv[]) {

	SOCKET m_skt = init(8000);

	_beginthread(start, 0, (void*)m_skt);
	while (true) {
		if (_kbhit()) {
			if (_getch() == VK_SPACE) {
				g_bExit;
				break;
			}
		}
		Sleep(500);
	}

	return 0;
}

SOCKET init(u_short port) {
	WSADATA wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0) {
		printf("[server] WSAStartup error ...%d\n", GetLastError());
		return INVALID_SOCKET;
	}
	puts("[server] WSAStartup success ...");

	//����һ���׽��� IPV4 ������ TCPЭ��
	SOCKET m_skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_skt == INVALID_SOCKET) {
		printf("[server] socket error ...%d\n", GetLastError());
		return INVALID_SOCKET;
	}
	puts("[server] socket success ...");

	//IPV4Э�� ip �˿�
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;//IPV4
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");//�Զ��󶨱���IP��ַ
	addr.sin_port = htons(port);//�˿�8000

	//���׽���
	if (bind(m_skt, (const sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		printf("[server] bind error ...%d\n", GetLastError());
		return INVALID_SOCKET;
	}
	puts("[server] bind success ...");

	//�����׽���
	if (listen(m_skt, SOMAXCONN) == SOCKET_ERROR) {
		printf("[server] listen error ...%d\n", GetLastError());
		return INVALID_SOCKET;
	}
	puts("[server] listen success ...");
	return m_skt;
}

void start(void *lpParam) {
	SOCKET m_skt = (SOCKET)lpParam;
	
	fd_set m_fds;
	FD_ZERO(&m_fds);//��ʼ��
	FD_SET(m_skt, &m_fds);//����socket���뼯��

	timeval tv = { 0, 30 };

	char buf[MAX_SIZE_BUF];
	while (!g_bExit) {
		fd_set rfds = m_fds;// ������ȡ������

		if (select(0, &rfds, NULL, NULL, &tv) <= 0) {
			continue;
		}
		for (u_int i = 0; i < rfds.fd_count; ++i) {
			SOCKET tskt = rfds.fd_array[i];
			if (tskt == m_skt) {//���µĿͻ�����������
				SOCKET cskt = accept(m_skt, NULL, NULL);
				if (cskt == INVALID_SOCKET) {
					printf("[server] accept error ...%d\n", GetLastError());
					continue;
				}
				printf("[server] accept success %d...\n", cskt);
				FD_SET(cskt, &m_fds);
				continue;
			}
			memset(buf, 0, sizeof(buf));
			int irecv = recv(tskt, buf, sizeof(buf), 0);//����������������Ϣ
			if (irecv > 0) {
				dispatch_msg(&m_fds, m_skt, buf, strlen(buf)+1);// ������ܵ���Ϣ
			}
			else {
				FD_CLR(tskt, &m_fds);
				closesocket(tskt);
			}
		}
	}
	clear(m_skt);
}

void clear(SOCKET skt) {
	closesocket(skt);//�ر��׽���
	WSACleanup();//��������
}

void dispatch_msg(fd_set *pfds, SOCKET skt, char *buf, int len) {
	for (u_int i = 0; i < pfds->fd_count; i++) {
		SOCKET tskt = pfds->fd_array[i];
		if (tskt == skt) {
			continue;
		}
		if (send(tskt, buf, len, 0) <= 0) {
			printf("[server] send error ...%d\n", GetLastError());
		}
	}
}