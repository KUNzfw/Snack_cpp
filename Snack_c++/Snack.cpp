#include "Snack.h"

using namespace kun;


void Snack::init() {
	selection();
}
void Snack::selection() {
	//����
	clearMap();
	paint.setCursorPosition(0, 0);
	//����Ʒְ�
	for (int x = mapW; x <= mapW + 10; x++)
	{
		for (int y = 0; y < mapH; y++)
		{
			if (x == mapW + 10 || y == 0 || y == mapH - 1)
			{
				paint.consoleOutput("  ", BLACK, HIGHLIGHT, x * 2, y);
			}
			else
			{
				paint.consoleOutput("  ", BLACK, HIGHLIGHT, x * 2, y);
			}
		}
	}
	paint.setCursorPosition(0, 0);
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
	paint.setCursorPosition(0, 0);

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
			case W:
			case w:
				if (sel == 1) {
					sel = 0;
					paint.consoleOutput("Start", HIGHLIGHT, BLACK, 20, 10);
					paint.consoleOutput("Exit", BLACK, HIGHLIGHT, 20, 15);
				}
				break;
			case S:
			case s:
				if (sel == 0) {
					sel = 1;
					paint.consoleOutput("Start", BLACK, HIGHLIGHT, 20, 10);
					paint.consoleOutput("Exit", HIGHLIGHT, BLACK, 20, 15);
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
	ULONGLONG timer = GetTickCount64();
	time_t gameStartTime = time(0);
	//��ʼ��ʳ��
	genFood();
	//��ʱ����
	Direction temp = (Direction)direction;

	//���üǷְ�
	for (int x = mapW; x <= mapW + 10; x++)
	{
		for (int y = 0; y < mapH; y++)
		{
			if (x == mapW + 10 || y == 0 || y == mapH - 1)
			{
				paint.consoleOutput("  ", WHITE, HIGHLIGHT, x * 2, y);
			}
			else
			{
				paint.consoleOutput("  ", BLACK, HIGHLIGHT, x * 2, y);
			}
		}
	}
	paint.consoleOutput("SCORE:", BLACK, BLACK, (mapW + 3) * 2, 1);
	paint.consoleOutput("TIME:", BLACK, BLACK, (mapW + 3) * 2, 4);
	paint.consoleOutput("SPEED:", BLACK, BLACK, (mapW + 3) * 2, 7);

	while (true)
	{
		//�������¼�
		if (kbInput.ifKeyPress()) {
			switch (kbInput.getKeyBoardChar())
			{
			case W:
			case w:
				if (direction != SOUTH)
					temp = NORTH;
				break;
			case S:
			case s:
				if (direction != NORTH)
					temp = SOUTH;
				break;
			case A:
			case a:
				if (direction != EAST)
					temp = WEST;
				break;
			case D:
			case d:
				if (direction != WEST)
					temp = EAST;
				break;
			default:
				break;
			}
		}
		//��Ϸ���� 
		if (GetTickCount64() - timer >= (ULONGLONG)gameSpeed)
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
				break;
			}
			//����Ƿ�Ե�����
			for (std::deque<Coord>::iterator a = snack.begin() + 3; a < snack.end(); a++)
				if (a->getX() == snack.front().getX() && a->getY() == snack.front().getY()) {
					over();
					return;
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
			timer = GetTickCount64();

			//���¼Ƿְ�
			paint.consoleOutput(snackLong - 1, BLACK, BLACK, (mapW + 3) * 2, 2);
			paint.consoleOutput(std::to_string(time(0) - gameStartTime) + "s", BLACK, BLACK, (mapW + 3) * 2, 5);
			paint.consoleOutput(gameSpeed, BLACK, BLACK, (mapW + 3) * 2, 8);
		}
		//����cpuռ��
		Sleep(1);
	}
}
//��Ϸ��������
void Snack::over() {
	//�����ͼ
	clearMap();

	paint.consoleOutput("GAME OVER!!!", BLACK, HIGHLIGHT, 20, 15);
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
		foodPostiton = Coord((rand() % (mapW - 4) + 2) * 2, rand() % (mapH - 4) + 2);

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