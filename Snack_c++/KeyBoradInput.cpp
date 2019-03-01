#include "KeyBoradInput.h"

using namespace kun;

bool KeyBoradInput::ifKeyPress() {
	return _kbhit();
}
KeyChar KeyBoradInput::getKeyBoardChar() {
	int ch;
	ch = _getch();
	switch (ch)
	{
	case 97:
		return a;
	case 119:
		return w;
	case 115:
		return s;
	case 100:
		return d;
	case 13:
		return enter;
	case 32:
		return space;
	default:
		return null;
		break;
	}
}