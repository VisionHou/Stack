#include<stdio.h>
#include<assert.h>
#include<windows.h>
#include<string.h>

#define Max_Size 100

typedef int DataType;

typedef enum { ADD, SUB, MUL, DIV, DATA }Operator;
typedef struct Cell
{
	Operator _op;
	int data;
}Cell;

typedef struct Stack
{
	DataType _array[Max_Size];//������
	int _top;//��ЧԪ�ظ���(��ʾջ��λ��)
}Stack;

//��ʼ��
void StackInit(Stack* s);

//��ջ
void StackPush(Stack* s,DataType data);

//��ջ
void StackPop(Stack* s);

//��ȡջ��Ԫ��
DataType StackTop(Stack* s);

//��ȡ��ЧԪ�صĸ���
int StackSize(Stack* s);

//ջ�Ƿ�Ϊ��
int StackEmpty(Stack* s);

//��ӡջ
void PrintStack(Stack* s);


/////////////////////////////////////////
int IsBracket(char c);
int MatchBrackets(const char* pstr);
int CalcRPN(Cell RPN[],int size);
