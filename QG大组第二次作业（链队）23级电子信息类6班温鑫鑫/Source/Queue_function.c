#include "Queue.h"

//�˵�
void menus()
{
	printf("************************************************************************\n");
	printf("**                                                                    **\n");
	printf("**                                 menus                              **\n");
	printf("**          1����ʼ������                          2��Ԫ�����        **\n");
	printf("**          3��Ԫ�س���                            4���ж϶ӿ�        **\n");
	printf("**          5�����ӳ���                            6����ͷԪ��        **\n");
	printf("**          7����βԪ��                            8���������        **\n");
	printf("**          9����������                            10����ӡ����Ԫ��   **\n");
	printf("**          0���˳�                                                   **\n");
	printf("**                  ע����ʼ�����Ӻ���ܽ�����������                  **\n");
	printf("************************************************************************\n");
}

void ElemTypemenus()
{
	printf("************************************************************************\n");
	printf("**                          ElemType menus                            **\n");
	printf("**               1��int                         2��short int          **\n");
	printf("**               3��long int                    4��bool               **\n");
	printf("**               5��char                        6��float              **\n");
	printf("**               7��double                                            **\n");
	printf("**                                                                    **\n");
	printf("**      ע������Ϊ�������ݵ��������ͱ�Ų˵����ҿ��Թ�����������      **\n");
}
//���������ʾ
void print(Status info)
{
	if (info == SUCCESS)
		printf("�����ɹ���\n");
	else
		printf("����ʧ�ܣ�\n");
}

//�����Ļ
void clearScreen()
{
	Sleep(1000);
	system("cls");
}

//ѭ������
//�������
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

//�ж϶ӿ�
Status isEmpty_LQueue(QueueL s)
{
	if (!s)
		return FAIL;
	else if (!s->count)
		return SUCCESS;
	else
		return ERROR;
}

//���+��������ת��
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
			printf("���ѡ����int������\n");
		else
			printf("���ѡ����int������\n");

		(int*)data = (int*)malloc(n * sizeof(int));
		if (!data)
			return ERROR;
		printf("������Ԫ��ֵ��");
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
			printf("���ѡ����short int������\n");
		else
			printf("���ѡ����short int������\n");

		(short int*)data = (short int*)malloc(n * sizeof(short int));
		if (!data)
			return ERROR;

		printf("������Ԫ��ֵ��");
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
			printf("���ѡ����long int������\n");
		else
			printf("���ѡ����long int������\n");

		(long int*)data = (long int*)malloc(n * sizeof(long int));
		if (!data)
			return ERROR;
		printf("������Ԫ��ֵ��");
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
			printf("���ѡ����bool������\n");
			(bool*)data = (bool*)malloc(sizeof(bool));
			if (!data)
				return ERROR;

			int num = 1;
			while (num)
			{
				printf("������Ԫ��ֵ(0��False,1��True)��");
				int flag = 0;

				do {
					if (scanf_s("%d", &num) == 0)
					{
						rewind(stdin);
						printf("���ݷǷ������������룡\n");
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
					printf("���ݷǷ������������룡\n");
					num = 1;
					break;
				}

				rewind(stdin);
			}

		}
		else
		{
			printf("���ѡ����bool����\n");
			(bool*)data = (bool*)malloc(n*sizeof(bool));
			if (!data)
				return ERROR;

			for (int i = 0; i < n; i++)
			{
				int num = 1;
				while (num)
				{
					printf("������Ԫ��ֵ(0��False,1��True)��");
					int flag = 0;

					do {
						if (scanf_s("%d", &num) == 0)
						{
							rewind(stdin);
							printf("���ݷǷ������������룡\n");
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
						printf("���ݷǷ������������룡\n");
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
			printf("���ѡ����char������\n");
			(char*)data = (char*)malloc(n * sizeof(char));
			if (!data)
				return ERROR;

			printf("������Ԫ��ֵ��");
			scanf_s("%c", (char*)data);
			printf("\n");
		}
		else
		{
			printf("���ѡ����char������(�ַ�����\n");
			(char*)data = (char*)malloc((n+1) * sizeof(char));
			if (!data)
				return ERROR;

			printf("������Ԫ��ֵ��");
			scanf_s("%s", (char*)data);
			printf("\n");
		}

		t->data = (char*)data;
		break;

	case 6:
		if (n == 1)
			printf("���ѡ����float������\n");
		else
			printf("���ѡ����float������\n");

		(float*)data = (float*)malloc(n * sizeof(float));
		if (!data)
			return ERROR;

		printf("������Ԫ��ֵ��");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%f", &((float*)data)[i]);
		}
		printf("\n");

		t->data = (float*)data;
		break;

	case 7:
		if (n == 1)
			printf("���ѡ����double������\n");
		else
			printf("���ѡ����double������\n");

		(double*)data = (double*)malloc(n * sizeof(double));
		if (!data)
			return ERROR;
		printf("������Ԫ��ֵ��");
		for (int i = 0; i < n; i++)
		{
			scanf_s("%lf", &((double*)data)[i]);
		}
		printf("\n");
		t->data = (double*)data;
		break;

	default:
		printf("��������ݷǷ�\n");
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
	
//����+��������ת��
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
		printf("����Ԫ��Ϊ��");
		for (int i = 0; i < t->n; i++)
			printf("%d ", ((int*)t->data)[i]);
		printf("\n");

		break;

	case 2:
		printf("����Ԫ��Ϊ��");
		for (int i = 0; i < t->n; i++)
			printf("%hd ", ((short int*)t->data)[i]);
		printf("\n");
		break;

	case 3:
		printf("����Ԫ��Ϊ��");
		for (int i = 0; i < t->n; i++)
			printf("%ld ", ((long int*)t->data)[i]);
		printf("\n");
		break;

		//bool��
	case 4:
		printf("bool��������int��ʽ���\n");
		printf("����Ԫ��Ϊ��");
		for (int i = 0; i < t->n; i++)
			printf("%d", ((bool*)t->data)[i]);
		printf("\n");
		break;
	
	case 5:
		printf("����Ԫ��Ϊ��");
		if (t->n == 1)
			printf("%c ", *((char*)t->data));

		else
			printf("%s ", (char*)t->data);
		printf("\n");
		break;

	case 6:
		printf("����Ԫ��Ϊ��");
		for (int i = 0; i < t->n; i++)
			printf("%f ", ((float*)t->data)[i]);
		printf("\n");
		break;

	case 7:
		printf("����Ԫ��Ϊ��");
		for (int i = 0; i < t->n; i++)
			printf("%lf ", ((double*)t->data)[i]);
		printf("\n");
		break;

	default:
		printf("Ԫ�طǷ���\n");
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
		printf("��ͷԪ��Ϊ��");
		for (int i = 0; i < s->top->n; i++)
			printf("%d ", ((int*)s->top->data)[i]);
		printf("\n");
		break;

	case 2:
		printf("��ͷԪ��Ϊ��");
		for (int i = 0; i < s->top->n; i++)
			printf("%hd ", ((short int*)s->top->data)[i]);
		printf("\n");
		break;

	case 3:
		printf("��ͷԪ��Ϊ��");
		for (int i = 0; i < s->top->n; i++)
				printf("%ld ", ((long int*)s->top->data)[i]);
		printf("\n");
		break;

		//bool��
	case 4:
		printf("bool��������int��ʽ���\n");
		printf("��ͷԪ��Ϊ��");
		for (int i = 0; i < s->top->n; i++)
			printf("%d", *((bool*)s->top->data));
		printf("\n");
		break;

	case 5:
		printf("��ͷԪ��Ϊ��");
		if (s->top->n == 1)
			printf("%c ", *((char*)s->top->data));

		else
			printf("%s", (char*)s->top->data);
		printf("\n");
		break;

	case 6:
		printf("��ͷԪ��Ϊ��");
		for (int i = 0; i < s->top->n; i++)
			printf("%f ", ((float*)s->top->data)[i]);
		
		printf("\n");
		break;

	case 7:
		printf("��ͷԪ��Ϊ��");
		for (int i = 0; i < s->top->n; i++)
			printf("%lf ", ((double*)s->top->data)[i]);
		printf("\n");
		break;

	default:
		printf("Ԫ�طǷ���\n");
		break;
	}
	return SUCCESS;
}

//ȡ��βԪ��
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
		printf("��βԪ��Ϊ��");
		for (int i = 0; i < s->rear->n; i++)
			printf("%d ", ((int*)s->rear->data)[i]);
		printf("\n");

		break;

	case 2:
		printf("��βԪ��Ϊ��");
		for (int i = 0; i < s->rear->n; i++)
			printf("%hd ", ((short int*)s->rear->data)[i]);
		printf("\n");
		break;

	case 3:
		printf("��βԪ��Ϊ��");
		for (int i = 0; i < s->rear->n; i++)
			printf("%ld ", ((long int*)s->rear->data)[i]);
		printf("\n");
		break;

		//bool��
	case 4:
		printf("bool��Ԫ����int��ʽ���\n");
		printf("��βԪ��Ϊ��");
		for (int i = 0; i < s->rear->n; i++)
			printf("%d", *((bool*)s->rear->data));
		printf("\n");
		break;

	case 5:
		printf("��βԪ��Ϊ��");
		if (s->rear->n == 1)
			printf("%c ", *((char*)s->rear->data));

		else
			printf("%s ", (char*)s->rear->data);
		printf("\n");
		break;

	case 6:
		printf("��βԪ��Ϊ��");
		for (int i = 0; i < s->rear->n; i++)
			printf("%f ", ((float*)s->rear->data)[i]);
		printf("\n");
		break;

	case 7:
		printf("��βԪ��Ϊ��");
		for (int i = 0; i < s->rear->n; i++)
			printf("%lf ", ((double*)s->rear->data)[i]);
		printf("\n");
		break;

	default:
		printf("Ԫ�طǷ���\n");
		break;
	}
	return SUCCESS;
}


//��ն���
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

//�ӳ���
Status LengthQueue(QueueL s, int* length)
{
	if (!s)
		return FAIL;

	*length = s->count;
	return SUCCESS;
}

//���ٶ���
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

//�������в���ӡ����
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

			//bool��
		case 4:
			printf("bool��������int��ʽ���\n");
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
			printf("���ݷǷ���\n");
			break;

		}
		
		t = t->next;
	}

	return SUCCESS;
}
 

