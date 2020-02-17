#pragma once


// CTLogin 对话框

class CTLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CTLogin)

public:
	CTLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ID;
	CString password;
};
