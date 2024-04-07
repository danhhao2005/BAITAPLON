#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;
int toa_dox[MAX] = { 0 };
int toa_doy[MAX] = { 0 };
int sl = 4;
int xqua = -1;
int yqua = -1;

void ve_tuong();
void khoi_tao_ran();
void play();
void ve_ran();
void di_chuyen_ran(int x, int y);
bool game_over();
void tao_qua();
void ve_qua();

bool kt_ran_an_qua();
void xu_ly_ran_an_qua();
bool kt_ran_cham_than();

int main()
{
	srand(time(NULL));
	play();

	_getch();
	return 0;
}

void ve_tuong()
{
	for (int x = 10;x <= 95;x++)
	{
		gotoXY(x, 1);
		cout << "+";
		gotoXY(x, 25);
		cout << "+";
	}
	for (int y = 1;y <= 25;y++)
	{
		gotoXY(10, y);
		cout << "+";
		gotoXY(95, y);
		cout << "+";
	}
}
void play()
{
	ShowCur(0);
	SetColor(11);

	ve_tuong();
	khoi_tao_ran();
	tao_qua();
	ve_qua();
	int x = toa_dox[0];
	int y = toa_doy[0];
	int check = 2;//0: đi xuống
				//1: đi lên
				//2: đi qua phải
				//3: đi qua trái

	while (true)
	{
		gotoXY(toa_dox[sl], toa_doy[sl]);
		cout << " ";

		ve_ran();

		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
			}
		}

		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check ==3)
		{
			x--;
		}

		if (game_over())
		{
			break;
		}
		xu_ly_ran_an_qua();

		di_chuyen_ran(x,y);

		Sleep(100);
	}
}
void khoi_tao_ran()
{
	int x_khoi_tao = 50;
	int y_khoi_tao = 13;
	for (int i = 0;i < sl;i++)
	{
		toa_dox[i] = x_khoi_tao--;
		toa_doy[i] = y_khoi_tao;
	}
}
void ve_ran()
{
	for (int i = 0;i < sl;i++)
	{
		gotoXY(toa_dox[i], toa_doy[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "o";
		}
	}
}
void di_chuyen_ran(int x,int y)
{
	for (int i = sl;i > 0;i--)
	{
		toa_dox[i] = toa_dox[i-1];
		toa_doy[i] = toa_doy[i-1];
	}
	toa_dox[0] = x;
	toa_doy[0] = y;
}
bool kt_ran_cham_than()
{
	for (int i = 1;i <= sl;i++)
	{
		if (toa_dox[0] == toa_dox[i] && toa_doy[0] == toa_doy[i])
		{
			return true;
		}
	}
	return false;
}
bool game_over()
{
	if (toa_dox[0] == 10 || toa_dox[0] == 95 || toa_doy[0] == 1 || toa_doy[0] == 25)
	{
		return true;
	}
	return kt_ran_cham_than();
}
bool kt_ran_de_qua()
{
	for (int i = 0;i < sl;i++)
	{
		if (xqua == toa_dox[i] && yqua == toa_doy[i]) {
			return true;
		}
	}
	return false;
}
void tao_qua()
{
	do
	{
		xqua = rand() % (94 - 11 + 1) + 11;
		yqua = rand() % (25 - 1 + 1) + 1;
	}while(kt_ran_de_qua());
}
void ve_qua()
{
	gotoXY(xqua, yqua);cout << "$";
}
bool kt_ran_an_qua()
{
	return (toa_dox[0] == xqua && toa_doy[0] == yqua);
}
void xu_ly_ran_an_qua()
{
	if (kt_ran_an_qua())
	{
		sl++;
		tao_qua();
		ve_qua();
	}
}
