// CommentSee.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "CommentSee.h"
#include "afxdialogex.h"


// CCommentSee �Ի���

IMPLEMENT_DYNAMIC(CCommentSee, CDialogEx)

CCommentSee::CCommentSee(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCommentSee::IDD, pParent)
{

}

CCommentSee::~CCommentSee()
{
}

void CCommentSee::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}


BEGIN_MESSAGE_MAP(CCommentSee, CDialogEx)
END_MESSAGE_MAP()


// CCommentSee ��Ϣ�������


BOOL CCommentSee::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	//���
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(dwStyle);
	m_list.SetBkColor(RGB(0,255,255));
	m_list.SetTextBkColor(RGB(240,240,0));
	m_list.InsertColumn(0,_T("���۵ȼ�"),LVCFMT_CENTER,60);
	m_list.InsertColumn(1,_T("����"),LVCFMT_CENTER,300);
	OnShow();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CCommentSee::OnShow(void)
{
	for(UINT i=0,k=0;i<student.size();i++)
	{
		for(UINT j=0;j<student[i].gv.size();j++)
		{
			if(student[i].gv[j].b_com&&student[i].gv[j].course.Name==CouName&&student[i].gv[j].course.teacher.ID==teaID)
			{
				CString str;
				switch(student[i].gv[j].i_com)
				{
				case 1:str="�ܲ�����";break;
				case 2:str="��̫����";break;
				case 3:str="һ��";break;
				case 4:str="����";break;
				case 5:str="������";break;
				}
				m_list.InsertItem(k,L"");
				m_list.SetItemText(k,0,str);
				m_list.SetItemText(k,1,student[i].gv[j].c_Comment);
			}
		}
	}
}
