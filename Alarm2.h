#pragma once


// CAlarm2 �Ի���

class CAlarm2 : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarm2)

public:
	CAlarm2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAlarm2();

// �Ի�������
	enum { IDD = IDD_ALARM2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
};
