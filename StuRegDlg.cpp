// StuRegDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "StuRegDlg.h"
#include "afxdialogex.h"


// CStuRegDlg �Ի���

IMPLEMENT_DYNAMIC(CStuRegDlg, CDialogEx)

CStuRegDlg::CStuRegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStuRegDlg::IDD, pParent)
{

	m_classNum = _T("");
	m_ID = _T("");
	m_Name = _T("");
	m_Speciaty = _T("");
}

CStuRegDlg::~CStuRegDlg()
{
}

void CStuRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CLASS, m_classNum);
	DDX_Text(pDX, IDC_ID, m_ID);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_SPECIATY, m_Speciaty);
	DDX_Control(pDX, IDC_STU_LIST, m_list);
}


BOOL CStuRegDlg::OnInitDialog()
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
	m_list.InsertColumn(0,_T("ѧ��"),LVCFMT_CENTER,100);
	m_list.InsertColumn(1,_T("����"),LVCFMT_CENTER,100);
	m_list.InsertColumn(2,_T("�༶"),LVCFMT_CENTER,100);
	m_list.InsertColumn(3,_T("רҵ"),LVCFMT_CENTER,250);
	OnShow();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BEGIN_MESSAGE_MAP(CStuRegDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStuRegDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_DELETE, &CStuRegDlg::OnBnClickedDelete)
END_MESSAGE_MAP()


// CStuRegDlg ��Ϣ�������



void CStuRegDlg::OnShow(void)
{
	m_list.DeleteAllItems();
	for(UINT i=0;i<student.size();i++)
	{
		m_list.InsertItem(i,L"");
		m_list.SetItemText(i,0,student[i].ID);
		m_list.SetItemText(i,1,student[i].Name);
		m_list.SetItemText(i,2,student[i].ClassNum);
		m_list.SetItemText(i,3,student[i].Specialty);
	}
}


void CStuRegDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	StudentData temp;
	if(m_ID==""||m_Name==""||m_classNum==""||m_Speciaty=="")
	{
		AfxMessageBox(L"�������붼����Ϊ��");
	}
	for(UINT j=0;j<student.size();j++)
	{
		if(m_ID==student[j].ID)
		{
			AfxMessageBox(L"ѧ����Ϣ�Ѵ��ڣ������ظ�¼�룡����");
			return;
		}
		else
			if(j==student.size()-1)
			{
				break;
			}
	}
	temp.ID=m_ID;
	temp.Name=m_Name;
	temp.ClassNum=m_classNum;
	temp.Specialty=m_Speciaty;
	student.push_back(temp);
	for(int i=0;i<25;i++)
	{
		if(classnumber[i]!=""&&classnumber[i]!=m_classNum)
			continue;
		else
		{
			if(classnumber[i]=="")
				classnumber[i]=m_classNum;
			break;
		}
	}
	MessageBox(L"¼��ɹ���");
	OnShow();
	m_ID="";
	m_Name="";
	m_classNum="";
	m_Speciaty="";
	UpdateData(FALSE);
}


void CStuRegDlg::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			CString str=m_list.GetItemText(i,0);
			for(UINT k=0;k<student.size();k++)
			{
				if(student[k].ID==str)
				{
					for(UINT l=k;l<student.size()-1;l++)
					{
						student[l]=student[l+1];
					}
					student.pop_back();
					break;
				}
			}
			break;
		}
	}
}
