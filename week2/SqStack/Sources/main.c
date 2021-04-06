#include"SqStack.h"

int main()
{
	int a;
	SqStack S;                               //一个顺序栈
	S.top = -1;                               //初始化top
	int b = 0;
	Catalog();
	printf("请输入你需要多大的栈:");
	scanf("%d", &b);
	while (getchar() != '\n')               //判断是否为非法输入
	{
		printf("非法输入，请重新输入：");
		while (getchar() != '\n');
		scanf("%d", &b);
	}
	while (b < 1|| b>500)                     //判断是否为正确的操作
	{
		printf("（别小于1也别大于500吧，老哥）请再次输入：");
		scanf("%d", &b);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &b);
		}
	}
	
	system("pause");
	system("cls");
	
	while (1)
	{
		Catalog();
		printf("你的栈大小为%d qwq ：",b);
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
				int x;
				printf("输入你要加入的数据(整型）：");
				scanf("%d", &x);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
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
				printf("请输入你要改成多大的栈:");
				scanf("%d", &b);
				while (getchar() != '\n')               //判断是否为非法输入
				{
					printf("非法输入，请重新输入：");
					while (getchar() != '\n');
					scanf("%d", &b);
				}
				while (b < 1 || b>500)                     //判断是否为正确的操作
				{
					printf("（别小于1也别大于500吧，老哥）请再次输入：");
					scanf("%d", &b);
					while (getchar() != '\n')               //判断是否为非法输入
					{
						printf("非法输入，请重新输入：");
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