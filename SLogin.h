#pragma once


// CSLogin 对话框

class CSLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CSLogin)

public:
	CSLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ID;
	CString password;
};
