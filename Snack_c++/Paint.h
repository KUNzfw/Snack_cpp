#ifndef PAINT_KUN
#define PAINT_KUN
#include <Windows.h>
#include "Coord.h"
namespace kun {
	enum Color
	{
		HIGHLIGHT,
		WHITE,
		BLACK,
		GREEN,
		RED,
		BULE
	};
	class Paint
	{
	public:
		void setCursorPosition(short x = 0, short y = 0);
		void setCursorPosition(Coord c);
		void setColor(Color backgroundColor, Color textColor);
		//控制台输出，模板类函数要写在头文件中，不然会报ink2019(vs2017中)
		//使用coord坐标系版本
		template<typename T>
		void consoleOutput(T text, Color backgroundColor, Color textColor, Coord position) {
			setCursorPosition(position);//设置光标位置
			setColor(backgroundColor, textColor);//设置颜色
			std::cout << text;//输出文本
		}
		//直接输入 x,y 版本
		template<typename T>
		void consoleOutput(T text, Color backgroundColor, Color textColor, int x, int y) {
			setCursorPosition(x, y);//设置光标位置
			setColor(backgroundColor, textColor);//设置颜色
			std::cout << text;//输出文本
		}
		//不改变坐标版本
		template<typename T>
		void consoleOutput(T text, Color backgroundColor, Color textColor) {
			setColor(backgroundColor, textColor);//设置颜色
			std::cout << text;//输出文本
		}
	};
}
#endif // !PAINT_KUN