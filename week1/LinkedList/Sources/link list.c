#include<stdio.h>
#include"linklist.h"

/*��������*/
void catelog()//Ŀ¼
{
	printf("--------------------1.��ʼ��һ������������\t\-------------\n");
	printf("--------------------2.����ڵ�\t\t\t-------------\n");
	printf("--------------------3.�������\t\t\t-------------\n");
	printf("--------------------4.������������\t\t-------------\n");
	printf("--------------------5.������ż˳��\t\t-------------\n");
	printf("--------------------6.�ҵ��м�ڵ�\t\t-------------\n");
	printf("--------------------7.ɾ���ڵ�\t\t\t-------------\n");
	printf("--------------------8.��ѯ�ڵ�\t\t\t-------------\n");
	printf("--------------------9.����һ��ѭ������\t\t-------------\n");
	printf("--------------------10.�ж������Ƿ�ɻ�\t\t-------------\n");
	printf("--------------------11.���ٽڵ㣬��������\t-------------\n");
	printf("--------------------ѭ������͵������ʼ��һ��\t-------------\n");
	printf("\n");
	printf("����ѡ�����������");
}

LinkList CreateListHead(int n)    //1.��ʼ������
{
	LinkList L, p, r;
	int i;
	L = (LinkList)malloc(sizeof(Node));
	r = L;
	printf("���������ݣ�int�ͣ�\n��");
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

void ListInsert(LinkList L, int i)   //2.����ڵ�
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
	p->next = r;
	n++;           //ˢ�½ڵ���
	printf("��������%d������\n", n);
}

void ListOutout(LinkList L)    //3.�������
{
	printf("���������ǣ�");
	LinkList p = L->next;
	int j = 0;           //Ϊѭ���������׼��
	while (p != NULL && j < n)
	{
		j++;
		printf("%d\t", (p->data));
		p = p->next;
	}
	printf("\n");

}

LinkList ListReverse(LinkList L)    //4.������������
{
	LinkList r, p1, p2, l;
	int J = ListJudge(L);
	if (J == 1)
	{
		printf("������˼����û������ѭ������ת\n");
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

void ListOdd_Even_Exchange(LinkList L)   //5.������ż˳��
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

void ListMiddleNode(LinkList L, int n)     //6.�ҵ��м�ڵ�
{
	LinkList p;
	int i = 0;
	p = L;
	if (n % 2 == 1)         //������Ϊ������
	{
		while (i <= (n / 2))
		{
			p = p->next;
			i++;
		}
		printf("�м�ڵ��ֵΪ:%d\n", p->data);
		printf("�м�ڵ�Ϊ��%d�����ݡ�\n", i);
	}
	else
	{

		printf("������Ϊż������Ч�ڵ㣬�����м�ڵ㡣\n");
		while (i < (n / 2))
		{
			p = p->next;
			i++;
		}
		printf("�м��������ڵĽڵ�ֱ�Ϊ%d��%d��\n", p->data, p->next->data);
	}
}

void ListDelete(LinkList L, int i)           //7.ɾ���ڵ�
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
	free(p);
	n--;                //ˢ�½ڵ���
}

void ListFind(LinkList L, int i)     //8.��ѯ�ڵ�
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



LinkList CreateListHead_Loop(int n)     //9.����һ��ѭ������
{
	LinkList L, p, r;
	int i;
	L = (LinkList)malloc(sizeof(Node));
	r = L;
	printf("���������ݣ�int�ͣ���\n");
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

int ListJudge(LinkList L)              //10.�ж������Ƿ�ɻ�
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

void ListDestroy(LinkList L)           //11.���ٽڵ㣬��������
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