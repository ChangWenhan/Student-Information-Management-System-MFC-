#pragma once
#include "afxcmn.h"


// CTeaRegDlg 对话框

class CTeaRegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeaRegDlg)

public:
	CTeaRegDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeaRegDlg();

// 对话框数据
	enum { IDD = IDD_TEA_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

protected:
	void OnShow(void);
public:
	CString m_ID;
	CString m_Name;
	CListCtrl m_list;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedSort();
	afx_msg void OnBnClickedDelete();
};
