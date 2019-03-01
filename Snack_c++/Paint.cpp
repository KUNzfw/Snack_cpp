#include "Paint.h"
using namespace kun;

void Paint::setCursorPosition(short x, short y) {
	COORD c = { x,y }; //����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//���ù��λ��
}
void Paint::setCursorPosition(Coord coord) {
	COORD c = { (short)coord.getX(),(short)coord.getY() }; //����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//���ù��λ��
}
void Paint::setColor(Color backgroundColor,Color textColor) {
	WORD color = FOREGROUND_INTENSITY;
	//������ɫ
	switch (backgroundColor)
	{
	case HIGHLIGHT:
		color = color | BACKGROUND_INTENSITY;
		break;
	case WHITE:
		color = color | BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
		break;
	case BLACK:
		break;
	case GREEN:
		color = color | BACKGROUND_INTENSITY | BACKGROUND_GREEN;
		break;
	case RED:
		color = color | BACKGROUND_INTENSITY | BACKGROUND_RED;
		break;
	case BULE:
		color = color | BACKGROUND_INTENSITY | BACKGROUND_BLUE;
		break;
	}
	//������ɫ
	switch (textColor)
	{
	case HIGHLIGHT:
		break;
	case WHITE:
		break;
	case BLACK:
		color = color | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		break;
	case GREEN:
		color = color | FOREGROUND_GREEN;
		break;
	case RED:
		color = color | FOREGROUND_RED;
		break;
	case BULE:
		color = color | FOREGROUND_BLUE;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

