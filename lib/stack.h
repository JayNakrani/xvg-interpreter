/*
Author 		: dj
DateTime	: 14-10-2012 10:02
Description	:
	This header file wraps the functionality of "character" stack.
	c_stack
	Properties:
		ch: pointer to char.
		top:points to top of the stack.
		max:maximum length of stack.
	Functions:
		c_stack(x)
			Constructor that creates a stack of x length.
		push
			Pushes the character specified.
		pop
			Pops the top character.
		dump
			Dumps the stack object.
*/

#ifndef _STACK_
#define _STACK_ 0

#include "config.h"
using namespace std;
class c_stack
{
	//charcter stack
	private:
		char *ch;
		int top;
		int max;
	public:
		c_stack(int x)
		{
			max=x;
			top=-1;
		}
		~c_stack(void)
		{
			
		}
		int push(char);
		char pop(void);
		void dump(void);

};
int c_stack::push(char x)
		{
			if(top>=max)
			{
				//stack overflow
				return(-1);
			}
			top++;
			ch[top]=x;
			return(top);
		}
char c_stack::pop(void)
{
		if(top<0)
		{
			//stack underflow
			return('\0');
		}
		top--;
		return(ch[top]);
}
void c_stack::dump(void)
{
	cout<<"\n::::::::::::::::::::Dumping stack::::::::::::::::::::\n";
	for(int i=0;i<top;i++)
	{
		cout<<ch[i]<<"\n";
	}
	cout<<"\n::::::::::::::::::::Dumping over::::::::::::::::::::\n";
}

#endif
