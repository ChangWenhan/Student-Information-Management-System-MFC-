// StudentPart.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "StudentPartDlg.h"
#include "afxdialogex.h"
#include "CommentWrite.h"

// CStudentPartDlg 对话框

IMPLEMENT_DYNAMIC(CStudentPartDlg, CDialogEx)

CStudentPartDlg::CStudentPartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStudentPartDlg::IDD, pParent)
	, CourseName(_T(""))
{

	m_creditGetted = 0.0;
	m_creditSelected=0.0;
}

CStudentPartDlg::~CStudentPartDlg()
{
}

void CStudentPartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, CourseName);
	DDX_Text(pDX, IDC_EDIT2, m_creditGetted);
	DDX_Text(pDX, IDC_EDIT3, m_creditSelected);
	DDX_Text(pDX, IDC_EDIT4, m_student.ID);
	DDX_Text(pDX, IDC_EDIT5, m_student.Name);
	DDX_Control(pDX, IDC_COMBO1, xuanbixiu);
}


BEGIN_MESSAGE_MAP(CStudentPartDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEARCH, &CStudentPartDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_GRADE, &CStudentPartDlg::OnBnClickedGrade)
	ON_BN_CLICKED(IDC_SELECTED, &CStudentPartDlg::OnBnClickedSelected)
	ON_BN_CLICKED(IDC_SELECT, &CStudentPartDlg::OnBnClickedSelect)
	ON_BN_CLICKED(IDC_DELETE, &CStudentPartDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_CAN_SELECT, &CStudentPartDlg::OnBnClickedCanSelect)
	ON_BN_CLICKED(IDC_COMMENT, &CStudentPartDlg::OnBnClickedComment)
END_MESSAGE_MAP()


BOOL CStudentPartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	xuanbixiu.AddString(L"不限");
	xuanbixiu.AddString(L"必修");
	xuanbixiu.AddString(L"选修");
	xuanbixiu.SetCurSel(0);
	//表格
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(dwStyle);
	m_list.SetBkColor(RGB(0,255,255));
	m_list.SetTextBkColor(RGB(240,240,0));
	m_list.InsertColumn(0,_T("课程编号"),LVCFMT_CENTER,80);
	m_list.InsertColumn(1,_T("课程名称"),LVCFMT_CENTER,220);
	m_list.InsertColumn(2,L"课程学分",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,L"任课教师",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,_T("课程性质"),LVCFMT_CENTER,80);
	showctrl=false;
	ShowCtrl();

	for(UINT i=0;i<m_student.gv.size();i++)
	{
		if(m_student.gv[i].grade>=60)
		{
			m_creditGetted+=m_student.gv[i].course.credit;
		}
		m_creditSelected+=m_student.gv[i].course.credit;
	}


	UpdateData(FALSE);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


// CStudentPartDlg 消息处理程序

void CStudentPartDlg::ShowCtrl()
{
	this->GetDlgItem(IDC_DELETE)->ShowWindow(showctrl&&!canselect);
	this->GetDlgItem(IDC_SELECT)->ShowWindow(showctrl&&canselect);
	this->GetDlgItem(IDC_COMMENT)->ShowWindow(!showctrl);
	m_list.DeleteColumn(4);
	if(showctrl)
		m_list.InsertColumn(4,_T("课程性质"),LVCFMT_CENTER,80);
	else
		m_list.InsertColumn(4,_T("成绩"),LVCFMT_CENTER,80);
	open=false;
}


void CStudentPartDlg::OnBnClickedGrade()
{
	// TODO: 在此添加控件通知处理程序代码
	showctrl=false;
	CourseName="";
	kind="不限";
	show();
}


void CStudentPartDlg::OnBnClickedSelected()
{
	// TODO: 在此添加控件通知处理程序代码
	showctrl=true;
	canselect=false;
	CourseName="";
	kind="不限";
	show1();
}


void CStudentPartDlg::OnBnClickedCanSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	showctrl=true;
	canselect=true;
	CourseName="";
	kind="不限";
	show2();
}


void CStudentPartDlg::OnBnClickedSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int nIndex=xuanbixiu.GetCurSel();
	xuanbixiu.GetLBText(nIndex,kind);
	if(!showctrl)
		show();
	else
		if(canselect)
			show2();
		else
			show1();
}


void CStudentPartDlg::OnBnClickedSelect()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			GradeData temp(course[cou[i]]);
			temp.b_com=false;
			temp.i_com=0;
			m_student.gv.push_back(temp);
			m_list.DeleteItem(i);
			for(;i<cou.size()-1;i++)
			{
				cou[i]=cou[i+1];
			}
			cou.pop_back();
		}
	}
}


void CStudentPartDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			CString str=m_list.GetItemText(i,1);
			UINT j=cou[i];
			if(!m_student.gv[j].test)
			{
				for(;j<m_student.gv.size()-1;j++)
				{
					m_student.gv[j]=m_student.gv[j+1];
				}
				m_student.gv.pop_back();
				m_list.DeleteItem(i);
			}
			else
				AfxMessageBox(L"此课程无法退选！！！");
			break;
		}
	}
}


void CStudentPartDlg::show()
{
	ShowCtrl();
	m_list.DeleteAllItems();
	cou.clear();
	for(UINT i=0,k=0;i<m_student.gv.size();i++)
	{
		if(m_student.gv[i].test&&m_student.gv[i].course.IsSame(CourseName)&&(kind=="不限"||kind==m_student.gv[i].course.kind))
		{
			cou.push_back(i);
			m_list.InsertItem(k,L"");
			m_list.SetItemText(k,0,m_student.gv[i].course.CourseID);
			m_list.SetItemText(k,1,m_student.gv[i].course.Name);
			CString str;
			str.Format(_T("%.1f"),m_student.gv[i].course.credit);
			m_list.SetItemText(k,2,str);
			m_list.SetItemText(k,3,m_student.gv[i].course.teacher.Name);
			str.Format(_T("%.1f"),m_student.gv[i].grade);
			m_list.SetItemText(k,4,str);
			k++;
		}
	}
}


void CStudentPartDlg::show1()
{
	cou.clear();
	ShowCtrl();
	m_list.DeleteAllItems();
	for(UINT i=0,k=0;i<m_student.gv.size();i++)
	{
		if(m_student.gv[i].course.IsSame(CourseName)&&(kind=="不限"||kind==m_student.gv[i].course.kind))
		{
			cou.push_back(i);
			m_list.InsertItem(k,L"");
			m_list.SetItemText(k,0,m_student.gv[i].course.CourseID);
			m_list.SetItemText(k,1,m_student.gv[i].course.Name);
			CString str;
			str.Format(_T("%.1f"),m_student.gv[i].course.credit);
			m_list.SetItemText(k,2,str);
			m_list.SetItemText(k,3,m_student.gv[i].course.teacher.Name);
			m_list.SetItemText(k,4,m_student.gv[i].course.kind);
			k++;
		}
	}
}


void CStudentPartDlg::show2()
{
	cou.clear();
	ShowCtrl();
	m_list.DeleteAllItems();
	for(UINT i=0,k=0;i<course.size();i++)
	{
		bool noselect=true;
		bool test=false;
		double temp=0;
		for(UINT j=0;j<m_student.gv.size();j++)
		{
			if(m_student.gv[j].course.Name==course[i].Name)
			{
				noselect=false;
				if(m_student.gv[j].test)
				{
					temp=max(temp,m_student.gv[j].grade);
					test=true;
				}
			}
		}
		if(((test&&temp<60)||noselect)&&course[i].IsSame(CourseName)&&(kind=="不限"||kind==course[i].kind))
		{
			cou.push_back(i);
			m_list.InsertItem(k,L"");
			m_list.SetItemText(k,0,course[i].CourseID);
			m_list.SetItemText(k,1,course[i].Name);
			CString str;
			str.Format(_T("%.1f"),course[i].credit);
			m_list.SetItemText(k,2,str);
			m_list.SetItemText(k,3,course[i].teacher.Name);
			m_list.SetItemText(k,4,course[i].kind);
			k++;
		}
	}
}


void CStudentPartDlg::OnBnClickedComment()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			CString str=m_list.GetItemText(i,1);
			UINT j=cou[i];
			CCommentWrite dlg;
			if(dlg.DoModal()==IDOK)
			{
				m_student.gv[j].i_com=dlg.i_comment;
				m_student.gv[j].c_Comment=dlg.comment;
				m_student.gv[j].b_com=true;
			}
		}
	}

}
