#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int SElemType;

typedef struct                    //顺序栈
{
	SElemType date[MAXSIZE];
	int top;
}SqStack;



void Catalog();                   //目录
void Push(SqStack* S, SElemType e);//入栈
void Pop(SqStack* S);             //出栈
void Print(SqStack* S);           //打印