#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 500

typedef int SElemType;

typedef struct                    //˳��ջ
{
	SElemType date[MAXSIZE];
	int top;
}SqStack;



void Catalog();                   //Ŀ¼
void Push(SqStack* S, SElemType e,int b);//��ջ
void Pop(SqStack* S);             //��ջ
void Print(SqStack* S,int b);           //��ӡ