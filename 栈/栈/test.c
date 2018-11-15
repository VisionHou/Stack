#include"stack.h"

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	PrintStack(&s);
	printf("\n");

	StackPop(&s);
	PrintStack(&s);

	printf("\n");
	printf("栈顶元素是%d\n", StackTop(&s));

	printf("栈中元素个数是%d\n", StackSize(&s));

	int ret = StackEmpty(&s);
	if(ret==0)
		printf("栈不是空栈\n");
	else
		printf("栈不是空栈\n");

}

void TestMatch()
{
	char a[] = "(())abc{[(])}";  // 匹配不正确
	char b[] = "(()))abc{[]}";   // 右括号多
	char c[] = "(()()abc{[]}";   // 坐括号多
	char d[] = "(())abc{[]()}";  // 匹配正确
	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
}

void TestRPN()
{
	// 12*(3+4)-6+8/2 —–> 12 3 4 + * 6 - 8 2 / +
	Cell RPN[] = { {DATA, 12},{DATA, 3}, {DATA, 4}, {ADD, 0},
				  {MUL,   0},{DATA, 6}, {SUB,  0}, {DATA, 8},
				  {DATA,  2},{DIV,  0}, {ADD,  0} };

	printf("%d\n", CalcRPN(RPN, sizeof(RPN) / sizeof(RPN[0])));

}
int main()
{
	//TestStack();
	//TestMatch();
	TestRPN();
	system("pause");
	return 0;
}