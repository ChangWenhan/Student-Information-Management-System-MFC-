
// ManageSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "ManageSystemDlg.h"
#include "afxdialogex.h"
#include "TeacherPartDlg.h"
#include "StudentPartDlg.h"
#include "ManagerPart.h"

#include "TLogin.h"
#include "SLogin.h"
#include "MLogin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CManageSystemDlg �Ի���




CManageSystemDlg::CManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManageSystemDlg::IDD, pParent)
	, pathName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CManageSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TEACHER, &CManageSystemDlg::OnBnClickedTeacher)
	ON_BN_CLICKED(IDC_STUDENT, &CManageSystemDlg::OnBnClickedStudent)
	ON_BN_CLICKED(IDC_MANAGE, &CManageSystemDlg::OnBnClickedManage)
END_MESSAGE_MAP()


// CManageSystemDlg ��Ϣ�������

BOOL CManageSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	Load();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CManageSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CManageSystemDlg::OnBnClickedTeacher()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTLogin dlgg;
	CTeacherPartDlg dlg;
	if(dlgg.DoModal()==IDOK)
	{
		ID=dlgg.ID;
		password=dlgg.password;
		if(password!="")
		{
			AfxMessageBox(L"������������ԣ�");
			return;
		}
	}
	else
		return;
	unsigned i=0;
	for(i=0;i<teacher.size();i++)
	{
		if(teacher[i].ID==ID)
		{
			dlg.m_teacher=teacher[i];
			dlg.m_teaID=ID;
			break;
		}
		else
			if(i==teacher.size()-1)
			{
				MessageBox(L"���Ų����ڣ��������룡");
				return;
			}
	}
	dlg.DoModal();
}


void CManageSystemDlg::OnBnClickedStudent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSLogin dlgg;
	CStudentPartDlg dlg;
	if(dlgg.DoModal()==IDOK)
	{
		ID=dlgg.ID;
		password=dlgg.password;
		if(password!="")
		{
			AfxMessageBox(L"������������ԣ�");
			return;
		}
	}
	else
		return;
	unsigned i=0;
	for(i=0;i<student.size();i++)
	{
		if(student[i].ID==ID)
		{
			dlg.m_student=student[i];
			break;
		}
		else
			if(i==student.size()-1)
			{
				MessageBox(L"ѧ�Ų����ڣ��������룡");
				return;
			}
	}
	dlg.DoModal();
	student[i]=dlg.m_student;
}


void CManageSystemDlg::OnBnClickedManage()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMLogin dlgg;
	CManagerPart dlg;
	if(dlgg.DoModal()==IDOK)
	{
		password=dlgg.passsword;
		if(password!="")
		{
			AfxMessageBox(L"������������ԣ�");
			return;
		}
		else
			dlg.DoModal();
	}
	else
		return;
}


void CManageSystemDlg::Load(void)
{
	wchar_t buf[100];
	GetCurrentDirectory(sizeof(buf),buf);
	CString Temp=buf;
	//��ʦ��Ϣ
	pathName=Temp+L"\\data\\staff.txt";
	CStdioFile file;
	if (file.Open(pathName, CFile::modeRead))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		while (file.ReadString(strline))
		{	
			TeacherData temp;
			CStringCut(0, strline, str);
			if(str=="#END")
				break;
			if(str[0]=='#')
				continue;
			temp.ID = str;
			CStringCut(1, strline, str);
			temp.Name=str;
			temp.comment=0;
			temp.b_comment=false;
			for(unsigned int i=2;CStringCut(i, strline, str);i++)
				temp.cv.push_back(str);
			teacher.push_back(temp);
		}
	}
	file.Close();

	//�γ���Ϣ
	ifstream ifile;
	pathName=Temp+L"\\data\\module.txt";
	ifile.open(pathName);
	while(1)
	{
		CourseData temp;
		ifile>>str0>>str1>>str2>>str3>>str4;
		temp.CourseID=str0.c_str();
		if(str0=="#END")
			break;
		if(temp.CourseID[0]=='#')
			continue;
		temp.Name=str1.c_str();
		temp.credit=atof(str2.c_str());
		temp.period=atoi(str3.c_str());
		temp.kind=str4.c_str();
		for(unsigned int i=0;i<teacher.size();i++)
		{
			for(unsigned int j=0;j<teacher[i].cv.size();j++)
				if(teacher[i].cv[j]==temp.Name)
				{
					temp.teacher=teacher[i];
					course.push_back(temp);
				}
		}
	}
	ifile.close();
	
	//ѧ����Ϣ
	pathName=Temp+L"\\data\\student.txt";
	if (file.Open(pathName, CFile::modeRead))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		while (file.ReadString(strline))
		{	
			StudentData temp;
			CStringCut(0, strline, str);
			if(str=="#END")
				break;
			if(str[0]=='#')
				continue;
			temp.ID = str;
			CStringCut(1, strline, str);
			temp.Name=str;
			CStringCut(2, strline, str);
			temp.ClassNum=str;
			CStringCut(3, strline, str);
			temp.Specialty=str;
			student.push_back(temp);
		}
	}
	file.Close();
	//�ɼ�����
	pathName=Temp+L"\\data\\score.txt";
	if (file.Open(pathName, CFile::modeRead))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		while (file.ReadString(strline))
		{
			CStringCut(0, strline, str);
			if(str=="#END")
				break;
			if(str[0]=='#')
				continue;
			for(unsigned int i=0;i<student.size();i++)
				if(str==student[i].ID)
				{
					CStringCut(2, strline, str);
					for(unsigned int j=0;j<course.size();j++)
						if(course[j].Name==str)
						{
							GradeData temp(course[j],0);
							CStringCut(3, strline, str);
							temp.grade=_ttof(str);
							temp.test=true;
							if(CStringCut(4, strline, str))
							{
								temp.b_com=true;
								temp.i_com=_ttoi(str);
								if(CStringCut(5, strline, str))
									temp.c_Comment=str;
							}
							else
								temp.b_com=false;

							student[i].gv.push_back(temp);
						}
					
						break;
				}
		}
	}
	file.Close();

}
