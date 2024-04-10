#include <stdio.h>
#include <stdlib.h>

typedef enum Status {
	FAIL=-1,
	ERROR,
	SUCCESS
}Status;

typedef struct BiNode {
	struct BiNode* lchild,* rchild;
	int data;
	int visited;

}BiNode,*BiTree;


typedef struct BiStack {
	BiTree B[100];
	int top;
}BiStack,*BiStackL;

typedef struct BiQueue {
	BiTree B[100];
	int top;
}BiQueue,*BiQueueL;

void menus();

Status Init_BiTree(BiTree* L);

Status Insert_BiTree(BiTree L, int data);

Status SearchBiTree(BiTree L, int data);

Status DeleteBiNode(BiTree* L, int data);

void visit(BiNode* L);

Status InitStack(BiStackL* S);

Status IsEmptyStack(BiStackL S);

Status PushStack(BiStackL S, BiTree p);

Status PopStack(BiStackL S, BiTree* p);
Status PreOrderTraverse(BiTree L);
Status PreOrderTraverse_(BiTree L);

Status InOrderTraverse(BiTree L);
Status InOrderTraverse_(BiTree L);

Status PostOrderTraverse(BiTree L);
Status DestroyRoot(BiTree* L);

//·ÇµÝ¹é
Status PostOrderTraverse_(BiTree L);

//²ã´Î±éÀú
Status InitQueue(BiQueueL* qu);
Status IsEmptyQueue(BiQueueL qu);

Status PushQueue(BiQueueL qu, BiTree p);
Status PopQueue(BiQueueL qu, BiTree* p);

Status LevelOrder(BiTree L);

void Clear(BiTree L);