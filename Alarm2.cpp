// Alarm2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "Alarm2.h"
#include "afxdialogex.h"


// CAlarm2 �Ի���

IMPLEMENT_DYNAMIC(CAlarm2, CDialogEx)

CAlarm2::CAlarm2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAlarm2::IDD, pParent)
	, name(_T(""))
{

}

CAlarm2::~CAlarm2()
{
}

void CAlarm2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STU_NAME, name);
}


BEGIN_MESSAGE_MAP(CAlarm2, CDialogEx)
END_MESSAGE_MAP()


// CAlarm2 ��Ϣ�������
