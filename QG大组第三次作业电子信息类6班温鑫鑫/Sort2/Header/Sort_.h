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



//菜单
void menus();



//数据生成函数
Status data(SqlistL L, int number);

//文件写入函数
Status FileSave(SqlistL L);

//文件读取函数
Status FileRead(SqlistL L);

//直接插入升序法
Status InsertupSort(SqlistL L);

//降序
Status InsertdownSort(SqlistL L);




//归并排序
Status MergeupSort(SqlistL L);

Status merge(int num1[], int num2[], int left, int mid, int right);
Status msort(int num1[], int num2[], int left, int right);


//快速排序递归
Status QupSort_(SqlistL L, int left, int right);

int QSort(SqlistL L, int left, int right);

//计数排序(0~10)
Status CountSort(SqlistL L);


//基数计数排序
//百位数

Status CountSort_(SqlistL L, int number);
Status RadixCountSort(SqlistL L);

