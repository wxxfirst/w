#include "stack.h"

//菜单功能选择
void menus()
{
	printf("********************************************************************\n");
	printf("*                             menus                                *\n");
	printf("*    0、退出                                  1、初始化栈          *\n");
	printf("*    2、入栈                                  3、出栈              *\n");
	printf("*    4、判断空栈                              5、取出栈顶元素      *\n");
	printf("*    6、清空栈                                7、销毁栈            *\n");
	printf("*    8、统计栈长                              9、打印栈            *\n");
	printf("********************************************************************\n");
	printf("**               注：初始化栈才能进行其他操作                     **\n");

}
//显示结果
void print(Status info)
{
	if (info==SUCCESS)
		printf("操作成功！\n");
	else
		printf("操作失败！\n");
}
//清除显示屏
void clearScreen()
{
	Sleep(600);
	system("cls");
}


//初始化栈
Status initLStack(LinkStackP* s)
{
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));

	(*s)->top = NULL;
	(*s)->count = 0;

	return SUCCESS;
}

//判断栈空
Status isEmpty_LStack(LinkStack * s)
{
	if (!s)
		return FAIL;
	else if (!s->top || !s->count)
		return SUCCESS;
	else
		return ERROR;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	if (!s)
		return FAIL;

	LinkStackPtr t = NULL;

	t = (LinkStackPtr)malloc(sizeof(StackNode));

	if (!t)
		return ERROR;

	t->data = data;
	t->next = s->top;
	s->top = t;
	s->count++;

	return SUCCESS;

}

//出栈
Status popLStack(LinkStack* s,ElemType * data)
{
	if (!s)
		return FAIL;

	if (!s->top)
		return  ERROR;

	LinkStackPtr t = NULL;

	t = s->top;
	*data = t->data;
	s->top = s->top->next;
	free(t);
	t = NULL;
	s->count--;

	return SUCCESS;

}

//取出栈顶元素
Status getTopLStack(LinkStack* s,ElemType* e)
{
	if (!s)
		return FAIL;

	if (!s->top)
		return ERROR;

	*e = s->top->data;

	return SUCCESS;
}

//清空栈元素
Status clearLStack(LinkStack* s)
{
	if (!s)
		return ERROR;

	if (!s->top||!s->count)
		return SUCCESS;

	LinkStackPtr t = s->top;

	while (s->top)
	{
		t = s->top;
		s->top = s->top->next;
		free(t);
		t = NULL;
	}

	s->count = 0;

	return SUCCESS;

}

//销毁栈
Status destroyLStack(LinkStackP* s)
{
	if (!(*s))
		return SUCCESS;

	LinkStack* p = *s;

	Status clearLStack(p);

	free(*s);

	*s = NULL;

	return SUCCESS;
}

//打印栈
Status printStack(LinkStack* s)
{
	if (!s)
		return FAIL;

	if (!s->count)
		return ERROR;

	LinkStackPtr t = NULL;

	t = s->top;

	while (t)
	{
		printf("%d ", t->data);
		t = t->next;
	}

	return SUCCESS;
}

//统计栈长度
Status LStackLength(LinkStack* s, int* length)
{

	if (!s)
		return ERROR;

	*length = s->count;

	return SUCCESS;
}
