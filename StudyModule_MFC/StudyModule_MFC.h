
// StudyModule_MFC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

#pragma region includeothers

#include <iostream>

#pragma endregion

// CStudyModule_MFCApp:
// �йش����ʵ�֣������ StudyModule_MFC.cpp
//

class CStudyModule_MFCApp : public CWinApp
{
public:
	CStudyModule_MFCApp();

// ��д
public:
	virtual BOOL InitInstance();

	void dlg_control(int);

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CStudyModule_MFCApp theApp;