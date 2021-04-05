#include"linklist twoway.h"



int main()
{
	int a;     //命令

	catelog();
	scanf("%d", &a);
	while (a < 1 || a>6)
	{
		printf("请输入正确的操作指令:");
		scanf("%d", &a);
	}
	while (a != 1 )//先初始化
	{
		printf("请您先初始化链表。");
		scanf("%d", &a);
	}


	while (1)
	{
		while (a < 1 || a>6)
		{
			printf("请输入正确的操作指令:");
			scanf("%d", &a);
		}
		switch (a)
		{
		case(1):
		{

			printf("请输入所需链表有效节点数：");
			scanf("%d", &n);
			while (n <= 0)
			{
				printf("请输入正确的个数（至少为第一个）：");
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
			printf("您要插入到第几个：");
			scanf("%d", &i);
			while (i <= 0)
			{
				printf("请输入正确的插入位置（至少为第一个）：");
				scanf("%d", &i);
			}
			while (i > n + 1)
			{
				printf("请输入正确的插入位置（不得大于尾部%d）：", n + 1);
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
			int i;
			ListOutout(L);
			printf("请输入要删除第几个数据：");
			scanf("%d", &i);
			while (i <= 0 || i > n)
			{
				printf("要删除的数据至少为第一个且至多为第%d个（%d为链表一共的数据个数）。", n, n);
				printf("请重新输入：");
				scanf("%d", &i);
			}
			ListDelete(L, i);
			printf("删除第%d个后", i);
			ListOutout(L);
		}
		break;
		case(5):
		{
			int i;
			printf("请输入您要查询第几个数据：");
			scanf("%d", &i);
			while (i <= 0 || i > n)
			{
				printf("要查询的数据至少为第一个且至多为第%d个（%d为链表一共的数据个数）。", n, n);
				printf("请重新输入：");
				scanf("%d", &i);
			}
			ListFind(L, i);
		}
		break;

		break;
		case(6):
		{
			ListDestroy(L);
			printf("已清除链表！\n");

			return 0;
		}
		break;
		default:printf("输入错误");
		}


		printf("请你选择接下来所需操作：");
		scanf("%d", &a);
		while (a == 1 || a == 9)//已经初始化过链表就没有必要再初始化一次
		{
			printf("您已经初始化了链表。");
			scanf("%d", &a);
		}
		
	}



	return 0;
}

/*case(1):
			{
				int i;
				printf("请输入所需链表有效节点数：");
				scanf("%d", &i);
				while (i <= 0)
				{
					printf("请输入正确的个数（至少为第一个）：");
					scanf("%d", &i);
				}

				CreateListHead_TwoWay(i);

			}
				break;
				*/