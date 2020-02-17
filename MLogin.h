#pragma once


// CMLogin 对话框

class CMLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CMLogin)

public:
	CMLogin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMLogin();

// 对话框数据
	enum { IDD = IDD_LOGIN1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString passsword;
};
