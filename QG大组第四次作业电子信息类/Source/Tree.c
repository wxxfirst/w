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
			printf("请输入选择的选择的序号：");
			if (scanf_s("%d", &number) == 0)
			{
				printf("输入非法！请重新输入！\n");
				flag = 1;
				rewind(stdin);
			}
			else
				flag = 0;
		} while (flag);

		switch (number)
		{
		case 0:
			printf("你的选择是退出！\n");
			break;

		case 1:
			printf("你的选择是初始化二叉树！\n");
			sign = Init_BiTree(&L);
			if (sign)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;

		case 2:
			printf("你的选择是数据插入二叉树！\n");
			rewind(stdin);
			flag = 0;
			do {
				printf("请输入插入的数值：");
				if (scanf_s("%d", &data) == 0)
				{
					printf("输入非法！请重新输入！\n");
					flag = 1;
					rewind(stdin);
				}
				else
					flag = 0;
			} while (flag);
			rewind(stdin);
			sign = Insert_BiTree(L,data);
			if (sign==SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
			
		case 3:
			printf("你的选择是二叉树数值查找！\n");
			rewind(stdin);
			flag = 0;
			do {
				printf("请输入查找的数值：");
				if (scanf_s("%d", &data) == 0)
				{
					printf("输入非法！请重新输入！\n");
					flag = 1;
					rewind(stdin);
				}
				else
					flag = 0;
			} while (flag);
			rewind(stdin);
			sign = SearchBiTree(L, data);
			if (sign == SUCCESS)
				printf("查找成功！\n");
			else
				printf("查找失败！\n");
			system("pause");
			break;
			
		case 4:
			printf("你的选择是二叉树数值删除！\n");
			rewind(stdin);
			flag = 0;
			do {
				printf("请输入删除的数值：");
				if (scanf_s("%d", &data) == 0)
				{
					printf("输入非法！请重新输入！\n");
					flag = 1;
					rewind(stdin);
				}
				else
					flag = 0;
			} while (flag);
			rewind(stdin);
			sign = DeleteBiNode(&L, data);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
			
		case 5:
			printf("你的选择是二叉树先序遍历（递归）！\n");

			sign = PreOrderTraverse(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;

		case 6:
			printf("你的选择是二叉树先序遍历（非递归）！\n");

			sign = PreOrderTraverse_(L);
			Clear(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
		case 7:
			printf("你的选择是二叉树中序遍历（递归）！\n");

			sign = InOrderTraverse(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
		case 8:
			printf("你的选择是二叉树中序遍历（非递归）！\n");

			sign = InOrderTraverse_(L);
			Clear(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
		case 9:
			printf("你的选择是二叉树后序遍历（递归）！\n");

			sign = PostOrderTraverse(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
		case 10:
			printf("你的选择是二叉树后序遍历（非递归）！\n");

			sign = PostOrderTraverse_(L);
			Clear(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
		case 11:
			printf("你的选择是二叉树层次遍历！\n");

			sign = LevelOrder(L);
			if (sign == SUCCESS)
				printf("成功！\n");
			else
				printf("失败！\n");
			system("pause");
			break;
		default:
			printf("输入非法！请重试！\n");
			number = 1;
			system("pause");
			rewind(stdin);

		}
		rewind(stdin);
		system("cls");

	} while (number);
	return 0;
}