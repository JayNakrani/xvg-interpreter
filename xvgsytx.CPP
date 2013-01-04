#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
#include "lib/stack.h"
#define MAX 1000
/*flags
statusFlag

	0 : initial
	1 : last symbol was '<'
	2 : last symbol was '>'
	4 : now in the attributes/in the tag
	5 : last was starting '"'
	6 : last was ending '"'


*/
void main(int argC,char *argV[])
{
	c_stack dblQuoteStack(MAX),endSymbStack(MAX);
	unsigned short int error=0;
	unsigned int chCount=0;
	int statusFlag=0;
	char c,tmpCh,prevChar;
	clrscr();
	if(argC<2)
	{
		//cmd argument is not specified. Ask for it specifically
		cout<<"\nPlease enter the relative file path:";
		cin>>argV[1];
	}
	ifstream iFile (argV[1], ios::in);
	//ofstream oFile("log.txt", ios::out);
	do
	{
		prevChar=c;
		iFile.read (&c,1);
		chCount++;
		cout<<"\n"<<c<<" : "<<statusFlag;
		switch(c)
		{
			case '<':
				endSymbStack.push('<');
				statusFlag=1;
				break;
			case '>':
				tmpCh=endSymbStack.pop();
				if(tmpCh=='\0' && prevChar!=c)
				{
					cout<<"\nError (code 0)\nAt char:"<<chCount<<"\n";
					//oFile<<"\nError (code 0)\nAt char:"<<chCount<<"\n";
					error=1;
				}
				statusFlag=2;
				break;
			case '"':
				if(statusFlag==5)
				{
					tmpCh=dblQuoteStack.pop();
					if(tmpCh=='\0')
					{
						cout<<"\nError (code 1)\nAt char:"<<chCount<<"\n";
						//oFile<<"\nError (code 1)\nAt char:"<<chCount<<"\n";
						error=1;
					}
					statusFlag=4;
				}
				else
				{
					statusFlag=5;
					dblQuoteStack.push('"');
				}
					break;
			default:
				break;
		}
	}while(!iFile.eof());
	if(error==0)
	{
		cout<<"\n\nFile was error free..!\n\n";
	}
	iFile.close();
	//oFile.close();
	getch();
}