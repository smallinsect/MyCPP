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

	//创建一个套接字 IPV4 流类型 TCP协议
	SOCKET m_skt = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_skt == INVALID_SOCKET) {
		puts("[server] socket error ...");
		return -1;
	}
	puts("[server] socket success ...");

	//IPV4协议 ip 端口
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;//IPV4
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");//自动绑定本机IP地址
	addr.sin_port = htons(8000);//端口8000

	//绑定套接字
	if (bind(m_skt, (const sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
		puts("[server] bind error ...");
		return -1;
	}
	puts("[server] bind success ...");

	//监听套接字
	if (listen(m_skt, SOMAXCONN) == SOCKET_ERROR) {
		printf("[server] listen error ...%d\n", GetLastError());
		return -1;
	}
	puts("[server] listen success ...");

	fd_set m_fds;

	FD_ZERO(&m_fds);//初始化
	FD_SET(m_skt, &m_fds);//服务socket放入集合

	timeval tv = { 0, 30 };

	char buf[MAX_SIZE_BUF];
	while (1) {
		fd_set readfds = m_fds;
		if (select(0, &readfds, NULL, NULL, &tv) <= 0) {
			continue;
		}
		for (u_int i = 0; i < readfds.fd_count; ++i) {
			SOCKET tskt = readfds.fd_array[i];
			if (tskt == m_skt) {//有新的客户端请求连接
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
			int irecv = recv(tskt, buf, sizeof(buf), 0);//接受浏览器请求的消息
			if (irecv > 0) {
				// 处理接受的消息
				//webserver->dispatch(tskt, buf, strlen(buf));
			}
			// 将客户端套接字，从集合中删除。
			FD_CLR(tskt, &m_fds);
			//irecv=0 表示客户端退出 irecv=-1 表示客户端异常退出 
			closesocket(tskt); // 关闭客户端套接字
		}
	}

	closesocket(m_skt);//关闭套接字
	WSACleanup();//清理数据

	return 0;
}