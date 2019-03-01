#ifndef SNACK_KUN
#define SNACK_KUN
#include <Windows.h>
#include <process.h>
#include <iostream>
#include <thread>
#include <ctime>
#include <cstdlib>
#include <deque>
#include "Paint.h"
#include "KeyBoradInput.h"
namespace kun {
	enum Direction
	{
		NORTH,
		SOUTH,
		WEST,
		EAST
	};
	class Snack
	{
	private:
		int mapW = 30;
		int mapH = 30;
		int direction = NORTH;
		std::deque<Coord> snack;
		int snackLong = 1;
		Coord foodPostiton = Coord(0, 0);
		unsigned int gameSpeed = 150;
		KeyBoradInput kbInput;
		Paint paint;

	public:
		void init();
		void selection();
		void start();
		void over();
		void clearMap();
		void genFood();
	};
}
#endif // !SNACK_KUN


