#include<stdio.h>
int b[1000] = { 0 };
void qustion1(int a[], int len);


void qustion1(int a[], int len)
{
	int p = 0;
	int p1 = 0;
	int p2 = len-1;
	int m;	
	while (a[p1] == 0) p1++;
	while (a[p2] == 2) p2--;
	p = p1;
	while (p <= p2)
	{

		if (a[p] == 0)
		{
			m = a[p];
			a[p] = a[p1];
			a[p1] = m;
			p1++; 
			
			
		}
		if (a[p] == 2 && p2!=p)
		{
			m = a[p];
			a[p] = a[p2];
			a[p2] = m;
			p2--;


		}
		else p++;
		
	}

}

void print(int a[], int len)                          //��ӡ
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

int main()
{
	int _len;
	printf("��������Ҫ���ɵ�����ĳ���(���1000��)��");
	scanf("%d", &_len);
	while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
	{
		printf("�Ƿ����룬���������룺");
		while (getchar() != '\n');
		scanf("%d", &_len);
	}
	while (_len < 1 || _len>1000)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
	{
		printf("��������ȷ�Ĳ�����");
		scanf("%d", &_len);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &_len);
		}
	}
	printf("���������ݣ�\n");

	for (int i = 1; i <= _len; i++)
	{
		int x;
		scanf("%d", &x);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &x);
		}
		while (x < 0 || x>2)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
		{
			printf("��������ȷ�Ĳ�����");
			scanf("%d", &x);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &x);
			}
		}
		b[i] = x;
	}

	printf("����Ϊ��\n");
	print(b, _len);
	printf("���������Ϊ��\n");
	qustion1(b, _len);
	print(b, _len);
	return 0;
}