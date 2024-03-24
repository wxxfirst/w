#include "stack.h"

int main()
{
	LinkStack* s = NULL;
	//栈

	ElemType  elem;
	//w临时存储变量

	int number = 0;
	//操作符号

	int n = 0;
	//临时个数变量

	int length = 0;
	//临时长度变量

	int flag = 0;
	//标志位

	Status result = 0;


	do {
		menus();

		printf("\n");
		printf("请输入选择的序号：");

		if (scanf("%d",&number)==0)
		{
			number = 1;
			rewind(stdin);
			printf("你的选择非法，请重新选择！\n");
			clearScreen();
			continue;
		}

		switch (number)
		{

		case 0:
			printf("退出！\n");

			break;

		case 1:
			
			printf("你的选择是初始化链栈\n");

			result = initLStack(&s);
			print(result);

			break;

		case 2:
			
				printf("你的选择是元素入栈！\n");
				printf("请确保该栈已存在！\n");

				flag = 0;

				do {
					printf("请输入入栈的元素个数：");

					if (scanf("%d", &n) == 0)
					{
						printf("输入元素个数非法！\n");
						rewind(stdin);
						flag = 1;

					}
					else
						flag = 0;

				} while (flag);

				while (n--)
				{ 
						printf("请输入入栈元素值：");

						if (scanf("%d", &elem) == 0)
						{
							rewind(stdin);
							n++;
							printf("该元素非法,请输入整数！\n");
						}
						else {

							result = pushLStack(s, elem);

							if (result==SUCCESS)
							{
								print(result);
								printf("%d元素入栈成功！\n", elem);
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("未建立链栈!请选择‘1’，建立链栈后进行该操作！\n");
								else
									printf("内存不足，无法开辟空间！\n");
								break;
							}
						}
					
				}
			break;

		case 3:
			//出栈
			printf("你的选择是元素出栈！\n");
			printf("请确保栈非空！\n");


			printf("当前该栈长为：%d\n", s->count);
			printf("出栈元素的个数需小于或等于栈长！\n");
			flag = 0;

			do {
				printf("请输入要出栈的元素个数：");

				if (scanf("%d", &n) == 0)
				{
					printf("输入的出栈元素个数非法！\n");
					rewind(stdin);
					flag = 1;
				}
				else
					flag = 0;

			} while (flag);

				if (n <= s->count)
				{
					while (n--)
					{
						result = popLStack(s, &elem);

						if (result==SUCCESS)
						{
							print(result);
							printf("栈顶元素出栈成功，该元素为：%d", elem);
							elem = 0;
						}
						else
						{
							print(result);
							if (result == FAIL)
								printf("未建立链栈!请选择‘1’，建立链栈后进行该操作！\n");
							else
								printf("该栈为空栈，请选择'2',将元素入栈！\n ");
							break;
						}

					}
				}
				else
					printf("超出栈长，请重新选择！\n");


			break;

		case 4:
			printf("你的选择是判断空栈！\n");
			printf("请确保该栈已存在！\n");

			result = isEmpty_LStack(s);

			if (result==SUCCESS)
				printf("该栈为空栈！\n");
			else if (result == ERROR)
				printf("该栈为非空栈！\n");
			else
			{
				print(result);
				printf("该栈不存在！\n");
			}

			break;

		case 5:
			printf("你的选择是选取栈顶元素！\n");
			printf("请确保该栈已存在！\n");

			elem = 0;

			result = getTopLStack(s, &elem);

			if (result==SUCCESS)
			{
				print(result);
				printf("该栈顶元素为：%d\n", elem);
			}
			else
			{
				print(result);
				if (result == FAIL)
					printf("未建立链栈!选择‘1’，建立链栈后进行该操作！\n");
				else
					printf("该栈为空，请选择‘2’，将元素入栈，才能实现操作！\n");
			}

			break;

		case 6:
			printf("你的选择是清空栈！\n");
			printf("请确保该栈已存在！\n");

			result = clearLStack(s);

			if (result==SUCCESS)
			{
				print(result);
				printf("栈已清空完毕！\n");
			}
			else
			{
				print(result);
				printf("未建立链栈!请选择‘1’，建立链栈后进行该操作！\n");
			}

			break;

		case 7:
			printf("你的选择是销毁栈！\n");
			printf("请确保该栈已存在！\n");
			result = destroyLStack(&s);

			if (result==SUCCESS)
			{
				print(result);
				printf("该栈已被销毁！\n");
			}
			else
				print(result);

			break;

		case 8:
			printf("你的选择是统计表长！\n");
			printf("请确保该栈已存在\n");

			result = LStackLength(s, &length);
			if (result==SUCCESS)
			{
				print(result);
				printf("该栈长为：%d\n", length);
			}
			else
			{
				print(result);
				printf("未建立链栈!请选择‘1’，建立链栈后进行该操作！\n");
			}

			break;

		case 9:
			printf("你的选择是打印栈！\n");
			printf("请确保该栈已存在！\n");

			result = printStack(s);
			if (result==SUCCESS)
			{
				print(result);
				printf("栈元素已打印完毕！\n");
			}
			else
			{ 
				print(result);
				if (result == FAIL)
					printf("未建立链栈!请选择‘1’，建立链栈后进行该操作！\n");
				else
					printf("该栈为空栈！请选择‘2’，将元素入栈，才能实现该操作！\n");
			}

			break;

		default:
			printf("你的选择非法，请重新选择！\n");
			number = 1;
			break;
		}
		clearScreen();

	} while (number);

	return 0;
}