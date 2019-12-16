
// CntrItem.h: CDemoMFC03CntrItem 类的接口
//

#pragma once

class CDemoMFC03Doc;
class CDemoMFC03View;

class CDemoMFC03CntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CDemoMFC03CntrItem)

// 构造函数
public:
	CDemoMFC03CntrItem(REOBJECT* preo = nullptr, CDemoMFC03Doc* pContainer = nullptr);
		// 注意: 允许 pContainer 为 NULL 以启用 IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE 要求类具有带零
		//  参数的构造函数。  OLE 项通常是用
		//  非 null 文档指针

// 特性
public:
	CDemoMFC03Doc* GetDocument()
		{ return reinterpret_cast<CDemoMFC03Doc*>(CRichEditCntrItem::GetDocument()); }
	CDemoMFC03View* GetActiveView()
		{ return reinterpret_cast<CDemoMFC03View*>(CRichEditCntrItem::GetActiveView()); }

// 实现
public:
	~CDemoMFC03CntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

