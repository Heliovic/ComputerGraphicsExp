
// TransformationView.cpp: CTransformationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Transformation.h"
#endif

#include "TransformationDoc.h"
#include "TransformationView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTransformationView

IMPLEMENT_DYNCREATE(CTransformationView, CView)

BEGIN_MESSAGE_MAP(CTransformationView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTransformationView 构造/析构

CTransformationView::CTransformationView() noexcept
{
	// TODO: 在此处添加构造代码

}

CTransformationView::~CTransformationView()
{
}

BOOL CTransformationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTransformationView 绘图

void CTransformationView::OnDraw(CDC* /*pDC*/)
{
	CTransformationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CTransformationView 打印

BOOL CTransformationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTransformationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTransformationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTransformationView 诊断

#ifdef _DEBUG
void CTransformationView::AssertValid() const
{
	CView::AssertValid();
}

void CTransformationView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTransformationDoc* CTransformationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTransformationDoc)));
	return (CTransformationDoc*)m_pDocument;
}
#endif //_DEBUG


// CTransformationView 消息处理程序


void CTransformationView::DrawRect(CPoint pt1, CPoint pt2, CPoint pt3, CPoint pt4)
{
	// TODO: 在此处添加实现代码.
	CClientDC dc(this);
	dc.MoveTo(pt1);
	dc.LineTo(pt2);
	dc.LineTo(pt3);
	dc.LineTo(pt4);
	dc.LineTo(pt1);
}


void CTransformationView::DrawProjCubic()
{
	// TODO: 在此处添加实现代码.
	DrawRect(m_pjLtBkBt, m_pjLtBkTp, m_pjLtFtTp, m_pjLtFtBt);
	DrawRect(m_pjRtBkBt, m_pjRtBkTp, m_pjRtFtTp, m_pjRtFtBt);
	DrawRect(m_pjLtBkBt, m_pjLtBkTp, m_pjRtBkTp, m_pjRtBkBt);
	DrawRect(m_pjLtFtBt, m_pjLtFtTp, m_pjRtFtTp, m_pjRtFtBt);
	DrawRect(m_pjLtBkBt, m_pjLtFtBt, m_pjRtFtBt, m_pjRtBkBt);
	DrawRect(m_pjLtBkTp, m_pjLtFtTp, m_pjRtFtTp, m_pjRtBkTp);
}


void CTransformationView::From3DTo2D()
{
	// TODO: 在此处添加实现代码.
	m_pjLtBkBt.x = m_LtBkBt.x * m_pjMatrix[0][0] + m_LtBkBt.y * m_pjMatrix[0][1] + m_LtBkBt.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjLtBkBt.y = m_LtBkBt.x * m_pjMatrix[1][0] + m_LtBkBt.y * m_pjMatrix[1][1] + m_LtBkBt.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];
	m_pjLtBkTp.x = m_LtBkTp.x * m_pjMatrix[0][0] + m_LtBkTp.y * m_pjMatrix[0][1] + m_LtBkTp.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjLtBkTp.y = m_LtBkTp.x * m_pjMatrix[1][0] + m_LtBkTp.y * m_pjMatrix[1][1] + m_LtBkTp.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];
	m_pjLtFtBt.x = m_LtFtBt.x * m_pjMatrix[0][0] + m_LtFtBt.y * m_pjMatrix[0][1] + m_LtFtBt.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjLtFtBt.y = m_LtFtBt.x * m_pjMatrix[1][0] + m_LtFtBt.y * m_pjMatrix[1][1] + m_LtFtBt.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];
	m_pjLtFtTp.x = m_LtFtTp.x * m_pjMatrix[0][0] + m_LtFtTp.y * m_pjMatrix[0][1] + m_LtFtTp.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjLtFtTp.y = m_LtFtTp.x * m_pjMatrix[1][0] + m_LtFtTp.y * m_pjMatrix[1][1] + m_LtFtTp.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];

	m_pjRtBkBt.x = m_RtBkBt.x * m_pjMatrix[0][0] + m_RtBkBt.y * m_pjMatrix[0][1] + m_RtBkBt.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjRtBkBt.y = m_RtBkBt.x * m_pjMatrix[1][0] + m_RtBkBt.y * m_pjMatrix[1][1] + m_RtBkBt.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];
	m_pjRtBkTp.x = m_RtBkTp.x * m_pjMatrix[0][0] + m_RtBkTp.y * m_pjMatrix[0][1] + m_RtBkTp.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjRtBkTp.y = m_RtBkTp.x * m_pjMatrix[1][0] + m_RtBkTp.y * m_pjMatrix[1][1] + m_RtBkTp.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];
	m_pjRtFtBt.x = m_RtFtBt.x * m_pjMatrix[0][0] + m_RtFtBt.y * m_pjMatrix[0][1] + m_RtFtBt.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjRtFtBt.y = m_RtFtBt.x * m_pjMatrix[1][0] + m_RtFtBt.y * m_pjMatrix[1][1] + m_RtFtBt.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];
	m_pjRtFtTp.x = m_RtFtTp.x * m_pjMatrix[0][0] + m_RtFtTp.y * m_pjMatrix[0][1] + m_RtFtTp.z * m_pjMatrix[0][2] + m_pjMatrix[0][3];
	m_pjRtFtTp.y = m_RtFtTp.x * m_pjMatrix[1][0] + m_RtFtTp.y * m_pjMatrix[1][1] + m_RtFtTp.z * m_pjMatrix[1][2] + m_pjMatrix[1][3];

}


void CTransformationView::Clear()
{
	// TODO: 在此处添加实现代码.
	CClientDC dc(this);
	CRect window;
	GetClientRect(window);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Rectangle(window);
}
