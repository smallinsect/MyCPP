﻿
// DemoMFC03.h: DemoMFC03 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CDemoMFC03App:
// 有关此类的实现，请参阅 DemoMFC03.cpp
//

class CDemoMFC03App : public CWinAppEx
{
public:
	CDemoMFC03App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	COleTemplateServer m_server;
		// 用于文档创建的服务器对象
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDemoMFC03App theApp;
