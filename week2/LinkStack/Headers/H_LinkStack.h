#include<stdio.h>
typedef int SElemType;
typedef struct StackNode
{
	SElemType date;
	struct StackNode* next;
}StackNode, * LinkStackPt;

typedef struct LinkStack
{
	LinkStackPt top;
	int cout;
}LinkStack;

void Catalog();                   //目录
void Push(LinkStack* S, SElemType e);//入栈
void Pop(LinkStack* S);             //出栈
void Print(LinkStack* S);           //打印