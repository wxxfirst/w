#include "expression.h"

int main()
{
	StackLNode s = NULL;
	//�����ջ

	StackLNode_ s_ = NULL;
	//��ֵջ

	char expression[Maxsize];
	//������ʽ

	Sign e;
	//��ű��ʽ�������

	Sign sign_e = ERROR;
	//���������

	double e1_ = 0;
	double e2_ = 0;
	//��ֵ�洢����

	double e_ = 0;
	//Ԫ��ƥ����

	double n = 0;
	//Ԫ��������

	int i = 0;
	//��ѭ������

	size_t length = 0;
	//���ʽ�ַ�������

	Status p = ERROR;
	//���������ջ�жϲ����Ƿ����

	Status q = ERROR;
	//������ֵջ�Ƿ����

	int priority1 = 0;
	int priority2 = 0;
	//��������ȼ�

	int number = 0;
	int flag = 0;
	//������־����


	p = InitStack(&s);
	q = InitStack_(&s_);
	//����ջ

	if (p && q)
	{

		do {
			if (number == 2 || number == 0)
			{
				menus();
				printf("��ѡ������Ҫ�Ĳ�����ţ�");
			}

			if (scanf_s("%d", &number) == 0)
			{
				rewind(stdin);
				printf("��ŷǷ������������룡\n");
				number = 2;
				clearScreen();
				continue;
			}

			switch (number)
			{

			case 0:
				printf("���ѡ�����˳���\n");
				break;

			case 1:
				rewind(stdin);
				do {
					i = 0;
					printf("���ѡ���Ǽ��㣡\n");
					printf("��������ʽ��");
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
												//ȡ����ֵ
												Get_Top_(s_, &e2_);
												PopStack_(s_);

												Get_Top_(s_, &e1_);
												PopStack_(s_);

												//ȡ�������
												PopStack(s);

												//����
												n = Result(priority2, e1_, e2_, sign_e);
												PushStack_(s_, n);

												//ջ�������




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
									printf("���ʽ���������������޷����㣡");
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
									printf("���ʽ���������������޷����㣡\n");
									break;
								}

							}
							else if (e == ')')
							{

								Get_Top(s, &sign_e);
								priority2 = Priority_sign(sign_e);
								while (sign_e != '(' && s->top && s_->top > 1)
								{
									//ȡ����ֵ
									Get_Top_(s_, &e2_);
									PopStack_(s_);

									Get_Top_(s_, &e1_);
									PopStack_(s_);

									//ȡ�������
									PopStack(s);

									//����

									n = Result(priority2, e1_, e2_, sign_e);
									PushStack_(s_, n);

									//ջ�������
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
							printf("���ʽ�д��ڷǷ�����������������룡\n");
							flag = 1;
							clearScreen();
							break;

						}
					}
					//ջʣ��Ԫ�ؼ���

					if (i == length)
					{
						if (!IsEmpty_Stack(s))
						{
							Get_Top(s, &sign_e);

							while (!IsEmpty_Stack(s))
							{
								//ȡ����ֵ
								Get_Top_(s_, &e2_);
								PopStack_(s_);

								//ȡ����ֵ
								Get_Top_(s_, &e1_);
								PopStack_(s_);

								//���ȼ�ȷ��
								priority2 = Priority_sign(sign_e);

								//����
								n = Result(priority2, e1_, e2_, sign_e);
								PushStack_(s_, n);

								//�������ջ
								PopStack(s);
								Get_Top(s, &sign_e);
							}
						}
						
						if (flag == 0||!IsEmpty_Stack_(s_))
						{

							Get_Top_(s_, &n);
							printf("�ñ��ʽ������Ϊ��%.2lf\n", n);
							printf("������ϣ�\n");
							number = 2;
							clearScreen();
						}

					}
					clearStack(s);
					clearStack_(s_);

				} while (flag);

				break;

			default:
				printf("���ѡ��Ƿ������������룡\n");
				number = 2;
				clearScreen();
				rewind(stdin);
				break;
			}

		} while (number);
	}

	else
		printf("�ڴ治�㣡�޷����г���\n");

	return 0;
}