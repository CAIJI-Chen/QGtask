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

void Catalog();                   //Ŀ¼
void Push(LinkStack* S, SElemType e);//��ջ
void Pop(LinkStack* S);             //��ջ
void Print(LinkStack* S);           //��ӡ