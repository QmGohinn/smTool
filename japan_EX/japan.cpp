#include <graphics.h>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
	initgraph(800, 600, 0);

	IMAGE image;

	loadimage(&image, 
		"../japan_EX/japan.png", 
		800, 600);
	putimage(0, 0, &image);

	while(1)
	{
		MOUSEMSG msg = GetMouseMsg();

		if (msg.uMsg == WM_RBUTTONDOWN)
		{
			exit(0);
		}else{}
	}

	return 0;
}