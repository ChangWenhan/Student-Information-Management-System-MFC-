#pragma once
#include "afxcmn.h"


// CTeaRegDlg �Ի���

class CTeaRegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeaRegDlg)

public:
	CTeaRegDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeaRegDlg();

// �Ի�������
	enum { IDD = IDD_TEA_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
