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
public:
	void init();
	void selection();
	void start();
	void over();
	void clearMap();
};
#endif // !SNACK_KUN


