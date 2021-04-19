#include"Sort_h.h"



void catalog()                         //目录  
{
	printf("----------------1 生成数组\t\t----------------\n");
	printf("----------------2 插入排序\t\t----------------\n");
	printf("----------------3 快速排序\t\t----------------\n");
	printf("----------------4 归并排序\t\t----------------\n");
	printf("----------------5 基数排序\t\t----------------\n");
	printf("----------------6 计数排序\t\t----------------\n");
	printf("----------------7 大数据量时排序所需时间----------------\n");
	printf("----------------8 100*100k排序所需用时\t----------------\n");
	printf("----------------9 重新定义数组\t\t----------------\n");
	printf("----------------10 退出\t\t\t----------------\n");

}

void insertsort(int r[], int a)    //插入排序
{
	int i, j;

	for (i = 2; i <= a; i++)
	{
		r[0] = r[i];
		j = i - 1;
		while (r[0] < r[j])
		{
			r[j + 1] = r[j];
			j--;
		}
		r[j + 1] = r[0];

	}
}

void quick_sort(int r[], int begin, int end)    //快速排序
{
	if (begin > end)	return;
	int m;
	int t = r[begin];
	int i = begin, j = end;
	while (i != j)
	{

		while (r[j] >= t && j > i) j--;
		while (r[i] <= t && j > i) i++;
		if (j > i)
		{
			m = r[i];
			r[i] = r[j];
			r[j] = m;
		}
	}
	r[begin] = r[i];
	r[i] = t;
	quick_sort(r, begin, i - 1);
	quick_sort(r, i + 1, end);
}

void Merge(int r[], int r1[], int startIndex, int midIndex, int endIndex)
{
	int i = startIndex, j = midIndex + 1, k = startIndex;
	//首先将小的放在前面
	while (i != midIndex + 1 && j != endIndex + 1)
	{
		if (r[i] > r[j])//如果前半部分比后半部分大，就将小的放在前面
			r1[k++] = r[j++];
		else
			r1[k++] = r[i++];
	}
	while (i != midIndex + 1)
		r1[k++] = r[i++];//小的放在前面
	while (j != endIndex + 1)
		r1[k++] = r[j++];
	for (i = startIndex; i <= endIndex; i++)
		r[i] = r1[i];
}




void MergeSort(int r[], int r1[], int startIndex, int endIndex)
{
	int midIndex;
	if (startIndex < endIndex)
	{
		midIndex = startIndex + (endIndex - startIndex) / 2;//避免溢出int
		MergeSort(r, r1, startIndex, midIndex);
		MergeSort(r, r1, midIndex + 1, endIndex);
		Merge(r, r1, startIndex, midIndex, endIndex);
	}
}

void radixSort(int* a, int size)               //基数排序
{
	int** temp = (int**)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
	{
		temp[i] = (int*)malloc(sizeof(int) * MAX / 2);
	}
	int order[10] = { 0 };
	int i, j, k; //k表示当前比较的那一位上的具体数字
	int n; //n=1,10,100,1000...取决于a中的最大的数
	int p;
	n = 1;
	while (n <= 100)
	{
		for (i = 0; i < size; i++)
		{
			k = (a[i] / n) % 10;
			temp[k][order[k]] = a[i];
			order[k]++;
		}
		p = 0; //p为一次排序过程中,a的脚标
		for (i = 0; i < 10; i++)
		{
			if (order[i] != 0)
			{
				for (j = 0; j < order[i]; j++)
				{
					a[p] = temp[i][j];
					p++;
				}
				order[i] = 0;
			}
		}
		n *= 10;
	}
	free(temp);
}

void CountSort(int* a, int len)      //计数排序
{
	int max = a[0], min = a[0];
	for (int i = 0; i < len; i++) {
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int* b = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < len; i++) {
		b[a[i] - min] += 1;
	}
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (b[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(b);
}

void print(int a[], int len)                          //打印
{
	for (int i = 1; i <= len; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

int** Data_Generation(int rows, int columns) //计数排序
{
	int i, j;
	int** p = (int**)malloc(sizeof(int) * rows);
	for (int i = 0; i < rows; i++)
	{
		p[i] = (int*)malloc(sizeof(int) * columns);
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{

		}
	}
	return **p;
}

void data(int a1[],int a2[],int a3[])
{
	for (int i = 0; i < 10000; i++)
	{
		int y = rand() % 1000000;
		a1[i] = y;
		
	}
	clock_t start, finish;
	double TheTimes;
	printf("10000层次：\n");
	printf("插入排序需要的时间为");
	start = clock();
	insertsort(a1, 10000);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	//printf("快速排序需要的时间为");//   
	//start = clock();
	//quick_sort(a1, 1, 10000);
	//finish = clock();
	//TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 10000; i++)
	{
		int y = rand() % 1000000;
		a1[i] = y;
		
	}
	printf("归并排序需要的时间为");
	start = clock();
	int* a_1 = (int)malloc(10000 * sizeof(int));
	MergeSort(a1, a_1, 1, 10000 - 1);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	free(a_1);
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 10000; i++)
	{
		int y = rand() % 1000000;
		a1[i] = y;

	}
	printf("基数排序需要的时间为");
	start = clock();
	radixSort(a1, 10001);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 10000; i++)
	{
		int y = rand() % 1000000;
		a1[i] = y;

	}
	printf("计数排序需要的时间为");
	start = clock();
	CountSort(a1, 10000 + 1);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);



	for (int i = 0; i < 50000; i++)
	{
		int y = rand() % 1000000;
		a2[i] = y;
		
	}
	
	printf("50000层次：\n");
	printf("插入排序需要的时间为");
	start = clock();
	insertsort(a2, 50000);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	printf("快速排序需要的时间为");//   
	start = clock();
	quick_sort(a1, 1, 50000);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 50000; i++)
	{
		int y = rand() % 1000000;
		a2[i] = y;

	}
	printf("归并排序需要的时间为");
	start = clock();
	int* a_2 = (int)malloc(50000 * sizeof(int));
	MergeSort(a2, a_2, 1, 50000 - 1);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	free(a_2);
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 50000; i++)
	{
		int y = rand() % 1000000;
		a2[i] = y;

	}
	printf("基数排序需要的时间为");
	start = clock();
	radixSort(a2, 50001); 
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 50000; i++)
	{
		int y = rand() % 1000000;
		a2[i] = y;

	}
	printf("计数排序需要的时间为");
	start = clock();
	CountSort(a2, 50000 + 1);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);


	

	
	
	printf("200000层次：\n");

	

	for (int i = 0; i < 200000; i++)
	{
		int y = rand() % 1000000;
		a3[i] = y;

	}
	printf("插入排序需要的时间为");
	start = clock();
	insertsort(a3, 200000);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	//printf("快速排序需要的时间为");//   
	//start = clock();
	//quick_sort(a1, 1, 200000);
	//finish = clock();
	//TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	//printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 200000; i++)
	{
		int y = rand() % 1000000;
		a3[i] = y;

	}
	printf("归并排序需要的时间为");
	start = clock();
	int* a_3 = (int)malloc(200000 * sizeof(int));
	MergeSort(a3, a_3, 1, 200000 - 1);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	free(a_3);
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 200000; i++)
	{
		int y = rand() % 1000000;
		a3[i] = y;

	}
	printf("基数排序需要的时间为");
	start = clock();
	radixSort(a3, 200001);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);

	for (int i = 0; i < 200000; i++)
	{
		int y = rand() % 1000000;
		a3[i] = y;

	}
	printf("计数排序需要的时间为");
	start = clock();
	CountSort(a3, 200000 + 1); 
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%lf秒。\n", TheTimes);
}


void _100()
{
	int e[101] = { 0 };
	clock_t start, finish;
	double TheTimes;
	
	for (int j = 0; j < 100; j++)
	{
		int y = rand() % 1000000;
		e[j] = y;
		
	}
	start = clock();
	for(int i=0;i<100000;i++)	insertsort(e, 100);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("插入排序需要的时间为");
	printf("%lf秒。\n", TheTimes);

	for (int j = 0; j < 100; j++)
	{
		int y = rand() % 1000000;
		e[j] = y;
		
	}
	start = clock();
	for (int i = 0; i < 100000; i++)	quick_sort(e, 1, 100);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("快速排序需要的时间为");
	printf("%lf秒。\n", TheTimes);

	for (int j = 0; j < 100; j++)
	{
		int y = rand() % 1000000;
		e[j] = y;
		
	}
	start = clock();
	int* e1 = (int)malloc(100 * sizeof(int));
	for (int i = 0; i < 100000; i++)	MergeSort(e, e1, 1, 100 - 1);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	free(e1);
	printf("归并排序需要的时间为");
	printf("%lf秒。\n", TheTimes);

	for (int j = 0; j < 100; j++)
	{
		int y = rand() % 1000000;
		e[j] = y;
		
	}
	start = clock();
	for (int i = 0; i < 100; i++)	radixSort(e, 100);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("基数排序需要的时间为");
	printf("%lf秒。\n", TheTimes);

	for (int j = 0; j < 100; j++)
	{
		int y = rand() % 1000000;
		e[j] = y;
		
	}
	start = clock();
	for (int i = 0; i < 100000; i++)	CountSort(e, 100);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("计数排序需要的时间为");
	printf("%lf秒。\n", TheTimes);

	return;
	
}