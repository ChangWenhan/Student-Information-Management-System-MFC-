#pragma once
#include "afxcmn.h"


// CStuRegDlg �Ի���

class CStuRegDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStuRegDlg)

public:
	CStuRegDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStuRegDlg();

// �Ի�������
	enum { IDD = IDD_STU_REG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
