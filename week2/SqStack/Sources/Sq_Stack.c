#include"SqStack.h"
void Catalog()                    //Ŀ¼
{
	printf("\t\t-------------------˳��ջ--------------------\n");
	printf("\t\t-------------------1.��ջ--------------------\n");
	printf("\t\t-------------------2.��ջ--------------------\n");
	printf("\t\t-------------------3.��ӡ--------------------\n");
	printf("\t\t-------------------4.�˳�--------------------\n");
}

void Push(SqStack* S, SElemType e)//��ջ
{
	if (S->top - 1 == MAXSIZE)
	{
		printf("�ֵܣ�ջ���ˣ�\n");
		return;
	}
	S->top++;
	S->date[S->top] = e;
	printf("��������ӣ�\n");
	return;
}

void Pop(SqStack* S)//��ջ
{
	if (S->top == -1)
	{
		printf("�ֵܣ����Ѿ��ǿ�ջ�ˣ�\n");
		return;
	}
	S->date[S->top] == 0;
	S->top--;
	printf("ջ��������ɾ����\n");
	return;
}

void Print(SqStack* S)
{
	int n;
	printf("���ջΪ\n");
	if (S->top == -1)
	{
		printf("��ջ\n");
		return;
	}
	for (n = 0; n < S->top + 1; n++)
	{
		printf("%d\n", S->date[n]);
	}
}