#include"H_LinkStack.h"

int main()
{
	int a;
	LinkStack S;
	S.cout = 0;

	while (1)
	{
		Catalog();
		printf("输入您的操作：");
		scanf("%d", &a);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>4)                     //判断是否为正确的操作
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
