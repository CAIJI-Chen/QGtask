#pragma once

typedef int ElemType;
typedef struct Node         //������
{
	ElemType data;
	struct Node* next;
}Node, * LinkList;

/*ȫ�ֱ���*/
int n;             //��Ч�ڵ���
LinkList L;        //����ͷ���

/*��������*/
void catelog();                               //Ŀ¼
LinkList CreateListHead(int n);               //1.��ʼ������
void ListInsert(LinkList L, int i);           //2.����ڵ�
void ListOutout(LinkList L);                  //3.�������
LinkList ListReverse(LinkList L);             //4.������������
void ListOdd_Even_Exchange(LinkList L);       //5.������ż˳��
void ListMiddleNode(LinkList L, int n);       //6.�ҵ��м�ڵ�
void ListDelete(LinkList L, int i);           //7.ɾ���ڵ�
void ListFind(LinkList L, int i);             //8.��ѯ�ڵ�
LinkList CreateListHead_Loop(int n);          //9.����һ��ѭ������
int ListJudge(LinkList L);                    //10.�ж������Ƿ�ɻ�
void ListDestroy(LinkList L);                 //11.���ٽڵ㣬��������

