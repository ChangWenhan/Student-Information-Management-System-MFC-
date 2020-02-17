#pragma once


// CChangeData 对话框

class CChangeData : public CDialogEx
{
	DECLARE_DYNAMIC(CChangeData)

public:
	CChangeData(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChangeData();

// 对话框数据
	enum { IDD = IDD_CHANGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_stuName;
	double m_Grade;
	CString m_ID;
	CString m_courseName;
};
