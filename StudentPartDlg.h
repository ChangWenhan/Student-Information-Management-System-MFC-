#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CStudentPart �Ի���

class CStudentPartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStudentPartDlg)
private:
	bool open;
public:
	CStudentPartDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStudentPartDlg();
	void show();
	void show1();
	void show2();
// �Ի�������
	enum { IDD = IDD_STUDENT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedGrade();
	afx_msg void OnBnClickedSelected();
	afx_msg void OnBnClickedSelect();
	afx_msg void OnBnClickedDelete();
	StudentData m_student;
	void ShowCtrl();
	bool showctrl;
	bool canselect;
	CListCtrl m_list;
	CString CourseName;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCanSelect();
	double m_creditGetted;
	double m_creditSelected;
	vector<int> cou;
	CComboBox xuanbixiu;
	CString kind;
	afx_msg void OnBnClickedComment();
};
