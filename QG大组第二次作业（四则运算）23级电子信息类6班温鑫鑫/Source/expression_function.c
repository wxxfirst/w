#include "expression.h"

//菜单
void menus()
{
	printf("**************************************************************\n");
	printf("**                欢迎使用四则运算求值计算器                **\n");
	printf("**         0、退出计算                1、进行计算操         **\n");
	printf("**               注：本计算器支持多位数字计算               **\n");
	printf("**                   规范格式如：（1+3）*4                  **\n");
	printf("**************************************************************\n");
}

//屏幕清空
void clearScreen()
{
	Sleep(1800);
	system("cls");
}

//链栈
//初始化
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

//判断栈空
Status IsEmpty_Stack(StackLNode s)
{
	if (!s->top)
		return SUCCESS;
	return FAIL;
}


//判断栈满
Status IsFull_Stack(StackLNode s)
{
	if (s->top == 99)
		return SUCCESS;
	return FAIL;
}

//入栈
Status PushStack(StackLNode s,Sign e)
{
	if (!s)
		return FAIL;

	if(s->top<99)
		s->data[s->top++] = e;
	s->data[s->top] = '\0';
	return SUCCESS;
}



//运算符出栈
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


//取运算栈顶元素
Status Get_Top(StackLNode s,Sign* sign)
{

	if (!s->top)
		return FAIL;

	int t = s->top;
	*sign = s->data[--t];
	return SUCCESS;
}
//清空栈
Status clearStack(StackLNode s)
{
	if (!s->top)
		return SUCCESS;
	else
		s->top = 0;
	return SUCCESS;
}


//优先级
int Priority_sign(char sign)
{
	if (sign == '+' || sign == '-')
		return 0;
	else if (sign == '*' || sign == '/')
		return 1;
	else
		return -1;
}

//运算
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

//数字匹配
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

//判断栈空
Status IsEmpty_Stack_(StackLNode_ s)
{
	if (!s->top)
		return SUCCESS;
	return FAIL;
}


//判断栈满
Status IsFull_Stack_(StackLNode_ s)
{
	if (s->top == 99)
		return SUCCESS;
	return FAIL;
}

//入栈
Status PushStack_(StackLNode_ s, double num)
{
	if (!s)
		return FAIL;

	if (s->top < 99)
		s->data[s->top++] = num;
	s->data[s->top] = INT_MAX;
	return SUCCESS;
}



//运算符出栈
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


//取运算栈顶元素
Status Get_Top_(StackLNode_ s, double* num)
{

	if (!s->top)
		return FAIL;

	int t = s->top;
	*num = s->data[--t];
	return SUCCESS;
}

// 清空栈
Status clearStack_(StackLNode_ s)
{
	if (!s->top)
		return SUCCESS;
	else
		s->top = 0;
	return SUCCESS;
}