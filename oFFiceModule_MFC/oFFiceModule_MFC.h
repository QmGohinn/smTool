
// oFFiceModule_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#pragma region includeothers

#include <iostream>

#pragma endregion

// CoFFiceModule_MFCApp:
// �йش����ʵ�֣������ oFFiceModule_MFC.cpp
//

class CoFFiceModule_MFCApp : public CWinApp
{
public:
	CoFFiceModule_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

	void dlg_control(int);

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CoFFiceModule_MFCApp theApp;