// TLogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "TLogin.h"
#include "afxdialogex.h"


// CTLogin �Ի���

IMPLEMENT_DYNAMIC(CTLogin, CDialogEx)

CTLogin::CTLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTLogin::IDD, pParent)
	, ID(_T(""))
	, password(_T(""))
{

}

CTLogin::~CTLogin()
{
}

void CTLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TID, ID);
	DDX_Text(pDX, IDC_PASSWORD, password);
}


BEGIN_MESSAGE_MAP(CTLogin, CDialogEx)
END_MESSAGE_MAP()


// CTLogin ��Ϣ�������
