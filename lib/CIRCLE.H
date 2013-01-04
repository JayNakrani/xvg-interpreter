#ifndef _CONFIG_
	#include "lib/config.h"
	#define _CONFIG_ 0
#endif
#ifndef _POINT_
	#include "lib/point.h"
	#define _POINT_ 0
#endif

#define _CIRCLE_ 0

class c_circle
{
	public:
		c_point c;
		uint r;
		uint color;
		c_circle(c_point x,uint h,uint clr=0)
		{
			c=x;
			r=h;
			color=clr;
		}
		c_circle(void)
		{
			c.x=0;
			c.y=0;
			r=0;
			color=0;
		}
		~c_circle()
		{

		}
		void setCenter(int x,int y);
		void setRadius(uint x);
		uint getRadius(void);
		c_point getCenter(void);
		uint draw(void);
		void dump(void);
};

void c_circle::setCenter(int x,int y)
{
	c.setX(x);
	c.setY(y);
}
void c_circle::setRadius(uint x)
{
	r=x;
	cout<<c.getX()<<"  "<<c.getY();
}
uint c_circle::getRadius(void)
{
	return(r);
}
c_point c_circle:: getCenter(void)
{
	return(c);
}
uint c_circle::draw(void)
{
	setcolor(color);
	circle(c.x,c.y,r);
	return(1);
}
void c_circle::dump(void)
{
	cout<<"\n::::::::::::::::::::Dumping::::::::::::::::::::\n";
	cout<<"x:"<<c.x<<"\ty"<<c.y<<"\tr:"<<r<<"\tcolor:"<<color;
	cout<<"\n:::::::::::::::::::::Over::::::::::::::::::::::\n";
}