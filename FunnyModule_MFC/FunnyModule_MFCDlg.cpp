
// FunnyModule_MFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FunnyModule_MFC.h"
#include "FunnyModule_MFCDlg.h"
#include "afxdialogex.h"

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


// CFunnyModule_MFCDlg 对话框


CFunnyModule_MFCDlg::CFunnyModule_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFunnyModule_MFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunnyModule_MFCDlg::DoDataExchange(CDataExchange* pDX)
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
	_BIND_BUTTON_OBJ(16)

#pragma endregion
}

BEGIN_MESSAGE_MAP(CFunnyModule_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

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
	BIND_BUTTON_FUNC(16)

END_MESSAGE_MAP()

// CFunnyModule_MFCDlg 消息处理程序

BOOL CFunnyModule_MFCDlg::OnInitDialog()
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

<<<<<<< HEAD
	ModifyStyleEx(WS_EX_APPWINDOW,WS_EX_TOOLWINDOW);
=======
	CProgressCtrl* p_procontrol = 
		(CProgressCtrl*)(GetDlgItem(IDC_PROGRESS2));

	p_procontrol->SetPos(20);
>>>>>>> 9c24d21a3cbd87c00047a2fc6f7ebaa017aacc7a

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFunnyModule_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
<<<<<<< HEAD
	if(nID == SC_MOVE || nID == 0xF012)
	{
		return;
	}

=======
>>>>>>> 9c24d21a3cbd87c00047a2fc6f7ebaa017aacc7a
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

void CFunnyModule_MFCDlg::OnPaint()
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
HCURSOR CFunnyModule_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma region :定义事件处理函数(空)

void CFunnyModule_MFCDlg::OnOK()
{
}

BOOL CFunnyModule_MFCDlg::PreTranslateMessage(MSG* pMsg)
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
	BUTTON_CLICKED(16)

#pragma endregion

#pragma region :按钮实际功能定义

void CFunnyModule_MFCDlg::Identify_button(int button_num)
{
	switch (button_num)
	{
	case 1:
		ShellExecute(NULL,"Open","F:/wegame/wegame.exe",NULL,NULL,SW_HIDE);
		break;
	case 2:
		ShellExecute(NULL,"Open","F:/QQGame/QQGame.exe",NULL,NULL,SW_HIDE);
		break;
	case 3:
		ShellExecute(NULL,"Open","F:/steam/steam.exe",NULL,NULL,SW_HIDE);
		break;
	case 4:
		WinExec("taskkill /f /im FunnyModule.exe",SW_HIDE);
		WinExec("MainModule.exe",SW_HIDE);
		break;
	case 6:
		exit(0);
		break;
	case 9:
		ShellExecute(NULL,"Open","https://www.youtube.com/",NULL,NULL,SW_HIDE);
		break;
	case 10:
		ShellExecute(NULL,"Open","www.pornhub.com",NULL,NULL,SW_HIDE);
		break;
	case 16:
		ShellExecute(NULL,"Open","https://fs1.app/",NULL,NULL,SW_HIDE);
		break;
	default:
		break;
	}
}

#pragma endregion