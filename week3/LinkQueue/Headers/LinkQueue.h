#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 501
typedef struct QNode
{
	void *data;
	struct QNode* next;
	int t;                                //记录数据类型1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串
}QNode,*QueuePrt;

typedef struct
{
	QueuePrt front, rear;
}LinkQueue;

void Catalog();                         //目录
void EnQueue(LinkQueue* Q, void* e,int t); //入队
void DeQueue(LinkQueue* Q);               //出队
void Print(LinkQueue* Q);           //打印