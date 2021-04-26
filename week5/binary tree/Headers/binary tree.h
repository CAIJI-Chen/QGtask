#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_SIZE 100
#define MaxSize 100
#define MAXSIZE 200


typedef struct BiTNode    //����������ڵ�ṹ
{
	int data;
	struct BiTNode* lchild, * rchild;
}BTNode, BitTree, * BiTree;

typedef BiTree ElemTypeList;

// ���нṹ��
typedef struct {
	ElemTypeList data[MaxSize];
	int front, rear;
}SqQueue;

void catalog();        //Ŀ¼
void PreOrderTraverse(BiTree T); //������ǰ�����
void MidOrderTraverse(BiTree T); //�������������
void aftOrderTraverse(BiTree T); //�������������
int SearchBST(BiTree T, int key, BiTree f, BiTree* p);  //��ѯ
void InsertBST(BiTree T, int key);       //����
void Deleteer(BitTree* bt, int key);      //ɾ���ڵ�
void CreateBiTree(BiTree T, int len);          //��ʼ��
void PreOrder(BTNode* b);//�ǵݹ�ǰ����������� 
void InOrder(BTNode* b);//�ǵݹ�������������� 
void PostOrder(BTNode* b);// �ǵݹ������������� 
void LevelOrder(BiTree T);  //�������
void InitQueue(SqQueue* Q);
int QueueEmpty(SqQueue Q);
int EnQueue(SqQueue* Q, ElemTypeList e);
int DeQueue(SqQueue* Q, ElemTypeList* e);
