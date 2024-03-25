#include "Queue.h"

int main()
{
	QueueL s = NULL;
	//链队指针

	int number = 0;
	//功能选择

	int flag = 0;
	//标志位

	int num1 = 0;
	//数据类型选择

	int n = 0;
	//个数

	int length = 0;
	//长度

	void* elem = NULL;
	//数据记录

	Status result = ERROR;
	

	do {
		menus();

		printf("\n");
		printf("请输入你选择的序号：\n");

		if (scanf("%d", &number) == 0)
		{
			rewind(stdin);
			printf("输入序号值非法！\n");
			number = 1;

		}
		else
		{
			switch (number)
			{
			case 0:
				printf("你的选择是退出！\n");

				break;

			case 1:
				printf("你的选择是初始化链队！\n");

				result = InitQueue(&s);
				print(result);

				break;

			case 2:
				printf("你的选择是元素入队!\n");
				printf("请确保该链队已存在！\n");

				flag = 0;

				do {
					printf("请输入元素个数值：");
					if (scanf_s("%d", &num1) == 0)
					{
						rewind(stdin);
						printf("该元素个数值非法！请重新输入！\n");
						flag = 1;
					}
					else
						flag = 0;
				} while (flag);

				rewind(stdin);

				ElemTypemenus();

				while (num1--)
				{

					int type = 0;

					do {
						printf("请选择你要入队的单个元素类型：");

						if (scanf_s("%d", &type) == 0)
						{
							rewind(stdin);
							flag = 1;
							printf("你的选择非法！请重新输入！\n");
						}
						else
							flag = 0;
					} while (flag);

					rewind(stdin);

					switch (type)
					{
					case 1:
						printf("你的选择是构造int型数据！\n");

						printf("如果你想构造int型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;

					case 2:
						printf("你的选择是构造short int型数据！\n");

						printf("如果你想构造short int型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;

					case 3:
						printf("你的选择是构造long int型数据！\n");

						printf("如果你想构造long int型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;

					case 4:
						printf("你的选择是构造bool型数据！\n");

						printf("如果你想构造bool型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;
					case 5:
						printf("你的选择是构造char型数据！\n");

						printf("如果你想构造char型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;
					case 6:
						printf("你的选择是构造float型数据！\n");

						printf("如果你想构造float型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;
					case 7:
						printf("你的选择是构造double型数据！\n");

						printf("如果你想构造double型一维数组，请输入数组的个数n(n>1)：\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("该个数值非法，请输入整数！\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("元素入队成功！\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链队！请选择’1‘，建立链队后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
							}
						}
						break;

					default:
						printf("序号选择非法！请重新选择！\n");
						num1++;
						break;
					}


				}
				break;

			case 3:
				printf("你的选择是元素出队！\n");
				printf("请确保链队已存在且非空！\n");

				printf("当前链队长为：%d\n", s->count);
				printf("出队元素的个数需要小于或等于队长!\n");
				flag = 0;

				do {
					printf("请输入要出队的元素个数：");

					if (scanf_s("%d", &num1) == 0)
					{
						rewind(stdin);
						printf("输入的出队元素个数值非法！请重新输入！\n");
						flag = 1;
					}
					else
						flag = 0;
				} while (flag);

				rewind(stdin);

				if (num1 <= s->count)
				{
					while (num1--)
					{
						result = popLQueue(s, elem);

						if (result == SUCCESS)
						{
							print(result);

						}
					}
				}
				break;

			case 4:
				//判断队空
				printf("你的选择是判断链队是否为空！\n");
				printf("请确保链队已存在！\n");

				result = isEmpty_LQueue(s);

				if (result == SUCCESS)
					printf("该链队为空！\n");
				else if (result == ERROR)
					printf("该链队为非空！\n");
				else
				{
					print(result);
					printf("该链队不存在！\n");
				}

				break;

			case 5:
				printf("你的选择是统计链队长度！\n");
				printf("请确保该链队已存在\n");

				result = LengthQueue(s, &length);
				if (result == SUCCESS)
				{
					print(result);
					printf("该队长为：%d\n", length);
				}
				else
				{
					print(result);
					printf("未建立链队!请选择‘1’，建立链队后进行该操作！\n");
				}
				break;

			case 6:
				printf("你的选择是选取队头元素！\n");
				printf("请确保该链队已存在且非空！\n");

				result = Get_Top(s, elem);

				if (result == SUCCESS)
					print(result);
				else
				{
					print(result);
					if (result == FAIL)
						printf("未建立链队!选择‘1’，建立链队后进行该操作！\n");
					else
						printf("该链队为空，请选择‘2’，将元素入队，才能实现操作！\n");
				}

				break;

			case 7:
				printf("你的选择是选取队尾元素！\n");
				printf("请确保该链队已存在且非空！\n");

				result = Get_Rear(s, elem);

				if (result == SUCCESS)
					print(result);
				else
				{
					print(result);
					if (result == FAIL)
						printf("未建立链队!选择‘1’，建立链队后进行该操作！\n");
					else
						printf("该队为空，请选择‘2’，将元素入队，才能实现操作！\n");
				}

				break;

			case 8:
				printf("你的选择是清空链队！\n");
				printf("请确保该链队已存在！\n");

				result = ClearQueue(s);

				if (result == SUCCESS)
				{
					print(result);
					printf("链队已清空完毕！\n");
				}
				else
				{
					print(result);
					printf("未建立链队!请选择‘1’，建立链队后进行该操作！\n");
				}

				break;

			case 9:
				printf("你的选择是销毁链队！\n");

				result = DestroyQueue(&s);

				if (result == SUCCESS)
				{
					print(result);
					printf("该链队已被销毁！\n");
				}
				else
					print(result);

				break;

			case 10:
				printf("你的选择是打印链队元素！\n");
				printf("请确保该链队已存在且非空！\n");

				result = printQueue(s);
				if (result == SUCCESS)
				{
					print(result);
					printf("链队元素已打印完毕！\n");
				}
				else
				{
					print(result);
					if (result == FAIL)
						printf("未建立链队!请选择‘1’，建立链队后进行该操作！\n");
					else
						printf("该栈为空链队！请选择‘2’，将元素入队，才能实现该操作！\n");
				}

				break;

			default:
				printf("序号输入非法，请重新选择！\n");
				number = 1;
				break;
			}
		}
		rewind(stdin);
		clearScreen();
	} while (number);

	return 0;
}