#ifndef _POINT_
#define _POINT_ 0

#include "config.h"
using namespace std; 

class c_point
{
public:
	uint x;
	uint y;
	uint color; 
	c_point(uint a, uint b,uint clr=0)
	{
		this->x = a;
		this->y = b;
		color = clr;
	}
	c_point()
	{
		this->x = 0;
		this->y = 0;
		this->color = 0;
	}
	~c_point()
	{
	}
	uint getX(void);
	uint getY(void);
	void setX(uint a);
	void setY(uint a);
	void shiftOrigin(void);
	void draw(void);
	void dump(void);
};

uint c_point::getX(void)
{
	return(this->x);
}
uint c_point::getY(void)
{
	return(this->y);
}
void c_point::setX(uint a)
{
	this->x = a;
}
void c_point::setY(uint a)
{
	this->y = a;
}
void c_point::shiftOrigin(void)
{
	this->x += (int(float(getmaxx())/2.0));
	this->y = (int(float(getmaxy())/2.0))-(this->y);
}
void c_point::draw(void)
{
	putpixel(x,y,color);
}
void c_point::dump(void)
{
	cout << "\n::::::::::::::::::::Dumping::::::::::::::::::::\n";
	cout << "x:" << x << "\ty" << y << "\tcolor:" << color;
	cout << "\n:::::::::::::::::::::Over::::::::::::::::::::::\n";
}

#endif