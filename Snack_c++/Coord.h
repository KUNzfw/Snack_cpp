#ifndef COORD_KUN
#define COORD_KUN
class Coord
{
private:
	int x;
	int y;
public:
	Coord();
	Coord(int x1 = 0, int y1 = 0);
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(int x1 = 0) {
		x = x1;
	}
	void setY(int y1 = 0) {
		y = y1;
	}
};


#endif // !COORD_KUN