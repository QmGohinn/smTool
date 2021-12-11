#include<iostream>
#include<graphics.h>

#define _IMAGE_PATH(NAME) \
	"../gobang_EX/image/"#NAME

#pragma warning(disable:4996)

using namespace std;

int map[16][16];
int num = 1; 
int flag = 256;

void Initgame()
{
	IMAGE image;
	loadimage(&image, _IMAGE_PATH(back.png), 750, 750);
	putimage(0, 0, &image);
}
void Initmap()
{
	for (size_t i = 0; i < 16; i++)
	{
		for (size_t j = 0; j < 16; j++)
		{
			map[i][j] = 0;
		}
	}
}
bool JudgeCOL()
{
	for (size_t j = 0; j < 15; j++)
	{
		for (size_t i = 0; i < 11; i++)
		{
			if (map[i][j] == 1 &&
				map[i + 1][j] == 1 &&
				map[i + 2][j] == 1 &&
				map[i + 3][j] == 1 &&
				map[i + 4][j] == 1)
			{
				return true;
			}
			if (map[i][j] == 2 &&
				map[i + 1][j] == 2 &&
				map[i + 2][j] == 2 &&
				map[i + 3][j] == 2 &&
				map[i + 4][j] == 2)
			{
				return true;
			}
		}
	}
	return false;
}
bool JudgeROW()
{
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (map[i][j] == 1 &&
				map[i][j + 1] == 1 &&
				map[i][j + 2] == 1 &&
				map[i][j + 3] == 1 &&
				map[i][j + 4] == 1)
			{
				return true;
			}
			else if (map[i][j] == 2 &&
				map[i][j + 1] == 2 &&
				map[i][j + 2] == 2 &&
				map[i][j + 3] == 2 &&
				map[i][j + 4] == 2)
			{
				return true;
			}
		}
	}
	return false;
}
bool MouseEvent()
{

	MOUSEMSG msg = GetMouseMsg();

	if (msg.uMsg == WM_LBUTTONDOWN) {

		if (num % 2 == 0)
		{
			setfillcolor(BROWN);

			if (msg.x % 50 <= 10 && msg.y % 50 <= 10)
			{
				if (map[msg.y / 50][msg.x / 50] == 1 || map[msg.y / 50][msg.x / 50] == 2)
				{
					return false;
				}
				map[msg.y / 50][msg.x / 50] = 1;
				num++;
				fillcircle(msg.x - msg.x % 50, msg.y - msg.y % 50, 20);
				return true;
			}
			if (msg.x % 50 <= 10 && msg.y % 50 >= 40)
			{
				if (map[msg.y / 50 + 1][msg.x / 50] == 1 || map[msg.y / 50 + 1][msg.x / 50] == 2)
				{
					return false;
				}
				map[msg.y / 50 + 1][msg.x / 50] = 1;
				num++;
				fillcircle(msg.x - msg.x % 50, (msg.y / 50 + 1) * 50, 20);
				return true;
			}
			if (msg.x % 50 >= 40 && msg.y % 50 <= 10)
			{
				if (map[msg.y / 50][msg.x / 50 + 1] == 1 || map[msg.y / 50][msg.x / 50 + 1] == 2)
				{
					return false;
				}
				map[msg.y / 50][msg.x / 50 + 1] = 1;
				num++;
				fillcircle(50 * (msg.x / 50 + 1), msg.y - msg.y % 50, 20);
				return true;
			}
			if (msg.x % 50 >= 40 && msg.y % 50 >= 40)
			{
				if (map[msg.y / 50 + 1][msg.x / 50 + 1] == 1 || map[msg.y / 50 + 1][msg.x / 50 + 1] == 2)
				{
					return false;
				}
				map[msg.y / 50 + 1][msg.x / 50 + 1] = 1;
				num++;
				fillcircle(50 * (msg.x / 50 + 1), 50 * (msg.y / 50 + 1), 20);
				return true;
			}
		}
		else
		{
			setfillcolor(BLACK);

			if (msg.x % 50 <= 10 && msg.y % 50 <= 10)
			{
				if (map[msg.y / 50][msg.x / 50] == 1 || map[msg.y / 50][msg.x / 50] == 2)
				{
					return false;
				}
				map[msg.y / 50][msg.x / 50] = 2;
				num++;
				fillcircle(msg.x - msg.x % 50, msg.y - msg.y % 50, 20);
				return true;
			}
			if (msg.x % 50 <= 10 && msg.y % 50 >= 40)
			{
				if (map[msg.y / 50 + 1][msg.x / 50] == 1 || map[msg.y / 50 + 1][msg.x / 50] == 2)
				{
					return false;
				}
				map[msg.y / 50 + 1][msg.x / 50] = 2;
				num++;
				fillcircle(msg.x - msg.x % 50, (msg.y / 50 + 1) * 50, 20);
				return true;
			}
			if (msg.x % 50 >= 40 && msg.y % 50 <= 10)
			{
				if (map[msg.y / 50][msg.x / 50 + 1] == 1 || map[msg.y / 50][msg.x / 50 + 1] == 2)
				{
					return false;
				}
				map[msg.y / 50][msg.x / 50 + 1] = 2;
				num++;
				fillcircle(50 * (msg.x / 50 + 1), msg.y - msg.y % 50, 20);
				return true;
			}
			if (msg.x % 50 >= 40 && msg.y % 50 >= 40)
			{
				if (map[msg.y / 50 + 1][msg.x / 50 + 1] == 1 || map[msg.y / 50 + 1][msg.x / 50 + 1] == 2)
				{
					return false;
				}
				map[msg.y / 50 + 1][msg.x / 50 + 1] = 2;
				num++;
				fillcircle(50 * (msg.x / 50 + 1), 50 * (msg.y / 50 + 1), 20);
				return true;
			}
		}
	}
	return false;
}
bool JudgeSkew()
{
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			if (i <= 11 &&
				j <= 11 &&
				map[i][j] == 1 &&
				map[i + 1][j + 1] == 1 &&
				map[i + 2][j + 2] == 1 &&
				map[i + 3][j + 3] == 1 &&
				map[i + 4][j + 4] == 1)
			{
				return true;
			}
			else if (
				i <= 11 &&
				j <= 11 &&
				map[i][j] == 2 &&
				map[i + 1][j + 1] == 2 &&
				map[i + 2][j + 2] == 2 &&
				map[i + 3][j + 3] == 2 &&
				map[i + 4][j + 4] == 2)
			{
				return true;
			}
			else if (i <= 11 &&
				j >= 4 &&
				map[i][j] == 2 &&
				map[i + 1][j - 1] == 2 &&
				map[i + 2][j - 2] == 2 &&
				map[i + 3][j - 3] == 2 &&
				map[i + 4][j - 4] == 2)
			{
				return true;
			}
			else if (i <= 11 &&
				j >= 4 &&
				map[i][j] == 1 &&
				map[i + 1][j - 1] == 1 &&
				map[i + 2][j - 2] == 1 &&
				map[i + 3][j - 3] == 1 &&
				map[i + 4][j - 4] == 1)
			{
				return true;
			}
		}
	}
	return false;
}
bool Judgemap()
{
	if (0 == flag)
	{
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, "No winner Appear", "Over", MB_OK);
		cout << "流局" << endl;
		return true;
	}
	return false;
}
int Game()
{
	while (1)
	{
		if (true == MouseEvent())
		{
			flag -= 1;
		}
		if (true == Judgemap())
		{
			return 0;
		}
		if (JudgeCOL() || JudgeROW() || JudgeSkew())
		{
			cout << "游戏结束" << endl;
			if (num % 2 == 0)
			{
				HWND Hwnd = GetHWnd();
				MessageBoxA(Hwnd, "Black Has Won", "Over", MB_OK);
				cout << "黑棋胜利" << endl;
			}
			else
			{
				HWND Hwnd = GetHWnd();
				MessageBoxA(Hwnd, "White Has Won", "Over", MB_OK);
				cout << "白棋胜利" << endl;
			}
			return 0;
		}
	}
}

int main()
{
	initgraph(750, 750, 0);
	Initmap();
	Initgame();	
	Game();

	system("pause");
	return 0;
}
