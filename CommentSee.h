#pragma once
#include "afxcmn.h"


// CCommentSee �Ի���

class CCommentSee : public CDialogEx
{
	DECLARE_DYNAMIC(CCommentSee)

public:
	CCommentSee(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommentSee();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	void OnShow(void);
	CString teaID;
	CString CouName;
};
