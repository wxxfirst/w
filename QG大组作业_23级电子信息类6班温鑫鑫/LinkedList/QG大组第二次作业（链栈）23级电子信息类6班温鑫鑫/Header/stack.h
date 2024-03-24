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
//�˵�����ѡ��

void print(Status info);
//���������ʾ

void clearScreen();
//�����ʾ��

//��ջ

Status initLStack(LinkStackP* s);
//��ʼ��ջ

Status isEmpty_LStack(LinkStack* s);
//�ж�ջ�Ƿ�Ϊ��

Status getTopLStack(LinkStack* s, ElemType* e);
//�õ�ջ��Ԫ��

Status clearLStack(LinkStack* s);
//���ջ

Status destroyLStack(LinkStackP* s);
//����ջ

Status LStackLength(LinkStack* s, int* length);
//���ջ����

Status pushLStack(LinkStack* s, ElemType data);
//��ջ

Status popLStack(LinkStack* s, ElemType* data);
//��ջ

Status printStack(LinkStack* s);
//��ӡջ


#endif 
