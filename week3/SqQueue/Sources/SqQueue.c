#include"Sq_Queue.h"


void Catalog()
{
	printf("--------------------1.打印-----------------\n");
	printf("--------------------2.入队-----------------\n");
	printf("--------------------3.出队-----------------\n");
	printf("--------------------4.退出-----------------\n");
}

void Init(SqQueue* Q, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		Q->data[i] = (void*)malloc(20);
	}
	Q->front = 0;
	Q->rear = 0;
}

void EnQueue(SqQueue* Q, void* e, int n)
{
	if ((Q->rear + 1) % n == Q->front)
	{
		printf("你的队列满了\n");
		return;
	}

	if (Q->t[Q->rear] == 1) { int b = *(int*)e; Q->data[Q->rear] = b; }
	else if (Q->t[Q->rear] == 2) { char b = *(char*)e; Q->data[Q->rear] = b; }
	else if (Q->t[Q->rear] == 3) { double b = *(double*)e; Q->data[Q->rear] = (void*)malloc(8); memcpy(Q->data[Q->rear], e, sizeof(b)); }
	//else if (Q->t[Q->rear] == 4) { char b[20] = { '0' }; Q->data[Q->rear] = b; memcpy(Q->data[Q->rear], e, sizeof(b)); }

	Q->rear = (Q->rear + 1) % n;
	return;
}

void DeQueue(SqQueue* Q, int n)
{
	if (Q->front == Q->rear)
	{
		printf("此队列已空！\n");
		return;
	}
	Q->front = (Q->front + 1) % n;
	return;
}

void Print(SqQueue* Q, int n)
{
	int i = 1;
	int j = Q->front;
	if (Q->rear == Q->front)
	{
		printf("这是空的队列\n");
		return;
	}
	while (j != Q->rear)
	{
		int t = Q->t[j];
		switch (t)
		{
		case (1):
			printf("%d", Q->data[j]);
			break;
		case (2):
			printf("%c", Q->data[j]);
			break;
		case (3):
			printf("%-7.2lf", *(double*)Q->data[j]);
			break;
			//case (4):
				//printf("%s",  (char*)Q->data[j]);
			break;

		}
		printf("\t");
		j++;
		if (j >= n) j = j % n;

	}
	printf("\n");

}