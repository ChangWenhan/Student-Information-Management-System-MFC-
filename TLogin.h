#pragma once


// CTLogin �Ի���

class CTLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CTLogin)

public:
	CTLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ID;
	CString password;
};
