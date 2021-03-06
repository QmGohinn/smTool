
// LableDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Lable.h"
#include "LableDlg.h"
#include "afxdialogex.h"

#include "../CommFunc_DLL/CommFunc_DLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

#pragma warning(disable : 4018)

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


// CLableDlg 对话框


CLableDlg::CLableDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLableDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLableDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CLableDlg 消息处理程序

BOOL CLableDlg::OnInitDialog()
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


#pragma region 滚动条设置
//
//	SCROLLINFO scrollinfo;
//	GetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
//	scrollinfo.nPage=10; //设置滑块大小
//	scrollinfo.nMax=1000000000; //设置滚动条的最大位置0–100
//	SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
//
#pragma endregion

#pragma region 获取文件内容
//
//	int ini_line = 0;
//	char ini_info[50][100];
//
//	CStatic* static_lable = new CStatic;
//	static_lable->Create("CVSLearnINI-Info",WS_VISIBLE, CRect(0,0,180,20), this,1);
//	//static_lable->SetWindowTextA("CVSLearn-Info");
//
//	memset(ini_info,0x00,5000);
//
//	FILE* fp(NULL);
//	if(!fopen_s(&fp,_INI_PATH,"r+"))
//	{
//		while(fgets(ini_info[ini_line],100,fp))
//		{
//			ini_line += 1;
//		}
//		fclose(fp);
//	}
//
//	for(int i = 0; i < 50; i++)
//	{
//		ini_info[i][strlen(ini_info[i]) - 1] = '\0';
//	}
//
//	//for(int i = 0; i < 100; i++)
//	//{
//	//ini_info[0][i] = ini_info[0][i + 3];
//	//}
//
//	for(int i = 0; i < ini_line; i++)
//	{
//		CEdit* static_lable = new CEdit;
//		static_lable->Create(WS_VISIBLE, CRect(50,50 + i * 40,200,70 + i * 40), this,1);
//		static_lable->SetWindowTextA(ini_info[i]);
//	}
//
#pragma endregion


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLableDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLableDlg::OnPaint()
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
HCURSOR CLableDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma region 滚动条函数

void CLableDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	SCROLLINFO scrollinfo;
	GetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
	int unit=3;        
	switch (nSBCode)  
	{      
	case SB_LINEUP:          //Scroll one line up
		scrollinfo.nPos -= 1;  
		if (scrollinfo.nPos<scrollinfo.nMin)
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,unit); 
		break;  
	case SB_LINEDOWN:           //Scroll one line down
		scrollinfo.nPos += 1;  
		if (scrollinfo.nPos+scrollinfo.nPage>scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,-unit);  
		break;  
	case SB_PAGEUP:            //Scroll one page up.
		scrollinfo.nPos -= 5;  
		if (scrollinfo.nPos<=scrollinfo.nMin)
		{  
			scrollinfo.nPos = scrollinfo.nMin;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,unit*5);  
		break;  
	case SB_PAGEDOWN:        //Scroll one page down        
		scrollinfo.nPos += 5;  
		if (scrollinfo.nPos+scrollinfo.nPage>=scrollinfo.nMax)  //此处一定要注意加上滑块的长度，再作判断
		{  
			scrollinfo.nPos = scrollinfo.nMax;  
			break;  
		}  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);  
		ScrollWindow(0,-unit*5);  
		break;  
	case SB_ENDSCROLL:      //End scroll     
		break;  
	case SB_THUMBPOSITION:  //Scroll to the absolute position. The current position is provided in nPos
		break;  
	case SB_THUMBTRACK:                  //Drag scroll box to specified position. The current position is provided in nPos
		ScrollWindow(0,(scrollinfo.nPos-nPos)*unit);  
		scrollinfo.nPos = nPos;  
		SetScrollInfo(SB_VERT,&scrollinfo,SIF_ALL);
		break;  
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

#pragma endregion

