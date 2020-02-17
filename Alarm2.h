#pragma once


// CAlarm2 对话框

class CAlarm2 : public CDialogEx
{
	DECLARE_DYNAMIC(CAlarm2)

public:
	CAlarm2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAlarm2();

// 对话框数据
	enum { IDD = IDD_ALARM2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
};
