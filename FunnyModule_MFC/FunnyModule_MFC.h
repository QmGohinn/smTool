
// FunnyModule_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#pragma region includeothers

#include <iostream>

#pragma endregion

// CFunnyModule_MFCApp:
// �йش����ʵ�֣������ FunnyModule_MFC.cpp
//

class CFunnyModule_MFCApp : public CWinApp
{
public:
	CFunnyModule_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

	void dlg_control(int);

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFunnyModule_MFCApp theApp;