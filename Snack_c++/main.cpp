//mian�ļ�

#include <iostream>
#include "Snack.h"

using namespace kun;

Snack game = Snack();

int main() {
	//���ع�ꡣ
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);

	game.init();
	return 0;
}