
// TransformationView.h: CTransformationView 类的接口
//

#pragma once

#include "CPoint3.h"

class CTransformationView : public CView
{
protected: // 仅从序列化创建
	CTransformationView() noexcept;
	DECLARE_DYNCREATE(CTransformationView)

// 特性
public:
	CTransformationDoc* GetDocument() const;

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
	virtual ~CTransformationView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

private:
	CPoint3 m_LtBkBt;
	CPoint3 m_LtBkTp;
	CPoint3 m_LtFtBt;
	CPoint3 m_LtFtTp;
	CPoint3 m_RtBkBt;
	CPoint3 m_RtBkTp;
	CPoint3 m_RtFtBt;
	CPoint3 m_RtFtTp;

	CPoint m_pjLtBkBt;
	CPoint m_pjLtBkTp;
	CPoint m_pjLtFtBt;
	CPoint m_pjLtFtTp;
	CPoint m_pjRtBkBt;
	CPoint m_pjRtBkTp;
	CPoint m_pjRtFtBt;
	CPoint m_pjRtFtTp;

	int m_pjMatrix[4][4];

	void DrawRect(CPoint pt1, CPoint pt2, CPoint pt3, CPoint pt4);
	void DrawProjCubic();
	void From3DTo2D();
	void Clear();
};

#ifndef _DEBUG  // TransformationView.cpp 中的调试版本
inline CTransformationDoc* CTransformationView::GetDocument() const
   { return reinterpret_cast<CTransformationDoc*>(m_pDocument); }
#endif

