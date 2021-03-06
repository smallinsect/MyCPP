﻿
// 01MyServerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "01MyServer.h"
#include "01MyServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_SOCKET WM_USER+100

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy01MyServerDlg 对话框



CMy01MyServerDlg::CMy01MyServerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY01MYSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy01MyServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy01MyServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CMy01MyServerDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_STOP, &CMy01MyServerDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_SEND, &CMy01MyServerDlg::OnBnClickedSend)
END_MESSAGE_MAP()


// CMy01MyServerDlg 消息处理程序

BOOL CMy01MyServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMy01MyServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMy01MyServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMy01MyServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy01MyServerDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxBeginThread(ThreadProc, this);
}


void CMy01MyServerDlg::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMy01MyServerDlg::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMy01MyServerDlg::WinSockInit() {
	WSADATA wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0) {
		AfxMessageBox(TEXT("[server] WSAStartup error ...%d"));
		return;
	}
	AfxMessageBox(TEXT("[server] WSAStartup success ..."));
}

#define MAX_BUF_SIZE 4096
UINT CMy01MyServerDlg::ThreadProc(LPVOID lpParam) {
	TCHAR szBuf[MAX_BUF_SIZE] = {0};
	SOCKET ArrSocket[WSA_MAXIMUM_WAIT_EVENTS] = { 0 };
	WSAEVENT ArrEvent[WSA_MAXIMUM_WAIT_EVENTS] = { 0 };
	DWORD dwTotal = 0, dwIndex = 0;
	WSANETWORKEVENTS m_NetWorkEvents = {0};
	CMy01MyServerDlg* pServer = (CMy01MyServerDlg*)lpParam;

	pServer->WinSockInit();
	pServer->m_ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (pServer->m_ServerSocket == INVALID_SOCKET) {
		AfxMessageBox(TEXT("新建套接字失败"));
		goto __Error_End;
	}

	pServer->m_Addr.sin_family = AF_INET;//IPV4
	pServer->m_Addr.sin_addr.s_addr = INADDR_ANY;//自动绑定本机IP地址
	pServer->m_Addr.sin_port = htons(8000);//端口8000

	if (bind(pServer->m_ServerSocket, (const sockaddr*)&pServer->m_Addr, sizeof(pServer->m_Addr)) == SOCKET_ERROR) {
		AfxMessageBox(TEXT("套接字绑定地址和端口失败"));
		goto __Error_End;
	}
	// 创建事件
	WSAEVENT m_ListenEvent = WSACreateEvent();
	// 套接字绑定窗口 绑定事件 绑定操作
	WSAEventSelect(pServer->m_ServerSocket, m_ListenEvent, FD_ACCEPT | FD_CLOSE);
	// 监听
	if (listen(pServer->m_ServerSocket, SOMAXCONN) == SOCKET_ERROR) {
		AfxMessageBox(TEXT("监听套接字失败"));
		goto __Error_End;
	}

	ArrSocket[dwTotal] = pServer->m_ServerSocket;
	ArrEvent[dwTotal] = m_ListenEvent;
	++dwTotal;

	pServer->m_Exit = false;
	while (!pServer->m_Exit) {
		dwIndex = WSAWaitForMultipleEvents(dwTotal, ArrEvent, FALSE, 100, FALSE);
		if (dwIndex == WSA_WAIT_TIMEOUT) {
			continue;
		}
		WSAEnumNetworkEvents(ArrSocket[dwIndex-WSA_WAIT_EVENT_0], ArrEvent[dwIndex-WSA_WAIT_EVENT_0], &m_NetWorkEvents);
		//客户端连接
		if (m_NetWorkEvents.lNetworkEvents & FD_ACCEPT) {
			if (m_NetWorkEvents.iErrorCode[FD_ACCEPT_BIT] != 0) {
				continue;
			}
			pServer->m_ClientSocket = accept(ArrSocket[dwIndex - WSA_WAIT_EVENT_0], NULL, NULL);
			if (pServer->m_ClientSocket == INVALID_SOCKET) {
				continue;
			}
			WSAEVENT newEvent = WSACreateEvent();
			WSAEventSelect(pServer->m_ClientSocket, newEvent, FD_READ | FD_WRITE | FD_CLOSE);

			ArrSocket[dwTotal] = pServer->m_ClientSocket;
			ArrEvent[dwTotal] = newEvent;
			++dwTotal;
		}
		// 接受数据
		if (m_NetWorkEvents.lNetworkEvents & FD_READ) {
			if (m_NetWorkEvents.iErrorCode[FD_ACCEPT_BIT] != 0) {
				continue;
			}
			recv(ArrSocket[dwIndex - WSA_WAIT_EVENT_0], (char *)szBuf, MAX_BUF_SIZE, 0);
			pServer->ShowMsg(szBuf);
		}
		// 发送数据
		if (m_NetWorkEvents.lNetworkEvents & FD_WRITE) {
			if (m_NetWorkEvents.iErrorCode[FD_ACCEPT_BIT] != 0) {
				continue;
			}
			send(ArrSocket[dwIndex - WSA_WAIT_EVENT_0], (char*)szBuf, MAX_BUF_SIZE, 0);
		}
		// 关闭套接字
		if (m_NetWorkEvents.lNetworkEvents & FD_CLOSE) {
			if (m_NetWorkEvents.iErrorCode[FD_ACCEPT_BIT] != 0) {
				continue;
			}
			closesocket(ArrSocket[dwIndex - WSA_WAIT_EVENT_0]);
			//WSACloseEvent();
		}
	}

	return 0;

__Error_End:
	if (pServer->m_ServerSocket != INVALID_SOCKET) {
		closesocket(pServer->m_ServerSocket);
	}
	WSACleanup();
	return -1;
}
