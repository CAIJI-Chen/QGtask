#include"linklist twoway.h"



int main()
{
	int a;     //����

	catelog();
	scanf("%d", &a);
	while (a < 1 || a>6)
	{
		printf("��������ȷ�Ĳ���ָ��:");
		scanf("%d", &a);
	}
	while (a != 1 )//�ȳ�ʼ��
	{
		printf("�����ȳ�ʼ������");
		scanf("%d", &a);
	}


	while (1)
	{
		while (a < 1 || a>6)
		{
			printf("��������ȷ�Ĳ���ָ��:");
			scanf("%d", &a);
		}
		switch (a)
		{
		case(1):
		{

			printf("����������������Ч�ڵ�����");
			scanf("%d", &n);
			while (n <= 0)
			{
				printf("��������ȷ�ĸ���������Ϊ��һ������");
				scanf("%d", &n);
			}

			L = CreateListHead(n);
			ListOutout(L);
			printf("\n");

		}
		break;

		case(2):
		{
			int i;
			ListOutout(L);
			printf("��Ҫ���뵽�ڼ�����");
			scanf("%d", &i);
			while (i <= 0)
			{
				printf("��������ȷ�Ĳ���λ�ã�����Ϊ��һ������");
				scanf("%d", &i);
			}
			while (i > n + 1)
			{
				printf("��������ȷ�Ĳ���λ�ã����ô���β��%d����", n + 1);
				scanf("%d", &i);
			}
			ListInsert(L, i);
		}
		break;

		case(3):
		{
			ListOutout(L);
		}
		break;

		case(4):
		{
			int i;
			ListOutout(L);
			printf("������Ҫɾ���ڼ������ݣ�");
			scanf("%d", &i);
			while (i <= 0 || i > n)
			{
				printf("Ҫɾ������������Ϊ��һ��������Ϊ��%d����%dΪ����һ�������ݸ�������", n, n);
				printf("���������룺");
				scanf("%d", &i);
			}
			ListDelete(L, i);
			printf("ɾ����%d����", i);
			ListOutout(L);
		}
		break;
		case(5):
		{
			int i;
			printf("��������Ҫ��ѯ�ڼ������ݣ�");
			scanf("%d", &i);
			while (i <= 0 || i > n)
			{
				printf("Ҫ��ѯ����������Ϊ��һ��������Ϊ��%d����%dΪ����һ�������ݸ�������", n, n);
				printf("���������룺");
				scanf("%d", &i);
			}
			ListFind(L, i);
		}
		break;

		break;
		case(6):
		{
			ListDestroy(L);
			printf("���������\n");

			return 0;
		}
		break;
		default:printf("�������");
		}


		printf("����ѡ����������������");
		scanf("%d", &a);
		while (a == 1 || a == 9)//�Ѿ���ʼ���������û�б�Ҫ�ٳ�ʼ��һ��
		{
			printf("���Ѿ���ʼ��������");
			scanf("%d", &a);
		}
		
	}



	return 0;
}

/*case(1):
			{
				int i;
				printf("����������������Ч�ڵ�����");
				scanf("%d", &i);
				while (i <= 0)
				{
					printf("��������ȷ�ĸ���������Ϊ��һ������");
					scanf("%d", &i);
				}

				CreateListHead_TwoWay(i);

			}
				break;
				*/