
// CntrItem.cpp: CDemoMFC03CntrItem 类的实现
//

#include "stdafx.h"
#include "DemoMFC03.h"

#include "DemoMFC03Doc.h"
#include "DemoMFC03View.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoMFC03CntrItem 实现

IMPLEMENT_SERIAL(CDemoMFC03CntrItem, CRichEditCntrItem, 0)

CDemoMFC03CntrItem::CDemoMFC03CntrItem(REOBJECT* preo, CDemoMFC03Doc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: 在此添加一次性构造代码
}

CDemoMFC03CntrItem::~CDemoMFC03CntrItem()
{
	// TODO: 在此处添加清理代码
}


// CDemoMFC03CntrItem 诊断

#ifdef _DEBUG
void CDemoMFC03CntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CDemoMFC03CntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

