#include "config.h"
#include "stack.h"

int main(void)
{
	c_stack stack(10);
	stack.push('A');
	stack.push('B');
	stack.push('C');
	stack.push('D');
	stack.dump();
	cout << stack.pop();

	return 0;
}