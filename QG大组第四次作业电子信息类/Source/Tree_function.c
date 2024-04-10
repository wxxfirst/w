#include "Tree.h"

void menus()
{
	printf("***********************************************************\n");
	printf("**                         menus                         **\n");
	printf("**           0、退出                   1、初始化         **\n");
	printf("**           2、插入                   3、查找           **\n");
	printf("**           4、删除                   5、先序遍历(递归) **\n");
	printf("**           6、先序遍历(非递归)       7、中序遍历(递归) **\n");
	printf("**           8、中序遍历(非递归)       9、后序遍历(递归) **\n");
	printf("**          10、后序遍历(非递归)      11、层次遍历       **\n");
	printf("**                       注：二叉树                      **\n");
	printf("***********************************************************\n");
}

Status Init_BiTree(BiTree* L)
{
	*L = (BiTree)malloc(sizeof(BiNode));
	if (!*L)
		return ERROR;

	(*L)->lchild = NULL;
	(*L)->rchild = NULL;
	(*L)->visited = 1;
	return SUCCESS;
}

Status Insert_BiTree(BiTree L,int data)
{
	if (!L)
		return ERROR;

	if (L->visited == 1)
	{
		L->data = data;
		L->visited = 0;
		return SUCCESS;

	}
	BiNode* t = NULL;
	BiTree p = NULL;

	p = (BiTree)malloc(sizeof(BiNode));
	if (!p)
		return FAIL;

	p->lchild = NULL;
	p->rchild = NULL;
	p->data = data;
	t = L;
	while (t)
	{
		while (t->data >= data)
		{
			if (t->lchild == NULL)
			{
				t->lchild = p;
				t = NULL;
				break;
			}
			t = t->lchild;
		}
		if (!t)
			break;
		else
		{
			while (t->data < data)
			{
				if (t->rchild == NULL)
				{
					t->rchild = p;
					t = NULL;
					break;
				}
				t = t->rchild;
			}
		}
		if (!t)
			break;
	}



	return SUCCESS;

}

Status SearchBiTree(BiTree L, int data)
{
	if (!L)
		return ERROR;

	BiNode* t = NULL;

	t = L;
	int flag = 0;

	while (t)
	{
		if (t->data == data)
		{
			flag = 1;
			break;
		}
		else if (t->lchild && t->data > data)
			t = t->lchild;
		else if (t->rchild && t->data < data)
			t = t->rchild;
		else
			t = NULL;
	}

	if (flag)
		return SUCCESS;
	else
		return ERROR;
}

Status DestroyRoot(BiTree* L)
{
	if (!*L)
		return SUCCESS;
	else
	{
		free(*L);
		*L = NULL;
		return SUCCESS;
	}
}
Status DeleteBiNode(BiTree* L, int data)
{
	if (!*L)
		return ERROR;

	BiNode* t = NULL;
	BiNode* p = NULL;
	t = *L;
	while (t)
	{
		p=t;
		if (t->data == data)
		{
			break;
		}
		else if (t->lchild && t->data > data)
		{
			t = t->lchild;
		}
		else if (t->rchild && t->data < data)
		{
			t = t->rchild;
		}
		else
			t = NULL;
	}
	if (!t)
		return SUCCESS;
	else
	{
		if (p)
		{
			if (t->rchild && t->lchild)
			{
				BiNode* q = t;
				p = t;
				t = t->rchild;
				while (t->lchild)
				{
					p = t;
					t = t->lchild;
				}
				q->data = p->data;
				if (p->lchild == t)
				{
					p->lchild = t->rchild;
					free(t);
					t = NULL;
				}
				else if (p->rchild == t)
				{
					p->rchild = t->rchild;
					free(t);
					t = NULL;
				}
				return SUCCESS;

			}
			if (t->lchild && !t->rchild)
			{
				if (*L == t)
				{
					*L = t->lchild;
					t->lchild = NULL;
					free(t);
					t = NULL;
					return SUCCESS;
				}
				if (p->lchild == t)
				{
					p->lchild = t->lchild;
					t->lchild = NULL;
					free(t);
					t = NULL;
					return SUCCESS;
				}
				else if (p->rchild == t)
				{
					p->rchild = t->lchild;
					t->lchild = NULL;
					free(t);
					t = NULL;
					return SUCCESS;
				}
			}
			if (!t->lchild && t->rchild)
			{
				if (*L == t)
				{
					*L = t->rchild;
					t->rchild = NULL;
					free(t);
					t = NULL;
					return SUCCESS;
				}
				if (p->lchild == t)
				{
					p->lchild = t->rchild;
					t->rchild = NULL;
					free(t);
					t = NULL;
					return SUCCESS;
				}
				else if (p->rchild == t)
				{
					p->rchild = t->rchild;
					t->rchild = NULL;
					free(t);
					t = NULL;
					return SUCCESS;
				}
			}
				
				if (!t->lchild && !t->rchild)
				{
					if (t ==* L)
					{
						DestroyRoot(L);
						t = NULL;
						return SUCCESS;
					}
					else if (p->rchild == t)
					{
						p->rchild = NULL;
						t = NULL;
						return SUCCESS;
					}
					else if (p->lchild == t)
					{
						p->lchild = NULL;
						free(t);
						t = NULL;
						return SUCCESS;
					}

				}
			
		}

	}
	return SUCCESS;
}

void Clear(BiTree L)
{
	if (!L)
		return ;
	else
	{
		L->visited = 0;
		Clear(L->lchild);
		Clear(L->rchild);

	}
}

void visit(BiNode* L)
{
	printf("%d\n", L->data);
}

Status InitStack(BiStackL* S)
{
	*S = (BiStackL)malloc(sizeof(BiStack));
	if (!*S)
		return ERROR;

	(*S)->top = 0;
	for (int k = 0; k < 100; k++)
		(*S)->B[k] = 0;

	return SUCCESS;
}

Status IsEmptyStack(BiStackL S)
{
	if (!S)
		return ERROR;

	if (!S->top)
		return SUCCESS;
	else
		return FAIL;
}

Status PushStack(BiStackL S, BiTree p)
{
	if (!S || !p)
		return ERROR;

	p->visited++;
	S->B[S->top++] = p;
	
	return SUCCESS;
}

Status PopStack(BiStackL S, BiTree* p)
{
	if (!S)
		return ERROR;


	*p = S->B[--S->top];
	(*p)->visited++;
	return SUCCESS;
}


Status PreOrderTraverse(BiTree L)
{
	if (!L)
		return ERROR;
	else
	{
		visit(L);
		PreOrderTraverse(L->lchild);
		PreOrderTraverse(L->rchild);
		return SUCCESS; 
	}
}

Status PreOrderTraverse_(BiTree L)
{
	if (!L)
		return ERROR;

	BiTree p = NULL;
	BiTree q = NULL;
	BiStackL S = NULL;
	InitStack(&S);
	p = L;
	while (p || IsEmptyStack(S)!=SUCCESS)
	{
		if (p)
		{
			PushStack(S, p);
			visit(p);
			p = p->lchild;
		}
		else
		{
			PopStack(S,&q);
			p = q->rchild;
		}
	}

	free(S);
	S = NULL;
	return SUCCESS;
}


Status InOrderTraverse(BiTree L)
{
	if (!L)
		return ERROR;
	else {
		InOrderTraverse(L->lchild);
		visit(L);
		InOrderTraverse(L->rchild);
		return SUCCESS;
	}
}
Status InOrderTraverse_(BiTree L)
{
	if (!L)
		return ERROR;

	BiTree p = NULL;
	BiTree q = NULL;
	BiStackL S = NULL;
	InitStack(&S);
	p = L;
	while (p || IsEmptyStack(S)!=SUCCESS)
	{
		if (p)
		{
			PushStack(S, p);
			p = p->lchild;
		}
		else
		{
			PopStack(S,&q);
			visit(q);
			if (q->rchild)
			{
				p = q->rchild;
			}
		}
	}

	free(S);
	S = NULL;
	return SUCCESS;
}

Status PostOrderTraverse(BiTree L)
{
	if (!L)
		return ERROR;
	else {
		PostOrderTraverse(L->lchild);
		PostOrderTraverse(L->rchild);
		visit(L);
		return SUCCESS;
	}
}

Status PostOrderTraverse_(BiTree L)
{
	if (!L)
		return ERROR;

	BiTree p = NULL;
	BiTree q = NULL;
	BiStackL S = NULL;
	InitStack(&S);
	p = L;
	while (p || IsEmptyStack(S)!=SUCCESS)
	{
		if (p)
		{
			PushStack(S, p);
			p = p->lchild;
		}
		else
		{
			PopStack(S, &q);
			if (q&&q->visited == 3 || !q->rchild)
			{
				visit(q);
				q->visited = 0;
				p = NULL;
			}
			else
			{
				p = q->rchild;
				q->visited--;
				PushStack(S, q);
			}
		
		}

	}

	free(S);
	S = NULL;
	return SUCCESS;
}

Status InitQueue(BiQueueL* qu)
{
	*qu= (BiQueueL)malloc(sizeof(BiQueue));
	if (!*qu)
		return ERROR;

	(*qu)->top = 0;
	for (int k = 0; k < 100; k++)
		(*qu)->B[k] = 0;

	return SUCCESS;
}

Status IsEmptyQueue(BiQueueL qu)
{
	if (!qu)
		return ERROR;

	if (!qu->top)
		return SUCCESS;
	else
		return FAIL;
}

Status PushQueue(BiQueueL qu, BiTree p)
{
	if (!qu || !p)
		return ERROR;

	qu->B[qu->top++] = p;
	return SUCCESS;
}

Status PopQueue(BiQueueL qu, BiTree* p)
{
	if (!qu)
		return ERROR;

	qu->top--;
	*p = qu->B[qu->top];
	return SUCCESS;
}

Status LevelOrder(BiTree L)
{
	if (!L)
		return ERROR;

	BiNode* p = NULL;
	BiQueueL qu = NULL;
	InitQueue(&qu);
	PushQueue(qu, L);
	while (IsEmptyQueue(qu)==FAIL)
	{
		PopQueue(qu, &p);
		visit(p);
		if (p->lchild)
			PushQueue(qu, p->lchild);
		if (p->rchild )
			PushQueue(qu, p->rchild);
	}



	free(qu);
	qu = NULL;

	return SUCCESS;
}