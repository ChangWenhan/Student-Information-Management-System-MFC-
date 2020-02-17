#pragma once


// CManagerPart 对话框

class CManagerPart : public CDialogEx
{
	DECLARE_DYNAMIC(CManagerPart)

public:
	CManagerPart(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CManagerPart();

// 对话框数据
	enum { IDD = IDD_MANAGER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStuRegister();
	afx_msg void OnBnClickedTeaRegister();
	afx_msg void OnBnClickedCourseAdd();
	afx_msg void OnBnClickedSave();
};
