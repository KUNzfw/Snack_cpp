#include "Selection.h"
using namespace kun;
Paint paint = Paint();
KeyBoradInput kbInput = KeyBoradInput();
kun::Selection::Selection(bool i)
{
	ishorizontal = i;
}
kun::Selection::Selection()
{
}
void kun::Selection::addSelection(AnSelection as)
{
	selectionList.push_back(as);
	total++;
}

void kun::Selection::addSelection(std::string text, int x, int y, int id)
{
	AnSelection temp = {
		text,
		x,
		y,
		id
	};
	selectionList.push_back(temp);
	total++;
}

void kun::Selection::show()
{
	paint.consoleOutput(selectionList.front().text, HIGHLIGHT, WHITE, selectionList.front().x, selectionList.front().y);
	for (std::deque<AnSelection>::iterator i = selectionList.begin() + 1; i < selectionList.end(); i++) {
		paint.consoleOutput(i->text, BLACK, WHITE, i->x, i->y);
	}
}

int kun::Selection::waitForChoose()
{
	while (true)
	{
		//�������¼�
		if (kbInput.ifKeyPress())
		{

			if (!ishorizontal)
			{
				switch (kbInput.getKeyBoardChar())
				{
				case W:
				case w:
					if (localtion != 0)
					{
						//��һ��ѡ��
						paint.consoleOutput(selectionList[localtion].text, BLACK, WHITE, selectionList[localtion].x, selectionList[localtion].y);
						localtion--;
						paint.consoleOutput(selectionList[localtion].text, HIGHLIGHT, WHITE, selectionList[localtion].x, selectionList[localtion].y);
					}
					break;
				case S:
				case s:
					if (localtion != total - 1)
					{
						//��һ��ѡ��
						paint.consoleOutput(selectionList[localtion].text, BLACK, WHITE, selectionList[localtion].x, selectionList[localtion].y);
						localtion++;
						paint.consoleOutput(selectionList[localtion].text, HIGHLIGHT, WHITE, selectionList[localtion].x, selectionList[localtion].y);
					}
					break;
				case enter:
					//����id
					return selectionList[localtion].id;
					break;
				}
			}
			else
			{
				switch (kbInput.getKeyBoardChar())
				{
				case A:
				case a:
					if (localtion != 0)
					{
						//��һ��ѡ��
						paint.consoleOutput(selectionList[localtion].text, BLACK, WHITE, selectionList[localtion].x, selectionList[localtion].y);
						localtion--;
						paint.consoleOutput(selectionList[localtion].text, HIGHLIGHT, WHITE, selectionList[localtion].x, selectionList[localtion].y);
					}
					break;
				case D:
				case d:
					if (localtion != total - 1)
					{
						//��һ��ѡ��
						paint.consoleOutput(selectionList[localtion].text, BLACK, WHITE, selectionList[localtion].x, selectionList[localtion].y);
						localtion++;
						paint.consoleOutput(selectionList[localtion].text, HIGHLIGHT, WHITE, selectionList[localtion].x, selectionList[localtion].y);
					}
					break;
				case enter:
					//����id
					return selectionList[localtion].id;
					break;
				}
			}
		}
		Sleep(1);//����cpuռ��
	}
}
