
// ManageSystem.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include <vector>
using namespace std;


// CManageSystemApp:
// 有关此类的实现，请参阅 ManageSystem.cpp
//

class CManageSystemApp : public CWinApp
{
public:
	CManageSystemApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CManageSystemApp theApp;

class TeacherData
{
public:
	CString ID;
	CString Name;
	vector<CString> cv;
	double comment;
	bool b_comment;
};
class CourseData
{
public:
	CString CourseID;
	CString Name;
	double credit;
	int period;
	CString kind;
	TeacherData teacher;
	int stuNumber;
	bool IsSame(CString);
};
class GradeData
{
public:
	CourseData course;
	double grade;
	bool test;
	int i_com;
	CString c_Comment;
	bool b_com;
	GradeData(CourseData c,double g=0.0);
};
class StudentData
{
public:
	CString ID;
	CString Name;
	CString ClassNum;
	CString Specialty;
	vector<GradeData> gv;
	bool IsSame(CString);
};
extern vector<CourseData> course;
extern vector<StudentData> student;
extern vector<TeacherData> teacher;
extern CString classnumber[25];
bool CStringCut(unsigned int i,CString strline,CString &str);