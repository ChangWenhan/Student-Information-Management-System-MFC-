// CouAddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "CouAddDlg.h"
#include "afxdialogex.h"


// CCouAddDlg �Ի���

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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//���
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(dwStyle);
	m_list.SetBkColor(RGB(0,255,255));
	m_list.SetTextBkColor(RGB(240,240,0));
	m_list.InsertColumn(0,_T("�γ̱��"),LVCFMT_CENTER,80);
	m_list.InsertColumn(1,_T("�γ�����"),LVCFMT_CENTER,200);
	m_list.InsertColumn(2,L"�γ�ѧ��",LVCFMT_LEFT,80);
	m_list.InsertColumn(3,L"�γ�ѧʱ",LVCFMT_LEFT,80);
	m_list.InsertColumn(4,L"�ον�ʦ",LVCFMT_LEFT,80);
	m_list.InsertColumn(5,L"�γ�����",LVCFMT_LEFT,80);
	OnShow();
	m_kind.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BEGIN_MESSAGE_MAP(CCouAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCouAddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_COU_DEL, &CCouAddDlg::OnBnClickedCouDel)
	ON_NOTIFY(NM_CLICK, IDC_COURSE_LIST, &CCouAddDlg::OnNMClickCourseList)
END_MESSAGE_MAP()


// CCouAddDlg ��Ϣ�������


void CCouAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	CourseData temp;
	if(ID==""||Name==""||m_teaID==""||period==0)
	{
		AfxMessageBox(L"�������붼����Ϊ��");
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
				AfxMessageBox(L"��ʦ��Ϣ�����ڣ�����¼���ʦ��Ϣ������");
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
	MessageBox(L"¼��ɹ���");
	OnShow();
	ID="";
	Name="";
	m_teaID="";
	period=0;
	UpdateData(FALSE);
}


void CCouAddDlg::OnBnClickedCouDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
