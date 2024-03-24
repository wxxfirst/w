#include "stack.h"

//�˵�����ѡ��
void menus()
{
	printf("********************************************************************\n");
	printf("*                             menus                                *\n");
	printf("*    0���˳�                                  1����ʼ��ջ          *\n");
	printf("*    2����ջ                                  3����ջ              *\n");
	printf("*    4���жϿ�ջ                              5��ȡ��ջ��Ԫ��      *\n");
	printf("*    6�����ջ                                7������ջ            *\n");
	printf("*    8��ͳ��ջ��                              9����ӡջ            *\n");
	printf("********************************************************************\n");
	printf("**               ע����ʼ��ջ���ܽ�����������                     **\n");

}
//��ʾ���
void print(Status info)
{
	if (info==SUCCESS)
		printf("�����ɹ���\n");
	else
		printf("����ʧ�ܣ�\n");
}
//�����ʾ��
void clearScreen()
{
	Sleep(600);
	system("cls");
}


//��ʼ��ջ
Status initLStack(LinkStackP* s)
{
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));

	(*s)->top = NULL;
	(*s)->count = 0;

	return SUCCESS;
}

//�ж�ջ��
Status isEmpty_LStack(LinkStack * s)
{
	if (!s)
		return FAIL;
	else if (!s->top || !s->count)
		return SUCCESS;
	else
		return ERROR;
}

//��ջ
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

//��ջ
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

//ȡ��ջ��Ԫ��
Status getTopLStack(LinkStack* s,ElemType* e)
{
	if (!s)
		return FAIL;

	if (!s->top)
		return ERROR;

	*e = s->top->data;

	return SUCCESS;
}

//���ջԪ��
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

//����ջ
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

//��ӡջ
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

//ͳ��ջ����
Status LStackLength(LinkStack* s, int* length)
{

	if (!s)
		return ERROR;

	*length = s->count;

	return SUCCESS;
}
