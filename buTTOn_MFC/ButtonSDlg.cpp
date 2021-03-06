
// ButtonSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ButtonS.h"
#include "ButtonSDlg.h"

#include <afxdialogex.h>
#include <set>

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

// CButtonSDlg 对话框

CButtonSDlg::CButtonSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CButtonSDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

#pragma region 对象控件绑定

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

#pragma endregion

	srand((unsigned int)time(NULL));
}

BEGIN_MESSAGE_MAP(CButtonSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

#pragma region 函数控件绑定

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

#pragma endregion

END_MESSAGE_MAP()


// CButtonSDlg 消息处理程序

BOOL CButtonSDlg::OnInitDialog()
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

	set_default();
	srand((unsigned int)time(NULL));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CButtonSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CButtonSDlg::OnPaint()
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
		//CDialogEx::OnPaint();

#pragma region 更改背景图片

		CPaintDC dc(this);  
		CRect rect;  
		GetClientRect(&rect);  
		CDC dcMem;  
		dcMem.CreateCompatibleDC(&dc);  
		CBitmap bmpBackground;  
		bmpBackground.LoadBitmap(IDB_BITMAP1);   
		//IDB_Bg为刚刚载入的图片对应的ID

		BITMAP bitmap;  
		bmpBackground.GetBitmap(&bitmap);  
		CBitmap *pbmpOld=dcMem.SelectObject(&bmpBackground);  
		dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  

#pragma endregion

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CButtonSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma region 按钮实际功能定义

void CButtonSDlg::Identify_button(int button_num)
{
	if(button_num > 10)
	{
		switch (button_num)
		{
		case 11:
			for(UINT i = 0; i < 10; i++)
			{
				this->m_button[i].ShowWindow(SW_SHOW);
				this->m_button[++i].ShowWindow(SW_HIDE);
			}
			this->m_button[10].EnableWindow(OFF);
			this->m_button[12].EnableWindow(ON);
			break;
		case 12:
			set_default();
			break;
		case 13:
			for(UINT i = 1; i < 10; i++)
			{
				this->m_button[i - 1].ShowWindow(SW_HIDE);
				this->m_button[i++].ShowWindow(SW_SHOW);
			}
			this->m_button[10].EnableWindow(ON);
			this->m_button[12].EnableWindow(OFF);
			break;
		case 14:
			exit(0);
		default:
			break;
		}
	}
	else if(1 <= button_num && button_num <= 10)
	{
		button_opposite(button_num);
		rand_on_off(button_num);
	}
	else
	{
		return;
	}
}

#pragma endregion

#pragma region 按钮默认布局

void CButtonSDlg::set_default()
{
	this->m_button[0].ShowWindow(SW_SHOW);
	this->m_button[3].ShowWindow(SW_SHOW);
	this->m_button[5].ShowWindow(SW_SHOW);
	this->m_button[7].ShowWindow(SW_SHOW);
	this->m_button[9].ShowWindow(SW_SHOW);

	this->m_button[1].ShowWindow(SW_HIDE);
	this->m_button[2].ShowWindow(SW_HIDE);
	this->m_button[4].ShowWindow(SW_HIDE);
	this->m_button[6].ShowWindow(SW_HIDE);
	this->m_button[8].ShowWindow(SW_HIDE);

	this->m_button[10].EnableWindow(ON);
	this->m_button[12].EnableWindow(ON);
}

#pragma endregion

#pragma region 按钮布局相关函数

void CButtonSDlg::rand_on_off(int button_num)
{
	if(button_num > 0)
	{
		std::set<int> ON_NUM;
		if(ON == is_on_off(button_num))
		{
			ON_NUM.insert(1);ON_NUM.insert(3);
			ON_NUM.insert(5);ON_NUM.insert(7);
			ON_NUM.insert(9);
		}
		else
		{
			ON_NUM.insert(2);ON_NUM.insert(4);
			ON_NUM.insert(6);ON_NUM.insert(8);
			ON_NUM.insert(10);ON_NUM.erase(button_num);
		}
		ON_NUM.erase(button_num);

		for(std::set<int>::iterator i = ON_NUM.begin(); i != ON_NUM.end(); i++)
		{
			button_rand(*i);
		}
	}
}

bool CButtonSDlg::is_on_off(int button_num)
{
	return button_num % 2 ? ON : OFF;
}

void CButtonSDlg::button_opposite(int button_num)
{
	if(OFF == is_on_off(button_num))
	{
		this->m_button[button_num - 2].ShowWindow(SW_SHOW);
		this->m_button[12].EnableWindow(ON);
	}
	else
	{
		this->m_button[button_num].ShowWindow(SW_SHOW);
		this->m_button[10].EnableWindow(ON);
	}
	this->m_button[button_num - 1].ShowWindow(SW_HIDE);
}

void CButtonSDlg::button_rand(int button_num)
{
	if(button_num > 0)
	{
		if(ON == is_on_off(button_num))
		{
			int num = rand() % 2;
			if(OFF_NUM == num)
			{
				this->m_button[button_num - 1].ShowWindow(SW_HIDE);
				this->m_button[button_num].ShowWindow(SW_SHOW);
			}
			else
			{
			}
		}
		else
		{
			int num = rand() % 2;
			if(OFF_NUM == num)
			{
				this->m_button[button_num - 1].ShowWindow(SW_HIDE);
				this->m_button[button_num - 2].ShowWindow(SW_SHOW);
			}
			else
			{
			}
		}
	}
}

#pragma endregion

#pragma region 按钮处理函数定义

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

#pragma endregion
