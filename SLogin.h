#pragma once


// CSLogin �Ի���

class CSLogin : public CDialogEx
{
	DECLARE_DYNAMIC(CSLogin)

public:
	CSLogin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSLogin();

// �Ի�������
	enum { IDD = IDD_LOGIN2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ID;
	CString password;
};
