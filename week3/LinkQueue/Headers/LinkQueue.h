#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 501
typedef struct QNode
{
	void *data;
	struct QNode* next;
	int t;                                //��¼��������1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���
}QNode,*QueuePrt;

typedef struct
{
	QueuePrt front, rear;
}LinkQueue;

void Catalog();                         //Ŀ¼
void EnQueue(LinkQueue* Q, void* e,int t); //���
void DeQueue(LinkQueue* Q);               //����
void Print(LinkQueue* Q);           //��ӡ