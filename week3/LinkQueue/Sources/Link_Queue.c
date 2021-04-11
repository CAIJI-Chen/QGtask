#include"LinkQueue.h"


void Catalog()
{
	printf("--------------------1.打印-----------------\n");
	printf("--------------------2.入队-----------------\n");
	printf("--------------------3.出队-----------------\n");
	printf("--------------------4.退出-----------------\n");
}


void EnQueue(LinkQueue* Q, void* e,int t)
{
	QueuePrt s = (QueuePrt)malloc(sizeof(QNode));
	if (t == 1) { int b = *(int*)e; s->data = b; }
	else if (t == 2) { char b = *(char*)e; s->data = b; }
	else if (t == 3) { double b = *(double*)e; s->data = (void*)malloc(8); memcpy(s->data, e, sizeof(b)); }
	//else if (Q->rear->t == 4) { char b[20] = { '0' }; Q->data[Q->rear] = b; memcpy(Q->data[Q->rear], e, sizeof(b)); }
	s->next = NULL;
	s->t = t;
	Q->rear->next = s;
	Q->rear = s;

	return;
}

void DeQueue(LinkQueue* Q)
{
	QueuePrt p;
	if (Q->front == Q->rear)
	{
		printf("此队列已空！\n");
		return;
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);

	return;
}

void Print(LinkQueue* Q)
{
	QueuePrt p;
	p = Q->front->next;
	if (Q->rear == Q->front)
	{
		printf("这是空的队列\n");
		return;
	}
	while (p != NULL)
	{
		int t = p->t;
		switch (t)
		{
		case (1):
			printf("%d", p->data);
			break;
		case (2):
			printf("%c", p->data);
			break;
		case (3):
			printf("%-7.2lf", *(double*)p->data);
			break;
			//case (4):
				//printf("%s",  (char*));
			break;

		}
		printf("\t");
		p = p->next;

	}
	printf("\n");

}