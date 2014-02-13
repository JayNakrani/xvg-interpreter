#ifndef _COMMON_
#define _COMMON_ 0

#include "config.h"
#include "point.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"
#include "tag.h"
#include "stack.h"

#define MAXIMUM 1000

using namespace std;

//global params for whole xvg drawing
uint defaultColor=4;	//by default red
uint bgCol=15;			//by default white

uint colorAdjust(int color)
{
	if(color<0)
	{
		//making the color positive
		color*=(-1);
	}
	
	if(color>15)
	{
		color%=16;
	}
	return(color);
}

void initG(void)
{
	int gdriver = DETECT, gmode, errorcode;
	
	/* initialize graphics mode */
	initgraph(&gdriver, &gmode, NULL);

	// /* read result of initialization */
	// errorcode = graphresult();
	// if (errorcode != grOk)  /* an error occurred */
	// {
	// 	printf("\nGraphics error: %s\n", grapherrormsg(errorcode));
	// 	printf("\n\nPress any key to halt:");
	// 	getch();
	// 	exit(1);             /* return with error code */
	// }
}

#ifdef _DEBUG_FLAG_
	uint draw(c_tag *tagPtr,ofstream *oFile)
#else
	uint draw(c_tag *tagPtr)
#endif
{
	char strValue[MAX_LEN];
	usint allIsWell=0;			//flag stating if allIsWell or not, initially its not
	c_line line(0,0,0,0,0);
	c_rect rect(0,0,0,0,0);
	c_circle circle;
	if(strcmp(tagPtr->tagName,"point")==0)
	{
		//fetch all the necessary attribute values, ignore others
		c_point point(0,0,0);
		tagPtr->giveValue((char *)"x",strValue);
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
			tagPtr->giveValue((char *)"y",strValue);
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
			tagPtr->giveValue((char *)"color",strValue);
			if(*strValue!='\0')
			{
				point.color=atoi(strValue);
			}
			else
			{
				point.color=defaultColor;
			}
		}
		if(allIsWell==1)
		{
			point.draw();
		}
	}
	else if (strcmp(tagPtr->tagName,"line")==0)
	{
		//fetch all the necessary attribute values, ignore others
		tagPtr->giveValue((char *)"x1",strValue);
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
			tagPtr->giveValue((char *)"x2",strValue);
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
			tagPtr->giveValue((char *)"y1",strValue);
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
			tagPtr->giveValue((char *)"y2",strValue);
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
			tagPtr->giveValue((char *)"color",strValue);
			if(*strValue!='\0')
			{
				line.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				line.color=defaultColor;
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
		tagPtr->giveValue((char *)"top",strValue);
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
			tagPtr->giveValue((char *)"bottom",strValue);
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
			tagPtr->giveValue((char *)"left",strValue);
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
			tagPtr->giveValue((char *)"right",strValue);
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
			tagPtr->giveValue((char *)"color",strValue);
			if(*strValue!='\0')
			{
				rect.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				rect.color=defaultColor;
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
		tagPtr->giveValue((char *)"x",strValue);
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
			tagPtr->giveValue((char *)"y",strValue);
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
			tagPtr->giveValue((char *)"r",strValue);
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
			tagPtr->giveValue((char *)"color",strValue);
			if(*strValue!='\0')
			{
				circle.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				circle.color=defaultColor;
			}
		}
		if(allIsWell==1)
		{
			circle.draw();
		}	
	}
	else if(strcmp(tagPtr->tagName,"ellipse")==0)
	{
		c_ellipse ellipse;
		tagPtr->giveValue((char *)"x",strValue);
		if(*strValue!='\0')
		{
			ellipse.c.x=atoi(strValue);
			allIsWell=1;
		}
		else
		{
			allIsWell=0;
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue((char *)"y",strValue);
			if(*strValue!='\0')
			{
				ellipse.c.y=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue((char *)"rx",strValue);
			if(*strValue!='\0')
			{
				ellipse.rx=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue((char *)"ry",strValue);
			if(*strValue!='\0')
			{
				ellipse.ry=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue((char *)"start",strValue);
			if(*strValue!='\0')
			{
				ellipse.startAngle=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue((char *)"end",strValue);
			if(*strValue!='\0')
			{
				ellipse.endAngle=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				allIsWell=0;
			}
		}
		
		if(allIsWell==1)
		{
			tagPtr->giveValue((char *)"color",strValue);
			if(*strValue!='\0')
			{
				ellipse.color=atoi(strValue);
				allIsWell=1;
			}
			else
			{
				ellipse.color=defaultColor;
			}
		}
		if(allIsWell==1)
		{
			ellipse.draw();
		}	
	}
	else if(strcmp(tagPtr->tagName,"xvg")==0)
	{
		char tmpStr[20]={'\0'};
		//assign the golbal params
		tagPtr->giveValue((char *)"color",strValue);
		if(*strValue!='\0')
		{
			defaultColor=atoi(strValue);
			// no allIsWell because optional params
		}
		
		tagPtr->giveValue((char *)"bgColor",strValue);
		if(*strValue!='\0')
		{
			bgCol=atoi(strValue);
		}
		//setting the bg color of whole vector image
		setbkcolor(bgCol);
		
		tagPtr->giveValue((char *)"version",strValue);
		if(*strValue!='\0')
		{
			//displaying the version on the top-right corner of the window
			*oFile<<"\n\t\tVersion:"<<strValue;
			if(bgCol==getcolor())
				setcolor(bgCol+1);
			sprintf(tmpStr,"Version:%s",strValue);
			outtextxy(5,5,tmpStr);
		}
	}
	else if(strcmp(tagPtr->tagName,"/xvg")==0)
	{
		//do nothing
	}
	else
	{
		cout<<"\ninvalid tagName..!!\n";
		return(1);
	}
	return(0);
}

#endif