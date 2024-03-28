#include "expression.h"

int main()
{
	StackLNode s = NULL;
	//运算符栈

	StackLNode_ s_ = NULL;
	//数值栈

	char expression[Maxsize];
	//输入表达式

	Sign e;
	//存放表达式个体变量

	Sign sign_e = ERROR;
	//运算符变量

	double e1_ = 0;
	double e2_ = 0;
	//数值存储变量

	double e_ = 0;
	//元素匹配结果

	double n = 0;
	//元素运算结果

	int i = 0;
	//外循环控制

	size_t length = 0;
	//表达式字符串长度

	Status p = ERROR;
	//建立运算符栈判断操作是否成立

	Status q = ERROR;
	//建立数值栈是否成立

	int priority1 = 0;
	int priority2 = 0;
	//运算符优先级

	int number = 0;
	int flag = 0;
	//操作标志符号


	p = InitStack(&s);
	q = InitStack_(&s_);
	//建立栈

	if (p && q)
	{

		do {
			if (number == 2 || number == 0)
			{
				menus();
				printf("请选择你需要的操作序号：");
			}

			if (scanf_s("%d", &number) == 0)
			{
				rewind(stdin);
				printf("序号非法！请重新输入！\n");
				number = 2;
				clearScreen();
				continue;
			}

			switch (number)
			{

			case 0:
				printf("你的选择是退出！\n");
				break;

			case 1:
				rewind(stdin);
				do {
					i = 0;
					printf("你的选择是计算！\n");
					printf("请输入表达式：");
					scanf("%s", &expression);
					length = strlen(expression);
					for (; i < length; i++)
					{
						e = expression[i];
						if ((e == '(' || e == ')' || e == '+' || e == '-' || e == '*' || e == '/') || (e >= '0' && e <= '9'))
						{
							if (e == '+' || e == '-' || e == '*' || e == '/')
							{
								q = IsFull_Stack(s);
								if (!q)
								{
									if (IsEmpty_Stack(s))
									{
										PushStack(s, e);
									}
									else
									{

										Get_Top(s, &sign_e);
										if (sign_e != '(')
										{
											priority1 = Priority_sign(e);
											priority2 = Priority_sign(sign_e);
											while (priority1 <= priority2 && s_->top > 1)
											{
												//取出数值
												Get_Top_(s_, &e2_);
												PopStack_(s_);

												Get_Top_(s_, &e1_);
												PopStack_(s_);

												//取出运算符
												PopStack(s);

												//运算
												n = Result(priority2, e1_, e2_, sign_e);
												PushStack_(s_, n);

												//栈顶运算符




												Get_Top(s, &sign_e);
												priority2 = Priority_sign(sign_e);

											}
											PushStack(s, e);
										}
										else
										{
											PushStack(s, e);

											continue;

										}
									}
									continue;
								}
								else
								{
									printf("表达式过长，部分数据无法计算！");
									flag = 1;
									break;
								}


							}
							else if (e == '(')
							{
								q = IsFull_Stack(s);
								if (!q)
								{
									PushStack(s, e);
								}
								else
								{
									flag = 1;
									printf("表达式过长，部分数据无法计算！\n");
									break;
								}

							}
							else if (e == ')')
							{

								Get_Top(s, &sign_e);
								priority2 = Priority_sign(sign_e);
								while (sign_e != '(' && s->top && s_->top > 1)
								{
									//取出数值
									Get_Top_(s_, &e2_);
									PopStack_(s_);

									Get_Top_(s_, &e1_);
									PopStack_(s_);

									//取出运算符
									PopStack(s);

									//运算

									n = Result(priority2, e1_, e2_, sign_e);
									PushStack_(s_, n);

									//栈顶运算符
									Get_Top(s, &sign_e);
									priority2 = Priority_sign(sign_e);

								}

								PopStack(s);

								continue;
							}
							else if (e <= '9' && e >= '0')
							{
								int j = 0;
								double result = 0;
								int count = 0;
								for (; j + i < length; j++)
								{
									if (expression[i + j] >= '0' && expression[i + j] <= '9')
									{
										count++;
									}
									else
									{
										break;
									}
								}
								while (count)
								{
									match(expression[i], &e_);
									result += (e_ * pow(10, --count));
									i++;
								}
								PushStack_(s_, result);
								i--;
							}
						}
						else
						{
							rewind(stdin);
							printf("表达式中存在非法运算符！请重新输入！\n");
							flag = 1;
							clearScreen();
							break;

						}
					}
					//栈剩余元素计算

					if (i == length)
					{
						if (!IsEmpty_Stack(s))
						{
							Get_Top(s, &sign_e);

							while (!IsEmpty_Stack(s))
							{
								//取出数值
								Get_Top_(s_, &e2_);
								PopStack_(s_);

								//取出数值
								Get_Top_(s_, &e1_);
								PopStack_(s_);

								//优先级确定
								priority2 = Priority_sign(sign_e);

								//运算
								n = Result(priority2, e1_, e2_, sign_e);
								PushStack_(s_, n);

								//运算符出栈
								PopStack(s);
								Get_Top(s, &sign_e);
							}
						}
						
						if (flag == 0||!IsEmpty_Stack_(s_))
						{

							Get_Top_(s_, &n);
							printf("该表达式计算结果为：%.2lf\n", n);
							printf("计算完毕！\n");
							number = 2;
							clearScreen();
						}

					}
					clearStack(s);
					clearStack_(s_);

				} while (flag);

				break;

			default:
				printf("序号选择非法！请重新输入！\n");
				number = 2;
				clearScreen();
				rewind(stdin);
				break;
			}

		} while (number);
	}

	else
		printf("内存不足！无法运行程序！\n");

	return 0;
}