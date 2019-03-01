#include "Snack.h"

using namespace kun;


void Snack::init() {
	selection();
}
void Snack::selection() {
	//����
	clearMap();
	paint.setCursorPosition(0, 1);

	int sel = 0;

	//���Ƶ�ͼ����
	for (int x = 1; x <= mapW; x++) {
		for (int y = 1; y <= mapH; y++) {
			if (y == 1 || y == mapH || x == 1 || x == mapW) {
				paint.consoleOutput("  ", WHITE, HIGHLIGHT);
			}
			else {
				paint.consoleOutput("  ", BLACK, HIGHLIGHT);
			}
		}
		std::cout << std::endl;
	}

	//����ѡ��
	paint.consoleOutput("Start", HIGHLIGHT, BLACK, 20, 10);
	paint.consoleOutput("Exit", BLACK, HIGHLIGHT, 20, 15);
	paint.setCursorPosition(0, 1);

	while (true) {
		if (kbInput.ifKeyPress()) {
			//����������
			switch (kbInput.getKeyBoardChar())
			{
			case enter:
				switch (sel)
				{
				case 1:
					//�˳���Ϸ
					exit(0);
					break;
				case 0:
					//��ʼ��Ϸ������
					start();
					return;
					break;
				}
				break;
				//�л�ѡ��
			case w:
				if (sel == 1) {
					sel = 0;
					paint.consoleOutput("Start", HIGHLIGHT, BLACK, 20, 10);
					paint.consoleOutput("Exit", BLACK, HIGHLIGHT, 20, 15);
					paint.setCursorPosition(0, 1);
				}
				break;
			case s:
				if (sel == 0) {
					sel = 1;
					paint.consoleOutput("Start", BLACK, HIGHLIGHT, 20, 10);
					paint.consoleOutput("Exit", HIGHLIGHT, BLACK, 20, 15);
					paint.setCursorPosition(0, 1);
				}
				break;
			}
		}
		//����cpuռ��
		Sleep(1);
	}
}
//��Ϸ��ʼ
void Snack::start() {
	//�����ͼ
	clearMap();

	bool food = true;

	//���Ƶ�һ������
	snack.push_front(Coord(30, 15));
	paint.consoleOutput("  ", GREEN, BLACK, snack.front());

	//��ʼ����ʱ��
	DWORD time = GetTickCount();
	//��ʼ��ʳ��
	genFood();
	//��ʱ����
	Direction temp = (Direction)direction;

	while (true)
	{
		//�������¼�
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
		//��Ϸ���� 
		if (GetTickCount() - time >= (time_t)gameSpeed)
		{
			direction = temp;

			switch (direction)
			{
			case NORTH:
				//����ͷ��
				snack.push_front(Coord(snack.front().getX(), snack.front().getY() - 1));
				paint.consoleOutput("  ", GREEN, HIGHLIGHT, snack.front());
				//����Ƿ�Ե�food������Ե��Ͳ����β��
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.consoleOutput("  ", BLACK, HIGHLIGHT, snack.back());
					snack.pop_back();
				}
				//���ù�����ӹ�����
				paint.setCursorPosition(0, 1);
				break;
			case SOUTH:
				snack.push_front(Coord(snack.front().getX(), snack.front().getY() + 1));
				paint.consoleOutput("  ", GREEN, HIGHLIGHT, snack.front());
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.consoleOutput("  ", BLACK, HIGHLIGHT, snack.back());
					snack.pop_back();
				}
				paint.setCursorPosition(0, 1);
				break;
			case WEST:
				snack.push_front(Coord(snack.front().getX() - 2, snack.front().getY()));
				paint.consoleOutput("  ", GREEN, HIGHLIGHT, snack.front());
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.consoleOutput("  ", BLACK, HIGHLIGHT, snack.back());
					snack.pop_back();
				}
				paint.setCursorPosition(0, 1);
				break;
			case EAST:
				snack.push_front(Coord(snack.front().getX() + 2, snack.front().getY()));
				paint.consoleOutput("  ", GREEN, HIGHLIGHT, snack.front());
				if (snack.front().getX() == foodPostiton.getX() && snack.front().getY() == foodPostiton.getY()) {
					food = false;
					snackLong++;
				}
				else {
					paint.consoleOutput("  ", BLACK, HIGHLIGHT, snack.back());
					snack.pop_back();
				}
				paint.setCursorPosition(0, 1);
				break;
			}
			//����Ƿ�Ե�����
			for (std::deque<Coord>::iterator b = snack.begin() + 1; b < snack.end(); b++) {
				if (snack.front().getX() == (*b).getX() && snack.front().getY() == (*b).getY()) {
					over();
					return;
				}
			}
			//����Ƿ�ײǽ
			if (snack.front().getX() == 2 || snack.front().getX() == mapW * 2 - 2 || snack.front().getY() == 1 || snack.front().getY() == mapH) {
				over();
				return;
			}

			//��������food
			if (!food)
			{
				genFood();
				food = true;
			}

			//����ʱ��
			time = GetTickCount();
		}
		//����cpuռ��
		Sleep(1);
	}
}
//��Ϸ��������
void Snack::over() {
	//�����ͼ
	clearMap();

	paint.consoleOutput("GAME OVER!!!", BLACK, HIGHLIGHT, 20, 20);
	//����ߵ�����
	snack.clear();
	while (true)
	{
		//���س����ص���ʼ����
		if (kbInput.ifKeyPress())
			if (kbInput.getKeyBoardChar() == enter) {
				selection();
				return;
			}
		//����cpuռ��
		Sleep(1);
	}
}

void Snack::clearMap() {
	for (int y = 2; y <= mapH - 2; y++) {
		paint.setCursorPosition(2, y);
		for (int x = 2; x <= mapW - 1; x++) {
			paint.consoleOutput("  ", BLACK, HIGHLIGHT);
		}
	}
}
void Snack::genFood() {
	//ѭ�������ж�����
	bool isEnd = true;

	do
	{
		//�������foodλ��
		std::srand((unsigned int)std::time(0));
		foodPostiton = Coord((rand() % (mapW - 4) + 2) * 2, rand() % (mapH - 4) + 3);

		for (std::deque<Coord>::iterator i = snack.begin(); i < snack.end(); i++)
		{
			if ((*i).getX() == foodPostiton.getX() && (*i).getY() == foodPostiton.getY()) {
				isEnd = false;
			}
		}
		if (isEnd)
		{
			paint.consoleOutput("  ", RED, HIGHLIGHT, foodPostiton);
			return;
		}
	} while (true);
}