#pragma once
#include "afxcmn.h"


// CCommentSee 对话框

class CCommentSee : public CDialogEx
{
	DECLARE_DYNAMIC(CCommentSee)

public:
	CCommentSee(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommentSee();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void OnShow(void);
	CString teaID;
	CString CouName;
};
