#pragma once


// CCommentWrite �Ի���

class CCommentWrite : public CDialogEx
{
	DECLARE_DYNAMIC(CCommentWrite)

public:
	CCommentWrite(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommentWrite();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString comment;
	int i_comment;
	afx_msg void OnBnClickedOk();
};
