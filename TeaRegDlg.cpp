// TeaRegDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "TeaRegDlg.h"
#include "afxdialogex.h"
void Calcul();

// CTeaRegDlg �Ի���

IMPLEMENT_DYNAMIC(CTeaRegDlg, CDialogEx)

CTeaRegDlg::CTeaRegDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTeaRegDlg::IDD, pParent)
	, m_ID(_T(""))
	, m_Name(_T(""))
{

}

CTeaRegDlg::~CTeaRegDlg()
{
}

void CTeaRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ID, m_ID);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Control(pDX, IDC_TEA_LIST, m_list);
}


BOOL CTeaRegDlg::OnInitDialog()
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
	m_list.InsertColumn(0,_T("��ʦ����"),LVCFMT_CENTER,100);
	m_list.InsertColumn(1,_T("����"),LVCFMT_CENTER,100);
	m_list.InsertColumn(2,_T("ѧ��ƽ������"),LVCFMT_CENTER,100);
	Calcul();
	OnShow();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BEGIN_MESSAGE_MAP(CTeaRegDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTeaRegDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_SORT, &CTeaRegDlg::OnBnClickedSort)
	ON_BN_CLICKED(IDC_DELETE, &CTeaRegDlg::OnBnClickedDelete)
END_MESSAGE_MAP()


// CTeaRegDlg ��Ϣ�������

void Calcul()
{
	for(UINT i=0;i<teacher.size();i++)
	{
		double c=0;
		int cc=0;
		for(UINT j=0;j<teacher[i].cv.size();j++)
		{
			CString couname=teacher[i].cv[j];
			CString teaID=teacher[i].ID;
			for(UINT k=0;k<student.size();k++)
			{
				for(UINT l=0;l<student[k].gv.size();l++)
				{
					if(student[k].gv[l].course.Name==couname&&student[k].gv[l].course.teacher.ID==teaID)
					{
						if(student[k].gv[l].b_com)
						{
							c+=student[k].gv[l].i_com;
							cc++;
						}
						break;
					}
				}
			}
		}
		if(!cc)
			cc=1;
		teacher[i].comment=c/cc;
		if(teacher[i].comment!=0)
			teacher[i].b_comment=true;
	}
}

void CTeaRegDlg::OnShow(void)
{
	m_list.DeleteAllItems();
	for(UINT i=0;i<teacher.size();i++)
	{
		m_list.InsertItem(i,L"");
		m_list.SetItemText(i,0,teacher[i].ID);
		m_list.SetItemText(i,1,teacher[i].Name);
		CString str;
		if(teacher[i].b_comment)
			str.Format(_T("%.01lf"),teacher[i].comment);
		else
			str=L"δ����";
		m_list.SetItemText(i,2,str);
	}
}


void CTeaRegDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	TeacherData temp;
	if(m_ID==""||m_Name=="")
	{
		AfxMessageBox(L"�������붼����Ϊ��");
		return;
	}
	for(UINT j=0;j<teacher.size();j++)
	{
		if(m_ID==teacher[j].ID)
		{
			AfxMessageBox(L"��ʦ��Ϣ�Ѵ��ڣ������ظ�¼�룡����");
			return;
		}
		else
			if(j==teacher.size()-1)
			{
				break;
			}
	}
	temp.ID=m_ID;
	temp.Name=m_Name;
	temp.b_comment=false;
	temp.comment=0;
	teacher.push_back(temp);
	MessageBox(L"¼��ɹ���");
	OnShow();
	m_ID="";
	m_Name="";
	UpdateData(FALSE);
}


void CTeaRegDlg::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	for(int i=0;i<m_list.GetItemCount();i++)
	{
		if(m_list.GetItemState(i,LVIS_SELECTED)==LVIS_SELECTED)
		{
			CString str=m_list.GetItemText(i,0);
			for(UINT k=0;k<teacher.size();k++)
			{
				if(teacher[k].ID==str)
				{
					for(UINT l=k;l<teacher.size()-1;l++)
					{
						teacher[l]=teacher[l+1];
					}
					teacher.pop_back();
					break;
				}
			}
			break;
		}
	}
}


void CTeaRegDlg::OnBnClickedSort()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bool noswap=true;
	//��¼���һ�ν�����λ��
    
	UINT lastExchangeIndex = 0;
    
//�������еı߽磬ÿ�αȽ�ֻ��Ҫ�ȵ�����Ϊֹ
    
	UINT sortBorder = 0;
	for (unsigned int j = 0; j < teacher.size()-1; j++)
	{
		for (unsigned int k = teacher.size()-1; k > sortBorder; k--)
		{
			if (teacher[k].comment>teacher[k-1].comment)
			{
				TeacherData temp;
				temp = teacher[k];
				teacher[k] = teacher[k - 1];
				teacher[k - 1] = temp;
				noswap=false;
				lastExchangeIndex=k;
			}
		}
		sortBorder=lastExchangeIndex;
		if(noswap)
			return;
	}
	OnShow();
}
