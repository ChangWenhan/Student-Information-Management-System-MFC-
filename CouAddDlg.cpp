// CouAddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "CouAddDlg.h"
#include "afxdialogex.h"


// CCouAddDlg 对话框

IMPLEMENT_DYNAMIC(CCouAddDlg, CDialogEx)

CCouAddDlg::CCouAddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCouAddDlg::IDD, pParent)
	, ID(_T(""))
	, Name(_T(""))
	, period(0)
	, m_teaID(_T(""))
{

}

CCouAddDlg::~CCouAddDlg()
{
}

void CCouAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ID, ID);
	DDX_Text(pDX, IDC_NAME, Name);
	DDX_Text(pDX, IDC_PERIOD, period);
	DDX_Text(pDX, IDC_TEACHER, m_teaID);
	DDX_Control(pDX, IDC_COURSE_LIST, m_list);
	DDX_Control(pDX, IDC_KIND, m_kind);
}


BOOL CCouAddDlg::OnInitDialog()
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
	m_list.InsertColumn(0,_T("课程编号"),LVCFMT_CENTER,80);
	m_list.InsertColumn(1,_T("课程名称"),LVCFMT_CENTER,200);
	m_list.InsertColumn(2,L"课程学分",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,L"课程学时",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,L"任课教师",LVCFMT_LEFT,80);
	m_list.InsertColumn(5,L"课程性质",LVCFMT_LEFT,80);
	OnShow();
	m_kind.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BEGIN_MESSAGE_MAP(CCouAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCouAddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_COU_DEL, &CCouAddDlg::OnBnClickedCouDel)
	ON_NOTIFY(NM_CLICK, IDC_COURSE_LIST, &CCouAddDlg::OnNMClickCourseList)
END_MESSAGE_MAP()


// CCouAddDlg 消息处理程序


void CCouAddDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CourseData temp;
	if(ID==""||Name==""||m_teaID==""||period==0)
	{
		AfxMessageBox(L"所有输入都不得为空");
	}
	for(UINT j=0;j<teacher.size();j++)
	{
		if(m_teaID==teacher[j].ID)
		{
			teacher[j].cv.push_back(Name);
			temp.teacher=teacher[j];
			break;
		}
		else
			if(j==teacher.size()-1)
			{
				AfxMessageBox(L"教师信息不存在，请先录入教师信息！！！");
				return;
			}
	}
	temp.CourseID=ID;
	temp.Name=Name;
	temp.period=period;
	temp.credit=(double)period/16;
	CString str;
	int i=m_kind.GetCurSel();
	m_kind.GetLBText(i,str);
	temp.kind=str;
	course.push_back(temp);
	MessageBox(L"录入成功！");
	OnShow();
	ID="";
	Name="";
	m_teaID="";
	period=0;
	UpdateData(FALSE);
}


void CCouAddDlg::OnBnClickedCouDel()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			CString str=m_list.GetItemText(i,1);
			for(UINT k=0;k<teacher.size();k++)
			{
				if(teacher[k].ID==course[i].teacher.ID)
				{
					for(UINT l=0;l<teacher[k].cv.size();l++)
						if(teacher[k].cv[l]==str)
						{
							for(UINT j=l;j<teacher[k].cv.size()-1;j++)
							{
								teacher[k].cv[j]=teacher[k].cv[j+1];
							}
							teacher[k].cv.pop_back();
							break;
						}
				}
				break;
			}
			for(UINT j=i;j<course.size()-1;j++)
			{
				course[j]=course[j+1];
			}
			course.pop_back();
			m_list.DeleteItem(i);
			break;
		}
	}
}


void CCouAddDlg::OnNMClickCourseList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			address=i;
		}
	}
}


void CCouAddDlg::OnShow(void)
{
	m_list.DeleteAllItems();
	for(UINT i=0;i<course.size();i++)
	{
		CString str;
		m_list.InsertItem(i,L"");
		m_list.SetItemText(i,0,course[i].CourseID);
		m_list.SetItemText(i,1,course[i].Name);
		str.Format(_T("%.1f"),course[i].credit);
		m_list.SetItemText(i,2,str);
		str.Format(_T("%d"),course[i].period);
		m_list.SetItemText(i,3,str);
		m_list.SetItemText(i,4,course[i].teacher.Name);
		m_list.SetItemText(i,5,course[i].kind);
	}
}
