
// ManageSystem.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "ManageSystemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

GradeData::GradeData(CourseData c,double g)
{
	course=c;
	grade=g;
	test=false;
}
bool StudentData::IsSame(CString ssname)
{
	int find_result=0;
	for(int j=0;j<ssname.GetLength();j++)
	{
		find_result=find_result<Name.Find(ssname[j])?find_result:Name.Find(ssname[j]);
	}
	if(find_result==-1)
		return false;
	else
		return true;

}
bool CourseData::IsSame(CString ssname)
{
	int find_result=0;
	for(int j=0;j<ssname.GetLength();j++)
	{
		find_result=find_result<Name.Find(ssname[j])?find_result:Name.Find(ssname[j]);
	}
	if(find_result==-1)
		return false;
	else
		return true;

}
vector<CourseData> course;
vector<StudentData> student;
vector<TeacherData> teacher;
CString classnumber[25]={L"123081",L"123082",L"123091",L"123092",L"192081",L"193092",L"193102"};
// CManageSystemApp

BEGIN_MESSAGE_MAP(CManageSystemApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CManageSystemApp ����

CManageSystemApp::CManageSystemApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CManageSystemApp ����

CManageSystemApp theApp;


// CManageSystemApp ��ʼ��

BOOL CManageSystemApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CManageSystemDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

bool CStringCut(unsigned int i,CString strline,CString &str)
{
	vector<CString> strv;
	CString temp=_T("");
	bool b=true;
	for(int j=0;j<=strline.GetLength();j++)
	{
		if(strline[j]!=' '&&strline[j]!='\t'&&j<strline.GetLength())
		{
			temp+=strline[j];
			b=true;
		}
		else
		{
			if(b)
			{
				strv.push_back(temp);
				temp=L"";
				b=false;
			}
			continue;
		}
	}
	if(i<strv.size())
	{
		str=strv[i];
		return true;
	}
	else
		return false;
}