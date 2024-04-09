#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef enum Status {

	FAIL = -1,
	ERROR,
	SUCCESS
}Status;

typedef struct Sqlist {
	int num[INT_MAX / 4];
	int count;
}Sqlist, * SqlistL;



//�˵�
void menus();



//�������ɺ���
Status data(SqlistL L, int number);

//�ļ�д�뺯��
Status FileSave(SqlistL L);

//�ļ���ȡ����
Status FileRead(SqlistL L);

//ֱ�Ӳ�������
Status InsertupSort(SqlistL L);

//����
Status InsertdownSort(SqlistL L);




//�鲢����
Status MergeupSort(SqlistL L);

Status merge(int num1[], int num2[], int left, int mid, int right);
Status msort(int num1[], int num2[], int left, int right);


//��������ݹ�
Status QupSort_(SqlistL L, int left, int right);

int QSort(SqlistL L, int left, int right);

//��������(0~10)
Status CountSort(SqlistL L);


//������������
//��λ��

Status CountSort_(SqlistL L, int number);
Status RadixCountSort(SqlistL L);

