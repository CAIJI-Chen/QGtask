#include<stdio.h>
int b[1000] = { 0 };
void qustion1(int a[], int len);


void qustion1(int a[], int len)
{
	int p = 0;
	int p1 = 0;
	int p2 = len-1;
	int m;	
	while (a[p1] == 0) p1++;
	while (a[p2] == 2) p2--;
	p = p1;
	while (p <= p2)
	{

		if (a[p] == 0)
		{
			m = a[p];
			a[p] = a[p1];
			a[p1] = m;
			p1++; 
			
			
		}
		if (a[p] == 2 && p2!=p)
		{
			m = a[p];
			a[p] = a[p2];
			a[p2] = m;
			p2--;


		}
		else p++;
		
	}

}

void print(int a[], int len)                          //打印
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

int main()
{
	int _len;
	printf("请输入你要生成的数组的长度(最多1000个)：");
	scanf("%d", &_len);
	while (getchar() != '\n')               //判断是否为非法输入
	{
		printf("非法输入，请重新输入：");
		while (getchar() != '\n');
		scanf("%d", &_len);
	}
	while (_len < 1 || _len>1000)                     //判断是否为正确的操作
	{
		printf("请输入正确的操作：");
		scanf("%d", &_len);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &_len);
		}
	}
	printf("请输入数据：\n");

	for (int i = 1; i <= _len; i++)
	{
		int x;
		scanf("%d", &x);
		while (getchar() != '\n')               //判断是否为非法输入
		{
			printf("非法输入，请重新输入：");
			while (getchar() != '\n');
			scanf("%d", &x);
		}
		while (x < 0 || x>2)                     //判断是否为正确的操作
		{
			printf("请输入正确的操作：");
			scanf("%d", &x);
			while (getchar() != '\n')               //判断是否为非法输入
			{
				printf("非法输入，请重新输入：");
				while (getchar() != '\n');
				scanf("%d", &x);
			}
		}
		b[i] = x;
	}

	printf("数组为：\n");
	print(b, _len);
	printf("排序后数组为：\n");
	qustion1(b, _len);
	print(b, _len);
	return 0;
}