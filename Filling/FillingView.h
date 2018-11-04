
// FillingView.h: CFillingView 类的接口
//

#pragma once


class CFillingView : public CView
{
protected: // 仅从序列化创建
	CFillingView() noexcept;
	DECLARE_DYNCREATE(CFillingView)

// 特性
public:
	CFillingDoc* GetDocument() const;

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
	virtual ~CFillingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FillingView.cpp 中的调试版本
inline CFillingDoc* CFillingView::GetDocument() const
   { return reinterpret_cast<CFillingDoc*>(m_pDocument); }
#endif

