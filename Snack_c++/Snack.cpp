#include "Snack.h"

using namespace kun;


void Snack::init() {
	selection();
}
void Snack::selection() {
	//重置
	clearMap();
	paint.setCursorPosition(0, 0);
	//清除计分板
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

	//绘制地图方框
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
	paint.setCursorPosition(0, 0);
	//选项列表
	Selection selec = Selection();
	selec.addSelection("Start", mapW - 5, mapH / 3 * 1, 0);
	selec.addSelection("End", mapW - 5, mapH / 3 * 2, 1);
	selec.show();
	switch (selec.waitForChoose())
	{
	case 0:
		start();
		return;
		break;
	case 1:
		system("exit");
	}
}
//游戏开始
void Snack::start() {

	//清除地图
	clearMap();

	bool food = true;

	//绘制第一段蛇身
	snack.push_front(Coord(30, 15));
	paint.consoleOutput("  ", GREEN, BLACK, snack.front());

	//初始化计时器
	ULONGLONG timer = GetTickCount64();
	time_t gameStartTime = time(0);
	//初始化食物
	genFood();
	//临时变量
	Direction temp = (Direction)direction;

	//设置记分板
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
		//检测键盘事件
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
		//游戏更新 
		if (GetTickCount64() - timer >= (ULONGLONG)gameSpeed)
		{
			direction = temp;

			switch (direction)
			{
			case NORTH:
				//更新头部
				snack.push_front(Coord(snack.front().getX(), snack.front().getY() - 1));
				paint.consoleOutput("  ", GREEN, HIGHLIGHT, snack.front());
				//检测是否吃到food，如果吃到就不清除尾巴
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
			//更新时间
			timer = GetTickCount64();
			//检测是否吃到身体
			for (std::deque<Coord>::iterator a = snack.begin() + 3; a < snack.end(); a++)
				if (a->getX() == snack.front().getX() && a->getY() == snack.front().getY()) {
					over();
					return;
				}
			//检测是否撞墙
			if (snack.front().getX() == 2 || snack.front().getX() == mapW * 2 - 2 || snack.front().getY() == 0 || snack.front().getY() == mapH - 1) {
				//清除蛇头
				paint.consoleOutput("  ", WHITE, HIGHLIGHT, snack.front());

				over();
				return;
			}

			//重新生成food
			if (!food)
			{
				genFood();
				food = true;
			}

			

			//更新记分板
			paint.consoleOutput(snackLong - 1, BLACK, BLACK, (mapW + 3) * 2, 2);
			paint.consoleOutput(std::to_string(time(0) - gameStartTime) + "s", BLACK, BLACK, (mapW + 3) * 2, 5);
			paint.consoleOutput(gameSpeed, BLACK, BLACK, (mapW + 3) * 2, 8);
		}
		//减少cpu占用
		Sleep(1);
	}
}
//游戏结束界面
void Snack::over() {
	//清除地图
	clearMap();
	paint.consoleOutput("GAME OVER!!!", BLACK, HIGHLIGHT, mapW - 7, mapH / 5);
	//清除蛇的链表
	snack.clear();
	//绘制菜单
	Selection selec = Selection();
	selec.addSelection("Restart", mapW - 5, mapH / 5 * 3, 0);
	selec.addSelection("Back", mapW - 5, mapH / 5 * 4, 1);
	selec.show();
	switch (selec.waitForChoose())
	{
	case  0:
		//清除计分板
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

		start();
		return;
	case 1:
		selection();
		return;
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
	//循环结束判断条件
	bool isEnd = true;

	do
	{
		//随机生成food位置
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