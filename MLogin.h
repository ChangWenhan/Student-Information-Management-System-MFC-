#pragma once


// CMLogin �Ի���

class CMLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CMLogin)

public:
	CMLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString passsword;
};
