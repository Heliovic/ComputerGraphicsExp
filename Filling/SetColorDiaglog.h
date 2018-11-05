#pragma once


// SetColorDiaglog 对话框

class SetColorDiaglog : public CDialogEx
{
	DECLARE_DYNAMIC(SetColorDiaglog)

public:
	SetColorDiaglog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetColorDiaglog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nR;
	int m_nG;
	int m_nB;
};
