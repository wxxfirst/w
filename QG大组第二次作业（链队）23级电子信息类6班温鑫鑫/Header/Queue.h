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

//�˵�
void menus();

//��������
void ElemTypemenus();

//���������ʾ����
void print(Status info);

//�����Ļ
void clearScreen();


//ѭ������
//�������
Status InitQueue(QueueL* s);

//�ж϶ӿ�
Status isEmpty_LQueue(QueueL s);


//���
Status pushLQueue(QueueL s, void* data,size_t number,size_t n);

//����
Status popLQueue(QueueL s, void* elem);

//ȡ��ͷ
Status Get_Top(QueueL s, void* elem);

//ȡ��β
Status Get_Rear(QueueL s, void* elem);

//��ն���
Status ClearQueue(QueueL s);

//ͳ�ƶӳ�
Status LengthQueue(QueueL s, int* length);

//���ٶ���
Status DestroyQueue(QueueL* s);

//�������в���ӡ����
Status printQueue(QueueL s);

#endif