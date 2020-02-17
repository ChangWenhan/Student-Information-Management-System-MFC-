
// ManageSystem.cpp : 定义应用程序的类行为。
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


// CManageSystemApp 构造

CManageSystemApp::CManageSystemApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CManageSystemApp 对象

CManageSystemApp theApp;


// CManageSystemApp 初始化

BOOL CManageSystemApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CManageSystemDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
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