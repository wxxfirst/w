#include "Sort_.h"

int main()
{
	clock_t start, finish;

	double duration = 0;
	int num1 = 0;
	int num2 = 0;
	int flag = 0;

	Status sign = ERROR;

	SqlistL L = (SqlistL)malloc(sizeof(Sqlist));

	do {
		menus();
		do {
			printf("��ѡ������Ҫʵ�ֵ�����ѡ�");
			if (scanf_s("%d", &num1) == 0)
			{
				printf("����Ƿ��������ԣ�\n");
				rewind(stdin);
				flag = 1;
			}
			else
				flag = 0;
		} while (flag);

		switch (num1)
		{
		case 0:
			printf("���ѡ�����˳���");
			system("pause");

			break;

		case 1:
			printf("���ѡ����ֱ�Ӳ����������򣩣�\n");

			
				
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = InsertupSort(L);
					if (sign != SUCCESS)
					{
						printf("%d", sign);
						printf("����ʧ�ܣ�\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("����ʱ��Ϊ:%lfs\n", duration);
			system("pause");

			break;
		case 2:
			printf("���ѡ����ֱ�Ӳ������򣨽��򣩣�\n");

			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = InsertdownSort(L);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("����ʱ��Ϊ:%lf\n", duration);
			


			system("pause");

			break;


		case 3:
			//����һ������������
			printf("���ѡ���ǹ鲢�������򣩣�\n");

		
			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = MergeupSort(L);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("����ʱ��Ϊ:%lf\n",  duration);

			

			system("pause");
			break;

		case 4:
			printf("���ѡ���ǿ������򣨵ݹ顢���򣩣�\n");
		
		
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = QupSort_(L, 1, L->count);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("����ʱ��Ϊ:%lf\n", duration);
			
			system("pause");
			break;
		case 5:
			printf("���ѡ���Ǽ����������򣩣�\n");

			
			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = CountSort(L);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("����ʱ��Ϊ: % lf\n", duration);

			

			system("pause");
			break;

		case 6:

			printf("���ѡ���ǻ����������򣩣�\n");
			
			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = RadixCountSort(L);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("����ʱ��Ϊ:%lf\n",  duration);

			
			system("pause");
			break;
		default:
			printf("����Ƿ��������ԣ�");
			rewind(stdin);
			num1 = 1;
			system("pause");
		}

		system("cls");


	} while (num1);

	return 0;
}