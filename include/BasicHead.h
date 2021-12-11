/*

	Head File	:	BasicHead.h

	Author		:	wubin
	
	Date			:	2021/10/23

*/

#ifndef _BASICHEAD
#define _BASICHEAD

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <ctime>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <shellapi.h>
#include <time.h>

#ifdef _DEMO

using namespace std;

#else

using std::cout;
using std::cin;
using std::endl;
using std::string;

#endif // _DEMO

// CS - Person
class Person
{
public:
	int GetAge()
	{
		return m_iAge;
	}
	
protected:

private:
	int m_iAge;
	string m_sName;
	string m_sLocal;
};
// CE - Person




#endif // !_BASICHEAD
