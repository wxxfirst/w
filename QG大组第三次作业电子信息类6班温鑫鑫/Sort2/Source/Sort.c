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
			printf("请选择你想要实现的排序选项：");
			if (scanf_s("%d", &num1) == 0)
			{
				printf("输入非法！请重试！\n");
				rewind(stdin);
				flag = 1;
			}
			else
				flag = 0;
		} while (flag);

		switch (num1)
		{
		case 0:
			printf("你的选择是退出！");
			system("pause");

			break;

		case 1:
			printf("你的选择是直接插入排序（升序）！\n");

			
				
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
						printf("操作失败！\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("排序时间为:%lfs\n", duration);
			system("pause");

			break;
		case 2:
			printf("你的选择是直接插入排序（降序）！\n");

			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = InsertdownSort(L);
					if (sign != SUCCESS)
					{
						printf("操作失败！\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("排序时间为:%lf\n", duration);
			


			system("pause");

			break;


		case 3:
			//存在一两个无序现象
			printf("你的选择是归并排序（升序）！\n");

		
			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = MergeupSort(L);
					if (sign != SUCCESS)
					{
						printf("操作失败！\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("排序时间为:%lf\n",  duration);

			

			system("pause");
			break;

		case 4:
			printf("你的选择是快速排序（递归、升序）！\n");
		
		
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = QupSort_(L, 1, L->count);
					if (sign != SUCCESS)
					{
						printf("操作失败！\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("排序时间为:%lf\n", duration);
			
			system("pause");
			break;
		case 5:
			printf("你的选择是计数排序（升序）！\n");

			
			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = CountSort(L);
					if (sign != SUCCESS)
					{
						printf("操作失败！\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("排序时间为: % lf\n", duration);

			

			system("pause");
			break;

		case 6:

			printf("你的选择是基数排序（升序）！\n");
			
			
				start = clock();
				for (int i = 0; i < 100000; i++)
				{
					data(L, 100);
					FileSave(L);
					FileRead(L);
					sign = RadixCountSort(L);
					if (sign != SUCCESS)
					{
						printf("操作失败！\n");
					}
				}
				finish = clock();
				duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("排序时间为:%lf\n",  duration);

			
			system("pause");
			break;
		default:
			printf("输入非法！请重试！");
			rewind(stdin);
			num1 = 1;
			system("pause");
		}

		system("cls");


	} while (num1);

	return 0;
}