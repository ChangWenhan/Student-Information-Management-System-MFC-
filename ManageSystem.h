
// ManageSystem.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <vector>
using namespace std;


// CManageSystemApp:
// �йش����ʵ�֣������ ManageSystem.cpp
//

class CManageSystemApp : public CWinApp
{
public:
	CManageSystemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

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