#include "Queue.h"

int main()
{
	QueueL s = NULL;
	//����ָ��

	int number = 0;
	//����ѡ��

	int flag = 0;
	//��־λ

	int num1 = 0;
	//��������ѡ��

	int n = 0;
	//����

	int length = 0;
	//����

	void* elem = NULL;
	//���ݼ�¼

	Status result = ERROR;
	

	do {
		menus();

		printf("\n");
		printf("��������ѡ�����ţ�\n");

		if (scanf("%d", &number) == 0)
		{
			rewind(stdin);
			printf("�������ֵ�Ƿ���\n");
			number = 1;

		}
		else
		{
			switch (number)
			{
			case 0:
				printf("���ѡ�����˳���\n");

				break;

			case 1:
				printf("���ѡ���ǳ�ʼ�����ӣ�\n");

				result = InitQueue(&s);
				print(result);

				break;

			case 2:
				printf("���ѡ����Ԫ�����!\n");
				printf("��ȷ���������Ѵ��ڣ�\n");

				flag = 0;

				do {
					printf("������Ԫ�ظ���ֵ��");
					if (scanf_s("%d", &num1) == 0)
					{
						rewind(stdin);
						printf("��Ԫ�ظ���ֵ�Ƿ������������룡\n");
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
						printf("��ѡ����Ҫ��ӵĵ���Ԫ�����ͣ�");

						if (scanf_s("%d", &type) == 0)
						{
							rewind(stdin);
							flag = 1;
							printf("���ѡ��Ƿ������������룡\n");
						}
						else
							flag = 0;
					} while (flag);

					rewind(stdin);

					switch (type)
					{
					case 1:
						printf("���ѡ���ǹ���int�����ݣ�\n");

						printf("������빹��int��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;

					case 2:
						printf("���ѡ���ǹ���short int�����ݣ�\n");

						printf("������빹��short int��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;

					case 3:
						printf("���ѡ���ǹ���long int�����ݣ�\n");

						printf("������빹��long int��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;

					case 4:
						printf("���ѡ���ǹ���bool�����ݣ�\n");

						printf("������빹��bool��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;
					case 5:
						printf("���ѡ���ǹ���char�����ݣ�\n");

						printf("������빹��char��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;
					case 6:
						printf("���ѡ���ǹ���float�����ݣ�\n");

						printf("������빹��float��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;
					case 7:
						printf("���ѡ���ǹ���double�����ݣ�\n");

						printf("������빹��double��һά���飬����������ĸ���n(n>1)��\n");

						if (scanf_s("%d", &n) == 0)
						{
							rewind(stdin);
							n++;
							printf("�ø���ֵ�Ƿ���������������\n");
						}
						else
						{
							result = pushLQueue(s, elem, type, n);

							if (result == SUCCESS)
							{
								print(result);
								printf("Ԫ����ӳɹ���\n");
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ�������ӣ���ѡ��1�����������Ӻ���иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
							}
						}
						break;

					default:
						printf("���ѡ��Ƿ���������ѡ��\n");
						num1++;
						break;
					}


				}
				break;

			case 3:
				printf("���ѡ����Ԫ�س��ӣ�\n");
				printf("��ȷ�������Ѵ����ҷǿգ�\n");

				printf("��ǰ���ӳ�Ϊ��%d\n", s->count);
				printf("����Ԫ�صĸ�����ҪС�ڻ���ڶӳ�!\n");
				flag = 0;

				do {
					printf("������Ҫ���ӵ�Ԫ�ظ�����");

					if (scanf_s("%d", &num1) == 0)
					{
						rewind(stdin);
						printf("����ĳ���Ԫ�ظ���ֵ�Ƿ������������룡\n");
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
				//�ж϶ӿ�
				printf("���ѡ�����ж������Ƿ�Ϊ�գ�\n");
				printf("��ȷ�������Ѵ��ڣ�\n");

				result = isEmpty_LQueue(s);

				if (result == SUCCESS)
					printf("������Ϊ�գ�\n");
				else if (result == ERROR)
					printf("������Ϊ�ǿգ�\n");
				else
				{
					print(result);
					printf("�����Ӳ����ڣ�\n");
				}

				break;

			case 5:
				printf("���ѡ����ͳ�����ӳ��ȣ�\n");
				printf("��ȷ���������Ѵ���\n");

				result = LengthQueue(s, &length);
				if (result == SUCCESS)
				{
					print(result);
					printf("�öӳ�Ϊ��%d\n", length);
				}
				else
				{
					print(result);
					printf("δ��������!��ѡ��1�����������Ӻ���иò�����\n");
				}
				break;

			case 6:
				printf("���ѡ����ѡȡ��ͷԪ�أ�\n");
				printf("��ȷ���������Ѵ����ҷǿգ�\n");

				result = Get_Top(s, elem);

				if (result == SUCCESS)
					print(result);
				else
				{
					print(result);
					if (result == FAIL)
						printf("δ��������!ѡ��1�����������Ӻ���иò�����\n");
					else
						printf("������Ϊ�գ���ѡ��2������Ԫ����ӣ�����ʵ�ֲ�����\n");
				}

				break;

			case 7:
				printf("���ѡ����ѡȡ��βԪ�أ�\n");
				printf("��ȷ���������Ѵ����ҷǿգ�\n");

				result = Get_Rear(s, elem);

				if (result == SUCCESS)
					print(result);
				else
				{
					print(result);
					if (result == FAIL)
						printf("δ��������!ѡ��1�����������Ӻ���иò�����\n");
					else
						printf("�ö�Ϊ�գ���ѡ��2������Ԫ����ӣ�����ʵ�ֲ�����\n");
				}

				break;

			case 8:
				printf("���ѡ����������ӣ�\n");
				printf("��ȷ���������Ѵ��ڣ�\n");

				result = ClearQueue(s);

				if (result == SUCCESS)
				{
					print(result);
					printf("�����������ϣ�\n");
				}
				else
				{
					print(result);
					printf("δ��������!��ѡ��1�����������Ӻ���иò�����\n");
				}

				break;

			case 9:
				printf("���ѡ�����������ӣ�\n");

				result = DestroyQueue(&s);

				if (result == SUCCESS)
				{
					print(result);
					printf("�������ѱ����٣�\n");
				}
				else
					print(result);

				break;

			case 10:
				printf("���ѡ���Ǵ�ӡ����Ԫ�أ�\n");
				printf("��ȷ���������Ѵ����ҷǿգ�\n");

				result = printQueue(s);
				if (result == SUCCESS)
				{
					print(result);
					printf("����Ԫ���Ѵ�ӡ��ϣ�\n");
				}
				else
				{
					print(result);
					if (result == FAIL)
						printf("δ��������!��ѡ��1�����������Ӻ���иò�����\n");
					else
						printf("��ջΪ�����ӣ���ѡ��2������Ԫ����ӣ�����ʵ�ָò�����\n");
				}

				break;

			default:
				printf("�������Ƿ���������ѡ��\n");
				number = 1;
				break;
			}
		}
		rewind(stdin);
		clearScreen();
	} while (number);

	return 0;
}