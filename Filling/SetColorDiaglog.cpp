// SetColorDiaglog.cpp: 实现文件
//

#include "stdafx.h"
#include "Filling.h"
#include "SetColorDiaglog.h"
#include "afxdialogex.h"


// SetColorDiaglog 对话框

IMPLEMENT_DYNAMIC(SetColorDiaglog, CDialogEx)

SetColorDiaglog::SetColorDiaglog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_nR(0)
	, m_nG(0)
	, m_nB(0)
{

}

SetColorDiaglog::~SetColorDiaglog()
{
}

void SetColorDiaglog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nR);
	DDX_Text(pDX, IDC_EDIT2, m_nG);
	DDX_Text(pDX, IDC_EDIT3, m_nB);
}


BEGIN_MESSAGE_MAP(SetColorDiaglog, CDialogEx)
END_MESSAGE_MAP()


// SetColorDiaglog 消息处理程序
