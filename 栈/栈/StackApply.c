#include"stack.h"

//�ж�����ƥ������

//�Ƿ�Ϊ����
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

	//ȡiλ�õ��ַ��ж��Ƿ�Ϊ����
	for (i = 0; i < len; ++i)
	{
		//�������ţ���������ѭ��������
		if (!IsBracket(pstr[i]))
		{
			continue;
		}
		//������
		else
		{
			//�������ţ���ջ������ִ��
			if (pstr[i] == '(' || pstr[i] == '[' || pstr[i] == '{')
			{
				StackPush(&s, pstr[i]);
			}
			//��������
			else
			{
				char c;
				if (StackEmpty(&s))
				{
					printf("�����ű������Ŷ�\n");
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
						printf("���Ų�ƥ��\n");
						return 0;
					}
				}
			}
		}
	}
	if (!StackEmpty(&s))
	{
		printf("�����ű������Ŷ�\n");
		return 0;
	}
	else
	{
		printf("����ƥ����ȷ\n");
		return 1;
	}
}




//�沨�����ʽ(��׺���ʽ)
//    ��׺���ʽ  - - >    ��׺���ʽ
// 12*(3+4)-6+8/2 ���C> 12 3 4 + * 6 - 8 2 / +


int CalcRPN(Cell RPN[], int size)
{
	Stack s;
	StackInit(&s);

	for (int i = 0; i < size; i++)
	{
		//�Ƿ�Ϊ���� 
		//������ ��ջ
		if (DATA == RPN[i]._op)
			StackPush(&s, RPN[i].data);

		//�ǲ�����
		else
		{
			//ȡջ��Ԫ��->�Ҳ����� ��ջ
			DataType right = 0;
			right = StackTop(&s);
			StackPop(&s);
			//ȡջ��Ԫ��->������� ��ջ
			DataType left = 0;
			left= StackTop(&s);
			StackPop(&s);
			//���в���
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
					printf("����Ϊ0 ���Ƿ�����\n");
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
