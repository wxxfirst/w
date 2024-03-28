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


//菜单
void menus();

//屏幕清空
void clearScreen();

//链栈
//初始化
Status InitStack(StackLNode* s);


//判断栈空
Status IsEmpty_Stack(StackLNode s);

//判断栈满
Status IsFull_Stack(StackLNode s);

//入栈
Status PushStack(StackLNode s, Sign e);

//出栈
Status PopStack(StackLNode s);

//取栈顶元素
Status Get_Top(StackLNode s, Sign* e);

//清空栈
Status clearStack(StackLNode s);

//数字匹配
void match(char sign_number, double* e);

//运算
double Result(int priority, double e1, double e2, char sign);

//优先级
int Priority_sign(char sign);

////初始化
Status InitStack_(StackLNode_* s);


//判断栈空
Status IsEmpty_Stack_(StackLNode_ s);

//判断栈满
Status IsFull_Stack_(StackLNode_ s);

//入栈
Status PushStack_(StackLNode_ s, double num);

//出栈
Status PopStack_(StackLNode_ s);

//取栈顶元素
Status Get_Top_(StackLNode_ s, double* num);

//清空栈
Status clearStack_(StackLNode_ s);