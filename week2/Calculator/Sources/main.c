
#include"H_calculator.h"

int main()
{	
	
	int q = 1;
	while (q)
	{
		Catalog();
		char str[100] = { "\0" };
		char* p = str;
		double* n1, * n2, a = 0, b = 0;
		char* p1, * p2;
		char stack1[50];                      //符号栈 栈顶指针p2，栈底指针p1 
		double stack2[50];                    //数字栈 栈顶指针n2，栈底指针n1 

		p1 = p2 = stack1;
		n1 = n2 = stack2;
		*p2++ = '#';
		printf("请输入需要计算的算术表达式：");
		gets(str);
		strcat(str, "#");
		int J = 1;                             //循环的开关
		while (J)
		{
			if (*p == 'q') { J = 0; q = 0; }
			if (*p <= '9' && *p >= '0')
			{
				a = a * 10 + (*p - '0');
				if (*(p + 1) > '9' || *(p + 1) < '0')
				{
					*n2++ = a;
					a = 0;
				}
				p++;
			}
			

			else
			{
				switch (Priority(*p, *(p2 - 1)))
				{
				case 0:
				{
					if (n1 != n2)	printf("计算结果为:%lf\n", *n1);
					else printf("似乎没有值qwq\n");                //不能不输入
					p++;
				}	break;
				case 1:
				{
					b = *--n2;
					if (n2 == n1)
					{
						printf("输入的式子好像不对哦，不要再为难我了，球球了qwq\n");
						J = 0;
						break;
					}
					switch (*(--p2))
					{
					case '+':*(n2 - 1) = *(n2 - 1) + b; break;
					case '*':*(n2 - 1) = *(n2 - 1) * b; break;
					case '-':*(n2 - 1) = *(n2 - 1) - b; break;
					case '/':
					{
						if (b == 0)
						{
							printf("被除数不能为0！qwq\n");
							J = 0;
						}
						else *(n2 - 1) = *(n2 - 1) / b;
					}	break;
					case'(':
					{
						printf("括号的输入有一点小问题呀！\n");
						J = 0;
					}   break;
					case')':
					{
						printf("括号的输入有一点小问题呀！\n");
						J = 0;
					}   break;

					}
				}break;
				case 2:
					*p2++ = *p++;
					break;
				case 3:
				{
					p++;
					p2--;
				}	break;
				case 4:
				{
					if (*p == 'q') printf("再见 qwq\n");
					else printf("老哥，有符号输错了叭！\n");
					p++;
					J = 0;
				}	break;

				}
			}

			if (*p == '\0') J = 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
