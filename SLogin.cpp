// SLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "SLogin.h"
#include "afxdialogex.h"


// CSLogin �Ի���

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


// CSLogin ��Ϣ�������
