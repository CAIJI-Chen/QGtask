#include"binary tree.h"



void catalog()
{
	printf("---------------------  ����������\t-------------------\n");
	printf("---------------------1. ��������\t-------------------\n");
	printf("---------------------2. ��������\t-------------------\n");
	printf("---------------------3. ɾ������\t-------------------\n");
	printf("---------------------4. �ݹ�ǰ�����\t-------------------\n");
	printf("---------------------5. �ݹ��������\t-------------------\n");
	printf("---------------------6. �ݹ�������\t-------------------\n");
	printf("---------------------7. ����ǰ�����\t-------------------\n");
	printf("---------------------8. �����������\t-------------------\n");
	printf("---------------------9. �����������\t-------------------\n");
	printf("---------------------10.�������\t-------------------\n");
	printf("---------------------11.�˳�����\t-------------------\n");
}


void InitQueue(SqQueue* Q) {
	Q->front = Q->rear = 0;
}

int QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear) return 1;
	return 0;
}


int EnQueue(SqQueue* Q, ElemTypeList e) {
	if ((Q->rear + 1) % MaxSize == Q->front) {
		printf("queue is full!");
		return 0;
	}//������������һ���洢��Ԫ
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MaxSize;
	return 1;
}

int DeQueue(SqQueue* Q, ElemTypeList* e) {
	if (QueueEmpty(*Q)) return 0;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MaxSize;
	return 1;
}

void LevelOrder(BiTree T)
{
	SqQueue Q;
	InitQueue(&Q);
	EnQueue(&Q, T);
	BiTree p;
	while (!QueueEmpty(Q)) {
		DeQueue(&Q, &p);

		printf("%d\t", p->data);
		if (p->lchild != NULL)
			EnQueue(&Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(&Q, p->rchild);
	}
}




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


void PreOrderTraverse(BiTree T) //������ǰ�����
{
	if (T == NULL)	return;
	printf("%d\t", T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);

}

void MidOrderTraverse(BiTree T) //�������������
{
	if (T == NULL)	return;
	MidOrderTraverse(T->lchild);
	printf("%d\t", T->data);
	MidOrderTraverse(T->rchild);

}

void aftOrderTraverse(BiTree T) //�������������
{
	if (T == NULL)	return;
	aftOrderTraverse(T->lchild);
	aftOrderTraverse(T->rchild);
	printf("%d\t", T->data);
}

int SearchBST(BiTree T, int key, BiTree f, BiTree* p)  //��ѯ
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

void InsertBST(BiTree T, int key)       //����
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
		printf("����������ˣ�\n");
		return;
	}

}


void CreateBiTree(BiTree T, int len)          //��ʼ��
{
	int n;
	scanf("%d", &n);
	while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
	{
		printf("�Ƿ����룬���������룺");
		while (getchar() != '\n');
		scanf("%d", &n);
	}
	T->data = n;
	T->lchild = T->rchild = NULL;
	for (int i = 1; i < len; i++)
	{
		scanf("%d", &n);
		while (getchar() != '\n')               //�ж��Ƿ�Ϊ�Ƿ�����
		{
			printf("�Ƿ����룬���������룺");
			while (getchar() != '\n');
			scanf("%d", &n);
		}
		InsertBST(T, n);
	}

}
//�ǵݹ�ǰ����������� 
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

//�ǵݹ�������������� 
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

// �ǵݹ������������� 
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



