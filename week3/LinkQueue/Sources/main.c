#include"LinkQueue.h"


int main()
{
	
	QNode q;
	LinkQueue Q;
	Q.front = &q;
	Q.rear = &q;
	int a;
	
	while (1)
	{
		Catalog();
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
			Print(&Q);
		} break;

		case(2):
		{
			int t;                                   //������������
			printf("��������������ͣ�:\n");
			printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) \n");
			scanf("%d", &t);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &t);
			}
			while (t < 1 || t>3)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
			{
				printf("��������ȷ���������ͣ�");
				scanf("%d", &t);
				while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
				{
					printf("�Ƿ����룬���������룺");
					while (getchar() != '\n');
					scanf("%d", &t);
				}
			}
			printf("����ӵ����� :");
			switch (t)
			{
			case (1): {
				int e;
				scanf("%d", &e);
				while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
				{
					printf("�Ƿ����룬���������룺");
					while (getchar() != '\n');
					scanf("%d", &e);
				}
				
			
				EnQueue(&Q, &e, t);

				break;
			}
			case (2): {
				char e;
				scanf("%c", &e);

				while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
				{
					printf("�Ƿ����룬���������룺");
					while (getchar() != '\n');
					scanf("%c", &e);
				}
				
				
				EnQueue(&Q, &e,t);

				break;
			}
			case (3): {
				double e;
				scanf("%lf", &e);
				while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
				{
					printf("�Ƿ����룬���������룺");
					while (getchar() != '\n');
					scanf("%lf", &e);
				}
			
				
				EnQueue(&Q, &e,t);

				break;
			}
					//case (4):
					//{
					//	char e[20];
					//	printf("��󳤶�Ϊ20Ŷ��\n");
					//	scanf("%s", e);
					//	while (e[20] =='\0')               //�ж��Ƿ�Ϊ�Ƿ�����
					//	{
					//		printf("��೤��Ϊ20Ŷ�����������룺");
					//		scanf("%s", e);
					//	}
					//	Q.t[Q.rear] = 4;
					//	EnQueue(&Q, e,n);

					//	break;
					//}
			}


		}		break;

		case(3):
		{
			DeQueue(&Q);
		}		break;


		case(4):
		{
			return 0;
		}	break;

		}
		system("pause");
		system("cls");

	}







	return 0;
}