#pragma once
#include<stdio.h>
typedef struct Node   //˫������
{
	int data;
	struct Node* last;
	struct Node* next;
}Node, * LinkList;

LinkList L;//˫������ͷ���
int n;            ////��Ч�ڵ���

LinkList CreateListHead(int n);               //1.��ʼ������
void ListInsert(LinkList L, int i);           //2.����ڵ�
void ListOutout(LinkList L);                  //3.�������
void ListDelete(LinkList L, int i);           //4.ɾ���ڵ�
void ListFind(LinkList L, int i);             //5.��ѯ�ڵ�
void ListDestroy(LinkList L);                 //6.���ٽڵ㣬��������
