#ifndef PAINT_KUN
#define PAINT_KUN
#include <Windows.h>
#include "Coord.h"
enum Color
{
	HIGHLIGHT,
	WHITE,
	BLACK,
	GREEN,
	RED
};
class Paint
{
public:
	void setCursorPostition(short x = 0, short y = 0);
	void setCursorPostition(Coord c);
	void setBackGroundColor(Color c);
};

#endif // !PAINT_KUN