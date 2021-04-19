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
		printf("请输入你的操作：");
		scanf("%d", &a);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>10)                     //判断是否为正确的操作
		{
			printf("请输入正确的操作：");
			scanf("%d", &a);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &a);
			}
		}


		switch (a)
		{
		case(1):                               //1 生成数组
		{

			printf("请输入你要生成的数组的长度：");
			scanf("%d", &_len);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &_len);
			}
			while (_len < 1 || _len>1000000)                     //判断是否为正确的操作
			{
				printf("请输入正确的操作：");
				scanf("%d", &_len);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &_len);
				}
			}
			printf("请输入数据：\n");

			for (int i = 1; i <= _len; i++)
			{
				int x;
				scanf("%d", &x);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &x);
				}
				b[i] = x;
			}

			printf("数组为：");
			print(b, _len);



		} break;


		case(2):                     //2 插入排序
		{
			insertsort(b, _len);
			printf("此时数组为：\n");
			print(b, _len);
		} break;

		case(3):                      //3 快速排序
		{
			quick_sort(b, 1, _len);
			printf("此时数组为：\n");
			print(b, _len);

		} break;

		case(4):                        // 4 归并排序
		{
			int* b1 = (int)malloc(MAX * sizeof(int));
			MergeSort(b, b1, 1, _len);
			printf("此时数组为：\n");
			print(b, _len);

		} break;


		case(5):                       //5 基数排序
		{
			radixSort(b, _len + 1);
			printf("此时数组为：\n");
			print(b, _len);

		} break;


		case(6):                        //6 计数排序
		{
			CountSort(b, _len + 1);
			printf("此时数组为：\n");
			print(b, _len);

		} break;


		case(7):                          //7 大数据量时排序所需时间
		{

			data(a1,a2,a3);


		} break;


		case(8):                           //100 * 100k排序所需用时
		{

			_100();

		} break;


		case(9):                           //9 重新定义数组
		{
			printf("请输入你要生成的数组的长度：");
			scanf("%d", &_len);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &_len);
			}
			while (_len < 1 || _len>1000000)                     //判断是否为正确的操作
			{
				printf("请输入正确的操作：");
				scanf("%d", &_len);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &_len);
				}
			}
			printf("请输入数据：\n");

			for (int i = 1; i <= _len; i++)
			{
				int x;
				scanf("%d", &x);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &x);
				}
				b[i] = x;
			}

			printf("数组为：");
			print(b, _len);

		} break;


		case(10):                           //10 退出
		{
			printf("再见qwq\n");
			return 0;
		} break;




		}
		system("pause");
		system("cls");

	}
	return 0;

}