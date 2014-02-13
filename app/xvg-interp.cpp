#include "../lib/tag.h"
#include "../lib/common.h"

using namespace std;

/*flags
statusFlag

	0 : initial
	1 : last symbol was '<'
	2 : last symbol was '>'
	4 : now in the attributes/in the tag
	5 : last was starting '"'
	6 : last was ending '"'
	7 : comments


*/
int main(int argC, char *argV[])
{
	c_stack endSymbStack(MAXIMUM);
	c_tag tag;
	usint  statusFlag=0;
	ifstream iFile;
	int chCount=0,tagNameCount=0,attributeNameCount=0,attributeValueCount,attributeGlbCount=0;
	char c='\0',tmpCh='\0',prevChar='\0';
	char *tagName,*attributeName,*attributeValue;

#ifdef _DEBUG_FLAG_
	ofstream oFile;
	time_t rawtime;
	struct tm * timeinfo;
#endif

	/* Allocate memories */
	attributeName = new char[MAXIMUM];
	tagName = new char[MAXIMUM];
	attributeValue = new char[MAXIMUM];
	
	if(argC<2)
	{
		cout<<"\nTarget file missing..!!\nPlease enter relative path here:";
		cin>>argV[1];
	}

	iFile.open(argV[1],ios::in);
	#ifdef _DEBUG_FLAG_	
		oFile.open("log/log.txt",ios::out|ios::ate);
		oFile<<"\n----------------------------------------------------------------------------------------------\n";
		oFile<<"\nFile:"<<argV[1];
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		oFile<<"\nStarting time:"<<asctime(timeinfo)<<"\t(in milliseconds from 1st January,1971 : "<<rawtime<<")";
	#endif


	if(!iFile.is_open())
	{
		cout<<"\nError::Could not open target file";
		exit(1);
	}
	
	
	initG();


	while(!iFile.eof())
	{
		prevChar=c;
		iFile.read (&c,1);
		chCount++;
		if(statusFlag!=7)
		{
			switch(c)
			{
				case '<':
					endSymbStack.push(c);
					if(iFile.peek() != '/')
					{
						statusFlag=1;
					}
					else
					{
						statusFlag=3;
					}
					break;
				case '>':
					tmpCh=endSymbStack.pop();
					if(prevChar != c)
					{
						if(tmpCh=='\0')
						{
							cout<<"\nError (code 0)\nAt char:"<<chCount<<"\n";
						}
					}

					#ifdef _DEBUG_FLAG_
						draw(&tag,&oFile);
					#else
						draw(&tag);
					#endif

					attributeGlbCount=0;
					statusFlag=0;
					break;
				case ' ':
					//do nothing, just ignore it.
					break;
				default:
					//check is any other then special symbols
					switch(statusFlag)
					{
						case 0:
							break;
						case 1:
							//fetching the tagName
							tagNameCount=0;
							tag.tagName[tagNameCount++]=c;
							do
							{
								iFile.read (&tmpCh,1);
								chCount++;
								tag.tagName[tagNameCount++]=tmpCh;
							}while(tmpCh!=' ');
							tag.tagName[tagNameCount-1]='\0';
							statusFlag=4;
							break;
						case 2:
							break;
						case 3:
							break;
						case 4:
							//fetching the attributeName
							attributeNameCount=0;
							if(c!=' ')
								attributeName[attributeNameCount++]=c;
							do
							{
								iFile.read (&tmpCh,1);
								chCount++;
								attributeName[attributeNameCount++]=tmpCh;
							}while(tmpCh!='"');
							//ignoring the ending = and " both
							attributeName[attributeNameCount-2]='\0';
							strcpy(tag.attribute[attributeGlbCount],attributeName);
							statusFlag=5;
							break;
						case 5:
							//fetching the attributeValue
							attributeValueCount=0;
							attributeValue[attributeValueCount++]=c;
							do
							{
								iFile.read (&tmpCh,1);
								chCount++;
								attributeValue[attributeValueCount++]=tmpCh;
							}while(tmpCh!='"');
							attributeValue[attributeValueCount-1]='\0';
							strcpy(tag.attributeValue[attributeGlbCount],attributeValue);
							statusFlag=4;
							tag.attributeCount=++attributeGlbCount;
							break;
						default:
							break;
					}
					break;
			}
		}

	}

	/* Debugging code. */
	#ifdef _DEBUG_FLAG_	
		oFile<<"\n\t\tTotal characters in file:"<<chCount;
		time ( &rawtime );
		timeinfo = localtime ( &rawtime );
		oFile<<"\nEnding time:"<<asctime(timeinfo)<<"\t(in milliseconds from 1st January,1971 : "<<rawtime<<")";
		oFile<<"\n----------------------------------------------------------------------------------------------\n";
		iFile.close();
		oFile.close();
	#endif

	getch();
	closegraph();
	return(0);
}