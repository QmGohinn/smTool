
// MainModule.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "MainModule.h"
#include "MainModuleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainModuleApp

BEGIN_MESSAGE_MAP(CMainModuleApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMainModuleApp 构造

CMainModuleApp::CMainModuleApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMainModuleApp 对象

CMainModuleApp theApp;


// CMainModuleApp 初始化

BOOL CMainModuleApp::InitInstance()
{

	int iNum = 0;

#pragma region 确保程序运行一次

	HANDLE hMutex = ::CreateMutex(NULL,FALSE,"smTool");

	if(GetProcessCount("MainModule.exe") > 1 
		|| GetProcessCount("OfficeModule.exe") > 1
		|| GetProcessCount("StudyModule.exe") > 1
		|| GetProcessCount("FunnyModule.exe") > 1
		)
	{
		MessageBoxA(0,"程序运行中...","错误!",0);
		return FALSE;
	}
	else
	{
	}

#pragma endregion

	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。]

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

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("MainModule"));

	CMainModuleDlg dlg;
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
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "warning\n");
		TRACE(traceAppMsg, 0, "warning\n");
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

/*回调函数*/
void CMainModuleApp::dlg_control(int button_num)
{
	((CMainModuleDlg*)m_pMainWnd)->Identify_button(button_num);
}

/*输出日志函数*/
void CMainModuleApp::_out_log(std::string log)
{
	FILE* fp(NULL);
	if(!fopen_s(&fp,"..//log//PwdList.log","a"))
	{
		fprintf(fp,log.c_str());
	}
	else
	{
	}

	fclose(fp);
	return;
}

#pragma region :检测exe文件是否运行中

int GetProcessCount(const TCHAR* szExeName)
{ 
	TCHAR sztarget[MAX_PATH]; 
	lstrcpy(sztarget, szExeName); 
	CharLowerBuff(sztarget, MAX_PATH); 
	int count = 0; 
	PROCESSENTRY32 my; 
	HANDLE l = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); 
	if (((int)l) != -1)  
	{  
		my.dwSize = sizeof(my);   
		if (Process32First(l, &my))    
		{     
			do      
			{       
				CharLowerBuff(my.szExeFile, MAX_PATH);       
				if (lstrcmp(sztarget, my.szExeFile) == 0)        
				{
					count++;       
				}      
			}while (Process32Next(l, &my));   
		}  
		CloseHandle(l); 
	} 
	return count;
}

#pragma endregion

