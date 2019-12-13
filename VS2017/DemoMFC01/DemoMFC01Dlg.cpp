
// DemoMFC01Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "DemoMFC01.h"
#include "DemoMFC01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CDemoMFC01Dlg 对话框



CDemoMFC01Dlg::CDemoMFC01Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMOMFC01_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoMFC01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemoMFC01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDemoMFC01Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDemoMFC01Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDemoMFC01Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CDemoMFC01Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CDemoMFC01Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDemoMFC01Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDemoMFC01Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDemoMFC01Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDemoMFC01Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CDemoMFC01Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CDemoMFC01Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CDemoMFC01Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CDemoMFC01Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CDemoMFC01Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CDemoMFC01Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CDemoMFC01Dlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CDemoMFC01Dlg 消息处理程序

BOOL CDemoMFC01Dlg::OnInitDialog()
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

void CDemoMFC01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDemoMFC01Dlg::OnPaint()
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
HCURSOR CDemoMFC01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDemoMFC01Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	system("calc");
}


void CDemoMFC01Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	//\Program Files (x86) 64位前 (x86)要有空格
	system("\"D:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe\"");
}


void CDemoMFC01Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	system("taskkill /f /im QQ.exe");// /f强制 /im进程名
}

void CDemoMFC01Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	system("\"C:\\Program Files\\internet explorer\\iexplore.exe\" http://www.baidu.com");
}

void CDemoMFC01Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	system("taskkill /f /im iexplore.exe");
}

void CDemoMFC01Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	system("tasklist & pause");
}


void CDemoMFC01Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	system("ipconfig & pause");
}


void CDemoMFC01Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	system("tasklist > E:\\1.txt");
	system("C:\\1.txt");
}


void CDemoMFC01Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	system("appwiz.cpl");
}


void CDemoMFC01Dlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	system("certmgr.msc");
}


void CDemoMFC01Dlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	system("charmap");
}


void CDemoMFC01Dlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	system("chkdsk");
}


void CDemoMFC01Dlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	system("clearmrg");
}


void CDemoMFC01Dlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	system("colorcpl");
}


void CDemoMFC01Dlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	system("credwiz");
}


void CDemoMFC01Dlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	system("dcomcnfg"); 
}
