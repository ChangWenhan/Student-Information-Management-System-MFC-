#pragma once


// CManagerPart �Ի���

class CManagerPart : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerPart)

public:
	CManagerPart(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CManagerPart();

// �Ի�������
	enum { IDD = IDD_MANAGER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStuRegister();
	afx_msg void OnBnClickedTeaRegister();
	afx_msg void OnBnClickedCourseAdd();
	afx_msg void OnBnClickedSave();
};
