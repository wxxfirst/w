#include "Tree.h"

int main()
{
	BiTree L = NULL;

	int number = 0;
	int flag = 0;
	int data = 0;

	Status sign = ERROR;

	do {
		menus();
		do {
			printf("������ѡ���ѡ�����ţ�");
			if (scanf_s("%d", &number) == 0)
			{
				printf("����Ƿ������������룡\n");
				flag = 1;
				rewind(stdin);
			}
			else
				flag = 0;
		} while (flag);

		switch (number)
		{
		case 0:
			printf("���ѡ�����˳���\n");
			break;

		case 1:
			printf("���ѡ���ǳ�ʼ����������\n");
			sign = Init_BiTree(&L);
			if (sign)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;

		case 2:
			printf("���ѡ�������ݲ����������\n");
			rewind(stdin);
			flag = 0;
			do {
				printf("������������ֵ��");
				if (scanf_s("%d", &data) == 0)
				{
					printf("����Ƿ������������룡\n");
					flag = 1;
					rewind(stdin);
				}
				else
					flag = 0;
			} while (flag);
			rewind(stdin);
			sign = Insert_BiTree(L,data);
			if (sign==SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
			
		case 3:
			printf("���ѡ���Ƕ�������ֵ���ң�\n");
			rewind(stdin);
			flag = 0;
			do {
				printf("��������ҵ���ֵ��");
				if (scanf_s("%d", &data) == 0)
				{
					printf("����Ƿ������������룡\n");
					flag = 1;
					rewind(stdin);
				}
				else
					flag = 0;
			} while (flag);
			rewind(stdin);
			sign = SearchBiTree(L, data);
			if (sign == SUCCESS)
				printf("���ҳɹ���\n");
			else
				printf("����ʧ�ܣ�\n");
			system("pause");
			break;
			
		case 4:
			printf("���ѡ���Ƕ�������ֵɾ����\n");
			rewind(stdin);
			flag = 0;
			do {
				printf("������ɾ������ֵ��");
				if (scanf_s("%d", &data) == 0)
				{
					printf("����Ƿ������������룡\n");
					flag = 1;
					rewind(stdin);
				}
				else
					flag = 0;
			} while (flag);
			rewind(stdin);
			sign = DeleteBiNode(&L, data);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
			
		case 5:
			printf("���ѡ���Ƕ���������������ݹ飩��\n");

			sign = PreOrderTraverse(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;

		case 6:
			printf("���ѡ���Ƕ���������������ǵݹ飩��\n");

			sign = PreOrderTraverse_(L);
			Clear(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
		case 7:
			printf("���ѡ���Ƕ���������������ݹ飩��\n");

			sign = InOrderTraverse(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
		case 8:
			printf("���ѡ���Ƕ���������������ǵݹ飩��\n");

			sign = InOrderTraverse_(L);
			Clear(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
		case 9:
			printf("���ѡ���Ƕ���������������ݹ飩��\n");

			sign = PostOrderTraverse(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
		case 10:
			printf("���ѡ���Ƕ���������������ǵݹ飩��\n");

			sign = PostOrderTraverse_(L);
			Clear(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
		case 11:
			printf("���ѡ���Ƕ�������α�����\n");

			sign = LevelOrder(L);
			if (sign == SUCCESS)
				printf("�ɹ���\n");
			else
				printf("ʧ�ܣ�\n");
			system("pause");
			break;
		default:
			printf("����Ƿ��������ԣ�\n");
			number = 1;
			system("pause");
			rewind(stdin);

		}
		rewind(stdin);
		system("cls");

	} while (number);
	return 0;
}