
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
