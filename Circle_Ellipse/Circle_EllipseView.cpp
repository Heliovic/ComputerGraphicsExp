
// Circle_EllipseView.cpp: CCircleEllipseView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Circle_Ellipse.h"
#endif

#include "Circle_EllipseDoc.h"
#include "Circle_EllipseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCircleEllipseView

IMPLEMENT_DYNCREATE(CCircleEllipseView, CView)

BEGIN_MESSAGE_MAP(CCircleEllipseView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CCircleEllipseView 构造/析构

CCircleEllipseView::CCircleEllipseView() noexcept
{
	// TODO: 在此处添加构造代码

}

CCircleEllipseView::~CCircleEllipseView()
{
}

BOOL CCircleEllipseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCircleEllipseView 绘图

void CCircleEllipseView::OnDraw(CDC* /*pDC*/)
{
	CCircleEllipseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCircleEllipseView 打印

BOOL CCircleEllipseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCircleEllipseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCircleEllipseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCircleEllipseView 诊断

#ifdef _DEBUG
void CCircleEllipseView::AssertValid() const
{
	CView::AssertValid();
}

void CCircleEllipseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCircleEllipseDoc* CCircleEllipseView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCircleEllipseDoc)));
	return (CCircleEllipseDoc*)m_pDocument;
}
#endif //_DEBUG


// CCircleEllipseView 消息处理程序
