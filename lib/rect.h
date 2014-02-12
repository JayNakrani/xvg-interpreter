#ifndef _RECT_
#define _RECT_ 0

#include "config.h"
#include "point.h"

using namespace std;

class c_rect
{
	public:
		uint top;
		uint left;
		uint right;
		uint bottom;
		uint color;
		c_rect(void)
		{
		
		}
		c_rect(uint t,uint b, uint l, uint r,uint clr)
		{
			top=t;
			bottom=b;
			left=l;
			right=r;
			color=clr;
		}
		void draw(void);
};
void c_rect::draw(void)
{
	setcolor(color);
	//top edge
	line(left,top,right,top);
	//bottom edge
	line(left,bottom,right,bottom);
	//left edge
	line(left,top,left,bottom);
	//right edge
	line(right,top,right,bottom);	
}

#endif