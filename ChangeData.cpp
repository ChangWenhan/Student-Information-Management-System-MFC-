// ChangeData.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "ChangeData.h"
#include "afxdialogex.h"


// CChangeData 对话框

IMPLEMENT_DYNAMIC(CChangeData, CDialogEx)

CChangeData::CChangeData(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChangeData::IDD, pParent)
{

	m_Grade = 0.0;
	m_stuName = _T("");
	m_ID = _T("");
	m_courseName = _T("");
}

CChangeData::~CChangeData()
{
}

void CChangeData::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STU_NAME, m_stuName);
	DDX_Text(pDX, IDC_GRADE, m_Grade);
	DDX_Text(pDX, IDC_STU_ID, m_ID);
	DDX_Text(pDX, IDC_COURSE_NAME, m_courseName);
}


BEGIN_MESSAGE_MAP(CChangeData, CDialogEx)
END_MESSAGE_MAP()


// CChangeData 消息处理程序
