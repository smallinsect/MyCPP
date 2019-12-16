
// DemoMFC03Doc.cpp: CDemoMFC03Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DemoMFC03.h"
#endif

#include "DemoMFC03Doc.h"
#include "CntrItem.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDemoMFC03Doc

IMPLEMENT_DYNCREATE(CDemoMFC03Doc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CDemoMFC03Doc, CRichEditDoc)
	// 启用默认的 OLE 容器实现
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_POPUP, &CDemoMFC03Doc::OnUpdateObjectVerbPopup)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_FILE_SEND_MAIL, &CDemoMFC03Doc::OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, &CDemoMFC03Doc::OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDemoMFC03Doc, CRichEditDoc)
END_DISPATCH_MAP()

// 注意: 我们添加了对 IID_IDemoMFC03 的支持来支持类型安全绑定
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {c33bbc6d-e547-45c5-9d31-ed55f8073f5a}
static const IID IID_IDemoMFC03 =
{0xc33bbc6d,0xe547,0x45c5,{0x9d,0x31,0xed,0x55,0xf8,0x07,0x3f,0x5a}};

BEGIN_INTERFACE_MAP(CDemoMFC03Doc, CRichEditDoc)
	INTERFACE_PART(CDemoMFC03Doc, IID_IDemoMFC03, Dispatch)
END_INTERFACE_MAP()


// CDemoMFC03Doc 构造/析构

CDemoMFC03Doc::CDemoMFC03Doc() noexcept
{
	// 使用 OLE 复合文件
	EnableCompoundFile();

	// TODO: 在此添加一次性构造代码

	EnableAutomation();

	AfxOleLockApp();
}

CDemoMFC03Doc::~CDemoMFC03Doc()
{
	AfxOleUnlockApp();
}

BOOL CDemoMFC03Doc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

CRichEditCntrItem* CDemoMFC03Doc::CreateClientItem(REOBJECT* preo) const
{
	return new CDemoMFC03CntrItem(preo, const_cast<CDemoMFC03Doc*>(this));
}




// CDemoMFC03Doc 序列化

void CDemoMFC03Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}

	// 调用基类 CRichEditDoc 会启用序列化
	//  容器文档的 COleClientItem 对象的序列化。
	// TODO: 如果作为文本进行序列化，则设置 CRichEditDoc::m_bRTF = FALSE
	CRichEditDoc::m_bRTF = FALSE;
	CRichEditDoc::Serialize(ar);
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CDemoMFC03Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CDemoMFC03Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CDemoMFC03Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDemoMFC03Doc 诊断

#ifdef _DEBUG
void CDemoMFC03Doc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CDemoMFC03Doc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// CDemoMFC03Doc 命令
