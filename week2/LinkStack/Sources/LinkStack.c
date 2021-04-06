#include"H_LinkStack.h"

void Catalog()                    //目录
{
	printf("\t\t------------------- 链栈 --------------------\n");
	printf("\t\t-------------------1.入栈--------------------\n");
	printf("\t\t-------------------2.出栈--------------------\n");
	printf("\t\t-------------------3.打印--------------------\n");
	printf("\t\t-------------------4.退出--------------------\n");
}

void Push(LinkStack* S, SElemType e)   //入栈
{
	LinkStackPt s = (LinkStackPt)malloc(sizeof(StackNode));
	s->date = e;
	s->next = S->top;
	S->top = s;
	S->cout++;
}

void Pop(LinkStack* S)             //出栈
{
	LinkStackPt p;
	if (S->cout == 0)
	{
		printf("只是一个空栈！\n");
		return;
	}
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->cout--;
}

void Print(LinkStack* S)           //打印
{
	int n;
	LinkStackPt p;
	p = S->top;
	printf("这个栈为\n");
	if (S->cout == 0)
	{
		printf("空栈\n");
		return;
	}
	for (n = 0; n < S->cout; n++)
	{
		printf("%d\n", p->date);
		p = p->next;
	}
}