// ManagerPart.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "ManagerPart.h"
#include "afxdialogex.h"
#include "CouAddDlg.h"
#include "StuRegDlg.h"
#include "TeaRegDlg.h"
#include <locale>

// CManagerPart 对话框

IMPLEMENT_DYNAMIC(CManagerPart, CDialogEx)

CManagerPart::CManagerPart(CWnd* pParent /*=NULL*/)
	: CDialogEx(CManagerPart::IDD, pParent)
{

}

CManagerPart::~CManagerPart()
{
}

void CManagerPart::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CManagerPart, CDialogEx)
	ON_BN_CLICKED(IDC_STU_REGISTER, &CManagerPart::OnBnClickedStuRegister)
	ON_BN_CLICKED(IDC_TEA_REGISTER, &CManagerPart::OnBnClickedTeaRegister)
	ON_BN_CLICKED(IDC_COURSE_ADD, &CManagerPart::OnBnClickedCourseAdd)
	ON_BN_CLICKED(IDC_SAVE, &CManagerPart::OnBnClickedSave)
END_MESSAGE_MAP()


// CManagerPart 消息处理程序


void CManagerPart::OnBnClickedStuRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CStuRegDlg dlg;
	dlg.DoModal();
}


void CManagerPart::OnBnClickedTeaRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	CTeaRegDlg dlg;
	dlg.DoModal();
}


void CManagerPart::OnBnClickedCourseAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CCouAddDlg dlg;
	dlg.DoModal();
}


void CManagerPart::OnBnClickedSave()
{
	// TODO: 在此添加控件通知处理程序代码
	wchar_t buf[100];
	GetCurrentDirectory(sizeof(buf),buf);
	CString Temp=buf;


	CString pathName;
	CStdioFile file;
	//教师信息
	pathName=Temp+L"\\data\\staff.txt";
	if (file.Open(pathName, CFile::modeWrite|CFile::modeCreate))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		file.WriteString(L"#工号（ID） 姓名 授课\n");
		for(UINT i=0;i<teacher.size();i++)
		{
			strline=teacher[i].ID+'\t'+teacher[i].Name;
			for(UINT j=0;j<teacher[i].cv.size();j++)
			{
				strline+=('\t'+teacher[i].cv[j]);
			}
			strline+="\n";
			file.WriteString(strline);
		}
		file.WriteString(L"#END");
	}
	file.Close();
	//课程信息
	pathName=Temp+L"\\data\\module.txt";
	if (file.Open(pathName, CFile::modeWrite|CFile::modeCreate))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		file.WriteString(L"#课程编号   课程名称  学分   学时   课程类别 \n");
		for(UINT i=0;i<course.size();i++)
		{
			strline=course[i].CourseID+'\t'+course[i].Name;
			str.Format(_T("%.1lf"),course[i].credit);
			strline+=('\t'+str);
			str.Format(_T("%d"),course[i].period);
			strline+=('\t'+str);
			strline+=('\t'+course[i].kind);
			strline+="\n";
			file.WriteString(strline);
		}
		file.WriteString(L"#END");
	}
	file.Close();

	
	//学生信息
	pathName=Temp+L"\\data\\student.txt";
	if (file.Open(pathName, CFile::modeWrite|CFile::modeCreate))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		file.WriteString(L"#学号(ID)   姓名	班级	专业\n");
		for(UINT i=0;i<student.size();i++)
		{
			strline=student[i].ID+'\t'+student[i].Name+'\t'+student[i].ClassNum+'\t'+student[i].Specialty;
			strline+="\n";
			file.WriteString(strline);
		}
		file.WriteString(L"#END");
	}
	file.Close();


	//成绩数据
	pathName=Temp+L"\\data\\score.txt";
	if (file.Open(pathName, CFile::modeWrite|CFile::modeCreate))
	{
		CString strline,str;
		setlocale(LC_CTYPE, "chs");
		file.WriteString(L"#学号	 姓名	 课程名称	成绩\n");
		for(UINT i=0;i<student.size();i++)
		{
			strline=student[i].ID+'\t'+student[i].Name;
			for(UINT j=0;j<student[i].gv.size();j++)
			{
				CString string=strline;
				string+=('\t'+student[i].gv[j].course.Name);
				str.Format(_T("%.1f"),student[i].gv[j].grade);
				string+=('\t'+str);
				if(student[i].gv[j].b_com)
				{
					str.Format(_T("\t%d\t")+student[i].gv[j].c_Comment,student[i].gv[j].i_com);
					string+=str;
				}
				string+="\n";
				file.WriteString(string);
			}
		}
		file.WriteString(L"#END");
	}
	file.Close();
	MessageBox(L"保存成功！！");

}
