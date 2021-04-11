

#include"Sq_Queue.h"


int main()
{
	Catalog();
	SqQueue Q;
	int a;
	
	printf("请输入你要多大的队列：");
	int n;                                   //队列大小
	scanf("%d", &n);
	while (getchar() != '\n')               //判断是否为非法输入
	{
		printf("非法输入，请重新输入：");
		while (getchar() != '\n');
		scanf("%d", &n);
	}
	while (n < 1 || n>500)                     //判断是否为正确的操作
	{
		printf("别小于1也别大于500吧老哥，请再次输入：");
		scanf("%d", &n);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &n);
		}
	}
	n++;                                        //需要留出一个空格
	Init(&Q, n);                                //初始化
	system("pause");
	system("cls");

	while (1)
	{
		Catalog();
		printf("你的队列大小为%d qwq ：", n-1);
		printf("输入您的操作：");
		scanf("%d", &a);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>5)                     //判断是否为正确的操作
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
		case(1):
		{
			Print(&Q, n);
		} break;

		case(2):
		{
			int t;                                   //输入数据类型
			printf("你想入队哪种类型？:\n");
			printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) \n");
			scanf("%d", &t);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &t);
			}
			while (t< 1 || t>3)                     //判断是否为正确的操作
			{
				printf("请输入正确的数据类型：");
				scanf("%d", &t);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &t);
				}
			}
			printf("想入队的数据 :");
			switch (t)
			{
			case (1): {
				int e;
				scanf("%d", &e);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &e);
				}
				
				Q.t[Q.rear] = 1;
				EnQueue(&Q, &e,n);
				
				break;
			}
			case (2): {
				char e;
				scanf("%c", &e);
				
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%c", &e);
				}
				
				Q.t[Q.rear] = 2;
				EnQueue(&Q, &e,n);
				
				break;
			}
			case (3): {
				double e;
				scanf("%lf", &e);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%lf", &e);
				}
				
				Q.t[Q.rear] = 3;
				EnQueue(&Q, &e,n);
				
				break;
			}
			//case (4):
			//{
			//	char e[20];
			//	printf("最大长度为20哦！\n");
			//	scanf("%s", e);
			//	while (e[20] =='\0')               //判断是否为非法输入
			//	{
			//		printf("最多长度为20哦，请重新输入：");
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
			DeQueue(&Q, n);
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