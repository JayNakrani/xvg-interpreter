unsigned int draw(c_tag *tagPtr)
{
	char strValue[MAX_LEN];
	c_point point(0,0);
	c_circle circle(0,0,0);
	c_rect rectangle(0,0,0,0);
	c_ellipse ellipse(0,0,0);
	if(strcmp(tagPtr->tagName,"point")==0)
	{
		tagPtr->giveValue("x",strValue);
		if(*strValue!='\0')
		{
			point.x=atoi(strValue);
		}
		else
		{
			break;
		}
		
		tagPtr->giveValue("y",strValue);
		if(*strValue!='\0')
		{
			point.y=atoi(strValue);
		}
		else
		{
			break;
		}
		
		tagPtr->giveValue("color",strValue);
		if(*strValue!='\0')
		{
			point.color=atoi(strValue);
		}
		else
		{
			break;
		}
		point.draw();
	}
	else if (strcmp(tagPtr->tagName,"line")==0)
	{
		
	}
	else if (strcmp(tagPtr->tagName,"rect")==0)
	{
		type=3;
	}
	else if(strcmp(tagPtr->tagName,"circle")==0)
	{
		type=4;
	}
	else if(strcmp(tagPtr->tagName,"ellipse")==0)
	{
		type=5;
	}
	else
	{
		type=0;
	}	