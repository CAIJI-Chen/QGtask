#include"linklist twoway.h"
void catelog()//Ŀ¼
{
	printf("--------------------1.��ʼ��һ��˫����������\t\-------------\n");
	printf("--------------------2.����ڵ�\t\t\t-------------\n");
	printf("--------------------3.�������\t\t\t-------------\n");
	printf("--------------------4.ɾ���ڵ�\t\t\t-------------\n");
	printf("--------------------5.��ѯ�ڵ�\t\t\t-------------\n");
	printf("--------------------6.���ٽڵ㣬��������\t-------------\n");
	printf("\n");
	printf("����ѡ�����������");
}

LinkList CreateListHead(int i)                 //1.����һ��˫������
{
	LinkList L, p, r;
	int j;
	L = (LinkList)malloc(sizeof(Node));
	r = L;
	printf("���������ݣ�int�ͣ���\n");
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
void ListInsert(LinkList L, int i)             //2.����ڵ�
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
	printf("��������Ҫ���������Ϊ��\n");
	scanf("%d", &(r->data));
	r->next = p->next;
	r->last = p;
	p->next = r;
	if(r->next!=NULL) r->next->last = r;
	n++;           //ˢ�½ڵ���
	printf("��������%d������\n", n);
}
void ListOutout(LinkList L)                   //3.�������
{
	printf("���������ǣ�");
	LinkList p = L;
	printf("�������\n");
	while (p->next != NULL )
	{
		p = p->next;
		printf("%d\t", (p->data));
	}
	printf("\n");
	printf("�������\n");
	while (p != L)
	{

		printf("%d\t", (p->data));
		p = p->last;
	}
	printf("\n");
}

void ListDelete(LinkList L, int i)           //4.ɾ���ڵ�
{
	LinkList p, r;       //rΪp����һ���ڵ�
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
	n--;                //ˢ�½ڵ���
}
void ListFind(LinkList L, int i)     //5.��ѯ�ڵ�
{
	LinkList p;
	p = L;
	int j = 0;
	while (j < i)
	{
		p = p->next;
		j++;

	}
	printf("�ýڵ������Ϊ��%d\n", p->data);
}
void ListDestroy(LinkList L)           //6.���ٽڵ㣬��������
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