#include"H_LinkStack.h"

void Catalog()                    //Ŀ¼
{
	printf("\t\t------------------- ��ջ --------------------\n");
	printf("\t\t-------------------1.��ջ--------------------\n");
	printf("\t\t-------------------2.��ջ--------------------\n");
	printf("\t\t-------------------3.��ӡ--------------------\n");
	printf("\t\t-------------------4.�˳�--------------------\n");
}

void Push(LinkStack* S, SElemType e)   //��ջ
{
	LinkStackPt s = (LinkStackPt)malloc(sizeof(StackNode));
	s->date = e;
	s->next = S->top;
	S->top = s;
	S->cout++;
}

void Pop(LinkStack* S)             //��ջ
{
	LinkStackPt p;
	if (S->cout == 0)
	{
		printf("ֻ��һ����ջ��\n");
		return;
	}
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->cout--;
}

void Print(LinkStack* S)           //��ӡ
{
	int n;
	LinkStackPt p;
	p = S->top;
	printf("���ջΪ\n");
	if (S->cout == 0)
	{
		printf("��ջ\n");
		return;
	}
	for (n = 0; n < S->cout; n++)
	{
		printf("%d\n", p->date);
		p = p->next;
	}
}