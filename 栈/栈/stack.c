#include"stack.h"


//��ʼ��
void StackInit(Stack* s)
{
	assert(s);
	s->_top = 0;
}

//��ջ
void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_top == Max_Size)
	{
		printf("ջ��,�޷���ջ\n");
		return;
	}
	s->_array[(s->_top)++] = data;
}

//��ջ
void StackPop(Stack* s)
{
	assert(s);
	if (s->_top == 0)
	{
		printf("��ջ,�޷���ջ\n");
		return;
	}
	s->_top--;
}

//��ȡջ��Ԫ��
DataType StackTop(Stack* s)
{
	assert(s);
	if (!StackEmpty(s));
	return s->_array[s->_top-1];
}

//��ȡ��ЧԪ�صĸ���
int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

//ջ�Ƿ�Ϊ��
int StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0;//��ջ--��
	                    //�ǿ�--��
}

void PrintStack(Stack* s)
{
	assert(s);
	if (s->_top == 0)
	{
		printf("ջΪ�գ���\n");
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


