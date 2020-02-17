// SLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "SLogin.h"
#include "afxdialogex.h"


// CSLogin 对话框

IMPLEMENT_DYNAMIC(CSLogin, CDialogEx)

CSLogin::CSLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSLogin::IDD, pParent)
	, ID(_T(""))
	, password(_T(""))
{

}

CSLogin::~CSLogin()
{
}

void CSLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ID);
	DDX_Text(pDX, IDC_EDIT2, password);
}


BEGIN_MESSAGE_MAP(CSLogin, CDialogEx)
END_MESSAGE_MAP()


// CSLogin 消息处理程序
