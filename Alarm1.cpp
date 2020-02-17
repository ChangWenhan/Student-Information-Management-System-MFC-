// Alarm1.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "Alarm1.h"
#include "afxdialogex.h"


// CAlarm1 对话框

IMPLEMENT_DYNAMIC(CAlarm1, CDialogEx)

CAlarm1::CAlarm1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAlarm1::IDD, pParent)
{

}

CAlarm1::~CAlarm1()
{
}

void CAlarm1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ID);
}


BEGIN_MESSAGE_MAP(CAlarm1, CDialogEx)
END_MESSAGE_MAP()


// CAlarm1 消息处理程序
