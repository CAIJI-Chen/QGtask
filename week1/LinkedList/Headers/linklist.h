#pragma once

typedef int ElemType;
typedef struct Node         //单链表
{
	ElemType data;
	struct Node* next;
}Node, * LinkList;

/*全局变量*/
int n;             //有效节点数
LinkList L;        //链表头结点

/*函数声明*/
void catelog();                               //目录
LinkList CreateListHead(int n);               //1.初始化链表
void ListInsert(LinkList L, int i);           //2.插入节点
void ListOutout(LinkList L);                  //3.输出链表
LinkList ListReverse(LinkList L);             //4.反向连接链表
void ListOdd_Even_Exchange(LinkList L);       //5.调换奇偶顺序
void ListMiddleNode(LinkList L, int n);       //6.找到中间节点
void ListDelete(LinkList L, int i);           //7.删除节点
void ListFind(LinkList L, int i);             //8.查询节点
LinkList CreateListHead_Loop(int n);          //9.创建一个循环链表
int ListJudge(LinkList L);                    //10.判断链表是否成环
void ListDestroy(LinkList L);                 //11.销毁节点，结束进程

