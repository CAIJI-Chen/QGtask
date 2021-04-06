#include<stdio.h>
#include"linklist.h"

/*函数定义*/
void catelog()//目录
{
	printf("--------------------1.初始化一个单链表链表\t\-------------\n");
	printf("--------------------2.插入节点\t\t\t-------------\n");
	printf("--------------------3.输出链表\t\t\t-------------\n");
	printf("--------------------4.反向连接链表\t\t-------------\n");
	printf("--------------------5.调换奇偶顺序\t\t-------------\n");
	printf("--------------------6.找到中间节点\t\t-------------\n");
	printf("--------------------7.删除节点\t\t\t-------------\n");
	printf("--------------------8.查询节点\t\t\t-------------\n");
	printf("--------------------9.创建一个循环链表\t\t-------------\n");
	printf("--------------------10.判断链表是否成环\t\t-------------\n");
	printf("--------------------11.销毁节点，结束进程\t-------------\n");
	printf("--------------------循环链表和单链表初始化一个\t-------------\n");
	printf("\n");
	printf("请你选择所需操作：");
}

LinkList CreateListHead(int n)    //1.初始化链表
{
	LinkList L, p, r;
	int i;
	L = (LinkList)malloc(sizeof(Node));
	r = L;
	printf("请输入数据（int型）\n：");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &(p->data));
		printf("->");
		r->next = p;
		r = p;
	}
	r->next = NULL;
	printf("NULL\n");
	return L;
}

void ListInsert(LinkList L, int i)   //2.插入节点
{
	int j = 0;
	LinkList p, r;
	p = L;
	r = (LinkList)malloc(sizeof(Node));
	while (j < i - 1)
	{
		j++;
		p = p->next;
	}
	printf("请输入您要插入的数据为：\n");
	scanf("%d", &(r->data));

	r->next = p->next;
	p->next = r;
	n++;           //刷新节点数
	printf("链表中有%d个数据\n", n);
}

void ListOutout(LinkList L)    //3.输出链表
{
	printf("您的链表是：");
	LinkList p = L->next;
	int j = 0;           //为循环链表输出准备
	while (p != NULL && j < n)
	{
		j++;
		printf("%d\t", (p->data));
		p = p->next;
	}
	printf("\n");

}

LinkList ListReverse(LinkList L)    //4.反向连接链表
{
	LinkList r, p1, p2, l;
	int J = ListJudge(L);
	if (J == 1)
	{
		printf("不好意思，还没有做出循环链表反转\n");
		return L;
	}
	r = L;
	p1 = p2 = L->next;
	r = NULL;
	while (p2 != NULL)
	{
		p1 = p1->next;
		p2->next = r;
		r = p2;
		p2 = p1;
	}
	printf("%d", r->data);
	l = (LinkList)malloc(sizeof(Node));
	l->next = r;
	return l;
}

void ListOdd_Even_Exchange(LinkList L)   //5.调换奇偶顺序
{
	LinkList p1, p2, r;
	r = L;
	p1 = L->next;
	p2 = p1->next;
	while (1)
	{
		p1->next = p2->next;
		p2->next = p1;
		r->next = p2;
		r = p1;
		p1 = p1->next;
		if (p1 == NULL || p1 == L) break;
		p2 = p1->next;
		if (p2 == NULL || p2 == L) break;
	}
}

void ListMiddleNode(LinkList L, int n)     //6.找到中间节点
{
	LinkList p;
	int i = 0;
	p = L;
	if (n % 2 == 1)         //若数据为奇数个
	{
		while (i <= (n / 2))
		{
			p = p->next;
			i++;
		}
		printf("中间节点的值为:%d\n", p->data);
		printf("中间节点为第%d个数据。\n", i);
	}
	else
	{

		printf("该链表为偶数个有效节点，故无中间节点。\n");
		while (i < (n / 2))
		{
			p = p->next;
			i++;
		}
		printf("中间两个相邻的节点分别为%d和%d。\n", p->data, p->next->data);
	}
}

void ListDelete(LinkList L, int i)           //7.删除节点
{
	LinkList p, r;       //r为p的上一个节点
	p = L;
	int j = 0;
	while (j < i)
	{
		r = p;
		p = p->next;
		j++;
	}
	r->next = p->next;
	free(p);
	n--;                //刷新节点数
}

void ListFind(LinkList L, int i)     //8.查询节点
{
	LinkList p;
	p = L;
	int j = 0;
	while (j < i)
	{
		p = p->next;
		j++;

	}
	printf("该节点的数据为：%d\n", p->data);
}



LinkList CreateListHead_Loop(int n)     //9.创建一个循环链表
{
	LinkList L, p, r;
	int i;
	L = (LinkList)malloc(sizeof(Node));
	r = L;
	printf("请输入数据（int型）：\n");
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		scanf("%d", &(p->data));
		printf("->");
		r->next = p;
		r = p;
	}
	r->next = L;
	printf("head\n");
	return L;
}

int ListJudge(LinkList L)              //10.判断链表是否成环
{
	int J = 0;
	LinkList p1, p2;
	p1 = p2 = L;
	while (p1 != NULL && p1->next != NULL && p1->next->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if (p1 == p2) break;
	}
	if (p1 == p2) J = 1;
	return J;

}

void ListDestroy(LinkList L)           //11.销毁节点，结束进程
{
	LinkList p, r;
	p = r = L;
	int j = 0;
	while (j < n)
	{
		p = p->next;
		free(r);
		r = p;
		j++;

	}
}