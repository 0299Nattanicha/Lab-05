#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(2, 4);
	printf(" <-0-> ");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("       ");
}
void draw_bullet(int a, int b)
{
	gotoxy(a, b);
	setcolor(2, 0);
	printf("   *   ");
}
void erase_bullet(int a, int b)
{
	gotoxy(a, b);
	setcolor(0, 0);
	printf("       ");
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

int main()
{
	char ch = '.';
	int x = 38, y = 20, direction = 2, bullet[5] = {0}, a[5], b[5];
	setcursor(0);
	draw_ship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			
			if (ch == 'a' )
			{
				direction = 0;
			}
			if (ch == 'd' )
			{
				direction = 1;
			}
			if (ch == 's')
			{
				direction = 2;
			}
			if (ch == ' '&& bullet[0] == 0)
			{
				a[0] = x;
				b[0] = y-1;
				bullet[0] = 1;
			}
			else if (ch == ' ' && bullet[1] == 0)
			{
				a[1] = x;
				b[1] = y-1;
				bullet[1] = 1;
			}
			else if (ch == ' ' && bullet[2] == 0)
			{
				a[2] = x;
				b[2] = y-1;
				bullet[2] = 1;
			}
			else if (ch == ' ' && bullet[3] == 0)
			{
				a[3] = x;
				b[3] = y-1;
				bullet[3] = 1;
			}
			else if (ch == ' ' && bullet[4] == 0)
			{
				a[4] = x;
				b[4] = y-1 ;
				bullet[4] = 1;
			}

			
		}
		if (direction == 0 && x > 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (direction == 1 && x < 80)
		{
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (direction == 2)
		{
			draw_ship(x, y);
		}
		if (bullet[0] == 1 )
		{
			erase_bullet(a[0], b[0]);
			if ( b[0] > 0)
			{
				draw_bullet(a[0], --b[0]);
			}
			else
			{
				erase_bullet(a[0], b[0]); 
				b[0] = 20; 
				bullet[0] = 0; 
			}
		}
		if (bullet[1] == 1)
		{
			erase_bullet(a[1], b[1]);
			if (b[1] > 0)
			{
				draw_bullet(a[1], --b[1]);
			}
			else
			{
				erase_bullet(a[1], b[1]);
				b[1] = 20;
				bullet[1] = 0;
			}
		}
		if (bullet[2] == 1)
		{
			erase_bullet(a[2], b[2]);
			if (b[2] > 0)
			{
				draw_bullet(a[2], --b[2]);
			}
			else
			{
				erase_bullet(a[2], b[2]);
				b[2] = 20;
				bullet[2] = 0;
			}
		}
		if (bullet[3] == 1)
		{
			erase_bullet(a[3], b[3]);
			if (b[3] > 0)
			{
				draw_bullet(a[3], --b[3]);
			}
			else
			{
				erase_bullet(a[3], b[3]);
				b[3] = 20;
				bullet[3] = 0;
			}
		}
		if (bullet[4] == 1)
		{
			erase_bullet(a[4], b[4]);
			if (b[4] > 0)
			{
				draw_bullet(a[4], --b[4]);
			}
			else
			{
				erase_bullet(a[4], b[4]);
				b[4] = 20;
				bullet[4] = 0;
			}
		}
		
		fflush(stdin);
		Sleep(100);
	} 
	while (ch != 'x');
	return 0;
}