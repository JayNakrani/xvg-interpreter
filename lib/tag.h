/**
 *
 * Author 		: dj
 * DateTime		: 22-10-2012 22:08
 * Description	:
 *	This header file is for tags. All xvg tags can have diifferent different attributes and values. This header file declares a class 'c_tag' that wraps around all the functionalities of it.
 *	c_tag
 *	Properties:
 *		tagName: Holds the string of tag name.
 *		attribute: Array that holds attribute names
 *		attributeValue:Array that holds attribute values.
 *		attributeCount:unsigned int indicating number of attributes.
 *	Functions:
 *		giveValue(attributeName,valueStr)
 *			Gives value in valueStr corrosponding to the 'attributeName'.
 *			If value not found then assigns "\0".
 *		dump()
 *			Dumps the object.
 */

#ifndef _TAG_
#define _TAG_ 0

#include "config.h"
#include "point.h"	
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"

#define MAX_LEN 20
class c_tag
{
	public:
		char tagName[MAX_LEN];
		char attribute[MAX_LEN][MAX_LEN];
		char attributeValue[MAX_LEN][MAX_LEN];
		uint attributeCount;
		c_tag(void)
		{
			*tagName='\0';
			**attribute='\0';
			**attributeValue='\0';
			attributeCount=0;
		}
		void giveValue(char *attributeName,char *value);
		void dump(void);
		void reinit(void);
};

void c_tag::giveValue(char *attributeName,char *value)
{
	if(tagName=='\0')
	{
		cout<<"uninitilized tagName";
		getch();
	}
	uint i=0,valueSetFlag=0;
	for(i=0;i<attributeCount;i++)
	{
		//cout<<"\narg:"<<attributeName<<"localValue"<<attribute[i];
		if(strcmp(attributeName,attribute[i])==0)
		{
			strcpy(value,attributeValue[i]);
			valueSetFlag=1;			//setting the flag
		}
	}
	//cout<<"\n\nvalue:"<<value<<"flag"<<valueSetFlag;
	if(valueSetFlag!=1)
	{
		//value not found..!!
		strcpy(value,"\0");
	}
}

void c_tag::dump(void)
{
	uint i=0;
	cout<<"\n::::::::::::::::::::Dumping::::::::::::::::::::\ntagName:"<<tagName;
	for(i=0;i<attributeCount;i++)
	{
		cout<<"\n"<<(i+1)<<" : "<<attribute[i]<<" : "<<attributeValue[i];
	}
	cout<<"\n:::::::::::::::::::::Over::::::::::::::::::::::\n";
}
void c_tag::reinit(void)
{
	*tagName='\0';
	**attribute='\0';
	**attributeValue='\0';
	attributeCount=0;
}

#endif

