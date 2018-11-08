#pragma once


// SelectAxisDialog 对话框

class SelectAxisDialog : public CDialogEx
{
	DECLARE_DYNAMIC(SelectAxisDialog)

public:
	SelectAxisDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SelectAxisDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGAXIS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_nRotateAxis;
};
