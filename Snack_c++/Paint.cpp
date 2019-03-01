#include "Paint.h"
void Paint::setCursorPostition(short x, short y) {
	COORD c = { x,y }; //坐标
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//
	SetConsoleCursorPosition(h, c);//设置光标位置
}
void Paint::setCursorPostition(Coord coord) {
	COORD c = { (short)coord.getX(),(short)coord.getY() }; //坐标
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//
	SetConsoleCursorPosition(h, c);//设置光标位置
}
void Paint::setBackGroundColor(Color c) {
	switch (c)
	{
	case HIGHLIGHT:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
		break;
	case WHITE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		break;
	case BLACK:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
		break;
	case GREEN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_GREEN);
		break;
	case RED:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED);
		break;
	default:
		break;
	}
}
