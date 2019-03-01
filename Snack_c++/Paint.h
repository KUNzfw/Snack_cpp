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
		//����̨�����ģ���ຯ��Ҫд��ͷ�ļ��У���Ȼ�ᱨink2019(vs2017��)
		//ʹ��coord����ϵ�汾
		template<typename T>
		void consoleOutput(T text, Color backgroundColor, Color textColor, Coord position) {
			setCursorPosition(position);//���ù��λ��
			setColor(backgroundColor, textColor);//������ɫ
			std::cout << text;//����ı�
		}
		//ֱ������ x,y �汾
		template<typename T>
		void consoleOutput(T text, Color backgroundColor, Color textColor, int x, int y) {
			setCursorPosition(x, y);//���ù��λ��
			setColor(backgroundColor, textColor);//������ɫ
			std::cout << text;//����ı�
		}
		//���ı�����汾
		template<typename T>
		void consoleOutput(T text, Color backgroundColor, Color textColor) {
			setColor(backgroundColor, textColor);//������ɫ
			std::cout << text;//����ı�
		}
	};
}
#endif // !PAINT_KUN