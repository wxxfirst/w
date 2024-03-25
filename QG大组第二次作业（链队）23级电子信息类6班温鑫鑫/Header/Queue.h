#define _CRT_SECURE_NO_WARNINGS

#ifndef Queue_H_INCLUDED
#define Queue_H_INCLUDED
#define ERROR 0
#define SUCCESS 1
#define FAIL -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

typedef char Status;

typedef struct QueueNode {
	void* data;
	size_t num, n;
	struct QueueNode* next;
}QueueNode,*QueueLNode;

typedef struct Queue {
	QueueLNode  top;
	QueueLNode  rear;
	int count;
}Queue,*QueueL;

//菜单
void menus();

//数据类型
void ElemTypemenus();

//操作结果显示函数
void print(Status info);

//清除屏幕
void clearScreen();


//循环队列
//构造队列
Status InitQueue(QueueL* s);

//判断队空
Status isEmpty_LQueue(QueueL s);


//入队
Status pushLQueue(QueueL s, void* data,size_t number,size_t n);

//出队
Status popLQueue(QueueL s, void* elem);

//取队头
Status Get_Top(QueueL s, void* elem);

//取队尾
Status Get_Rear(QueueL s, void* elem);

//清空队列
Status ClearQueue(QueueL s);

//统计队长
Status LengthQueue(QueueL s, int* length);

//销毁队列
Status DestroyQueue(QueueL* s);

//遍历队列并打印数据
Status printQueue(QueueL s);

#endif