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
	DataType _array[Max_Size];//数组存放
	int _top;//有效元素个数(表示栈顶位置)
}Stack;

//初始化
void StackInit(Stack* s);

//入栈
void StackPush(Stack* s,DataType data);

//出栈
void StackPop(Stack* s);

//获取栈顶元素
DataType StackTop(Stack* s);

//获取有效元素的个数
int StackSize(Stack* s);

//栈是否为空
int StackEmpty(Stack* s);

//打印栈
void PrintStack(Stack* s);


/////////////////////////////////////////
int IsBracket(char c);
int MatchBrackets(const char* pstr);
int CalcRPN(Cell RPN[],int size);
