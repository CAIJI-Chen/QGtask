
#include"linklist.h"
int main()
{
	int a;     //����

	catelog();
	scanf("%d", &a);
	while (a < 1 || a>11)
	{
		printf("��������ȷ�Ĳ���ָ��:");
		scanf("%d", &a);
	}
	while (a != 1  && a != 9)//�ȳ�ʼ��
	{
		printf("�����ȳ�ʼ������");
		scanf("%d", &a);
	}

	
	while (1)
	{
		while (a < 1 || a>11)
		{
			printf("��������ȷ�Ĳ���ָ��:");
			scanf("%d", &a);
		}
		switch(a)
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
				while (i > n+1)
				{
					printf("��������ȷ�Ĳ���λ�ã����ô���β��%d����",n+1);
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
				ListOutout(L);
				printf("\n");
				L=ListReverse(L);
				printf("��ת��");
				ListOutout(L);

			}
				break;

			case(5):
			{
				ListOutout(L);
				printf("\n");
				ListOdd_Even_Exchange(L);
				printf("��������Ϊ��	\n");
				ListOutout(L);
			}
				break;
			case(6):
			{
				ListOutout(L);
				printf("\n");
				ListMiddleNode(L, n);
			}
				break;
			case(7):
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
				printf("ɾ����%d����",i);
				ListOutout(L);
			}
				break;
			case(8):
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
			
			case(9):
			{
				printf("����������������Ч�ڵ�����");
				scanf("%d", &n);
				while (n <= 0)
				{
					printf("��������ȷ�ĸ���������Ϊ��һ������");
					scanf("%d", &n);
				}

				L = CreateListHead_Loop(n);
				//ListOutout(L);
				printf("\n");
				
			}
				break;
			case(10):
			{
				int J;
				J = ListJudge(L);
				if (J == 1) printf("���������ѭ������\n");
				else if(J==0) printf("������Ĳ���ѭ������\n");
			}
				break;
			case(11):
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
		while (a == 1 ||a == 9)//�Ѿ���ʼ���������û�б�Ҫ�ٳ�ʼ��һ��
		{
			printf("���Ѿ���ʼ����������ѭ���б�͵�����ֻѡ��һ��");
			scanf("%d", &a);
		}
		  
	}



	return 0;
}