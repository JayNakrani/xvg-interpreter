#ifndef _CONFIG_
	#include "lib/config.h"
	#define _CONFIG_ 0
#endif
#ifndef _POINT_
	#include "lib/point.h"
	#define _POINT_ 0
#endif

#define _LINE_ 0


class c_line
{
	public:
		c_point p1;
		c_point p2;
		uint color;
		c_line()
		{
			p1.x=0;
			p1.y=0;
			p2.x=0;
			p2.y=0;
		}
		c_line(uint x1,uint y1, uint x2, uint y2,uint clr=0)
		{
			p1.x=x1;
			p1.y=y1;
			p2.x=x2;
			p2.y=y2;
			color=clr;
		}
		~c_line()
		{
			
		}
		void draw(void);
};

void c_line::draw(void)
{
	setcolor(color);
	line(p1.x,p1.y,p2.x,p2.y);
}