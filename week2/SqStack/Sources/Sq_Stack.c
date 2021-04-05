#include"SqStack.h"
void Catalog()                    //目录
{
	printf("\t\t-------------------顺序栈--------------------\n");
	printf("\t\t-------------------1.入栈--------------------\n");
	printf("\t\t-------------------2.出栈--------------------\n");
	printf("\t\t-------------------3.打印--------------------\n");
	printf("\t\t-------------------4.退出--------------------\n");
}

void Push(SqStack* S, SElemType e)//入栈
{
	if (S->top - 1 == MAXSIZE)
	{
		printf("兄弟，栈满了！\n");
		return;
	}
	S->top++;
	S->date[S->top] = e;
	printf("数据已添加！\n");
	return;
}

void Pop(SqStack* S)//出栈
{
	if (S->top == -1)
	{
		printf("兄弟，这已经是空栈了！\n");
		return;
	}
	S->date[S->top] == 0;
	S->top--;
	printf("栈顶数据已删除！\n");
	return;
}

void Print(SqStack* S)
{
	int n;
	printf("这个栈为\n");
	if (S->top == -1)
	{
		printf("空栈\n");
		return;
	}
	for (n = 0; n < S->top + 1; n++)
	{
		printf("%d\n", S->date[n]);
	}
}