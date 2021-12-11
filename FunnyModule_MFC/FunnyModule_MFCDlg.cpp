
// FunnyModule_MFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FunnyModule_MFC.h"
#include "FunnyModule_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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


// CFunnyModule_MFCDlg �Ի���


CFunnyModule_MFCDlg::CFunnyModule_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFunnyModule_MFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunnyModule_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

#pragma region �ؼ��Ͷ����

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

// CFunnyModule_MFCDlg ��Ϣ�������

BOOL CFunnyModule_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	CProgressCtrl* p_procontrol = 
		(CProgressCtrl*)(GetDlgItem(IDC_PROGRESS2));

	p_procontrol->SetPos(20);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFunnyModule_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFunnyModule_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFunnyModule_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

#pragma region :�����¼�������(��)

void CFunnyModule_MFCDlg::OnOK()
{
}

BOOL CFunnyModule_MFCDlg::PreTranslateMessage(MSG* pMsg)
{        
	return false;
}

#pragma endregion

#pragma region :���尴ť��������

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

#pragma region :��ťʵ�ʹ��ܶ���

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