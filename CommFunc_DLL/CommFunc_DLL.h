
#pragma once
#include "pch.h"
#include <fstream>

#ifdef _WINDLL
#define DLLAPI __declspec(dllexport)

#else	// !DLLEXPOERS
#define DLLAPI __declspec(dllimport)

#endif // DLLEXPORTS

#pragma warning(disable : 4067)

#ifndef UINT
#define UINT unsigned int
#endif	// !UINT

#ifndef INT
#define INT int
#endif	// !INT

#ifndef VOID
#define VOID void
#endif	// !VOID

#ifndef STRING
#define STRING string
#endif // !STRING

#ifndef CHAR
#define CHAR char			
#endif	// !CHAR

#ifndef UCHAR
#define UCHAR unsigned char
#endif	// !UCHAR

#ifndef NAMESPACE
#define NAMESPACE namespace
#endif	// !NAMESPACE

#ifndef SPACE
#define SPACE NAMESPACE
#endif	// !SPACE

#ifndef BOOL
#define BOOL INT
#endif // !BOOL

#define __STD(NAME)						\
	using std::##NAME

#ifndef _DEF_STRUCT
#define _DEF_STRUCT typedef struct
#endif // !_DEF_STRUCT

#define DEF_STRUCT(NAME)					\
	_DEF_STRUCT NAME

#define SPLICE_STR(_STRA,_STRB)			\
# _STRA ## #_STRB

#define SPLICE_INT(_INTA,_INTB) _INTA##_INTB

#ifndef START_WEB(NAME)
#define START_WEB(NAME) "start "#NAME
#endif // !START_WEB

#ifndef _LOG_PATH
#define _LOG_PATH "..//log//LOG.log"
#endif // !_LOG_PATH

#ifndef _PWD_LOG
#define _PWD_LOG	 "..//log//PwdList.log"
#endif // !_PWD_LOG

#ifndef _INI_PATH
#define _INI_PATH "..//ini//CommSet.ini"
#endif // !_INI_PATH

#ifndef STATIC
#define STATIC static
#endif // !STATIC

// ****** ▼▼▼▼▼▼ LS - FuncDll ▼▼▼▼▼▼ ****** //
SPACE FUNC_DLL
{
	__STD(cin);__STD(cout);__STD(endl);__STD(string);

// *** ▼▼▼ LS - MathLib ▼▼▼ *** //
	SPACE MATH_LIB
	{
		DEF_STRUCT(Complex)
		{
			INT m_real;
			INT m_virtual;
		}Complex;

		DLLAPI UINT _rand_uint();
		DLLAPI INT _rand_int();

	};		
// *** ▲▲▲ LE - MathLib ▲▲▲ *** //
// *** ▼▼▼ LS - StrLib ▼▼▼ *** //
	SPACE STR_LIB
	{

	};
// *** ▲▲▲ LE - StrLib ▲▲▲ *** //
// *** ▼▼▼ LS - PwdLib ▼▼▼ *** //
	SPACE PWD_LIB
	{
		DLLAPI VOID _pwd_menu();
		DLLAPI STRING _rand_pwd();
		DLLAPI STRING _encrypt(STRING);
		DLLAPI STRING _decrypt(STRING);
	};
// *** ▲▲▲ LE - PwdLib ▲▲▲ *** //
// *** ▼▼▼ LS - IniLib ▼▼▼ *** //
	SPACE INI_LIB
	{
	};
// *** ▲▲▲ LE - IniLib ▲▲▲ *** //
};
// ****** ▲▲▲▲▲▲ LE - FuncDll ▲▲▲▲▲▲ ****** //

#ifndef FD_MATH
#define FD_MATH  FUNC_DLL::MATH_LIB
#endif // !FD_MATH

#ifndef FD_STR 
#define FD_STR	FUNC_DLL::STR_LIB
#endif // !FD_STR 

#ifndef FD_PWD
#define FD_PWD	FUNC_DLL::PWD_LIB
#endif // !FD_PWD

#ifndef FD_INT
#define FD_INI FUNC_DLL::INI_LIB
#endif // !FD_INT
