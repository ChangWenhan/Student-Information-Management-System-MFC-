#pragma once


// CChangeData �Ի���

class CChangeData : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeData)

public:
	CChangeData(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChangeData();

// �Ի�������
	enum { IDD = IDD_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_stuName;
	double m_Grade;
	CString m_ID;
	CString m_courseName;
};
