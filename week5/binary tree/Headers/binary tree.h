#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_SIZE 100
#define MaxSize 100
#define MAXSIZE 200


typedef struct BiTNode    //二叉树链表节点结构
{
	int data;
	struct BiTNode* lchild, * rchild;
}BTNode, BitTree, * BiTree;

typedef BiTree ElemTypeList;

// 队列结构体
typedef struct {
	ElemTypeList data[MaxSize];
	int front, rear;
}SqQueue;

void catalog();        //目录
void PreOrderTraverse(BiTree T); //二叉树前序遍历
void MidOrderTraverse(BiTree T); //二叉树中序遍历
void aftOrderTraverse(BiTree T); //二叉树后序遍历
int SearchBST(BiTree T, int key, BiTree f, BiTree* p);  //查询
void InsertBST(BiTree T, int key);       //插入
void Deleteer(BitTree* bt, int key);      //删除节点
void CreateBiTree(BiTree T, int len);          //初始化
void PreOrder(BTNode* b);//非递归前序遍历二叉树 
void InOrder(BTNode* b);//非递归中序遍历二叉树 
void PostOrder(BTNode* b);// 非递归后序遍历二叉树 
void LevelOrder(BiTree T);  //层序遍历
void InitQueue(SqQueue* Q);
int QueueEmpty(SqQueue Q);
int EnQueue(SqQueue* Q, ElemTypeList e);
int DeQueue(SqQueue* Q, ElemTypeList* e);
