// MLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "MLogin.h"
#include "afxdialogex.h"


// CMLogin 对话框

IMPLEMENT_DYNAMIC(CMLogin, CDialogEx)

CMLogin::CMLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMLogin::IDD, pParent)
	, passsword(_T(""))
{

}

CMLogin::~CMLogin()
{
}

void CMLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, passsword);
}


BEGIN_MESSAGE_MAP(CMLogin, CDialogEx)
END_MESSAGE_MAP()


// CMLogin 消息处理程序
