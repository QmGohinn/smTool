
// StudyModule_MFC.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

#pragma region includeothers

#include <iostream>

#pragma endregion

// CStudyModule_MFCApp:
// 有关此类的实现，请参阅 StudyModule_MFC.cpp
//

class CStudyModule_MFCApp : public CWinApp
{
public:
	CStudyModule_MFCApp();

// 重写
public:
	virtual BOOL InitInstance();

	void dlg_control(int);

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CStudyModule_MFCApp theApp;