#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 501
typedef struct
{
	void* data[MAXSIZE];
	int front;
	int rear;
	int t[MAXSIZE];                                //��¼��������1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) 4. �ַ���
}SqQueue;

void Catalog();                         //Ŀ¼
void Init(SqQueue* Q, int n);           //��ʼ��
void EnQueue(SqQueue* Q, void* e, int n); //���
void DeQueue(SqQueue* Q, int n);               //����
void Print(SqQueue* Q, int n);           //��ӡ