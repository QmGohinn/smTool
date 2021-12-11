#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<windows.h>

#define Interval 100

#define _IMAGE_PATH(NAME) \
	"../pushbox_EX/image/"#NAME

#pragma warning(disable:4244)

using namespace std;

int map[3][8][8] =
{
	{
		{0,0,1,1,1,0,0,0},
		{0,0,1,4,1,0,0,0},
		{0,0,1,0,1,0,0,0},
		{0,1,1,3,1,1,1,1},
		{0,1,4,3,0,3,4,1},
		{0,1,1,1,3,1,1,1},
		{0,0,0,1,4,1,0,0},
		{0,0,0,1,1,1,0,0}
	},
	{
		{ 1,1,1,1,1,1,1,1.},
		{ 1,0,4,0,0,0,0,1.},
		{ 1,0,3,0,0,0,0,1.},
		{ 1,0,3,0,0,0,4,1.},
		{ 1,0,0,0,0,0,0,1.},
		{ 1,0,0,0,3,0,0,1.},
		{ 1,4,0,3,0,0,4,1.},
		{ 1,1,1,1,1,1,1,1.},
	},
	{
		{ 0,0,0,0,0,0,0,0.},
		{ 0,1,1,1,1,1,1,0.},
		{ 0,1,4,1,1,1,1,0.},
		{ 0,1,0,0,3,0,1,0.},
		{ 0,1,0,1,0,0,1,0.},
		{ 0,1,0,0,0,0,1,0.},
		{ 0,1,1,1,1,1,1,0.},
		{ 0,0,0,0,0,0,0,0.},
		}
};
int Pmap[3][8][8];
IMAGE image[6];
int x = 4, y = 4, num = 0, n = 0, choose = 0;

void Menu()
{
	cout << "恭喜你，通过了本关卡" << endl;
	cout << "请输入您的选择" << endl;
	cout << "1.开始下一关" << endl;
	cout << "2.退出游戏" << endl;
	cout << "3.重玩本关卡" << endl;
}
void Setimage()
{
	loadimage(&image[0], _IMAGE_PATH(nbsp.png), 100, 100);
	loadimage(&image[1], _IMAGE_PATH(wall.png), 100, 100);
	loadimage(&image[2], _IMAGE_PATH(user.png), 100, 100);
	loadimage(&image[3], _IMAGE_PATH(boxs.png), 100, 100);
	loadimage(&image[4], _IMAGE_PATH(goal.png), 100, 100);
	loadimage(&image[5], _IMAGE_PATH(wins.png), 100, 100);
}
void GetsourceMap()
{
	for (size_t i = 0; i < 3; i++)
	{

		for (size_t j = 0; j < 8; j++)
		{
			for (size_t k = 0; k < 8; k++)
			{
				Pmap[i][j][k] = map[i][j][k];
			}
		}
	}
}
void Drawmap()
{
	map[n][x][y] = 2;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (map[n][i][j])
			{
			case 0:					//空白
				cout << setw(2) << " ";
				break;
			case 1:					//墙壁
				cout << setw(2) << "*";
				break;
			case 2:					//人物
				cout << setw(2) << "O";
				break;
			case 3:					//箱子
				cout << setw(2) << "?";
				break;
			case 4:					//目的地
				cout << setw(2) << "&";
				break;
			case 5:
				cout << setw(2) << "!";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}
void Draweasyxmap()
{
	map[n][x][y] = 2;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (map[n][i][j])
			{
			case 0:					//空白
				putimage(j * Interval, i * Interval, &image[0]);
				break;
			case 1:					//墙壁
				putimage(j * Interval, i * Interval, &image[1]);
				break;
			case 2:					//人物
				putimage(j * Interval, i * Interval, &image[2]);
				break;
			case 3:					//箱子
				putimage(j * Interval, i * Interval, &image[3]);
				break;
			case 4:					//目的地
				putimage(j * Interval, i * Interval, &image[4]);
				break;
			case 5:
				putimage(j * Interval, i * Interval, &image[5]);
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}
void GetControl()
{
	switch (_getch())
	{
	case 75:
	case 'a':
		if (map[n][x][y - 1] == 1 || map[n][x][y - 1] == 5 || (map[n][x][y - 1] == 3 && map[n][x][y - 2] == 1) || (map[n][x][y - 1] == 3 && map[n][x][y - 2] == 3))
		{
			break;
		}
		else if (map[n][x][y - 1] == 3 && map[n][x][y - 2] != 4)
		{
			map[n][x][y] = 0;
			map[n][x][y - 2] = map[n][x][y - 1];
			y -= 1;
		}
		else if (map[n][x][y - 1] == 0)
		{
			map[n][x][y] = 0;
			y -= 1;
		}
		else if (map[n][x][y - 1] == 3 && map[n][x][y - 2] == 4)
		{
			map[n][x][y] = 0;
			map[n][x][y - 2] = 5;
			num -= 1;
			y -= 1;
		}
		break;

	case 80:
	case 's':
		if (map[n][x + 1][y] == 1 || map[n][x + 1][y] == 5 || (map[n][x + 1][y] == 3 && map[n][x + 2][y] == 1) || (map[n][x + 1][y] == 3 && map[n][x + 2][y] == 3))
		{
			break;
		}
		else if (map[n][x + 1][y] == 3 && map[n][x + 2][y] != 4)
		{
			map[n][x][y] = 0;
			map[n][x + 2][y] = map[n][x + 1][y];
			x += 1;
		}
		else if (map[n][x + 1][y] == 0)
		{
			map[n][x][y] = 0;
			x += 1;
		}
		else if (map[n][x + 1][y] == 3 && map[n][x + 2][y] == 4)
		{
			map[n][x][y] = 0;
			map[n][x + 2][y] = 5;
			num -= 1;
			x += 1;
		}
		break;

	case 77:
	case 'd':
		if (map[n][x][y + 1] == 1 || map[n][x][y + 1] == 5 || (map[n][x][y + 1] == 3 && map[n][x][y + 2] == 1) || (map[n][x][y + 1] == 3 && map[n][x][y + 2] == 3))
		{
			break;
		}
		else if (map[n][x][y + 1] == 3 && map[n][x][y + 2] != 4)
		{
			map[n][x][y] = 0;
			map[n][x][y + 2] = map[n][x][y + 1];
			y = y + 1;
		}
		else if (map[n][x][y + 1] == 0)
		{
			map[n][x][y] = 0;
			y = y + 1;
		}
		else if (map[n][x][y + 1] == 3 && map[n][x][y + 2] == 4)
		{
			map[n][x][y] = 0;
			map[n][x][y + 2] = 5;
			num -= 1;
			y = y + 1;
		}
		break;

	case 72:
	case 'w':
		if (map[n][x - 1][y] == 1 || map[n][x - 1][y] == 5 || (map[n][x - 1][y] == 3 && map[n][x - 2][y] == 1) || (map[n][x - 1][y] == 3 && map[n][x - 2][y] == 3))
		{
			break;
		}
		else if (map[n][x - 1][y] == 3 && map[n][x - 2][y] != 4)
		{
			map[n][x][y] = 0;
			map[n][x - 2][y] = map[n][x - 1][y];
			x -= 1;
		}
		else if (map[n][x - 1][y] == 0)
		{
			map[n][x][y] = 0;
			x -= 1;
		}
		else if (map[n][x - 1][y] == 3 && map[n][x - 2][y] == 4)
		{
			map[n][x][y] = 0;
			map[n][x - 2][y] = 5;
			num -= 1;
			x -= 1;
		}
		break;

	default:
		break;
	}
}
void Getnum()
{
	num = 0;

	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			if (map[n][i][j] == 3)
			{
				num += 1;
			}
		}
	}
}
void GamePlay()
{
	Getnum();

	while (num)
	{
		Draweasyxmap(); Drawmap();
		GetControl();
		system("cls");
	};
	Draweasyxmap();
}

int main()
{
	Setimage();
	initgraph(800, 800, 0);
	GetsourceMap();
	GamePlay();
	while (1)
	{
		cin >> choose;
		system("cls");

		switch (choose)
		{
		case 1:
			n += 1; x = 4; y = 4;
			if (n == 3)
			{
				cout << "您已经通过了所有关卡" << endl;
				exit(0);
			}
			GamePlay();
			break;
		case 2:
			exit(0);
		case 3:
			x = 4; y = 4;
			for (size_t i = 0; i < 8; i++)
			{
				for (size_t j = 0; j < 8; j++)
				{
					map[n][i][j] = Pmap[n][i][j];
				}
			}
			GamePlay();
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
