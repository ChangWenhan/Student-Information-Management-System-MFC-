#pragma once
#include "afxcmn.h"


// CStuRegDlg 对话框

class CStuRegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStuRegDlg)

public:
	CStuRegDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStuRegDlg();

// 对话框数据
	enum { IDD = IDD_STU_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void OnShow(void);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedDelete();
	CString m_classNum;
	CString m_ID;
	CString m_Name;
	CString m_Speciaty;
	CListCtrl m_list;
};
