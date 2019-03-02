#ifndef SELEC_KUN
#define SELEC_KUN
#include <deque>
#include <string>
#include <Windows.h>
#include "KeyBoradInput.h"
#include "Paint.h"

namespace kun {
	struct AnSelection
	{
		std::string text;
		int x;
		int y;
		int id;
	};
	class Selection
	{
	private:
		std::deque<AnSelection> selectionList;
		int total = 0;
		int localtion = 0;
	public:
		void addSelection(AnSelection as);
		void addSelection(std::string text, int x, int y ,int id);
		void show();
		int waitForChoose();
	}; 
}

#endif
