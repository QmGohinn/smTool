
// MainModule.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#pragma region includeothers

#include <iostream>
#include <TlHelp32.h>
#pragma endregion

// CMainModuleApp:
// 有关此类的实现，请参阅 MainModule.cpp
//

class CMainModuleApp : public CWinApp
{
public:
	CMainModuleApp();

// 重写
public:
	virtual BOOL InitInstance();

	/*自定义函数声明*/
	void dlg_control(int);
	void _out_log(std::string);

// 实现

	DECLARE_MESSAGE_MAP()
};

int GetProcessCount(const TCHAR*);

extern CMainModuleApp theApp;