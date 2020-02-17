
// ManageSystemDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CManageSystemDlg 对话框




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


// CManageSystemDlg 消息处理程序

BOOL CManageSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	Load();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CManageSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CManageSystemDlg::OnBnClickedTeacher()
{
	// TODO: 在此添加控件通知处理程序代码
	CTLogin dlgg;
	CTeacherPartDlg dlg;
	if(dlgg.DoModal()==IDOK)
	{
		ID=dlgg.ID;
		password=dlgg.password;
		if(password!="")
		{
			AfxMessageBox(L"口令错误，请重试！");
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
				MessageBox(L"工号不存在，请检查输入！");
				return;
			}
	}
	dlg.DoModal();
}


void CManageSystemDlg::OnBnClickedStudent()
{
	// TODO: 在此添加控件通知处理程序代码
	CSLogin dlgg;
	CStudentPartDlg dlg;
	if(dlgg.DoModal()==IDOK)
	{
		ID=dlgg.ID;
		password=dlgg.password;
		if(password!="")
		{
			AfxMessageBox(L"口令错误，请重试！");
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
				MessageBox(L"学号不存在，请检查输入！");
				return;
			}
	}
	dlg.DoModal();
	student[i]=dlg.m_student;
}


void CManageSystemDlg::OnBnClickedManage()
{
	// TODO: 在此添加控件通知处理程序代码
	CMLogin dlgg;
	CManagerPart dlg;
	if(dlgg.DoModal()==IDOK)
	{
		password=dlgg.passsword;
		if(password!="")
		{
			AfxMessageBox(L"口令错误，请重试！");
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
	//教师信息
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

	//课程信息
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
	
	//学生信息
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
	//成绩数据
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
