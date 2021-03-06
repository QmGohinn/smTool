
// MainModuleDlg.cpp : 实现文件
//

#include "stdafx.h"

#include "afxdialogex.h"
#include <shellapi.h>

#include "MainModule.h"
#include "MainModuleDlg.h"

#include "../CommFunc_DLL/CommFunc_DLL.h"		//动态库头文件

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


// CMainModuleDlg 对话框


CMainModuleDlg::CMainModuleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainModuleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMainModuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

#pragma region 控件和对象绑定

	_BIND_BUTTON_OBJ(1)
	_BIND_BUTTON_OBJ(2)
	_BIND_BUTTON_OBJ(3)
	_BIND_BUTTON_OBJ(4)
	_BIND_BUTTON_OBJ(5)
	_BIND_BUTTON_OBJ(6)
	_BIND_BUTTON_OBJ(7)
	_BIND_BUTTON_OBJ(8)
	_BIND_BUTTON_OBJ(9)
	_BIND_BUTTON_OBJ(10)
	_BIND_BUTTON_OBJ(11)
	_BIND_BUTTON_OBJ(12)
	_BIND_BUTTON_OBJ(13)
	_BIND_BUTTON_OBJ(14)
	_BIND_BUTTON_OBJ(15)
	_BIND_BUTTON_OBJ(16)
	_BIND_BUTTON_OBJ(17)
	_BIND_BUTTON_OBJ(18)
	_BIND_BUTTON_OBJ(19)
	_BIND_BUTTON_OBJ(20)
	_BIND_BUTTON_OBJ(21)
	_BIND_BUTTON_OBJ(22)

#pragma endregion

}

BEGIN_MESSAGE_MAP(CMainModuleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

#pragma region 控件和函数绑定

	BIND_BUTTON_FUNC(1)
	BIND_BUTTON_FUNC(2)
	BIND_BUTTON_FUNC(3)
	BIND_BUTTON_FUNC(4)
	BIND_BUTTON_FUNC(5)
	BIND_BUTTON_FUNC(6)
	BIND_BUTTON_FUNC(7)
	BIND_BUTTON_FUNC(8)
	BIND_BUTTON_FUNC(9)
	BIND_BUTTON_FUNC(10)
	BIND_BUTTON_FUNC(11)
	BIND_BUTTON_FUNC(12)
	BIND_BUTTON_FUNC(13)
	BIND_BUTTON_FUNC(14)
	BIND_BUTTON_FUNC(15)
	BIND_BUTTON_FUNC(16)
	BIND_BUTTON_FUNC(17)
	BIND_BUTTON_FUNC(18)
	BIND_BUTTON_FUNC(19)
	BIND_BUTTON_FUNC(20)
	BIND_BUTTON_FUNC(21)
	BIND_BUTTON_FUNC(22)

#pragma endregion

END_MESSAGE_MAP()


// CMainModuleDlg 消息处理程序

BOOL CMainModuleDlg::OnInitDialog()
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

	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMainModuleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if(nID == SC_MOVE || nID == 0xF012)
	{
		return;
	}

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

void CMainModuleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, 
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();		//设置背景图片需要将此注释

#pragma region :设置背景图片

		//CPaintDC dc(this);  
		//CRect rect;  
		//GetClientRect(&rect);  
		//CDC dcMem;  
		//dcMem.CreateCompatibleDC(&dc);  
		//CBitmap bmpBackground;  
		//bmpBackground.LoadBitmap(IDB_BITMAP1);   
		////IDB_Bg为刚刚载入的图片对应的ID

		//BITMAP bitmap;  
		//bmpBackground.GetBitmap(&bitmap);  
		//CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);  
		//dc.StretchBlt(100,20,605,330,&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  

#pragma endregion

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMainModuleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma region :按钮实际功能定义

void CMainModuleDlg::Identify_button(int button_num)
{
	CString edit1_txt;
	CString edit2_txt;

	char url[100];
	memset(url,0x00,sizeof(url));

	switch (button_num)
	{
	case 1:
		(GetDlgItem(IDC_EDIT1))->GetWindowTextA(edit1_txt);

		sprintf_s(url,"%s",edit1_txt.GetString());

		if(strlen(url) > 6)
		{
			ShellExecute(NULL,"Open",url,NULL,NULL,SW_HIDE);
		}
		else
		{
			if(!GetProcessCount("cmd.exe"))
			{
				system("start ");
			}
		}
		break;
	case 2:
		ShellExecute(NULL,"Open","https://jwc.xust.edu.cn/",NULL,NULL,SW_HIDE);
		break;
	case 3:
		if(!GetProcessCount("ButtonS_MFC.exe"))
		{
			WinExec("ButtonS_MFC.exe",SW_HIDE);
		}
		else
		{
			MessageBoxA("Running...","Error",0);
		}
		break;
	case 4:
		ShellExecute(NULL,"Open","https://www.xust.edu.cn/",NULL,NULL,SW_HIDE);
		break;
	case 5:
		ShellExecute(NULL,"Open","https://tools.kalvinbg.cn/",NULL,NULL,SW_HIDE);
		break;
	case 6:
		ShellExecute(NULL,"Open","https://www.chazidian.com/",NULL,NULL,SW_HIDE);
		break;
	case 7:
		ShellExecute(NULL,"Open","https://www.bilibili.com/",NULL,NULL,SW_HIDE);
		break;
	case 8:
		ShellExecute(NULL,"Open","https://www.csdn.net/",NULL,NULL,SW_HIDE);
		break;
	case 9:
		ShellExecute(NULL,"Open","https://www.baidu.com/",NULL,NULL,SW_HIDE);
		break;
	case 10:
		ShellExecute(NULL,"Open","https://translate.google.cn",NULL,NULL,SW_HIDE);
		break;
	case 11:
		ShellExecute(NULL,"Open","https://www.neusoft.com/cn/",NULL,NULL,SW_HIDE);
		break;
	case 12:
		ShellExecute(NULL,"Open","https://github.com/",NULL,NULL,SW_HIDE);
		break;
	case 13:
		(GetDlgItem(IDC_EDIT1))->GetWindowTextA(edit1_txt);
		(GetDlgItem(IDC_EDIT2))->
			SetWindowTextA(FD_PWD::_encrypt(edit1_txt.GetString()).c_str());
		break;
	case 14:
		(GetDlgItem(IDC_EDIT1))->GetWindowTextA(edit1_txt);
		(GetDlgItem(IDC_EDIT2))->
			SetWindowTextA(FD_PWD::_decrypt(edit1_txt.GetString()).c_str());
		break;
	case 15:
		(GetDlgItem(IDC_EDIT1))->SetWindowTextA("");
		(GetDlgItem(IDC_EDIT2))->SetWindowTextA("");
		break;
	case 16:
		(GetDlgItem(IDC_EDIT2))->SetWindowTextA("");
		(GetDlgItem(IDC_EDIT1))->GetWindowTextA(edit1_txt);
		if(strlen(edit1_txt.GetString()) != 0)
		{
			theApp._out_log(edit1_txt.GetString());
			FD_PWD::_rand_pwd();
			(GetDlgItem(IDC_EDIT2))->SetWindowTextA("SuccessFul ! ");
		}
		else
		{
		}
		break;
	case 17:
		WinExec("FunnyModule.exe",SW_HIDE);
		WinExec("taskkill /f /im MainModule.exe",SW_HIDE);
		break;
	case 18:
		WinExec("oFFiceModule.exe",SW_HIDE);
		WinExec("taskkill /f /im MainModule.exe",SW_HIDE);
		break;
	case 19:
		WinExec("StudyModule.exe",SW_HIDE);
		WinExec("taskkill /f /im MainModule.exe",SW_HIDE);
		break;
	case 20:
		ShellExecute(NULL,"Open","https://www.linshiyouxiang.net/",NULL,NULL,SW_HIDE);
		break;
	case 21:
		exit(0);
		break;
	case 22:
		ShellExecute(NULL,"Open","https://co2.cnki.net/Main.html?dp=xust",NULL,NULL,SW_HIDE);
		break;
	default:
		break;
	}
}

#pragma endregion

#pragma region :定义事件处理函数(空)

void CMainModuleDlg::OnOK()
{
}

BOOL CMainModuleDlg::PreTranslateMessage(MSG* pMsg)
{        
	return false;
}

#pragma endregion

#pragma region :定义按钮触发函数

BUTTON_CLICKED(1)
	BUTTON_CLICKED(2)
	BUTTON_CLICKED(3)
	BUTTON_CLICKED(4)
	BUTTON_CLICKED(5)
	BUTTON_CLICKED(6)
	BUTTON_CLICKED(7)
	BUTTON_CLICKED(8)
	BUTTON_CLICKED(9)
	BUTTON_CLICKED(10)
	BUTTON_CLICKED(11)
	BUTTON_CLICKED(12)
	BUTTON_CLICKED(13)
	BUTTON_CLICKED(14)
	BUTTON_CLICKED(15)
	BUTTON_CLICKED(16)
	BUTTON_CLICKED(17)
	BUTTON_CLICKED(18)
	BUTTON_CLICKED(19)
	BUTTON_CLICKED(20)
	BUTTON_CLICKED(21)
	BUTTON_CLICKED(22)

#pragma endregion