#include"linklist twoway.h"
void catelog()//目录
{
	printf("--------------------1.初始化一个双向链表链表\t\-------------\n");
	printf("--------------------2.插入节点\t\t\t-------------\n");
	printf("--------------------3.输出链表\t\t\t-------------\n");
	printf("--------------------4.删除节点\t\t\t-------------\n");
	printf("--------------------5.查询节点\t\t\t-------------\n");
	printf("--------------------6.销毁节点，结束进程\t-------------\n");
	printf("\n");
	printf("请你选择所需操作：");
}

LinkList CreateListHead(int i)                 //1.创建一个双向链表
{
	LinkList L, p, r;
	int j;
	L = (LinkList)malloc(sizeof(Node));
	r = L;
	printf("请输入数据（int型）：\n");
	for (j = 0; j < i; j++)
	{
		p = (LinkList)malloc(sizeof(Node));

		scanf("%d", &(p->data));
		printf("<=>");
		r->next = p;
		p->last = r;
		r = p;
	}
	r->next = NULL;
	printf("NULL\n");
	return L;
}
void ListInsert(LinkList L, int i)             //2.插入节点
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
	r->last = p;
	p->next = r;
	if(r->next!=NULL) r->next->last = r;
	n++;           //刷新节点数
	printf("链表中有%d个数据\n", n);
}
void ListOutout(LinkList L)                   //3.输出链表
{
	printf("您的链表是：");
	LinkList p = L;
	printf("正向输出\n");
	while (p->next != NULL )
	{
		p = p->next;
		printf("%d\t", (p->data));
	}
	printf("\n");
	printf("反向输出\n");
	while (p != L)
	{

		printf("%d\t", (p->data));
		p = p->last;
	}
	printf("\n");
}

void ListDelete(LinkList L, int i)           //4.删除节点
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
	p->next->last = r;
	free(p);
	n--;                //刷新节点数
}
void ListFind(LinkList L, int i)     //5.查询节点
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
void ListDestroy(LinkList L)           //6.销毁节点，结束进程
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