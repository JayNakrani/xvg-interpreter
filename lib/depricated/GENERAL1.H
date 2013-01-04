#ifndef _CONFIG_
	#include "lib/config.h"
	#define _CONFIG_ 0
#endif
#ifndef _POINT_
	#include "lib/point.h"
	#define _POINT_ 0
#endif
#ifndef _LINE_
	#include "lib/line.h"
	#define _LINE_ 0
#endif
#ifndef _RECT_
	#include "lib/rect.h"
	#define _RECT_ 0
#endif
#ifndef _CIRCLE_
	#include "lib/circle.h"
	#define _CIRCLE_ 0
#endif
#ifndef _TAG_
	#include "lib/tag.h"
	#define _TAG_ 0
#endif
#ifndef _STACK_
	#include "lib/stack.h"
	#define _STACK_ 0
#endif


#define _GENERAL_ 0

void initG(void)
{
	int gdriver = DETECT, gmode, errorcode;
	clrscr();
	/* initialize graphics mode */
	initgraph(&gdriver, &gmode, "X://TC//BGI");

	/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("\nGraphics error: %s\n", grapherrormsg(errorcode));
		printf("\n\nPress any key to halt:");
		getch();
		exit(1);             /* return with error code */
	}
}


uint draw(c_tag *tagPtr)
{
	char strValue[MAX_LEN];
	usint allIsWell=0;			//flag stating if allIsWell or not, initially its not
	c_point point(0,0,0);
	c_line line(0,0,0,0,0);
	c_rect rect(0,0,0,0,0);
	c_circle circle;
	//c_ellipse ellipse(0,0,0);
	
	if(strcmp(tagPtr->tagName,"point")==0)
	{
		tagPtr->giveValue("x",strValue);
		if(*strValue!='\0')
		{
			point.x=atoi(strValue);
			allIsWell=1;
		}
		else
		{
			allIsWell=0;
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue("y",strValue);
			if(*strValue!='\0')
			{
				point.y=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue("color",strValue);
			if(*strValue!='\0')
			{
				point.color=atoi(strValue);
			}
			else
			{
				allIsWell=0;
			}
		}
		if(allIsWell==1)
		{
			//point.dump();
			point.draw();
		}
	}
	else if (strcmp(tagPtr->tagName,"line")==0)
	{
		//fetch all the necessary attribute values, ignore others
		tagPtr->giveValue("x1",strValue);
		if(*strValue!='\0')
		{
			line.p1.x=atoi(strValue);
			allIsWell=1;
		}
		else
		{
			allIsWell=0;
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue("x2",strValue);
			if(*strValue!='\0')
			{
				line.p2.x=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue("y1",strValue);
			if(*strValue!='\0')
			{
				line.p1.y=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		if(allIsWell==1)
		{
			tagPtr->giveValue("y2",strValue);
			if(*strValue!='\0')
			{
				line.p2.y=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		if(allIsWell==1)
		{
			tagPtr->giveValue("color",strValue);
			if(*strValue!='\0')
			{
				line.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		//if all is well then draw that object
		if(allIsWell==1)
		{
			line.draw();
		}
		
	}
	else if (strcmp(tagPtr->tagName,"rect")==0)
	{
		tagPtr->giveValue("top",strValue);
		if(*strValue!='\0')
		{
			rect.top=atoi(strValue);
			allIsWell=1;
		}
		else
		{
			allIsWell=0;
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue("bottom",strValue);
			if(*strValue!='\0')
			{
				rect.bottom=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue("left",strValue);
			if(*strValue!='\0')
			{
				rect.left=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		if(allIsWell==1)
		{
			tagPtr->giveValue("right",strValue);
			if(*strValue!='\0')
			{
				rect.right=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		if(allIsWell==1)
		{
			tagPtr->giveValue("color",strValue);
			if(*strValue!='\0')
			{
				rect.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		//if all is well then draw that object
		if(allIsWell==1)
		{
			rect.draw();
		}
	}
	else if(strcmp(tagPtr->tagName,"circle")==0)
	{
		//tagPtr->dump();
		tagPtr->giveValue("x",strValue);
		//cout<<"\nx:"<<strValue;
		if(*strValue!='\0')
		{
			circle.c.x=atoi(strValue);
			allIsWell=1;
		}
		else
		{
			allIsWell=0;
		}

		if(allIsWell==1)
		{
			tagPtr->giveValue("y",strValue);
			//cout<<"\ny:"<<strValue;
			if(*strValue!='\0')
			{
				circle.c.y=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}

		if(allIsWell==1)
		{
			tagPtr->giveValue("r",strValue);
			//cout<<"\nr:"<<strValue;
			if(*strValue!='\0')
			{
				circle.r=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}

		if(allIsWell==1)
		{
			tagPtr->giveValue("color",strValue);
			//cout<<"\ncolor:"<<strValue;
			if(*strValue!='\0')
			{
				circle.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		if(allIsWell==1)
		{
			circle.draw();
		}
		//getch();
		//circle.dump();
	}
	/*else if(strcmp(tagPtr->tagName,"ellipse")==0)
	{
		type=5;
	}*/
	else if(strcmp(tagPtr->tagName,"xvg")==0 || strcmp(tagPtr->tagName,"/xvg")==0)
	{
		//do nothing
	}
	else
	{
		cout<<"\ninvalid tagName..!!\n";
	}	
	return(1);
}