#include "stack.h"

int main()
{
	LinkStack* s = NULL;
	//ջ

	ElemType  elem;
	//w��ʱ�洢����

	int number = 0;
	//��������

	int n = 0;
	//��ʱ��������

	int length = 0;
	//��ʱ���ȱ���

	int flag = 0;
	//��־λ

	Status result = 0;


	do {
		menus();

		printf("\n");
		printf("������ѡ�����ţ�");

		if (scanf("%d",&number)==0)
		{
			number = 1;
			rewind(stdin);
			printf("���ѡ��Ƿ���������ѡ��\n");
			clearScreen();
			continue;
		}

		switch (number)
		{

		case 0:
			printf("�˳���\n");

			break;

		case 1:
			
			printf("���ѡ���ǳ�ʼ����ջ\n");

			result = initLStack(&s);
			print(result);

			break;

		case 2:
			
				printf("���ѡ����Ԫ����ջ��\n");
				printf("��ȷ����ջ�Ѵ��ڣ�\n");

				flag = 0;

				do {
					printf("��������ջ��Ԫ�ظ�����");

					if (scanf("%d", &n) == 0)
					{
						printf("����Ԫ�ظ����Ƿ���\n");
						rewind(stdin);
						flag = 1;

					}
					else
						flag = 0;

				} while (flag);

				while (n--)
				{ 
						printf("��������ջԪ��ֵ��");

						if (scanf("%d", &elem) == 0)
						{
							rewind(stdin);
							n++;
							printf("��Ԫ�طǷ�,������������\n");
						}
						else {

							result = pushLStack(s, elem);

							if (result==SUCCESS)
							{
								print(result);
								printf("%dԪ����ջ�ɹ���\n", elem);
							}
							else
							{
								print(result);
								if (result == FAIL)
									printf("δ������ջ!��ѡ��1����������ջ����иò�����\n");
								else
									printf("�ڴ治�㣬�޷����ٿռ䣡\n");
								break;
							}
						}
					
				}
			break;

		case 3:
			//��ջ
			printf("���ѡ����Ԫ�س�ջ��\n");
			printf("��ȷ��ջ�ǿգ�\n");


			printf("��ǰ��ջ��Ϊ��%d\n", s->count);
			printf("��ջԪ�صĸ�����С�ڻ����ջ����\n");
			flag = 0;

			do {
				printf("������Ҫ��ջ��Ԫ�ظ�����");

				if (scanf("%d", &n) == 0)
				{
					printf("����ĳ�ջԪ�ظ����Ƿ���\n");
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
							printf("ջ��Ԫ�س�ջ�ɹ�����Ԫ��Ϊ��%d", elem);
							elem = 0;
						}
						else
						{
							print(result);
							if (result == FAIL)
								printf("δ������ջ!��ѡ��1����������ջ����иò�����\n");
							else
								printf("��ջΪ��ջ����ѡ��'2',��Ԫ����ջ��\n ");
							break;
						}

					}
				}
				else
					printf("����ջ����������ѡ��\n");


			break;

		case 4:
			printf("���ѡ�����жϿ�ջ��\n");
			printf("��ȷ����ջ�Ѵ��ڣ�\n");

			result = isEmpty_LStack(s);

			if (result==SUCCESS)
				printf("��ջΪ��ջ��\n");
			else if (result == ERROR)
				printf("��ջΪ�ǿ�ջ��\n");
			else
			{
				print(result);
				printf("��ջ�����ڣ�\n");
			}

			break;

		case 5:
			printf("���ѡ����ѡȡջ��Ԫ�أ�\n");
			printf("��ȷ����ջ�Ѵ��ڣ�\n");

			elem = 0;

			result = getTopLStack(s, &elem);

			if (result==SUCCESS)
			{
				print(result);
				printf("��ջ��Ԫ��Ϊ��%d\n", elem);
			}
			else
			{
				print(result);
				if (result == FAIL)
					printf("δ������ջ!ѡ��1����������ջ����иò�����\n");
				else
					printf("��ջΪ�գ���ѡ��2������Ԫ����ջ������ʵ�ֲ�����\n");
			}

			break;

		case 6:
			printf("���ѡ�������ջ��\n");
			printf("��ȷ����ջ�Ѵ��ڣ�\n");

			result = clearLStack(s);

			if (result==SUCCESS)
			{
				print(result);
				printf("ջ�������ϣ�\n");
			}
			else
			{
				print(result);
				printf("δ������ջ!��ѡ��1����������ջ����иò�����\n");
			}

			break;

		case 7:
			printf("���ѡ��������ջ��\n");
			printf("��ȷ����ջ�Ѵ��ڣ�\n");
			result = destroyLStack(&s);

			if (result==SUCCESS)
			{
				print(result);
				printf("��ջ�ѱ����٣�\n");
			}
			else
				print(result);

			break;

		case 8:
			printf("���ѡ����ͳ�Ʊ���\n");
			printf("��ȷ����ջ�Ѵ���\n");

			result = LStackLength(s, &length);
			if (result==SUCCESS)
			{
				print(result);
				printf("��ջ��Ϊ��%d\n", length);
			}
			else
			{
				print(result);
				printf("δ������ջ!��ѡ��1����������ջ����иò�����\n");
			}

			break;

		case 9:
			printf("���ѡ���Ǵ�ӡջ��\n");
			printf("��ȷ����ջ�Ѵ��ڣ�\n");

			result = printStack(s);
			if (result==SUCCESS)
			{
				print(result);
				printf("ջԪ���Ѵ�ӡ��ϣ�\n");
			}
			else
			{ 
				print(result);
				if (result == FAIL)
					printf("δ������ջ!��ѡ��1����������ջ����иò�����\n");
				else
					printf("��ջΪ��ջ����ѡ��2������Ԫ����ջ������ʵ�ָò�����\n");
			}

			break;

		default:
			printf("���ѡ��Ƿ���������ѡ��\n");
			number = 1;
			break;
		}
		clearScreen();

	} while (number);

	return 0;
}