// CommentWrite.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "CommentWrite.h"
#include "afxdialogex.h"


// CCommentWrite �Ի���

IMPLEMENT_DYNAMIC(CCommentWrite, CDialogEx)

CCommentWrite::CCommentWrite(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCommentWrite::IDD, pParent)
	, comment(_T(""))
{

}

CCommentWrite::~CCommentWrite()
{
}

void CCommentWrite::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_COMMENT, comment);
}


BEGIN_MESSAGE_MAP(CCommentWrite, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCommentWrite::OnBnClickedOk)
END_MESSAGE_MAP()


// CCommentWrite ��Ϣ�������


void CCommentWrite::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int IDC=this->GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO5);
	switch(IDC)
	{
	case IDC_RADIO1:i_comment=5;break;
	case IDC_RADIO2:i_comment=4;break;
	case IDC_RADIO3:i_comment=3;break;
	case IDC_RADIO4:i_comment=2;break;
	case IDC_RADIO5:i_comment=1;break;
	}
	CDialogEx::OnOK();
}
