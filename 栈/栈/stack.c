#include"stack.h"


//初始化
void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}

//入栈
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_top == Max_Size)
	{
		printf("栈满,无法入栈\n");
		return;
	}
	s->_array[(s->_top)++] = data;
}

//出栈
void StackPop(Stack* s)
{
	assert(s);
	if (s->_top == 0)
	{
		printf("空栈,无法出栈\n");
		return;
	}
	s->_top--;
}

//获取栈顶元素
DataType StackTop(Stack* s)
{
	assert(s);
	if (!StackEmpty(s));
	return s->_array[s->_top-1];
}

//获取有效元素的个数
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

//栈是否为空
int StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0;//空栈--真
	                    //非空--假
}

void PrintStack(Stack* s)
{
	assert(s);
	if (s->_top == 0)
	{
		printf("栈为空！！\n");
		return;
	}
	else
	{
		for (int i = 0; i < s->_top; ++i)
		{
			printf("%d  ", s->_array[i]);
		}
	}
}


