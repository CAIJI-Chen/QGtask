#include"binary tree.h"


int main()
{
	catalog();
	int a;
	BTNode t;
	BiTree T = &t;
	
	printf("�������ʼ�����ݵĸ�����");
	int len;
	scanf("%d", &len);
	while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
	{
		printf("�Ƿ����룬���������룺");
		while (getchar() != '\n');
		scanf("%d", &len);
	}
	while (len < 1 || len>500)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
	{
		printf("��С��1Ҳ�����100���ϸ磬���ٴ����룺");
		scanf("%d", &len);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &len);
		}
	}
	printf("�����룺\n");
	CreateBiTree(T, len);
	system("pause");
	system("cls");

	while (1)
	{
		catalog();
		printf("�������Ĳ�����");
		scanf("%d", &a);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>11)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
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
			int n;
			printf("��������Ҫ��������ݣ�");
			scanf("%d", &n);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &n);
			}
			InsertBST(T, n);

		} break;

		case(2):
		{
			BiTree p;
			int key;
			printf("��������Ҫ�����Ƿ���ڵ����ݣ�");
			scanf("%d", &key);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &key);
			}
			int t = SearchBST(T, key, NULL, &p);  //��ѯ
			
			if (t == 0) printf("δ�ҵ������ݣ�\n");
			if (t == 1) printf("�ҵ��������ˣ�\n");
			
		}		break;

		case(3):
		{
			int key;
			printf("��������Ҫɾ�������ݣ�");
			scanf("%d", &key);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &key);
			}
			Deleteer(T, key);        //ɾ���ڵ�

		}		break;


		case(4):
		{
			PreOrderTraverse(T);   //������ǰ�����
			printf("\n");

		}	break;

		case(5):
		{
			MidOrderTraverse(T); //�������������
			printf("\n");


		}	break;

		case(6):
		{
			aftOrderTraverse(T); //�������������
			printf("\n");

		}	break;

		case(7):
		{
			PreOrder(T);

		}	break;

		case(8):
		{
			InOrder(T);

		}	break;

		case(9):
		{
			PostOrder(T);

		}	break;

		case(10):
		{
			LevelOrder(T);
			printf("\n");

		}	break;

		case(11):
		{
			printf("bye bye~~\n");
			system("pause");
			system("cls");
			return 0;

		}	break;


		

		}
		system("pause");
		system("cls");

	}
}