
// ManageSystemDlg.h : ͷ�ļ�
//

#pragma once
#include <fstream>
#include <string>
#include <xstring>
using namespace std;
// CManageSystemDlg �Ի���
class CManageSystemDlg : public CDialogEx
{
// ����
public:
	CManageSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MANAGESYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTeacher();
	afx_msg void OnBnClickedStudent();
	afx_msg void OnBnClickedManage();
	void Load(void);
	string str0;
	string str1;
	string str2;
	string str3;
	string str4;
	CString pathName;
	CString ID;
	CString password;
};
