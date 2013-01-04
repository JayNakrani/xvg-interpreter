#ifndef _CONFIG_
	#include "lib/config.h"
	#define _CONFIG_ 0
#endif
#ifndef _POINT_
	#include "lib/point.h"
	#define _POINT_ 0
#endif

#define _RECT_ 0
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