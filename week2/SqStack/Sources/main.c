#include"SqStack.h"

int main()
{
	int a;
	SqStack S;                               //һ��˳��ջ
	S.top = -1;                               //��ʼ��top
	int b = 0;
	Catalog();
	printf("����������Ҫ����ջ:");
	scanf("%d", &b);
	while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
	{
		printf("�Ƿ����룬���������룺");
		while (getchar() != '\n');
		scanf("%d", &b);
	}
	while (b < 1|| b>500)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
	{
		printf("����С��1Ҳ�����500�ɣ��ϸ磩���ٴ����룺");
		scanf("%d", &b);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &b);
		}
	}
	
	system("pause");
	system("cls");
	
	while (1)
	{
		Catalog();
		printf("���ջ��СΪ%d qwq ��",b);
		printf("�������Ĳ�����");
		scanf("%d", &a);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>5)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
		{
			printf("��������ȷ�Ĳ�����");
			scanf("%d", &a);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &a);
			}
		}

		switch (a)
		{
			
			case(1):
			{
				int x;
				printf("������Ҫ���������(���ͣ���");
				scanf("%d", &x);
				while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
				{
					printf("�Ƿ����룬���������룺");
					while (getchar() != '\n');
					scanf("%d", &x);
				}
				Push(&S, x,b);
				

			}		break;

			case(2):
			{
				Pop(&S);
			}		break;

			case(3):
			{
				Print(&S,b);
			}	break;

			case(4):
			{
				int q = b;
				printf("��������Ҫ�ĳɶ���ջ:");
				scanf("%d", &b);
				while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
				{
					printf("�Ƿ����룬���������룺");
					while (getchar() != '\n');
					scanf("%d", &b);
				}
				while (b < 1 || b>500)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
				{
					printf("����С��1Ҳ�����500�ɣ��ϸ磩���ٴ����룺");
					scanf("%d", &b);
					while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
					{
						printf("�Ƿ����룬���������룺");
						while (getchar() != '\n');
						scanf("%d", &b);
					}
				}
				if (b > q)
				{
					while (q<=b)
					{
						S.date[q] = 0;
						q++;
					}
				}
				if (b < q)
				{
					while (q > b)
					{
						S.date[q] = 0;
						q--;
					}
				}



			}	break;

			case(5):
			{
				return 0;
			}	break;

		}
		system("pause");
		system("cls");
		
	}
}