# 二叉树

## 一、基本概念

​    (1)若它的左子树不为空，则左子树上所有节点的值均小于它的根节点的值；

​    (2)若它的右子树不为空，则右子树上所有节点的值均大于它的根节点的值；

​    (3)它的左、右子树也分别为二叉排序树。

二叉树是一种数据结构

![img](file:///C:\应用程序\QQ\1622674681\Image\C2C\41522AD36BA7947CE7EADB8E2F0163DD.png)

根据定义，可知左子树结点值<根结点值<右子树结点值，所以对二叉排序树进行中序遍历，可以得到一个递增的有序序列。如上图二叉排序树中序遍历序列为123468。

### 定义结构体

```c
typedef struct BiTNode    //二叉树链表节点结构
{
	int data;
	struct BiTNode* lchild, * rchild;
}BTNode, BitTree, * BiTree;
```

### 初始化

InsertBST函数在后面，是二叉树的插入

```c
void CreateBiTree(BiTree T, int len)          //初始化
{
	int n;
	scanf("%d", &n);
	while (getchar() != '\n')               //判断是否为非法输入
	{
		printf("非法输入，请重新输入：");
		while (getchar() != '\n');
		scanf("%d", &n);
	}
	T->data = n;
	T->lchild = T->rchild = NULL;
	for (int i = 1; i < len; i++)
	{
		scanf("%d", &n);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &n);
		}
		InsertBST(T, n);
	}

```



## 二、二叉树的基本操作



### 递归实现遍历

先序遍历：先访问根节点，然后先序遍历左子树，在先序遍历右子树

中序遍历：中序遍历根节点的左子树，然后访问根节点，最后遍历右子树

后序遍历：从左到右先遍历叶子后节点的方式遍历访问左右子树，最后访问根节点（左右根）

```c
void PreOrderTraverse(BiTree T) //二叉树前序遍历
{
	if (T == NULL)	return;
	printf("%d\t", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);

}

void MidOrderTraverse(BiTree T) //二叉树中序遍历
{
	if (T == NULL)	return;
	MidOrderTraverse(T->lchild);
	printf("%d\t", T->data);
	MidOrderTraverse(T->rchild);

}

void aftOrderTraverse(BiTree T) //二叉树后序遍历
{
	if (T == NULL)	return;
	aftOrderTraverse(T->lchild);
	aftOrderTraverse(T->rchild);
	printf("%d\t", T->data);
}
```



### 非递归实现遍历

```c
//非递归前序遍历二叉树 
void PreOrder(BTNode* b)
{
	BTNode* stack[MAXSIZE], * p;
	int top = -1;
	if (b != NULL)
	{

		top++;
		stack[top] = b;
		while (top > -1)
		{
			p = stack[top];
			top--;
			printf("%d\t", p->data);
			if (p->rchild != NULL)
			{
				top++;
				stack[top] = p->rchild;
			}
			if (p->lchild != NULL)
			{
				top++;
				stack[top] = p->lchild;
			}
		}
		printf("\n");
	}
}

//非递归中序遍历二叉树 
void InOrder(BTNode* b)
{
	BTNode* stack[MAXSIZE], * p;
	int top = -1;
	if (b != NULL)
	{
		p = b;
		while (top > -1 || p != NULL)
		{

			while (p != NULL)
			{
				top++;
				stack[top] = p;
				p = p->lchild;
			}
			if (top > -1)
			{

				p = stack[top];
				top--;
				printf("%d\t", p->data);

				p = p->rchild;
			}
		}
		printf("\n");
	}
}

// 非递归后序遍历二叉树 
void PostOrder(BTNode* b)
{
	BTNode* stack[MAXSIZE], * p;
	int sign, top = -1;
	if (b != NULL)
	{
		do
		{

			while (b != NULL)
			{
				top++;
				stack[top] = b;
				b = b->lchild;
			}

			p = NULL;

			sign = 1;
			while (top != -1 && sign)
			{

				b = stack[top];

				if (b->rchild == p)
				{
					printf("%d\t", b->data);
					top--;

					p = b;
				}
				else
				{

					b = b->rchild;

					sign = 0;
				}
			}
		} while (top != -1);
		printf("\n");
	}
}
```



### 二叉树的查询

从根结点开始查找，若树非空，将给定值与根结点关键字值比较，若相等，则查找成功；若不等且给定值小于根结点关键字值，在根结点左子树中查找；否则在根结点的右子树查找。

```c
int SearchBST(BiTree T, int key, BiTree f, BiTree* p)  //查询
{
	if (!T)
	{
		*p = f;
		return 0;
	}
	else if (key == T->data)
	{
		*p = T;

		return 1;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lchild, key, T, p);
	}
	else return SearchBST(T->rchild, key, T, p);

}
```



### 二叉树的插入

二叉排序树插入思想和查询思想很接近：若原二叉排序树为空，则直接插入结点；否则，若关键字k小于根结点关键字，则插入左子树；否则插入右子树。

```c
void InsertBST(BiTree T, int key)       //插入
{
	BiTree p, s;
	if (!SearchBST(T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BTNode));
		s->data = key;
		s->lchild = NULL;
		s->rchild = NULL;
		if (!p) T = s;
		else if (key < p->data)
			p->lchild = s;
		else p->rchild = s;
		return;

	}
	else
	{
		printf("已有这个数了！\n");
		return;
	}

}
```



### 二叉树的删除

删除操作的实现过程按3种情况来处理：

​    （1）若被删除结点是叶结点，则直接删除，不会破坏二叉排序树的性质；

​    （2）若结点只有一棵左子树或右子树，则让结点的子树成为结点父节点的子树替代。

​    （3）若结点有左、右两棵子树，则令该节点的直接后继（或直接前驱）替代，然后从二叉排序树中删除这个直接后继（或直接前驱），这样就转换成为了第一或第二种情况。

```c
void Deleteer(BitTree* bt, int key)
{
	BitTree* L, * LL;
	BitTree* p = bt;
	BitTree* parent = bt;
	int child = 0;
	if (!bt)
		return;
	while (p)
	{
		if (p->data == key)
		{
			if (!p->lchild && !p->rchild)
			{
				if (p == bt)
					free(p);
				else if (child == 0)
				{
					parent->lchild = NULL;
					free(p);
				}
				else
				{
					parent->rchild = NULL;
					free(p);
				}
			}

			else if (!p->lchild)
			{
				if (child == 0)
					parent->lchild = p->rchild;
				else
					parent->rchild = p->rchild;
				free(p);
			}

			else if (!p->rchild)
			{
				if (child == 0)
					parent->lchild = p->lchild;
				else
					parent->rchild = p->lchild;
				free(p);
			}

			else
			{
				LL = p;
				L = p->rchild;
				if (L->lchild)
				{
					LL = L;
					L = L->lchild;
					p->data = L->data;
					LL->lchild = L->lchild;
					for (; L->lchild; L = L->lchild);
					L->lchild = p->lchild;
					p->lchild = NULL;
				}
				else
				{
					p->data = L->data;
					LL->rchild = L->rchild;
				}
			}
			p = NULL;
		}

		else if (key < p->data)
		{

			child = 0;
			parent = p;
			p = p->lchild;
		}

		else
		{

			child = 1;
			parent = p;
			p = p->rchild;
		}
	}
}

```

