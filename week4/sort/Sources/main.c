#include"Sort_h.h"
#include<stdlib.h>
int b[MAX] = { 0 };
int a1[10000] = { 0 };
int a2[50000] = { 0 };
int a3[200000] = { 0 };

int main()
{
	int a;
	int _len = 0;




	while (1)
	{
		catalog();
		printf("��������Ĳ�����");
		scanf("%d", &a);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>10)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
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
		case(1):                               //1 ��������
		{

			printf("��������Ҫ���ɵ�����ĳ��ȣ�");
			scanf("%d", &_len);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &_len);
			}
			while (_len < 1 || _len>1000000)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
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
				b[i] = x;
			}

			printf("����Ϊ��");
			print(b, _len);



		} break;


		case(2):                     //2 ��������
		{
			insertsort(b, _len);
			printf("��ʱ����Ϊ��\n");
			print(b, _len);
		} break;

		case(3):                      //3 ��������
		{
			quick_sort(b, 1, _len);
			printf("��ʱ����Ϊ��\n");
			print(b, _len);

		} break;

		case(4):                        // 4 �鲢����
		{
			int* b1 = (int)malloc(MAX * sizeof(int));
			MergeSort(b, b1, 1, _len);
			printf("��ʱ����Ϊ��\n");
			print(b, _len);

		} break;


		case(5):                       //5 ��������
		{
			radixSort(b, _len + 1);
			printf("��ʱ����Ϊ��\n");
			print(b, _len);

		} break;


		case(6):                        //6 ��������
		{
			CountSort(b, _len + 1);
			printf("��ʱ����Ϊ��\n");
			print(b, _len);

		} break;


		case(7):                          //7 ��������ʱ��������ʱ��
		{

			data(a1,a2,a3);


		} break;


		case(8):                           //100 * 100k����������ʱ
		{

			_100();

		} break;


		case(9):                           //9 ���¶�������
		{
			printf("��������Ҫ���ɵ�����ĳ��ȣ�");
			scanf("%d", &_len);
			while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
			{
				printf("�Ƿ����룬���������룺");
				while (getchar() != '\n');
				scanf("%d", &_len);
			}
			while (_len < 1 || _len>1000000)                     //�ж��Ƿ�Ϊ��ȷ�Ĳ���
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
				b[i] = x;
			}

			printf("����Ϊ��");
			print(b, _len);

		} break;


		case(10):                           //10 �˳�
		{
			printf("�ټ�qwq\n");
			return 0;
		} break;




		}
		system("pause");
		system("cls");

	}
	return 0;

}