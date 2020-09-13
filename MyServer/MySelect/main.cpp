#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <WinSock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib")

#define MAX_SIZE_BUF 1024*16

int main(int argc, char* argv[]) {
	WSADATA wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0) {
		puts("[server] WSAStartup error ...");
		return -1;
	}
	puts("[server] WSAStartup success ...");

	//����һ���׽��� IPV4 ������ TCPЭ��
	SOCKET m_skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_skt == INVALID_SOCKET) {
		puts("[server] socket error ...");
		return -1;
	}
	puts("[server] socket success ...");

	//IPV4Э�� ip �˿�
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;//IPV4
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");//�Զ��󶨱���IP��ַ
	addr.sin_port = htons(8000);//�˿�8000

	//���׽���
	if (bind(m_skt, (const sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		puts("[server] bind error ...");
		return -1;
	}
	puts("[server] bind success ...");

	//�����׽���
	if (listen(m_skt, SOMAXCONN) == SOCKET_ERROR) {
		printf("[server] listen error ...%d\n", GetLastError());
		return -1;
	}
	puts("[server] listen success ...");

	fd_set m_fds;

	FD_ZERO(&m_fds);//��ʼ��
	FD_SET(m_skt, &m_fds);//����socket���뼯��

	timeval tv = { 0, 30 };

	char buf[MAX_SIZE_BUF];
	while (1) {
		fd_set readfds = m_fds;
		if (select(0, &readfds, NULL, NULL, &tv) <= 0) {
			continue;
		}
		for (u_int i = 0; i < readfds.fd_count; ++i) {
			SOCKET tskt = readfds.fd_array[i];
			if (tskt == m_skt) {//���µĿͻ�����������
				SOCKET cskt = accept(m_skt, NULL, NULL);
				if (cskt == INVALID_SOCKET) {
					printf("[server] accept error ...%d\n", GetLastError());
					return -1;
				}
				puts("[server] accept success ...");
				FD_SET(cskt, &m_fds);
				continue;
			}
			memset(buf, 0, sizeof(buf));
			int irecv = recv(tskt, buf, sizeof(buf), 0);//����������������Ϣ
			if (irecv > 0) {
				// ������ܵ���Ϣ
				//webserver->dispatch(tskt, buf, strlen(buf));
			}
			// ���ͻ����׽��֣��Ӽ�����ɾ����
			FD_CLR(tskt, &m_fds);
			//irecv=0 ��ʾ�ͻ����˳� irecv=-1 ��ʾ�ͻ����쳣�˳� 
			closesocket(tskt); // �رտͻ����׽���
		}
	}

	closesocket(m_skt);//�ر��׽���
	WSACleanup();//��������

	return 0;
}