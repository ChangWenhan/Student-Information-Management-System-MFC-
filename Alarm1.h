#pragma once


// CAlarm1 �Ի���

class CAlarm1 : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarm1)

public:
	CAlarm1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAlarm1();

// �Ի�������
	enum { IDD = IDD_ALARM1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	LONGLONG m_ID;
};
