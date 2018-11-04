
// Circle_EllipseView.h: CCircleEllipseView 类的接口
//

#pragma once


class CCircleEllipseView : public CView
{
protected: // 仅从序列化创建
	CCircleEllipseView() noexcept;
	DECLARE_DYNCREATE(CCircleEllipseView)

// 特性
public:
	CCircleEllipseDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCircleEllipseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Circle_EllipseView.cpp 中的调试版本
inline CCircleEllipseDoc* CCircleEllipseView::GetDocument() const
   { return reinterpret_cast<CCircleEllipseDoc*>(m_pDocument); }
#endif

