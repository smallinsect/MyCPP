
// DemoMFC03View.cpp: CDemoMFC03View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC03.h"
#endif

#include "DemoMFC03Doc.h"
#include "CntrItem.h"
#include "resource.h"
#include "DemoMFC03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC03View

IMPLEMENT_DYNCREATE(CDemoMFC03View, CRichEditView)

BEGIN_MESSAGE_MAP(CDemoMFC03View, CRichEditView)
	ON_WM_DESTROY()
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDemoMFC03View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CDemoMFC03View 构造/析构

CDemoMFC03View::CDemoMFC03View() noexcept
{
	EnableActiveAccessibility();
	// TODO: 在此处添加构造代码

}

CDemoMFC03View::~CDemoMFC03View()
{
}

BOOL CDemoMFC03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRichEditView::PreCreateWindow(cs);
}

void CDemoMFC03View::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// 设置打印边距(720 缇 = 1/2 英寸)
	SetMargins(CRect(720, 720, 720, 720));
}


// CDemoMFC03View 打印


void CDemoMFC03View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDemoMFC03View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}


void CDemoMFC03View::OnDestroy()
{
	// 析构时停用此项；这在
	// 使用拆分器视图时非常重要 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != nullptr && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == nullptr);
   }
   CRichEditView::OnDestroy();
}


void CDemoMFC03View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDemoMFC03View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDemoMFC03View 诊断

#ifdef _DEBUG
void CDemoMFC03View::AssertValid() const
{
	CRichEditView::AssertValid();
}

void CDemoMFC03View::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

CDemoMFC03Doc* CDemoMFC03View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoMFC03Doc)));
	return (CDemoMFC03Doc*)m_pDocument;
}
#endif //_DEBUG


// CDemoMFC03View 消息处理程序
