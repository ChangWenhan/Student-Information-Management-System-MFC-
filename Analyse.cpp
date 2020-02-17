// Analyse.cpp : 实现文件
//

#include "stdafx.h"
#include "ManageSystem.h"
#include "Analyse.h"
#include "afxdialogex.h"


// CAnalyse 对话框

IMPLEMENT_DYNAMIC(CAnalyse, CDialogEx)

CAnalyse::CAnalyse(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAnalyse::IDD, pParent)
	, CourseName(_T(""))
	, ClassNumber(_T(""))
	, ManNumber(0)
	, Average(L"")
{
	max=L"";
	min=L"";
	Standard_dev = L"";
	for(int i=0;i<6;i++)
	{
		iv[i]=0;
		if(i==0)
			sv[i]=L"<60";
		else
			if(i==5)
				sv[i]=L">=100";
			else
				sv[i].Format(_T("%d~%d"),50+i*10,60+i*10);
	}
	color[0]=RGB(255,0,0);
	color[1]=RGB(0,255,0);
	color[2]=RGB(0,0,255);
	color[3]=RGB(255,255,0);
	color[4]=RGB(255,0,255);
	color[5]=RGB(0,255,255);
}

CAnalyse::~CAnalyse()
{
}

void CAnalyse::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, CourseName);
	DDX_Text(pDX, IDC_EDIT3, ClassNumber);
	DDX_Text(pDX, IDC_EDIT2, ManNumber);
	DDX_Text(pDX, IDC_EDIT4, max);
	DDX_Text(pDX, IDC_EDIT5, min);
	DDX_Text(pDX, IDC_EDIT6, Average);
	//  DDX_Control(pDX, IDC_EDIT7, Standrad_dev);
	DDX_Text(pDX, IDC_EDIT7, Standard_dev);
}


BEGIN_MESSAGE_MAP(CAnalyse, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CAnalyse 消息处理程序


void CAnalyse::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	const int length=10;
	const int width=30;
	SetViewportOrgEx(dc, 350, 340, NULL);

	//绘制坐标系
	dc.MoveTo(0,0);
	dc.LineTo(0,-320);
	dc.LineTo(-5,-310);
	dc.MoveTo(0,-320);
	dc.LineTo(5,-310);
	dc.TextOutW(0,-340,L"人数");
	for(int i=0;i<=6;i++)
	{
		CString str;
		str.Format(_T("%d"),5*i);
		dc.MoveTo(0,-i*50);
		dc.LineTo(15,-i*50);
		dc.TextOutW(-20,-i*50,str);
	}
	dc.MoveTo(0,0);
	dc.LineTo(420,0);
	dc.LineTo(410,-5);
	dc.MoveTo(420,0);
	dc.LineTo(410,5);
	dc.TextOutW(420,0,L"成绩");

	//绘制条形图
	for(int i=1;i<=6;i++)
	{
		CBrush brush(color[i-1]);
		CRect rect((2*i-1)*width,-iv[i-1]*length,2*i*width,0);
		CBrush* oldBrush=dc.SelectObject(&brush);
		dc.Rectangle(rect);
		dc.SelectObject(oldBrush);
		dc.TextOutW((2*i-1)*width,5,sv[i-1]);
	}

	// 不为绘图消息调用 CDialogEx::OnPaint()
}
