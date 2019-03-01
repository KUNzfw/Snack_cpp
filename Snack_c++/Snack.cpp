#include "Snack.h"
Paint paint = Paint();
KeyBoradInput kbInput = KeyBoradInput();
void Snack::init() {
	selection();
}
void Snack::selection() {
	clearMap();
	paint.setCursorPostition(0, 1);
	int sel = 0;
	for (int x = 1; x <= mapW; x++) {

		for (int y = 1; y <= mapH; y++) {
			if (y == 1 || y == mapH || x == 1 || x == mapW) {
				paint.setBackGroundColor(WHITE);
			}
			std::cout << "  ";
			paint.setBackGroundColor(BLACK);
		}

		std::cout << std::endl;
	}
	paint.setBackGroundColor(BLACK);
	paint.setCursorPostition(20, 10);
	paint.setBackGroundColor(HIGHLIGHT);
	std::cout << "Start";
	paint.setBackGroundColor(BLACK);
	paint.setCursorPostition(20, 15);
	std::cout << "Exit";
	paint.setCursorPostition(1, 1);
	while (true) {
		if (kbInput.ifKeyPress()) {
			switch (kbInput.getKeyBoardChar())
			{
			case enter:
				switch (sel)
				{
				case 1:
					exit(0);
					break;
				case 0:
					goto START;
					break;
				}
				break;
			case w:
				if (sel == 1) {
					sel = 0;
					paint.setBackGroundColor(BLACK);
					paint.setCursorPostition(20, 15);
					std::cout << "Exit";
					paint.setBackGroundColor(HIGHLIGHT);
					paint.setCursorPostition(20, 10);
					std::cout << "Start";
					paint.setBackGroundColor(BLACK);
					paint.setCursorPostition(1, 1);
				}
				break;
			case s:
				if (sel == 0) {
					sel = 1;
					paint.setBackGroundColor(BLACK);
					paint.setCursorPostition(20, 10);
					std::cout << "Start";
					paint.setBackGroundColor(HIGHLIGHT);
					paint.setCursorPostition(20, 15);
					std::cout << "Exit";
					paint.setBackGroundColor(BLACK);
					paint.setCursorPostition(1, 1);
				}
				break;
			default:
				break;
			}
		}
		Sleep(1);
	}
START: {
	start();
	}
}
void Snack::start() {
	clearMap();
	bool food = true;
	paint.setCursorPostition(30, 15);
	snack.push_front(Coord(30, 15));
	paint.setBackGroundColor(GREEN);
	std::cout << "  ";
	DWORD time = GetTickCount();

	Coord foodPostiton = Coord(0, 0);
	do
	{
		std::srand(std::time(0));
		foodPostiton = Coord((rand() % 26 + 2) * 2, rand() % 26 + 2);
		std::deque<Coord>::iterator i = snack.begin();
		for (; i < snack.end(); i++)
		{
			if ((*i).getX() == foodPostiton.getX() && (*i).getY() == foodPostiton.getY()) {
				goto TWO;
			}
		}
		break;
	TWO: {}
	} while (true);
	paint.setCursorPostition(foodPostiton.getX(), foodPostiton.getY());
	paint.setBackGroundColor(RED);
	std::cout << "  ";
	paint.setBackGroundColor(BLACK);
	paint.setCursorPostition(1, 1);

	Direction temp = (Direction)direction;

	while (true)
	{
		if (kbInput.ifKeyPress()) {
			switch (kbInput.getKeyBoardChar())
			{
			case w:
				if (direction != SOUTH)
					temp = NORTH;
				break;
			case s:
				if (direction != NORTH)
					temp = SOUTH;
				break;
			case a:
				if (direction != EAST)
					temp = WEST;
				break;
			case d:
				if (direction != WEST)
					temp = EAST;
				break;
			default:
				break;
			}
		}

		if (GetTickCount() - time >= 150)
		{
			direction = temp;

			switch (direction)
			{
			case NORTH:
				snack.push_front(Coord(snack.front().getX(), snack.front().getY() - 1));
				paint.setBackGroundColor(GREEN);
				paint.setCursorPostition(snack.front().getX(), snack.front().getY());
				std::cout << "  ";
				paint.setBackGroundColor(BLACK);
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.setCursorPostition(snack.back().getX(), snack.back().getY());
					std::cout << "  ";
					snack.pop_back();
				}
				paint.setCursorPostition(1, 1);
				break;
			case SOUTH:
				snack.push_front(Coord(snack.front().getX(), snack.front().getY() + 1));
				paint.setBackGroundColor(GREEN);
				paint.setCursorPostition(snack.front().getX(), snack.front().getY());
				std::cout << "  ";
				paint.setBackGroundColor(BLACK);
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.setCursorPostition(snack.back().getX(), snack.back().getY());
					std::cout << "  ";
					snack.pop_back();
				}
				paint.setCursorPostition(1, 1);
				break;
			case WEST:
				snack.push_front(Coord(snack.front().getX() - 2, snack.front().getY()));
				paint.setBackGroundColor(GREEN);
				paint.setCursorPostition(snack.front().getX(), snack.front().getY());
				std::cout << "  ";
				paint.setBackGroundColor(BLACK);
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.setCursorPostition(snack.back().getX(), snack.back().getY());
					std::cout << "  ";
					snack.pop_back();
				}
				paint.setCursorPostition(1, 1);
				break;
			case EAST:
				snack.push_front(Coord(snack.front().getX() + 2, snack.front().getY()));
				paint.setBackGroundColor(GREEN);
				paint.setCursorPostition(snack.front().getX(), snack.front().getY());
				std::cout << "  ";
				paint.setBackGroundColor(BLACK);
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.setCursorPostition(snack.back().getX(), snack.back().getY());
					std::cout << "  ";
					snack.pop_back();
				}
				paint.setCursorPostition(1, 1);
				break;
			default:
				break;
			}
			std::deque<Coord>::iterator b = snack.begin() + 1;
			for (; b < snack.end(); b++) {
				if (snack.front().getX() == (*b).getX() && snack.front().getY() == (*b).getY())
					goto END;
			}
			if (snack.front().getX() == 2 || snack.front().getX() == mapW * 2 - 2 || snack.front().getY() == 1 || snack.front().getY() == mapH)
				goto END;
			if (!food)
			{
				do
				{
					std::srand(std::time(0));
					foodPostiton = Coord((rand() % 26 + 2) * 2, rand() % 26 + 2);
					std::deque<Coord>::iterator i = snack.begin();
					for (; i < snack.end(); i++)
					{
						if (i->getX() == foodPostiton.getX() && i->getY() == foodPostiton.getY()) {
							goto ONE;
						}
					}
					break;
				ONE: {}
				} while (true);
				paint.setCursorPostition(foodPostiton.getX(), foodPostiton.getY());
				paint.setBackGroundColor(RED);
				std::cout << "  ";
				paint.setBackGroundColor(BLACK);
				paint.setCursorPostition(1, 1);
				food = true;
			}

			time = GetTickCount();
		}
		Sleep(1);
	}
END: {
	over();
	}
}
void Snack::over() {
	clearMap();
	paint.setBackGroundColor(BLACK);
	paint.setCursorPostition(15, 15);
	std::cout << "Game Over!";
	snack.clear();
	while (true)
	{
		if (kbInput.ifKeyPress())
			if (kbInput.getKeyBoardChar() == enter)
				goto SEL;
		Sleep(1);
	}
SEL: {
	selection();
	}
}
void Snack::clearMap() {
	paint.setBackGroundColor(BLACK);
	for (int y = 2; y <= mapH - 2; y++) {
		paint.setCursorPostition(2, y);
		for (int x = 2; x <= mapW - 1; x++) {
			std::cout << "  ";
		}
	}
}