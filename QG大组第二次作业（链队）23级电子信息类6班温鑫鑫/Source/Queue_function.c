#include "Queue.h"

//菜单
void menus()
{
	printf("************************************************************************\n");
	printf("**                                                                    **\n");
	printf("**                                 menus                              **\n");
	printf("**          1、初始化链队                          2、元素入队        **\n");
	printf("**          3、元素出队                            4、判断队空        **\n");
	printf("**          5、链队长度                            6、队头元素        **\n");
	printf("**          7、队尾元素                            8、清空链队        **\n");
	printf("**          9、销毁链队                            10、打印链队元素   **\n");
	printf("**          0、退出                                                   **\n");
	printf("**                  注：初始化链队后才能进行其他操作                  **\n");
	printf("************************************************************************\n");
}

void ElemTypemenus()
{
	printf("************************************************************************\n");
	printf("**                          ElemType menus                            **\n");
	printf("**               1、int                         2、short int          **\n");
	printf("**               3、long int                    4、bool               **\n");
	printf("**               5、char                        6、float              **\n");
	printf("**               7、double                                            **\n");
	printf("**                                                                    **\n");
	printf("**      注：以上为单个数据的数据类型编号菜单，且可以构造数组类型      **\n");
}
//操作结果显示
void print(Status info)
{
	if (info == SUCCESS)
		printf("操作成功！\n");
	else
		printf("操作失败！\n");
}

//清空屏幕
void clearScreen()
{
	Sleep(1000);
	system("cls");
}

//循环队列
//构造队列
Status InitQueue(QueueL* s)
{
	(*s) = (QueueL)malloc(sizeof(Queue));
	if (!(*s))
		return FAIL;

	(*s)->top = NULL;
	(*s)->rear =  NULL;
	(*s)->count = 0;

	return SUCCESS;
}

//判断队空
Status isEmpty_LQueue(QueueL s)
{
	if (!s)
		return FAIL;
	else if (!s->count)
		return SUCCESS;
	else
		return ERROR;
}

//入队+数据类型转化
Status pushLQueue(QueueL s, void* data,size_t number,size_t n)
{
	if (!s)
		return FAIL;

	if (number<=0||n <= 0)
		return ERROR;

	QueueLNode t = NULL;

	t = (QueueLNode)malloc(sizeof(QueueNode));

	if (!t)
		return ERROR;

	switch (number)
	{
	case 1:
		if (n == 1)
			printf("你的选择是int型数据\n");
		else
			printf("你的选择是int型数组\n");

		(int*)data = (int*)malloc(n * sizeof(int));
		if (!data)
			return ERROR;
		printf("请输入元素值：");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &((int*)data)[i]);
			if (((int*)data)[i] > INT_MAX || ((int*)data)[i] < INT_MIN);
		}

		printf("\n");
		t->data = (int*)data;
		break;

	case 2:
		if (n == 1)
			printf("你的选择是short int型数据\n");
		else
			printf("你的选择是short int型数组\n");

		(short int*)data = (short int*)malloc(n * sizeof(short int));
		if (!data)
			return ERROR;

		printf("请输入元素值：");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%hd", &((short int*)data)[i]);
			if (((short int*)data)[i] > SHRT_MAX || ((short int*)data)[i] < SHRT_MIN)
				i--;
		}
		printf("\n");
		t->data = (short int*)data;
		break;

	case 3:
		if (n == 1)
			printf("你的选择是long int型数据\n");
		else
			printf("你的选择是long int型数组\n");

		(long int*)data = (long int*)malloc(n * sizeof(long int));
		if (!data)
			return ERROR;
		printf("请输入元素值：");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%ld", &((long int*)data)[i]);
			if (((short int*)data)[i] >  LONG_MAX || ((short int*)data)[i] <LONG_MIN)
				i--;
		}
		printf("\n");
		t->data = (long int*)data;
		break;

	case 4:
		if (n == 1)
		{
			printf("你的选择是bool型数据\n");
			(bool*)data = (bool*)malloc(sizeof(bool));
			if (!data)
				return ERROR;

			int num = 1;
			while (num)
			{
				printf("请输入元素值(0—False,1—True)：");
				int flag = 0;

				do {
					if (scanf_s("%d", &num) == 0)
					{
						rewind(stdin);
						printf("数据非法！请重新输入！\n");
						flag = 1;
					}
					else
						flag = 0;
				} while (flag);

				switch (num)
				{
				case 0:
					*((bool*)data) = false;
					num = 0;
					break;

				case 1:
					*((bool*)data) = true;
					num = 0;
					break;

				default:
					printf("数据非法！请重新输入！\n");
					num = 1;
					break;
				}

				rewind(stdin);
			}

		}
		else
		{
			printf("你的选择是bool数组\n");
			(bool*)data = (bool*)malloc(n*sizeof(bool));
			if (!data)
				return ERROR;

			for (int i = 0; i < n; i++)
			{
				int num = 1;
				while (num)
				{
					printf("请输入元素值(0—False,1—True)：");
					int flag = 0;

					do {
						if (scanf_s("%d", &num) == 0)
						{
							rewind(stdin);
							printf("数据非法！请重新输入！\n");
							flag = 1;
						}
						else
							flag = 0;
					} while (flag);

					switch (num)
					{
					case 0:
						((bool*)data)[i] = false;
						num = 0;
						break;

					case 1:
						((bool*)data)[i] = true;
						num = 0;
						break;

					default:
						printf("数据非法！请重新输入！\n");
						num = 1;
						break;
					}

					rewind(stdin);
				}
			}
		}
		t->data = (bool*)data;
		break;

	case 5:
		if (n == 1)
		{
			printf("你的选择是char型数据\n");
			(char*)data = (char*)malloc(n * sizeof(char));
			if (!data)
				return ERROR;

			printf("请输入元素值：");
			scanf_s("%c", (char*)data);
			printf("\n");
		}
		else
		{
			printf("你的选择是char型数组(字符串）\n");
			(char*)data = (char*)malloc((n+1) * sizeof(char));
			if (!data)
				return ERROR;

			printf("请输入元素值：");
			scanf_s("%s", (char*)data);
			printf("\n");
		}

		t->data = (char*)data;
		break;

	case 6:
		if (n == 1)
			printf("你的选择是float型数据\n");
		else
			printf("你的选择是float型数组\n");

		(float*)data = (float*)malloc(n * sizeof(float));
		if (!data)
			return ERROR;

		printf("请输入元素值：");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%f", &((float*)data)[i]);
		}
		printf("\n");

		t->data = (float*)data;
		break;

	case 7:
		if (n == 1)
			printf("你的选择是double型数据\n");
		else
			printf("你的选择是double型数组\n");

		(double*)data = (double*)malloc(n * sizeof(double));
		if (!data)
			return ERROR;
		printf("请输入元素值：");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%lf", &((double*)data)[i]);
		}
		printf("\n");
		t->data = (double*)data;
		break;

	default:
		printf("输入的数据非法\n");
		rewind(stdin);
		break;
	}

		
	t->num = number;
	t->n = n;

	t->next = NULL;

	if (!s->top)
	{
		s->top = t;
	}
	else
	{
		s->rear->next = t;
	}
	s->rear = t;

	s->count++;

	return SUCCESS;
}
	
//出队+数据类型转化
Status popLQueue(QueueL s,void* elem)
{
	if (!s)
		return FAIL;

	if (!s->count)
		return ERROR;

	QueueLNode t = NULL;

	t = s->top;
	elem = t->data;

	switch (t->num)
	{
	case 1:
		printf("出队元素为：");
		for (int i = 0; i < t->n; i++)
			printf("%d ", ((int*)t->data)[i]);
		printf("\n");

		break;

	case 2:
		printf("出队元素为：");
		for (int i = 0; i < t->n; i++)
			printf("%hd ", ((short int*)t->data)[i]);
		printf("\n");
		break;

	case 3:
		printf("出队元素为：");
		for (int i = 0; i < t->n; i++)
			printf("%ld ", ((long int*)t->data)[i]);
		printf("\n");
		break;

		//bool型
	case 4:
		printf("bool型数据以int形式输出\n");
		printf("出队元素为：");
		for (int i = 0; i < t->n; i++)
			printf("%d", ((bool*)t->data)[i]);
		printf("\n");
		break;
	
	case 5:
		printf("出队元素为：");
		if (t->n == 1)
			printf("%c ", *((char*)t->data));

		else
			printf("%s ", (char*)t->data);
		printf("\n");
		break;

	case 6:
		printf("出队元素为：");
		for (int i = 0; i < t->n; i++)
			printf("%f ", ((float*)t->data)[i]);
		printf("\n");
		break;

	case 7:
		printf("出队元素为：");
		for (int i = 0; i < t->n; i++)
			printf("%lf ", ((double*)t->data)[i]);
		printf("\n");
		break;

	default:
		printf("元素非法！\n");
		break;
	}

	s->top = s->top->next;
	free(t);
	t = NULL;
	s->count--;

	return SUCCESS;
}

Status Get_Top(QueueL s, void* elem)
{
	if (!s)
		return FAIL;

	if (!s->count)
		return  ERROR;

	elem = s->top->data;

	switch (s->top->num)
	{
	case 1:
		printf("队头元素为：");
		for (int i = 0; i < s->top->n; i++)
			printf("%d ", ((int*)s->top->data)[i]);
		printf("\n");
		break;

	case 2:
		printf("队头元素为：");
		for (int i = 0; i < s->top->n; i++)
			printf("%hd ", ((short int*)s->top->data)[i]);
		printf("\n");
		break;

	case 3:
		printf("队头元素为：");
		for (int i = 0; i < s->top->n; i++)
				printf("%ld ", ((long int*)s->top->data)[i]);
		printf("\n");
		break;

		//bool型
	case 4:
		printf("bool型数据以int形式输出\n");
		printf("队头元素为：");
		for (int i = 0; i < s->top->n; i++)
			printf("%d", *((bool*)s->top->data));
		printf("\n");
		break;

	case 5:
		printf("队头元素为：");
		if (s->top->n == 1)
			printf("%c ", *((char*)s->top->data));

		else
			printf("%s", (char*)s->top->data);
		printf("\n");
		break;

	case 6:
		printf("队头元素为：");
		for (int i = 0; i < s->top->n; i++)
			printf("%f ", ((float*)s->top->data)[i]);
		
		printf("\n");
		break;

	case 7:
		printf("队头元素为：");
		for (int i = 0; i < s->top->n; i++)
			printf("%lf ", ((double*)s->top->data)[i]);
		printf("\n");
		break;

	default:
		printf("元素非法！\n");
		break;
	}
	return SUCCESS;
}

//取队尾元素
Status Get_Rear(QueueL s, void* elem)
{
	if (!s)
		return FAIL;

	if (!s->count)
		return  ERROR;

	elem = s->rear->data;

	switch (s->rear->num)
	{
	case 1:
		printf("队尾元素为：");
		for (int i = 0; i < s->rear->n; i++)
			printf("%d ", ((int*)s->rear->data)[i]);
		printf("\n");

		break;

	case 2:
		printf("队尾元素为：");
		for (int i = 0; i < s->rear->n; i++)
			printf("%hd ", ((short int*)s->rear->data)[i]);
		printf("\n");
		break;

	case 3:
		printf("队尾元素为：");
		for (int i = 0; i < s->rear->n; i++)
			printf("%ld ", ((long int*)s->rear->data)[i]);
		printf("\n");
		break;

		//bool型
	case 4:
		printf("bool型元素以int形式输出\n");
		printf("队尾元素为：");
		for (int i = 0; i < s->rear->n; i++)
			printf("%d", *((bool*)s->rear->data));
		printf("\n");
		break;

	case 5:
		printf("队尾元素为：");
		if (s->rear->n == 1)
			printf("%c ", *((char*)s->rear->data));

		else
			printf("%s ", (char*)s->rear->data);
		printf("\n");
		break;

	case 6:
		printf("队尾元素为：");
		for (int i = 0; i < s->rear->n; i++)
			printf("%f ", ((float*)s->rear->data)[i]);
		printf("\n");
		break;

	case 7:
		printf("队尾元素为：");
		for (int i = 0; i < s->rear->n; i++)
			printf("%lf ", ((double*)s->rear->data)[i]);
		printf("\n");
		break;

	default:
		printf("元素非法！\n");
		break;
	}
	return SUCCESS;
}


//清空队列
Status ClearQueue(QueueL s)
{
	if (!s)
		return FAIL;

	if (!s->count)
		return  SUCCESS;

	QueueLNode t = NULL;

	while (s->top)
	{
		t = s->top;
		s->top = s->top->next;
		free(t->data);
		t->num = 0;
		free(t);
		t = NULL;
	}

	s->top = NULL;
	s->rear = NULL;
	s->count = 0;

	return SUCCESS;

}

//队长度
Status LengthQueue(QueueL s, int* length)
{
	if (!s)
		return FAIL;

	*length = s->count;
	return SUCCESS;
}

//销毁队列
Status DestroyQueue(QueueL* s)
{
	if (!(*s))
		return SUCCESS;

	Status result = ClearQueue((*s));

	if (result == 1)
	{
		free((*s));
		(*s) = NULL;
		return  SUCCESS;
	}
	else
		return ERROR;
}

//遍历队列并打印数据
Status printQueue(QueueL s)
{
	if (!s)
		return  FAIL;

	if (!s->count)
		return ERROR;

	QueueLNode t = NULL;

	t = s->top;
	while (t)
	{
		switch (t->num)
		{
		case 1:
			for (int i = 0; i < t->n; i++)
				printf("%d ", ((int*)t->data)[i]);
			printf("\n");
			break;

		case 2:
			for (int i = 0; i < t->n; i++)
				printf("%hd ", ((short int*)t->data)[i]);
			printf("\n");
			break;

		case 3:
			for (int i = 0; i < t->n; i++)
				printf("%ld ", ((long int*)t->data)[i]);
			printf("\n");
			break;

			//bool型
		case 4:
			printf("bool型数据以int形式输出\n");
			for (int i = 0; i < t->n; i++)
				printf("%d ", ((bool*)t->data)[i]);
			printf("\n");
			break;

		case 5:
			if (t->n == 1)
				printf("%c ", *((char*)t->data));

			else
				printf("%s ", (char*)t->data);

			printf("\n");
			break;

		case 6:
			for (int i = 0; i < t->n; i++)
				printf("%f ", ((float*)t->data)[i]);
			printf("\n");
			break;

		case 7:
			for (int i = 0; i < t->n; i++)
				printf("%lf ", ((double*)t->data)[i]);
			printf("\n");
			break;

		default:
			printf("数据非法！\n");
			break;

		}
		
		t = t->next;
	}

	return SUCCESS;
}
 

