#include "Sort.h"

int main()
{
	int number[3] = { 10000, 50000, 200000 };
	clock_t start, finish;

	double duration = 0;
	int num1 = 0;
	int num2 = 0;
	int flag = 0;

	Status sign = ERROR;

	SqlistL L1 = (SqlistL)malloc(sizeof(Sqlist));
	SqlistL L2 = (SqlistL)malloc(sizeof(Sqlist));
	SqlistL L3 = (SqlistL)malloc(sizeof(Sqlist));
	SqlistL L[3] = { L1,L2,L3 };


	for (int i = 0; i < 3; i++)
	{
		data(L[i], number[i]);
		FileSave(L[i], i+1);
	}
	
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

				for (int i = 0; i < 3; i++)
				{
					FileRead(L[i], i+1);
					start = clock();
					sign = InsertupSort(L[i]);
					if (sign != SUCCESS)
					{
						printf("%d", sign);
						printf("����ʧ�ܣ�\n");
					}
					finish = clock();
					duration = (double)(finish - start) / CLOCKS_PER_SEC;
					printf("������Ϊ%d������ʱ��Ϊ:%lfs\n", number[i],duration);
				}
				
				system("pause");

				break;
			case 2:
				printf("���ѡ����ֱ�Ӳ������򣨽��򣩣�\n");

				for (int i = 0; i < 3; i++)
				{
					FileRead(L[i], i+1);
					start = clock();
					sign = InsertdownSort(L[i]);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
					finish = clock();
					duration = (double)(finish - start) / CLOCKS_PER_SEC; 
					printf("������Ϊ%d������ʱ��Ϊ:%lf\n", number[i], duration);
				}
				

				system("pause");

				break;
			
			
			case 3:
				//����һ������������
				printf("���ѡ���ǹ鲢�������򣩣�\n");

				for (int i = 0; i < 3; i++)
				{
					FileRead(L[i], i+1);
					start = clock();
					sign = MergeupSort(L[i]);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
					finish = clock();
					duration = (double)(finish - start) / CLOCKS_PER_SEC;
					printf("������Ϊ%d������ʱ��Ϊ:%lf\n", number[i], duration);
					
				}

				system("pause");
				break;
		
			case 4:
				printf("���ѡ���ǿ������򣨵ݹ顢���򣩣�\n");
				for (int i = 0; i < 3; i++)
				{
					FileRead(L[i], i+1);
					start = clock();
					sign = QupSort_(L[i],1,L[i]->count);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
					finish = clock();
					duration = (double)(finish - start) / CLOCKS_PER_SEC;
					printf("������Ϊ%d������ʱ��Ϊ:%lf\n", number[i], duration);
				}
				system("pause");
				break;
			case 5:
				printf("���ѡ���Ǽ����������򣩣�\n");
				
				for (int i = 0; i < 3; i++)
				{
					FileRead(L[i], i+1);
					start = clock();
					sign = CountSort(L[i]);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
					finish = clock();
					duration = (double)(finish - start) / CLOCKS_PER_SEC;
					printf("������Ϊ%d������ʱ��Ϊ:%lf\n", number[i], duration);
				
				}
		
				system("pause");
				break;
			
			case 6:

				printf("���ѡ���ǻ����������򣩣�\n");
				for (int i = 0; i < 3; i++)
				{
					FileRead(L[i], i+1);
					start = clock();
					sign = RadixCountSort(L[i]);
					if (sign != SUCCESS)
					{
						printf("����ʧ�ܣ�\n");
					}
					finish = clock();
					duration = (double)(finish - start) / CLOCKS_PER_SEC;
					printf("������Ϊ%d������ʱ��Ϊ:%lf\n", number[i], duration);
			
				}
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