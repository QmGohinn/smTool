#include<iostream>
#include<graphics.h>
#include<time.h>

#define _IMAGE_PATH(NAME) \
	"../mine_clear_EX/image/"#NAME

#pragma warning(disable:4996)

using namespace std;

int map[15][15];
int Temp_map[15][15];
int Boom_x[15];
int Boom_y[15];
int Boomnum = 15;
IMAGE image;

void Initmap()
{
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			map[i][j] = 0;

			Temp_map[i][j] = 0;
		}
	}
}
void InitBoom()
{
	int x = 0;
	int y = 0;

	srand((unsigned int)time(NULL));

	for (size_t i = 0; i < 15; i++)
	{
		x = rand() % 15;
		y = rand() % 15;
		if (10 == map[x][y])
		{
			x = rand() % 15;
			y = rand() % 15;
		}
		Boom_x[i] = x;
		Boom_y[i] = y;
		map[x][y] = 10;
	}

	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			if (10 == map[i][j])
			{
				continue;
			}
			if (i != 0 && j != 0 && 10 == map[i - 1][j - 1])
			{
				map[i][j] += 1;
			}
			if (i != 0 && 10 == map[i - 1][j])
			{
				map[i][j] += 1;
			}
			if (j != 0 && 10 == map[i][j - 1])
			{
				map[i][j] += 1;
			}
			if (i < 14 && 10 == map[i + 1][j])
			{
				map[i][j] += 1;
			}
			if (j < 14 && 10 == map[i][j + 1])
			{
				map[i][j] += 1;
			}
			if (i < 14 && j < 14 && 10 == map[i + 1][j + 1])
			{
				map[i][j] += 1;
			}
			if (i != 0 && j < 14 && 10 == map[i - 1][j + 1])
			{
				map[i][j] += 1;
			}
			if (i < 14 && j != 0 && 10 == map[i + 1][j - 1])
			{
				map[i][j] += 1;
			}
		}
	}
}
void Coutmap()
{
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void IniteasyxMap()
{
	loadimage(&image, _IMAGE_PATH(back.png), 600, 600);
	putimage(0, 0, &image);

	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			outtextxy(j * 40 + 11, i * 40 + 11, "*");
		}
	}
}
void MouseEvent()
{
	MOUSEMSG msg = GetMouseMsg();
	setfillcolor(BLACK);
	int L_y = msg.x / 40;
	int L_x = msg.y / 40;

	if (msg.uMsg == WM_LBUTTONDOWN)
	{
		if (map[L_x][L_y] == 9)
		{
			return;
		}

		if (map[L_x][L_y] == 10)
		{
			HWND hwnd = GetHWnd();

			MessageBox(hwnd, "You lose", "Over", 0);

			exit(0);
		}
		else
		{
			if (0 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "0");
				map[L_x][L_y] = 11;
			}
			if (1 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "1");
				map[L_x][L_y] = 11;
			}
			if (2 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "2");
				map[L_x][L_y] = 11;
			}
			if (3 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "3");
				map[L_x][L_y] = 11;
			}
			if (4 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "4");
				map[L_x][L_y] = 11;
			}
			if (5 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "5");
				map[L_x][L_y] = 11;
			}
			if (6 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "6");
				map[L_x][L_y] = 11;
			}
			if (7 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "7");
				map[L_x][L_y] = 11;
			}
			if (8 == map[L_x][L_y])
			{
				fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);
				outtextxy(L_y * 40 + 11, L_x * 40 + 11, "8");
				map[L_x][L_y] = 11;
			}
		}
	}

	if (msg.uMsg == WM_RBUTTONDOWN)
	{
		if (map[L_x][L_y] == 11)
		{
			return;
		}
		if (map[L_x][L_y] == 10) 
		{
			Boomnum -= 1;
		}
		if (map[L_x][L_y] == 9)
		{
			if (Temp_map[L_x][L_y] == 10) 
			{
				Boomnum += 1;
			}
			setfillcolor(RGB(192, 192, 192));

			map[L_x][L_y] = Temp_map[L_x][L_y];

			fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);

			outtextxy(L_y * 40 + 11, L_x * 40 + 11, "*");

			return;
		}

		Temp_map[L_x][L_y] = map[L_x][L_y];

		map[L_x][L_y] = 9;

		fillrectangle(L_y * 40, L_x * 40, (L_y + 1) * 40, (L_x + 1) * 40);

		outtextxy(L_y * 40 + 11, L_x * 40 + 11, "!!!");
	}
}
bool JudgeOver()
{
	for (size_t i = 0; i < 15; i++)
	{
		if (map[Boom_x[i]][Boom_y[i]] == 9)
		{
			Boomnum -= 1;
		}
	}

	if (Boomnum == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	initgraph(600, 600, 0);
	Initmap();
	InitBoom();
	Coutmap();
	IniteasyxMap();

	while (1)
	{
		MouseEvent();

		if (Boomnum == 0) 
		{
			HWND  hwnd = GetHWnd();

			MessageBox(hwnd,"You win","Over",MB_OK);

			return 0;
		}
	}

	system("pause");
	return 0;
}
