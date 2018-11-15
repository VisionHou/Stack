#include"stack.h"

//判断括号匹配问题

//是否为括号
int IsBracket(char c)
{
	if (c == '(' || c == ')' ||
		c == '[' || c == ']' ||
		c == '{' || c == '}')
		return 1;
	else
		return 0;
}

int MatchBrackets(const char* pstr)
{
	int i = 0;
	int len = 0;
	Stack s;

	if (pstr == NULL)
		return 0;

	len = strlen(pstr);
	StackInit(&s);

	//取i位置的字符判断是否为括号
	for (i = 0; i < len; ++i)
	{
		//不是括号，跳过本次循环，继续
		if (!IsBracket(pstr[i]))
		{
			continue;
		}
		//是括号
		else
		{
			//是左括号：入栈，继续执行
			if (pstr[i] == '(' || pstr[i] == '[' || pstr[i] == '{')
			{
				StackPush(&s, pstr[i]);
			}
			//是右括号
			else
			{
				char c;
				if (StackEmpty(&s))
				{
					printf("右括号比左括号多\n");
					return 0;
				}
				else
				{
					c = StackTop(&s);
					if (('(' == c && ')' == pstr[i]) ||
						('[' == c && ']' == pstr[i]) ||
						('{' == c && '}' == pstr[i]))

					{
						StackPop(&s);
					}
					else
					{
						printf("括号不匹配\n");
						return 0;
					}
				}
			}
		}
	}
	if (!StackEmpty(&s))
	{
		printf("左括号比右括号多\n");
		return 0;
	}
	else
	{
		printf("括号匹配正确\n");
		return 1;
	}
}




//逆波兰表达式(后缀表达式)
//    中缀表达式  - - >    后缀表达式
// 12*(3+4)-6+8/2 —–> 12 3 4 + * 6 - 8 2 / +


int CalcRPN(Cell RPN[], int size)
{
	Stack s;
	StackInit(&s);

	for (int i = 0; i < size; i++)
	{
		//是否为数字 
		//是数字 入栈
		if (DATA == RPN[i]._op)
			StackPush(&s, RPN[i].data);

		//是操作符
		else
		{
			//取栈顶元素->右操作数 出栈
			DataType right = 0;
			right = StackTop(&s);
			StackPop(&s);
			//取栈顶元素->左操作数 出栈
			DataType left = 0;
			left= StackTop(&s);
			StackPop(&s);
			//进行操作
			switch (RPN[i]._op)
			{
			case ADD:
				StackPush(&s, left + right);
				break;
			case SUB:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left * right);
				break;
			case DIV:
				if (right == 0)
				{
					printf("除数为0 ，非法操作\n");
					return 0;
				}
				else
				{
					StackPush(&s, left / right);
					break;
				}
			}
		}
	}
	return StackTop(&s);
}
