#ifndef	GAME_H_
#define GAME_H_

#include <iostream>
#include <windows.h>
#include <ctime>
#include <cmath>

#define MAXIMUM 2048

using std::cout;

//─  │ ┌ ┐└ ┘ ├ ┤ ┬ ┴ ┼

class Square	//2048正方形
{
	private:
		int sideLength = 4;
		int maximum = 0;
		int **item;
		bool UP = false;
		bool DOWN = false;
		bool LEFT = false;
		bool RIGHT = false;
		bool STATE = true;
		
	public:
		Square(int n = 4);
		~Square();
		
		void createNum();
		void check();
		
		inline int getMax(){return maximum;}
		inline bool getUP(){return UP;}
		inline bool getDOWN(){return DOWN;}
		inline bool getLEFT(){return LEFT;}
		inline bool getRIGHT(){return RIGHT;}
		inline bool getSTATE(){return STATE;}
		
				
		void up();
		void down();
		void left();
		void right();
		
		void show(int x = 0, int y = 0);
};



void HideCursor(int n);  			//设置是否隐藏光标
void gotoxy(int x, int y);			//设置光标位置
void setColor(int color);			//设置文本颜色






#endif