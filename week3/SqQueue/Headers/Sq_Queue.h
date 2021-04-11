#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 501
typedef struct
{
	void* data[MAXSIZE];
	int front;
	int rear;
	int t[MAXSIZE];                                //记录数据类型1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串
}SqQueue;

void Catalog();                         //目录
void Init(SqQueue* Q, int n);           //初始化
void EnQueue(SqQueue* Q, void* e, int n); //入队
void DeQueue(SqQueue* Q, int n);               //出队
void Print(SqQueue* Q, int n);           //打印