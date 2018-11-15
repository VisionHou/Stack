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
	printf("ջ��Ԫ����%d\n", StackTop(&s));

	printf("ջ��Ԫ�ظ�����%d\n", StackSize(&s));

	int ret = StackEmpty(&s);
	if(ret==0)
		printf("ջ���ǿ�ջ\n");
	else
		printf("ջ���ǿ�ջ\n");

}

void TestMatch()
{
	char a[] = "(())abc{[(])}";  // ƥ�䲻��ȷ
	char b[] = "(()))abc{[]}";   // �����Ŷ�
	char c[] = "(()()abc{[]}";   // �����Ŷ�
	char d[] = "(())abc{[]()}";  // ƥ����ȷ
	MatchBrackets(a);
	MatchBrackets(b);
	MatchBrackets(c);
	MatchBrackets(d);
}

void TestRPN()
{
	// 12*(3+4)-6+8/2 ���C> 12 3 4 + * 6 - 8 2 / +
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