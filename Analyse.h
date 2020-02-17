#pragma once
#include "afxwin.h"


// CAnalyse 对话框

class CAnalyse : public CDialogEx
{
	DECLARE_DYNAMIC(CAnalyse)

public:
	CAnalyse(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAnalyse();

// 对话框数据
	enum { IDD = IDD_ANALYSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
