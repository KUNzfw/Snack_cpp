#ifndef KEYBORADINPUT_KUN
#include <conio.h>
#define KEYBORADINPUT_KUN
namespace kun {
	enum KeyChar
	{
		a, s, d, w, enter, null, space
	};
	class KeyBoradInput {
	public:
		bool ifKeyPress();
		KeyChar getKeyBoardChar();
	};
}
#endif // !KEYBORADINPUT_KUN
