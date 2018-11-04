
// FillingView.cpp: CFillingView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Filling.h"
#endif

#include "FillingDoc.h"
#include "FillingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFillingView

IMPLEMENT_DYNCREATE(CFillingView, CView)

BEGIN_MESSAGE_MAP(CFillingView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFillingView 构造/析构

CFillingView::CFillingView() noexcept
{
	// TODO: 在此处添加构造代码

}

CFillingView::~CFillingView()
{
}

BOOL CFillingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CFillingView 绘图

void CFillingView::OnDraw(CDC* /*pDC*/)
{
	CFillingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CFillingView 打印

BOOL CFillingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CFillingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CFillingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CFillingView 诊断

#ifdef _DEBUG
void CFillingView::AssertValid() const
{
	CView::AssertValid();
}

void CFillingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFillingDoc* CFillingView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFillingDoc)));
	return (CFillingDoc*)m_pDocument;
}
#endif //_DEBUG


// CFillingView 消息处理程序
