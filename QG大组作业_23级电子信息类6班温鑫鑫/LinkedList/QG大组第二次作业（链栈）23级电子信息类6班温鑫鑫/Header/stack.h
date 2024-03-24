#define  _CRT_SECURE_NO_WARNINGS

#ifndef stack_H_INCLUDED
#define stack_H_INCLUDED
#define ERROR 0
#define SUCCESS 1
#define FAIL -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <windows.h>
#include <math.h>

typedef char Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack, * LinkStackP;

void menus();
//菜单功能选择

void print(Status info);
//操作结果显示

void clearScreen();
//清除显示屏

//链栈

Status initLStack(LinkStackP* s);
//初始化栈

Status isEmpty_LStack(LinkStack* s);
//判断栈是否为空

Status getTopLStack(LinkStack* s, ElemType* e);
//得到栈顶元素

Status clearLStack(LinkStack* s);
//清空栈

Status destroyLStack(LinkStackP* s);
//销毁栈

Status LStackLength(LinkStack* s, int* length);
//检测栈长度

Status pushLStack(LinkStack* s, ElemType data);
//入栈

Status popLStack(LinkStack* s, ElemType* data);
//出栈

Status printStack(LinkStack* s);
//打印栈


#endif 
