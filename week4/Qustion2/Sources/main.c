#include<stdio.h>
int b[10000];

int FindNum(int* a, int left, int right, int k)
{
    int low = left;
    int high = right;
    int temp = a[low];
    int flag = 0;

    while (low < high)
    {
        if (0 == flag)
        {
            if (a[high] > temp)
            {
                high--;
            }
            else
            {
                a[low++] = a[high];
                flag = 1;
            }
        }
        else
        {
            if (a[low] < temp)
            {
                low++;
            }
            else
            {
                a[high--] = a[low];
                flag = 0;
            }
        }
    }


    if (k == low)
    {
        return temp;
    }
    else if (k > low)
    {
        return FindNum(a, low + 1, right, k);
    }
    else
    {
        return FindNum(a, left, low - 1, k);
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
    //int a[] = { 21,32,234,3,54,53,3,5,3 };
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

    for (int i = 0; i < _len; i++)
    {
        int x;
        scanf("%d", &x);
        while (getchar() != '\n')               //判断是否为非法输入
        {
            printf("非法输入，请重新输入：");
            while (getchar() != '\n');
            scanf("%d", &x);
        }
        
        b[i] = x;
    }

    printf("数组为：\n");
    print(b, _len);
    int k;
    while (1)
    {
        printf("请输入你要查第几小的元素(输入0退出)：\n");
        scanf("%d", &k);

        while (getchar() != '\n')               //判断是否为非法输入
        {
            printf("非法输入，请重新输入：");
            while (getchar() != '\n');
            scanf("%d", &k);
        }
        while (k < 0 || k>_len)                     //判断是否为正确的操作
        {
            printf("请输入正确的操作：");
            scanf("%d", &k);
            while (getchar() != '\n')               //判断是否为非法输入
            {
                printf("非法输入，请重新输入：");
                while (getchar() != '\n');
                scanf("%d", &k);
            }
        }

        if (k == 0) return 0;
        printf("%d", FindNum(b, 0, _len - 1, k - 1));
    }

}
