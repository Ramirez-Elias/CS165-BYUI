#ifndef POINT_H
#define POINT_H

class Point
{
private:
	int x;
	int y;

public:
	Point () : x(5), y(5){}
	Point(int x, int y);

	void display() const;
	int getX() const;
	int getY() const;
	void setX(int);
	void setY(int);
};

#endif