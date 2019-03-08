//mian文件

#include <iostream>
#include "Snack.h"

using namespace kun;

Snack game = Snack();

int main() {
	//隐藏光标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(hOut, &cci);

	game.init();
	return 0;
}
