
// DemoMFC03View.h: CDemoMFC03View 类的接口
//

#pragma once

class CDemoMFC03CntrItem;

class CDemoMFC03View : public CRichEditView
{
protected: // 仅从序列化创建
	CDemoMFC03View() noexcept;
	DECLARE_DYNCREATE(CDemoMFC03View)

// 特性
public:
	CDemoMFC03Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDemoMFC03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnDestroy();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // DemoMFC03View.cpp 中的调试版本
inline CDemoMFC03Doc* CDemoMFC03View::GetDocument() const
   { return reinterpret_cast<CDemoMFC03Doc*>(m_pDocument); }
#endif

