
// TransformationView.h: CTransformationView 类的接口
//

#pragma once

#include "CPoint3.h"
#include "SelectAxisDialog.h"

#define TYPE_MOVE 1
#define TYPE_SCALE 2
#define TYPE_ROTATE 3

#define ROTATE_X 0
#define ROTATE_Y 1
#define ROTATE_Z 2

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

	double m_pjMatrix[4][4];

	double m_fScale;

	int m_nOpType;
	int m_nRotateAxis;

	void DrawRect(CPoint pt1, CPoint pt2, CPoint pt3, CPoint pt4);
	void DrawProjCubic();
	void From3DTo2D();
	void Clear();
	void DrawPerspective();
	void DrawProj();
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMoveClick();
	afx_msg void OnScaleClick();
	afx_msg void OnRotateClick();
private:
	void MoveTransformation(UINT nChar);
	void ScaleTransformation(UINT nChar);
	void RotateTransformation(UINT nChar);
public:
	afx_msg void OnRotateaxisClick();
};

#ifndef _DEBUG  // TransformationView.cpp 中的调试版本
inline CTransformationDoc* CTransformationView::GetDocument() const
   { return reinterpret_cast<CTransformationDoc*>(m_pDocument); }
#endif

