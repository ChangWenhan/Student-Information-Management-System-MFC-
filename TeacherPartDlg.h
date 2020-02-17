#pragma once
#include "resource.h"
#include "afxcmn.h"
#include<fstream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include "afxwin.h"
using namespace std;

struct list
{
	unsigned int stuNum;
	unsigned int courseNum;
};

// CTeacherPartDlg 对话框

class CTeacherPartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherPartDlg)

public:
	CTeacherPartDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTeacherPartDlg();

// 对话框数据
	enum { IDD = IDD_TEACHER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
	vector<list> stu;
public:
	afx_msg void OnBnClickedSeeEva();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedChange();
	afx_msg void OnClickedFind();
	afx_msg void OnClickedAnanyse();
	afx_msg void OnClickedSelect();
	afx_msg void OnClickedShow();
	virtual BOOL OnInitDialog();
	void OnShow();
	void Sort(void);
	CListCtrl m_InfoList;
	CString m_teaID;
	TeacherData m_teacher;
	CString CourseName;
	CString m_class;
private:
	int m_findItem;
	bool showitem1;
	bool showitem2;
protected:
	CString ID;
	CString name;
	double min,max;
public:
	CComboBox m_showOption;
	CComboBox m_classNumber;
	void Select(void);
};
