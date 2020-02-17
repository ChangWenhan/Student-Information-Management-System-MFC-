
// ManageSystemDlg.h : 头文件
//

#pragma once
#include <fstream>
#include <string>
#include <xstring>
using namespace std;
// CManageSystemDlg 对话框
class CManageSystemDlg : public CDialogEx
{
// 构造
public:
	CManageSystemDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MANAGESYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
