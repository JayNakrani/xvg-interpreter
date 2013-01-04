#ifndef _CONFIG_
	#include "lib/config.h"
	#define _CONFIG_ 0
#endif
#ifndef _POINT_
	#include "lib/point.h"
	#define _POINT_ 0
#endif

#define _ELLIPSE_ 0

class c_ellipse
{
	public:
		c_point c;
		uint rx;
		uint ry;
		uint startAngle;
		uint endAngle;
		uint color;
		c_ellipse(uint x=0,uint y=0, uint stAngle=0,uint endAngle=0,uint xR=0, uint yR=0,uint clr=0)
		{
			c.x=x;
			c.y=y;
			rx=xR;
			ry=yR;
			startAngle=stAngle;
			endAngle=endAngle;
			color=clr;
		}
		~c_ellipse()
		{
		}
		void draw(void);
};
void c_ellipse::draw(void)
{

	setcolor(color);
	ellipse(c.x,c.y,startAngle,endAngle,rx,ry);
}