#include "expression.h"

//�˵�
void menus()
{
	printf("**************************************************************\n");
	printf("**                ��ӭʹ������������ֵ������                **\n");
	printf("**         0���˳�����                1�����м����         **\n");
	printf("**               ע����������֧�ֶ�λ���ּ���               **\n");
	printf("**                   �淶��ʽ�磺��1+3��*4                  **\n");
	printf("**************************************************************\n");
}

//��Ļ���
void clearScreen()
{
	Sleep(1800);
	system("cls");
}

//��ջ
//��ʼ��
void print(Status q)
{
	;
}

Status InitStack(StackLNode* s)
{
	(*s) = (StackLNode)malloc(sizeof(StackNode));
	if (!(*s))
		return  FAIL;

	(*s)->top = 0;
	return  SUCCESS;
}

//�ж�ջ��
Status IsEmpty_Stack(StackLNode s)
{
	if (!s->top)
		return SUCCESS;
	return FAIL;
}


//�ж�ջ��
Status IsFull_Stack(StackLNode s)
{
	if (s->top == 99)
		return SUCCESS;
	return FAIL;
}

//��ջ
Status PushStack(StackLNode s,Sign e)
{
	if (!s)
		return FAIL;

	if(s->top<99)
		s->data[s->top++] = e;
	s->data[s->top] = '\0';
	return SUCCESS;
}



//�������ջ
Status PopStack(StackLNode s)
{
	if (!s)
		return FAIL;

	if (!s->top)
		return FAIL;

	int t = 0;
	t = --s->top;
	s->data[t] = '\0';

	return SUCCESS;
	
}


//ȡ����ջ��Ԫ��
Status Get_Top(StackLNode s,Sign* sign)
{

	if (!s->top)
		return FAIL;

	int t = s->top;
	*sign = s->data[--t];
	return SUCCESS;
}
//���ջ
Status clearStack(StackLNode s)
{
	if (!s->top)
		return SUCCESS;
	else
		s->top = 0;
	return SUCCESS;
}


//���ȼ�
int Priority_sign(char sign)
{
	if (sign == '+' || sign == '-')
		return 0;
	else if (sign == '*' || sign == '/')
		return 1;
	else
		return -1;
}

//����
double Result(int priority,double e1, double e2,char sign)
{
	if (priority == 0)
	{
		if (sign == '+')
			return e1 + e2;
		else
			return e1 - e2;
	}
	else 
	{
		if (sign == '*')
			return e1 * e2;
		else
			return e1 / e2;
	}


}

//����ƥ��
void match(char sign_number,double * e)
{
	switch (sign_number)
	{
	case '0':
		*e = 0;
		break;
	case '1':
		*e = 1;
		break;
	case '2':
		*e = 2;
		break;
	case '3':
		*e = 3;
		break;
	case '4':
		*e = 4;
		break;
	case '5':
		*e = 5;
		break;
	case '6':
		*e = 6;
		break;
	case '7':
		*e = 7;
		break;
	case '8':
		*e = 8;
		break;
	case '9':
		*e = 9;
		break;
	default:
		break;
	}
	return;
}

Status InitStack_(StackLNode_* s)
{
	(*s) = (StackLNode_)malloc(sizeof(StackNode_));
	if (!(*s))
		return  FAIL;

	(*s)->top = 0;
	return  SUCCESS;
}

//�ж�ջ��
Status IsEmpty_Stack_(StackLNode_ s)
{
	if (!s->top)
		return SUCCESS;
	return FAIL;
}


//�ж�ջ��
Status IsFull_Stack_(StackLNode_ s)
{
	if (s->top == 99)
		return SUCCESS;
	return FAIL;
}

//��ջ
Status PushStack_(StackLNode_ s, double num)
{
	if (!s)
		return FAIL;

	if (s->top < 99)
		s->data[s->top++] = num;
	s->data[s->top] = INT_MAX;
	return SUCCESS;
}



//�������ջ
Status PopStack_(StackLNode_ s)
{
	if (!s)
		return FAIL;

	if (!s->top)
		return FAIL;

	int t = 0;
	t = --s->top;
	s->data[t] = INT_MAX;


	return SUCCESS;

}


//ȡ����ջ��Ԫ��
Status Get_Top_(StackLNode_ s, double* num)
{

	if (!s->top)
		return FAIL;

	int t = s->top;
	*num = s->data[--t];
	return SUCCESS;
}

// ���ջ
Status clearStack_(StackLNode_ s)
{
	if (!s->top)
		return SUCCESS;
	else
		s->top = 0;
	return SUCCESS;
}