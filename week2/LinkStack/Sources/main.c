#include"H_LinkStack.h"

int main()
{
	int a;
	LinkStack S;
	S.cout = 0;

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
		while (a < 1 || a>4)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
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
			Push(&S, x);


		}		break;

		case(2):
		{
			Pop(&S);
		}		break;

		case(3):
		{
			Print(&S);
		}	break;

		case(4):
		{
			return 0;
		}	break;

		}
		//system("pause");
		system("cls");

	}
}
