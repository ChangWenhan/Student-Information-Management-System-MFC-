// CommentSee.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "CommentSee.h"
#include "afxdialogex.h"


// CCommentSee 对话框

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


// CCommentSee 消息处理程序


BOOL CCommentSee::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//表格
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(dwStyle);
	m_list.SetBkColor(RGB(0,255,255));
	m_list.SetTextBkColor(RGB(240,240,0));
	m_list.InsertColumn(0,_T("评价等级"),LVCFMT_CENTER,60);
	m_list.InsertColumn(1,_T("评语"),LVCFMT_CENTER,300);
	OnShow();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
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
				case 1:str="很不满意";break;
				case 2:str="不太满意";break;
				case 3:str="一般";break;
				case 4:str="满意";break;
				case 5:str="很满意";break;
				}
				m_list.InsertItem(k,L"");
				m_list.SetItemText(k,0,str);
				m_list.SetItemText(k,1,student[i].gv[j].c_Comment);
			}
		}
	}
}
