#pragma once
#include "afxwin.h"


// CAnalyse �Ի���

class CAnalyse : public CDialogEx
{
	DECLARE_DYNAMIC(CAnalyse)

public:
	CAnalyse(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAnalyse();

// �Ի�������
	enum { IDD = IDD_ANALYSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString CourseName;
	CString ClassNumber;
	int ManNumber;
	CString max;
	CString min;
	CString Average;
	CString Standard_dev;
	int iv[6];
	CString sv[6];
	COLORREF color[6];
	afx_msg void OnPaint();
};
