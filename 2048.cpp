#include "2048.h"

/**
函数定义
*/

void HideCursor(int n)   			//设置是否隐藏光标
{
	n %= 2;
	CONSOLE_CURSOR_INFO cursor_info = {1, n};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x, int y) 			//设置光标位置
{
	COORD r;
	r.X = x;
	r.Y = y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), r);
}

void setColor(int color) 			//设置文本颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);	
}


/**
类定义
*/
Square::Square(int n) : sideLength(n)
{
	item = new int * [sideLength];
	for (int i = 0; i < sideLength; i++)
		item[i] = new int[sideLength];
	
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			item[i][j] = 0;
		}
	}
	
}

Square::~Square()
{	
	for (int i = 0; i < sideLength; i++)
		delete [] item[i];
	delete [] item;
}

void Square::createNum()
{
	std::srand((int)std::time(0));
	
	int num = std::rand() % 2 * 2 + 2;
	
	int count = 0;
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			if (item[i][j] == 0)
				count++;
		}
	}
	
	if (count == 0)
		return;
	
	int pos = std::rand() % count + 1;
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			if (item[i][j] == 0)
				pos--;
			else
				continue;
			
			if (pos == 0)
			{
				item[i][j] = num;
				break;
			}
		}
	}
}

void Square::check()
{
	UP = false;
	DOWN = false;
	LEFT = false;
	RIGHT = false;
	
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			if (item[i][j] == 0)
				continue;
			else if (item[i][j] > maximum)
			{
				maximum = item[i][j];
			}
			
			if (UP == false && i > 0)
			{
				if (item[i-1][j] == 0 || item[i-1][j] == item[i][j])
				{
					UP = true;
				}
			}
			
			if (DOWN == false && i < sideLength - 1)
			{
				if (item[i+1][j] == 0 || item[i+1][j] == item[i][j])
				{
					DOWN = true;
				}
			}
			
			if (LEFT == false && j > 0)
			{
				if (item[i][j-1] == 0 || item[i][j-1] == item[i][j])
				{
					LEFT = true;
				}
			}
			
			if (RIGHT == false && j < sideLength -1)
			{
				if (item[i][j+1] == 0 || item[i][j+1] == item[i][j])
				{
					RIGHT = true;
				}
			}
			
			if (UP == true && DOWN == true && LEFT == true && RIGHT == true)
				return;
		}
	}
	
	if (UP == false && DOWN == false && LEFT == false && RIGHT == false)
				STATE = false;
}

void Square::up() 
{
	//bool b;
	
	for (int j = 0; j < sideLength; j++)
	{
		for (int i = 1; i < sideLength; i++)
		{
			if (item[i][j] == 0)
				continue;
			
			for (int n = i; n > 0; n--)
			{
				if (item[n-1][j] == 0)
				{
					item[n-1][j] = item[n][j];
					item[n][j] = 0;
				}
				else if (item[n-1][j] == item[n][j])
				{
					item[n-1][j] *= 2;
					item[n][j] = 0;
					break;
				}
				else
					break;
			}
		}
	}
	
	/**
	for (int i = 1; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			if (item[i][j] == 0)
				continue;
			
			for (int n = i; n > 0; n--)
			{
				if (item[n-1][j] == 0)
				{
					item[n-1][j] = item[n][j];
					item[n][j] = 0;
				}
				else if (item[n-1][j] == item[n][j])
				{
					item[n-1][j] *= 2;
					item[n][j] = 0;
					break;
				}
				else
					break;
			}
		}
	}
	*/
}

void Square::down() 
{
	for (int i = sideLength -2; i >= 0; i--)
	{
		for (int j = 0; j < sideLength; j++)
		{
			if (item[i][j] == 0)
				continue;
			
			for (int n = i; n < sideLength-1; n++)
			{
				if (item[n+1][j] == 0)
				{
					item[n+1][j] = item[n][j];
					item[n][j] = 0;
				}
				else if (item[n+1][j] == item[n][j])
				{
					item[n+1][j] *= 2;
					item[n][j] = 0;
					break;
				}
				else
					break;
			}
		}
	}
}

void Square::left() 
{
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 1; j < sideLength; j++)
		{
			if (item[i][j] == 0)
				continue;
			
			for (int n = j; n > 0; n--)
			{
				if (item[i][n-1] == 0)
				{
					item[i][n-1] = item[i][n];
					item[i][n] = 0;
				}
				else if (item[i][n-1] == item[i][n])
				{
					item[i][n-1] *= 2;
					item[i][n] = 0;
					break;
				}
				else
					break;
			}
		}
	}
}

void Square::right() 
{
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = sideLength -2; j >= 0; j--)
		{
			if (item[i][j] == 0)
				continue;
			
			for (int n = j; n < sideLength -1; n++)
			{
				if (item[i][n+1] == 0)
				{
					item[i][n+1] = item[i][n];
					item[i][n] = 0;
				}
				else if (item[i][n+1] == item[i][n])
				{
					item[i][n+1] *= 2;
					item[i][n] = 0;
					break;
				}
				else
					break;
			}
		}
	}
}


//─  │ ┌ ┐└ ┘ ├ ┤ ┬ ┴ ┼		
void Square::show(int x, int y)
{
	using std::cout;
	int a = x;
	int b = y;
	
	for (int i = 0; i < sideLength; i++)
	{
		for (int j = 0; j < sideLength; j++)
		{
			x = 6 * j + a;
			y = 4 * i + b;
			
			if (i == 0 && j == 0)				
			{
				gotoxy(x, y);
				cout << "┌──";
				
				gotoxy(x, y+1);
				cout << "│    ";
				
				gotoxy(x, y+2);
				cout << "│";
				if (item[i][j] == 0)
				{
					cout << "    ";
				}
				else
				{
					setColor(log(item[i][j]) / log(2) + 3);
					cout.width(4);
					cout << item[i][j];
					setColor(7);
				}
				
				gotoxy(x, y+3);
				cout << "│    ";
				
			}
			else if(i == 0 && j != 0)
			{
				gotoxy(x, y);
				cout << "┬──";
				
				gotoxy(x, y+1);
				cout << "│    ";
				
				gotoxy(x, y+2);
				cout << "│";
				if (item[i][j] == 0)
				{
					cout << "    ";
				}
				else
				{
					setColor(log(item[i][j]) / log(2) + 3);
					cout.width(4);
					cout << item[i][j];
					setColor(7);
				}
				
				gotoxy(x, y+3);
				cout << "│    ";
				
				if (j == sideLength -1)
				{
					gotoxy(x+6, y);
					cout << "┐";
					
					gotoxy(x+6, y+1);
					cout << "│";
					
					gotoxy(x+6, y+2);
					cout << "│";
					
					gotoxy(x+6, y+3);
					cout << "│";
				}
			}
			else if (i != 0 && j == 0)
			{
				gotoxy(x, y);
				cout << "├──";
				
				gotoxy(x, y+1);
				cout << "│    ";
				
				gotoxy(x, y+2);
				cout << "│";
				if (item[i][j] == 0)
				{
					cout << "    ";
				}
				else
				{
					setColor(log(item[i][j]) / log(2) + 3);
					cout.width(4);
					cout << item[i][j];
					setColor(7);
				}
				
				gotoxy(x, y+3);
				cout << "│    ";
				
				if (i == sideLength -1)
				{
					gotoxy(x, y+4);
					cout << "└──";
				}
			}
			else if (i != 0 && j != 0)
			{
				gotoxy(x, y);
				cout << "┼──";
				
				gotoxy(x, y+1);
				cout << "│    ";
				
				gotoxy(x, y+2);
				cout << "│";
				if (item[i][j] == 0)
				{
					cout << "    ";
				}
				else
				{
					setColor(log(item[i][j]) / log(2) + 3);
					cout.width(4);
					cout << item[i][j];
					setColor(7);
				}
				
				gotoxy(x, y+3);
				cout << "│    ";
				
				if (j == sideLength -1)
				{
					gotoxy(x+6, y);
					cout << "┤";
					
					gotoxy(x+6, y+1);
					cout << "│";
					
					gotoxy(x+6, y+2);
					cout << "│";
					
					gotoxy(x+6, y+3);
					cout << "│";
				}
				
				if (i == sideLength -1)
				{
					gotoxy(x, y+4);
					cout << "┴──";
					
					if (j == sideLength -1)
					{
						cout << "┘";
					}
				}
			}
			
			
		}
	}

}