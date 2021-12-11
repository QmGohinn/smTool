#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>

#pragma warning(disable : 4018)
#define MAX 100

HWND hwnd = NULL;
int cas = 1;
int cnt = 1;
int Speed = 100;
typedef struct Point
{
	int x;
	int y;
}MYPOINT;
struct mySnake
{
	int num;
	MYPOINT xy[100];
	char postion;
}snake;
struct myFood
{
	MYPOINT fdxy;
	int flag;
	int eatgrade;
}food;
enum movPostion
{
	right = 72,
	left = 75,
	down = 77,
	up = 80
};

void InitSnake();
void drawSnake();
void moveSnake();
void keyDown();
void initfood();
void drawfood();
void eatfood();
int gameover();
void getpause();
void showgrade();

int main()
{
	srand((unsigned int)time(NULL));
	hwnd = initgraph(640, 480, 0);
	setbkcolor(WHITE);
	cleardevice();
	InitSnake();

	while (1)
	{
		cleardevice();
		if (food.flag == 0)
		{
			initfood();
		}
		drawfood();
		drawSnake();
		showgrade();
		if (gameover())
		{
			break;
		}
		eatfood();
		moveSnake();
		while (_kbhit())
		{
			getpause();
			keyDown();
		}
		cas = cnt / 3;
		Sleep(Speed - cas * 10);
	}
	char a = getchar();
	closegraph();
	return 0;
}

void InitSnake()
{
	snake.num = 3;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.postion = right;

	food.flag = 0;

}
void drawSnake()
{
	for (size_t i = 0; i < snake.num; i++)
	{
		setlinecolor(BLUE);
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}
void moveSnake()
{
	for (size_t i = snake.num - 1; i > 0; i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	switch (snake.postion)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	default:
		break;
	}
}
void keyDown()
{
	char ch = '0';
	ch = _getch();
	switch (ch)
	{
	case right:
		if (snake.postion != down)
		{
			snake.postion = up;
		}
		break;
	case left:
		if (snake.postion != right)
		{
			snake.postion = left;
		}
		break;
	case up:
		if (snake.postion != up)
		{
			snake.postion = down;
		}
		break;
	case down:
		if (snake.postion != left)
		{
			snake.postion = right;
		}
		break;
	default:
		break;
	}
}
void initfood()
{
	food.fdxy.x = rand() % 64 * 10;
	food.fdxy.y = rand() % 48 * 10;
	food.flag = 1;
	for (size_t i = 0; i < snake.num; i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 64 * 10;
			food.fdxy.y = rand() % 48 * 10;
		}
	}

}
void drawfood()
{
	setlinecolor(BLACK);
	cleardevice();
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}
void eatfood()
{
	if (food.fdxy.x == snake.xy[0].x && food.fdxy.y == snake.xy[0].y)
	{
		snake.num++;
		food.eatgrade += 50;
		food.flag = 0;
		cnt += 1;
	}
}
int gameover()
{
	if (snake.xy[0].x < 0 || snake.xy[0].y < 0 || snake.xy[0].x > 640 || snake.xy[0].y > 480)
	{
		MessageBox(hwnd, "LOSE", "Over", 0);
		exit(0);
	}

	for (size_t i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			MessageBox(hwnd, "LOSE", "Over", 0);
			exit(0);
		}
	}
	return 0;
}
void getpause()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}
void showgrade()
{
	char grade[100] = { "" };
	char casStr[10] = { "" };
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
}
