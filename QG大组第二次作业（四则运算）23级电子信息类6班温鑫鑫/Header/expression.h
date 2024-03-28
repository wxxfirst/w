#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define Maxsize 100

typedef char Sign;


typedef enum Status {
	FAIL = 0,
	SUCCESS
}Status;

typedef struct StackNode {
	char data[100];
	int top;
}StackNode, * StackLNode;

typedef struct StackNode_ {
	double data[100];
	int top;
}StackNode_, * StackLNode_;


//�˵�
void menus();

//��Ļ���
void clearScreen();

//��ջ
//��ʼ��
Status InitStack(StackLNode* s);


//�ж�ջ��
Status IsEmpty_Stack(StackLNode s);

//�ж�ջ��
Status IsFull_Stack(StackLNode s);

//��ջ
Status PushStack(StackLNode s, Sign e);

//��ջ
Status PopStack(StackLNode s);

//ȡջ��Ԫ��
Status Get_Top(StackLNode s, Sign* e);

//���ջ
Status clearStack(StackLNode s);

//����ƥ��
void match(char sign_number, double* e);

//����
double Result(int priority, double e1, double e2, char sign);

//���ȼ�
int Priority_sign(char sign);

////��ʼ��
Status InitStack_(StackLNode_* s);


//�ж�ջ��
Status IsEmpty_Stack_(StackLNode_ s);

//�ж�ջ��
Status IsFull_Stack_(StackLNode_ s);

//��ջ
Status PushStack_(StackLNode_ s, double num);

//��ջ
Status PopStack_(StackLNode_ s);

//ȡջ��Ԫ��
Status Get_Top_(StackLNode_ s, double* num);

//���ջ
Status clearStack_(StackLNode_ s);