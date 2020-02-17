#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CCouAddDlg �Ի���

class CCouAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCouAddDlg)

public:
	CCouAddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCouAddDlg();

// �Ի�������
	enum { IDD = IDD_COU_ADD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ID;
	CString Name;
	int period;
	CString m_teaID;
	CListCtrl m_list;
	int address;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCouDel();
	afx_msg void OnNMClickCourseList(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	void OnShow(void);
	CComboBox m_kind;
};
