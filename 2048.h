#ifndef	GAME_H_
#define GAME_H_

#include <iostream>
#include <windows.h>
#include <ctime>
#include <cmath>

#define MAXIMUM 2048

using std::cout;

//��  �� �� ���� �� �� �� �� �� ��

class Square	//2048������
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



void HideCursor(int n);  			//�����Ƿ����ع��
void gotoxy(int x, int y);			//���ù��λ��
void setColor(int color);			//�����ı���ɫ






#endif