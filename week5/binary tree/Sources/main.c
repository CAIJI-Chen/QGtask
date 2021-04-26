#include"binary tree.h"


int main()
{
	catalog();
	int a;
	BTNode t;
	BiTree T = &t;
	
	printf("请输入初始化数据的个数：");
	int len;
	scanf("%d", &len);
	while (getchar() != '\n')               //判断是否为非法输入
	{
		printf("非法输入，请重新输入：");
		while (getchar() != '\n');
		scanf("%d", &len);
	}
	while (len < 1 || len>500)                     //判断是否为正确的操作
	{
		printf("别小于1也别大于100吧老哥，请再次输入：");
		scanf("%d", &len);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &len);
		}
	}
	printf("请输入：\n");
	CreateBiTree(T, len);
	system("pause");
	system("cls");

	while (1)
	{
		catalog();
		printf("输入您的操作：");
		scanf("%d", &a);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &a);
		}
		while (a < 1 || a>11)                     //判断是否为正确的操作
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
			int n;
			printf("请输入你要插入的数据：");
			scanf("%d", &n);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &n);
			}
			InsertBST(T, n);

		} break;

		case(2):
		{
			BiTree p;
			int key;
			printf("请输入你要查找是否存在的数据：");
			scanf("%d", &key);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &key);
			}
			int t = SearchBST(T, key, NULL, &p);  //查询
			
			if (t == 0) printf("未找到该数据！\n");
			if (t == 1) printf("找到该数据了！\n");
			
		}		break;

		case(3):
		{
			int key;
			printf("请输入你要删除的数据：");
			scanf("%d", &key);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &key);
			}
			Deleteer(T, key);        //删除节点

		}		break;


		case(4):
		{
			PreOrderTraverse(T);   //二叉树前序遍历
			printf("\n");

		}	break;

		case(5):
		{
			MidOrderTraverse(T); //二叉树中序遍历
			printf("\n");


		}	break;

		case(6):
		{
			aftOrderTraverse(T); //二叉树后序遍历
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