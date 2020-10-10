#include <iostream>
#include "2048.h"


//extern game_flag;
//©¤  ©¦ ©° ©´©¸ ©¼ ©À ©È ©Ð ©Ø ©à

int main()
{
	using std::cout;
	using std::endl;
	
	bool action = true;
	Square s;

	s.createNum();
	s.show(6, 2);
	
	s.check();
	while(s.getSTATE() )
	{		
		while(action)
		{
			if (s.getUP() && GetAsyncKeyState(VK_UP)& 0x8000)
			{	
				s.up();
				action = false;
			}
			else if (s.getDOWN() && GetAsyncKeyState(VK_DOWN)& 0x8000)
			{
				s.down();
				action = false;
			}
			else if (s.getLEFT() && GetAsyncKeyState(VK_LEFT)& 0x8000)
			{
				s.left();
				action = false;
			}
			else if (s.getRIGHT() && GetAsyncKeyState(VK_RIGHT)& 0x8000)
			{
				s.right();
				action = false;
			}
		}
		if (action == false)
		{
			s.createNum();
			s.show(6, 2);
			action = true;
		}
		s.check();
		
		if (s.getMax() >= MAXIMUM)
		{
			gotoxy(10,0);
			cout << "You WIN!";
			break;
		}
		else if (s.getSTATE() == false)
		{
			gotoxy(10,0);
			cout << "Game Over!";
		}

		Sleep(300);
	}
	
	system("pause > nul");

	/**
	initialized();
	
	while (game_flag)
	{
		updateWithoutInput();
		updateWithInput();
		show();
		Sleep(300);
		
	}
	*/
	//std::cin.get();
	return 0;
}