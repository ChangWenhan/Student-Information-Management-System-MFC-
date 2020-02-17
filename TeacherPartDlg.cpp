// TeacherPartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "TeacherPartDlg.h"
#include "afxdialogex.h"
#include "ChangeData.h"
#include "Alarm1.h"
#include "Alarm2.h"
#include "Analyse.h"
#include "CommentSee.h"


// CTeacherPartDlg 对话框

IMPLEMENT_DYNAMIC(CTeacherPartDlg, CDialogEx)

CTeacherPartDlg::CTeacherPartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeacherPartDlg::IDD, pParent)
{
	m_teaID = _T("");
	showitem1=showitem2=false;
}

CTeacherPartDlg::~CTeacherPartDlg()
{
}

void CTeacherPartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INFOLIST, m_InfoList);
	DDX_Control(pDX, IDC_COMBO3, m_showOption);
	DDX_Control(pDX, IDC_COMBO1, m_classNumber);
	DDX_Text(pDX, IDC_EDIT1, ID);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT3, min);
	DDX_Text(pDX, IDC_EDIT4, max);
}


BEGIN_MESSAGE_MAP(CTeacherPartDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEE_EVA, &CTeacherPartDlg::OnBnClickedSeeEva)
	ON_BN_CLICKED(IDC_CHANGE, &CTeacherPartDlg::OnClickedChange)
	ON_BN_CLICKED(IDOK, &CTeacherPartDlg::OnClickedFind)
	ON_BN_CLICKED(IDC_ANANYSE, &CTeacherPartDlg::OnClickedAnanyse)
	ON_BN_CLICKED(IDC_SHOW, &CTeacherPartDlg::OnClickedShow)
END_MESSAGE_MAP()


BOOL CTeacherPartDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//表格
	DWORD dwStyle = m_InfoList.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_InfoList.SetExtendedStyle(dwStyle);
	m_InfoList.SetBkColor(RGB(0,255,255));
	m_InfoList.SetTextBkColor(RGB(240,240,0));
	m_InfoList.InsertColumn(0,_T("学号"),LVCFMT_CENTER,100);
	m_InfoList.InsertColumn(1,_T("姓名"),LVCFMT_CENTER,60);
	m_InfoList.InsertColumn(2,_T("课程名称"),LVCFMT_CENTER,250);
	m_InfoList.InsertColumn(3,_T("成绩"),LVCFMT_LEFT,60);

	//Radio控件
	CheckRadioButton(IDC_ID,IDC_EDGE , IDC_ID);  //默认选中IDC_ID单选框

	//Combo box控件
	m_showOption.AddString(L"所有课程");
	m_classNumber.AddString(L"所有班级");
	for(unsigned int i=0;i<teacher.size();i++)
	{
		if(teacher[i].ID==m_teaID)
		{
			m_teacher=teacher[i];
			for(unsigned int j=0;j<teacher[i].cv.size();j++)
			{
				m_showOption.AddString(teacher[i].cv[j]);
			}
			break;
		}
	}
	for(int i=0;classnumber[i]!=L""&&i<25;i++)
		m_classNumber.AddString(classnumber[i]);
	m_showOption.SetCurSel(0);
	m_classNumber.SetCurSel(0);

	//编辑框
	min=0;
	max=110;

	UpdateData(FALSE);
	OnClickedShow();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CTeacherPartDlg::Sort(void)
{
	bool noswap=true;
	if(stu.size()==0)
		return;
    
//记录最后一次交换的位置
    
	UINT lastExchangeIndex = 0;
    
//无序数列的边界，每次比较只需要比到这里为止
    
	UINT sortBorder = 0;
	for (unsigned int j = 0; j < stu.size()-1; j++)
	{
		for (unsigned int k = stu.size()-1; k > sortBorder; k--)
		{
			if (student[stu[k].stuNum].gv[stu[k].courseNum].grade>student[stu[k-1].stuNum].gv[stu[k-1].courseNum].grade)
			{
				list temp;
				temp = stu[k];
				stu[k] = stu[k - 1];
				stu[k - 1] = temp;
				lastExchangeIndex=k;
				noswap=false;
			}
		}
		sortBorder=lastExchangeIndex;
		if(noswap)
			return;
	}
}


void CTeacherPartDlg::OnShow()
{
	setlocale(LC_CTYPE, "chs");
	CString str;
	if(showitem1)
	{
		for(unsigned int i=0;i<stu.size();i++)
		{
			m_InfoList.InsertItem(i,L"");
			m_InfoList.SetItemText(i,0,student[stu[i].stuNum].ID);
			m_InfoList.SetItemText(i,1,student[stu[i].stuNum].Name);
			m_InfoList.SetItemText(i,2,student[stu[i].stuNum].gv[stu[i].courseNum].course.Name);
			str.Format(_T("%.01f"),student[stu[i].stuNum].gv[stu[i].courseNum].grade);
			m_InfoList.SetItemText(i,3,str);
		}
	}
	else
	{
		if(showitem2)
			for(unsigned int i=0,k=0;i<stu.size();i++)
			{
				for(unsigned int j=0;j<student[stu[i].stuNum].gv.size();j++)
				{
					m_InfoList.InsertItem(k,L"");
					m_InfoList.SetItemText(k,0,student[stu[i].stuNum].ID);
					m_InfoList.SetItemText(k,1,student[stu[i].stuNum].Name);
					m_InfoList.SetItemText(k,2,student[stu[i].stuNum].gv[j].course.Name);
					str.Format(_T("%.01f"),student[stu[i].stuNum].gv[j].grade);
					m_InfoList.SetItemText(k,3,str);
					k++;
				}
			}
		else
			for(unsigned int i=0,k=0;i<student.size();i++)
			{
				for(unsigned int j=0;j<student[i].gv.size();j++)
				{
					m_InfoList.InsertItem(k,L"");
					m_InfoList.SetItemText(k,0,student[i].ID);
					m_InfoList.SetItemText(k,1,student[i].Name);
					m_InfoList.SetItemText(k,2,student[i].gv[j].course.Name);
					str.Format(_T("%.01f"),student[i].gv[j].grade);
					m_InfoList.SetItemText(k,3,str);
					k++;
				}
			}
	}
}


// CTeacherPartDlg 消息处理程序


void CTeacherPartDlg::OnBnClickedSeeEva()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex;
	nIndex=m_showOption.GetCurSel();
	m_showOption.GetLBText(nIndex,CourseName);
	showitem1=(CourseName!=L"所有课程");
	if(showitem1)
	{
		CCommentSee dlg;
		dlg.teaID=m_teaID;
		dlg.CouName=CourseName;
		dlg.DoModal();
	}
	else
	{
		MessageBox(L"请先选择一门课程！");
		return;
	}
}


void CTeacherPartDlg::OnClickedChange()
{
	for(int i=0;i<m_InfoList.GetItemCount();i++)
	{
		if(m_InfoList.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			unsigned int j=0,k=0;
			for(j=0;j<student.size();j++)
			{
				if(student[j].Name==m_InfoList.GetItemText(i,1))
				{
					for(k=0;k<student[j].gv.size();k++)
					{
						if(student[j].gv[k].course.Name==m_InfoList.GetItemText(i,2)&&student[j].gv[k].grade==_ttof(m_InfoList.GetItemText(i,3)))
							break;
					}
					
					break;
				}
			}
			CChangeData Dlg;
			Dlg.m_courseName=student[j].gv[k].course.Name;
			Dlg.m_ID=student[j].ID;
			Dlg.m_stuName=student[j].Name;
			Dlg.m_Grade=student[j].gv[k].grade;
			if(Dlg.DoModal()==IDOK&&student[j].gv[k].grade!=Dlg.m_Grade)
			{
				CAlarm2 dlg;
				dlg.name=student[j].Name;
				if(dlg.DoModal()==IDOK)
				{
					CString str1,str2;
					double d;
					bool up=true;
					int nItem=i;
					student[j].gv[k].grade=Dlg.m_Grade;
					student[j].gv[k].test=true;
					m_InfoList.DeleteItem(i);
					do
					{
						str1=m_InfoList.GetItemText(i,2);
						str2=m_InfoList.GetItemText(i,3);
						d=_ttof(str2);
						if(Dlg.m_Grade<d&&str1==Dlg.m_courseName)
						{
							i++;
							up=false;
							continue;
						}
						else
							break;
					}while(i>0&&i<m_InfoList.GetItemCount());
					while(i>0&&i<=m_InfoList.GetItemCount()&&up)
					{
						str1=m_InfoList.GetItemText(i-1,2);
						str2=m_InfoList.GetItemText(i-1,3);
						d=_ttof(str2);
						if(Dlg.m_Grade>d&&str1==Dlg.m_courseName)
							i--;
						else
							break;
					}
					m_InfoList.InsertItem(i,_T(""));
					m_InfoList.SetItemText(i,0,Dlg.m_ID);
					m_InfoList.SetItemText(i,1,Dlg.m_stuName);
					m_InfoList.SetItemText(i,2,Dlg.m_courseName);
					str1.Format(_T("%.01f"),Dlg.m_Grade);
					m_InfoList.SetItemText(i,3,str1);
				}
			}
			break;
		}
	}
}


void CTeacherPartDlg::OnClickedFind()
{
	// TODO: 在此添加控件通知处理程序代码
	m_InfoList.DeleteAllItems();
	UpdateData(TRUE);
	vector<list> fv=stu;
	int nIndex;
	m_InfoList.DeleteAllItems();
	nIndex=m_showOption.GetCurSel();
	m_showOption.GetLBText(nIndex,CourseName);
	nIndex=m_classNumber.GetCurSel();
	m_classNumber.GetLBText(nIndex,m_class);
	showitem1=(CourseName!=L"所有课程");
	showitem2=(m_class!=L"所有班级");
	int IDC=GetCheckedRadioButton(IDC_ID,IDC_EDGE);
	CString str;
	vector<list> tv;
	switch(IDC)
	{
	case IDC_ID:
		{
			if(showitem1)
			{
				for(unsigned int i=0;i<student.size();i++)
				{
					if((!showitem2||student[i].ClassNum==m_class)&&student[i].ID==ID)
					{
						for(unsigned int j=0;j<student[i].gv.size();j++)
						{
							if(student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID)
							{
								list temp;
								temp.stuNum=i;
								temp.courseNum=j;
								tv.push_back(temp);
							}
						}
					}
				}
				stu.swap(tv);
				Sort();
				OnShow();
			}
			else
			{
				showitem1=true;
				for(int i=0;i<course.size();i++)
				{
					tv.clear();
					stu.swap(tv);
					CourseName=course[i].Name;
					for(unsigned int i=0;i<student.size();i++)
					{
						for(unsigned int j=0;j<student[i].gv.size();j++)
						{
							if((!showitem2||student[i].ClassNum==m_class)&&student[i].ID==ID&&student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID)
							{
								list temp;
								temp.courseNum=j;
								temp.stuNum=i;
								stu.push_back(temp);
							}
						}
					}
					Sort();
					OnShow();
					stu.swap(tv);
				}
				showitem1=false;
			}
			break;
		}
	case IDC_NAME:
		{
			if(showitem1)
			{
				for(unsigned int i=0;i<student.size();i++)
				{
					if((!showitem2||student[i].ClassNum==m_class)&&student[i].IsSame(name))
					{
						for(unsigned int j=0;j<student[i].gv.size();j++)
						{
							if(student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID)
							{
								list temp;
								temp.stuNum=i;
								temp.courseNum=j;
								tv.push_back(temp);
							}
						}
					}
				}
				stu.swap(tv);
				Sort();
				OnShow();
			}
			else
			{
				showitem1=true;
				for(int i=0;i<course.size();i++)
				{
					tv.clear();
					stu.swap(tv);
					CourseName=course[i].Name;
					for(unsigned int i=0;i<student.size();i++)
					{
						for(unsigned int j=0;j<student[i].gv.size();j++)
						{
							if((!showitem2||student[i].ClassNum==m_class)&&student[i].IsSame(name)&&student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID)
							{
								list temp;
								temp.courseNum=j;
								temp.stuNum=i;
								stu.push_back(temp);
							}
						}
					}
					Sort();
					OnShow();
					stu.swap(tv);
				}
				showitem1=false;
			}
			break;
		}
	case IDC_EDGE:
		{
			if(showitem1)
			{
				for(unsigned int i=0;i<student.size();i++)
				{
					if((!showitem2||student[i].ClassNum==m_class))
					{
						for(unsigned int j=0;j<student[i].gv.size();j++)
						{
							if(student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID&&student[i].gv[j].grade>=min&&student[i].gv[j].grade<=max)
							{
								list temp;
								temp.stuNum=i;
								temp.courseNum=j;
								tv.push_back(temp);
							}
						}
					}
				}
				stu.swap(tv);
				Sort();
				OnShow();
			}
			else
			{
				showitem1=true;
				for(int i=0;i<course.size();i++)
				{
					tv.clear();
					stu.swap(tv);
					CourseName=course[i].Name;
					for(unsigned int i=0;i<student.size();i++)
					{
						for(unsigned int j=0;j<student[i].gv.size();j++)
						{
							if((!showitem2||student[i].ClassNum==m_class)&&student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID&&student[i].gv[j].grade>=min&&student[i].gv[j].grade<=max)
							{
								list temp;
								temp.courseNum=j;
								temp.stuNum=i;
								stu.push_back(temp);
							}
						}
					}
					Sort();
					OnShow();
					stu.swap(tv);
				}
				showitem1=false;
			}
			break;
		}
	}
	stu.swap(fv);
}


void CTeacherPartDlg::OnClickedAnanyse()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex;
	nIndex=m_showOption.GetCurSel();
	m_showOption.GetLBText(nIndex,CourseName);
	nIndex=m_classNumber.GetCurSel();
	m_classNumber.GetLBText(nIndex,m_class);
	showitem1=(CourseName!=L"所有课程");
	showitem2=(m_class!=L"所有班级");
	if(showitem1)
	{
		Select();
		int i=stu.size();
		CAnalyse dlg;
		double sum=0, sum1=0, max = 0, min = 120, aver = 0, standard_dev=0;
		for (int j = 0; j < i; j++)
		{
			double iii=student[stu[j].stuNum].gv[stu[j].courseNum].grade;
			sum += iii;
			if(iii<60)
				dlg.iv[0]++;
			else
				if(iii<70)
					dlg.iv[1]++;
				else
					if(iii<80)
						dlg.iv[2]++;
					else
						if(iii<90)
							dlg.iv[3]++;
						else
							if(iii<100)
								dlg.iv[4]++;
							else
								dlg.iv[5]++;
			max=max(iii,max);
			min=min(iii,min);
		}
		aver = sum / i;
		for (int j = 0; j < i; j++)
		{
			double iii=student[stu[j].stuNum].gv[stu[j].courseNum].grade;
			sum1 += (iii - aver)*(iii - aver);
		}
		standard_dev = sqrt((sum1) / i);
		dlg.CourseName=CourseName;
		dlg.ClassNumber=m_class;
		dlg.ManNumber=i;
		dlg.max.Format(_T("%.1f"),max);
		dlg.min.Format(_T("%.1f"),min);
		dlg.Average.Format(_T("%.1f"),aver);
		dlg.Standard_dev.Format(_T("%.1f"),standard_dev);
		dlg.DoModal();
	}
	else
	{
		MessageBox(L"请先选择一门课程！");
		return;
	}
}


void CTeacherPartDlg::OnClickedShow()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex;
	m_InfoList.DeleteAllItems();
	nIndex=m_showOption.GetCurSel();
	m_showOption.GetLBText(nIndex,CourseName);
	nIndex=m_classNumber.GetCurSel();
	m_classNumber.GetLBText(nIndex,m_class);
	showitem1=(CourseName!=L"所有课程");
	showitem2=(m_class!=L"所有班级");
	if(showitem1)
	{
		Select();
		Sort();
		OnShow();
	}
	else
	{
		showitem1=true;
		for(int i=0;i<course.size();i++)
		{
			CourseName=course[i].Name;
			Select();
			Sort();
			OnShow();
		}
		showitem1=false;
	}
}


void CTeacherPartDlg::Select(void)
{
	stu.clear();
	if(showitem1||showitem2)
		for(unsigned int i=0;i<student.size();i++)
		{
				for(unsigned int j=0;j<student[i].gv.size();j++)
				{
					if(student[i].gv[j].course.Name==CourseName&&student[i].gv[j].course.teacher.ID==m_teaID&&(!showitem2||student[i].ClassNum==m_class))
					{
						list temp;
						temp.courseNum=j;
						temp.stuNum=i;
						stu.push_back(temp);
					}
				}
		}
}



