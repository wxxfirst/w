  #include "Sort.h"

//菜单
void menus()
{
	printf("*********************************************\n");
	printf("**                   menus                 **\n");
	printf("**          0、退出                        **\n");
	printf("**          1、直接插入排序（升序）        **\n");
	printf("**          2、直接插入排序（降序）        **\n");
	printf("**          3、归并排序（升序）            **\n");
	printf("**          4、快速排序（递归、升序）      **\n");
	printf("**          5、计数排序（升序）            **\n");
	printf("**          6、基数排序（升序）            **\n"); 
	printf("*********************************************\n");
}

//数据生成函数
Status data(SqlistL L,int number)
{
	if (!L)
		return ERROR;
	
	L->count = number;
	srand((unsigned int)time(NULL));
	for (int i = 1; i <= L->count; i++)
	{
		L->num[i] = rand() % L->count;
	}
	return SUCCESS;
}
// 文件写入函数
Status FileSave(SqlistL L,int number)
{
	if (!L)
		return ERROR;

	if (!L->count)
		return FAIL;

	FILE* fp = NULL;

	switch (number)
	{
	case 1:
		fp = fopen("C:/Users/温/data1.txt", "w+");
		break;
	case 2:
		fp = fopen("C:/Users/温/data2.txt", "w+");
		break;
	case 3:
		fp = fopen("C:/Users/温/data3.txt", "w+");
		break;
	}

	if (!fp)
	{
		printf("文件打开失败！");
		return FAIL;
	}


	for (int i = 1; i <= L->count; i++)
	{
		int num = fprintf(fp, "%d ", L->num[i]);
	}
	fclose(fp);

	return SUCCESS;
}
// 文件读取函数
Status FileRead(SqlistL L,int number)
{
	if (!L)
		return ERROR;

	FILE* fp = NULL;
	switch (number)
	{
	case 1:
		fp = fopen("C:/Users/温/data1.txt", "w+");
		break;
	case 2:
		fp = fopen("C:/Users/温/data2.txt", "w+");
		break;
	case 3:
		fp = fopen("C:/Users/温/data3.txt", "w+");
		break;
	}

	if (!fp)
	{
		printf("打开文件失败！");
		return ERROR;
	}
	else
	{
		for (int i = 1; i <= L->count; i++)
		{
			int num=fscanf(fp, "%d ", &L->num[i]);
		}
	}

	fclose(fp);

	return SUCCESS;
}
//插入排序
//直接插入排序
//升序

Status InsertupSort(SqlistL L)
{
	if (!L)
		return ERROR;

	if (!L->count)
		return FAIL;

	int i = 1;
	
	for (i=1; i <=L->count; i++)
	{
		if (L->num[i] > L->num[i + 1])
		{
			L->num[0] = L->num[i+1];
			for (int j = 1; j < i; j++)
			{
				if (L->num[j] > L->num[0])
				{
					int k = i;
					for (; j<= k; k--)
					{
						L->num[k + 1] = L->num[k];
					}
					L->num[k++] = L->num[0];
					break;
				}
			}

			
		}
	}
	

	return  SUCCESS;

}

//降序
Status InsertdownSort(SqlistL L)
{
	if (!L)
		return ERROR;

	if (!L->count)
		return FAIL;

	int i = 2;

	
	for (; i <= L->count; i++)
	{
		if (L->num[i] >L->num[i -1])
		{
			L->num[0] = L->num[i];
			for (int j = 1; j < i; j++)
			{
				if (L->num[j] < L->num[0])
				{
					int k = i;
					for (; j < k; k--)
					{
						L->num[k] = L->num[k-1];
					}
					L->num[k] = L->num[0];
					break;
				}
			}
		}
	}
	
	return  SUCCESS;
}




//归并排序
Status MergeupSort(SqlistL L)
{
	if (!L)
		return ERROR;

	if (!L->count)
		return FAIL;
	
	int* num = (int*)malloc(sizeof(int) *( L->count+1));
	if (!num)
	{
		printf("分配内存失败！\n");
		return FAIL;
	}
	else
	{
		for (int i = 0; i <= L->count; i++)
			num[i] = L->num[i];
		msort(num, L->num, 1, L->count );
	}

	free(num);
	num = NULL;
	return SUCCESS;
}

Status merge(int num1[], int num2[], int left, int mid, int right)
{

	int l = left;
	int r = mid + 1;
	int t = left;

	while (l <= mid && r <= right)
	{
		if (num1[l] <= num2[r])
			num2[t++] = num1[l++];
		else
			num2[t++] = num1[r++];
	}

	while (l <= mid)
		num2[t++] = num1[l++];
	while (r <= right)
		num2[t++] = num1[r++];

	for (int i = left; i <= right; i++)
	{
		num1[i] = num2[i];
	}

	return SUCCESS;
}

Status msort(int num1[], int num2[], int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		msort(num1, num2, left, mid);
		msort(num1, num2, mid + 1, right);
		merge(num1, num2, left, mid, right);
		return SUCCESS;
	}
	else
		return SUCCESS;
}


//快速排序递归
Status QupSort_(SqlistL L,int left,int right)
{
	if (!L)
		return ERROR;

	if (!L->count)
		return FAIL;

	if (left < right&&right-left>1)
	{
		int sign = QSort(L, left, right);
		if (sign)
		{
			QupSort_(L, left, sign);
			QupSort_(L, sign + 1, right);
		}
		else
			return SUCCESS;
	}

	return SUCCESS;

}

int QSort(SqlistL L, int left, int right)

{
	if (!L)
		return 0;
	
	if (!L->count || right == left)
		return 0;

	int l = left;
	int r = right;
	if (l < r)
	{
		
				L->num[0] = L->num[l];
				
				while (l < r)
				{
					while (l < r && L->num[0] <=L->num[r])
					{
						--r;
					}
					L->num[l] = L->num[r];
					while (l<r && L->num[0]>=L->num[l])
					{
						++l;
					}
					L->num[r] = L->num[l];
				}
				L->num[l] = L->num[0];
				return l;
		
		
	}
	else
		return 0;
}

//计数排序
Status CountSort(SqlistL L)
{
	if (!L)
		return ERROR;

	if (L->count<=0)
		return FAIL;

	int min = L->num[1];
	int max = L->num[1];

	for (int j = 2; j <=L->count; j++)
	{
		if (L->num[j] < min)
			min = L->num[j];
		else if (L->num[j] > max)
			max = L->num[j];
		else
			;

	}

	int length = max - min + 1;
	int *count=(int*)malloc(sizeof(int)*length);
	if (!count)
		return ERROR;

	for (int k = 0; k < length; k++)
	{
		count[k] = 0;
	}
	int i = 1;
	//收集数组
	for (; i <=L->count; i++)
	{
		count[L->num[i]-min]+=1;
	}
	//累加数组
	i = 0;
	for (; i < length-1; i++)
	{
		count[i + 1] += count[i];
	}


	//结果数组
	for (int j = length-1; 0 <= j; j--)
	{
		while(count[j]>0)
		{ 
			L->num[count[j]] = j+min;
			count[j]--;
		}
	}

	free(count);
	count = NULL;

	return SUCCESS;
}


//基数计数排序
//百位数

Status CountSort_(SqlistL L,int number)
{
	if (!L)
		return ERROR;
	if (L->count <= 0)
		return FAIL;

	
	int* count = (int*)malloc(sizeof(int) * 10);
	int* temp = (int*)malloc(sizeof(int)*(L->count+1) );

	if (!count||!temp)
		return ERROR;

	for (int k = 0; k < 10; k++)
	{
		count[k] = 0;

	}
	temp[0] = 0;
	for (int k = 1; k <= L->count; k++)
	{
		temp[k] = L->num[k];
	}
	//统计数组
	int i = 0;
	for (; i <= L->count; i++)
	{
		count[L->num[i]/(int)pow(10,number-1)%10]++;
	}

	//结果数组

	for (int k = 0; k < 9; k++)
	{
		count[k + 1] += count[k];
	}
	//排序
	int t = 0;
	int num = L->count;
	
	for (int k = 9; 0 <= k; k--)
	{
			for (int i = num; 0<i; i--)
			{
				t = temp[i] / (int)pow(10, number - 1) % 10;
				if (t == k)
				{
					L->num[count[k]--] = temp[i];
					if (count[k] == 0)
						break;

				}
			}
		
	}

	

	count = NULL;
	free(count);
	count = NULL;
	free(temp);
	temp = NULL;

	return SUCCESS;

}
Status RadixCountSort(SqlistL L)
{
	if (!L)
		return ERROR;

	if (L->count<=0)
		return FAIL;

	int max = L->num[1];
	for (int k = 2; k <= L->count; k++)
	{
		if (L->num[k] > max)
			max = L->num[k];
	}
	int count = 0;
	int t = max;
	while (t /= 10)
	{
		CountSort_(L, ++count);
	}
	CountSort_(L, ++count);
	return SUCCESS;

}

