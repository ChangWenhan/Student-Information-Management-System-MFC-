#pragma once


// CCommentWrite 对话框

class CCommentWrite : public CDialogEx
{
	DECLARE_DYNAMIC(CCommentWrite)

public:
	CCommentWrite(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommentWrite();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString comment;
	int i_comment;
	afx_msg void OnBnClickedOk();
};
