#pragma once
#include<stdio.h>
typedef struct Node   //双向链表
{
	int data;
	struct Node* last;
	struct Node* next;
}Node, * LinkList;

LinkList L;//双向链表头结点
int n;            ////有效节点数

LinkList CreateListHead(int n);               //1.初始化链表
void ListInsert(LinkList L, int i);           //2.插入节点
void ListOutout(LinkList L);                  //3.输出链表
void ListDelete(LinkList L, int i);           //4.删除节点
void ListFind(LinkList L, int i);             //5.查询节点
void ListDestroy(LinkList L);                 //6.销毁节点，结束进程
