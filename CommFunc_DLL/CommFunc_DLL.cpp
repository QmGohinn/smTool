
// DLL.cpp : Defines the exported functions for the DLL application.
//

#include "pch.h"
#include "CommFunc_DLL.h"

#include <process.h>

// ****** ▼▼▼▼▼▼ LS - FuncDll ▼▼▼▼▼▼ ****** //
SPACE FUNC_DLL
{
// *** ▼▼▼ LS - MathLib ▼▼▼ *** //
	SPACE MATH_LIB
	{
// FS:_rand_uint	
		DLLAPI UINT _rand_uint()
		{
			INT res = rand();

			do
			{
				res = rand();
			}
			while(res < 0);

			return res;
		}
// FE:_rand_uint
// FS:_rand_int	
		DLLAPI INT _rand_int()
		{
			INT res = rand();
			return res;
		}	
// FE:_rand_int
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
// FS:_pwd_menu
		DLLAPI VOID _pwd_menu()
		{
			cout << "Choose One" << endl;
			cout << "1.encrypt" << endl;
			cout << "2.decrypt" << endl;
			cout << "3.getRandowPWD" << endl;

			string choose = "";
			cin >> choose;

			STRING source;

			if(choose.length() > 1 || choose[0] < '1' || choose[0] > '3')
			{
				return;
			}

			switch(choose[0] - '0')
			{
			case 1:
				cout << "Please Input The Source String" << endl;
				cin >> source;cout << FD_PWD::_encrypt(source) << endl;
				break;
			case 2:
				cout << "Please Input The Cipher String" << endl;
				cin >> source;cout << FD_PWD::_decrypt(source) << endl;
				break;
			case 3:
				cout << "Please Input The Soft Name" << endl;
				FD_PWD::_rand_pwd();
				break;
			default:
				break;
			}
			
		}
// FE:_pwd_menu
// FS:_rand_pwd
		DLLAPI STRING _rand_pwd()
		{
			STRING res,softname;FILE* fp(NULL);
			if(!fopen_s(&fp,_PWD_LOG,"a"))
			{
				INT Length = rand() % 6 + 10;
				cin >> softname;fprintf(fp,"%s : ",softname.data());
				for(INT i = 0; i < Length; i++)
				{
					INT ch = rand() % 93 + 33;
					res += (CHAR)ch;
				}
				fprintf(fp,"%s\n",res.data());
				cout << "Create Successful!" << endl;
				fclose(fp);
				return res;
			}
			else
			{
				return "";
			}
		}
// FE:_rand_pwd
// FS:_encrypt
		DLLAPI STRING _encrypt(STRING _pwd_str)
		{
			STRING res;

			for(UINT i = 0; i < _pwd_str.length(); i++)
			{
				res += _pwd_str[i] + 1;
			}
			return res;
		}
// FE:_encrypt
// FS:_decrypt
		DLLAPI STRING _decrypt(STRING _pwd_str)
		{
			STRING res;

			for(UINT i = 0; i < _pwd_str.length(); i++)
			{
				res += _pwd_str[i] - 1;
			}
			return res;		
		}
// FE:_decrypt
	};
// *** ▲▲▲ LE - PwdLib ▲▲▲ *** //
// *** ▼▼▼ LS - IniLib ▼▼▼ *** //
	SPACE INI_LIB
	{
	};
};
// ****** ▲▲▲▲▲▲ LE - FuncDll ▲▲▲▲▲▲ ****** //
