
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
		char stack1[50];                      //����ջ ջ��ָ��p2��ջ��ָ��p1 
		double stack2[50];                    //����ջ ջ��ָ��n2��ջ��ָ��n1 

		p1 = p2 = stack1;
		n1 = n2 = stack2;
		*p2++ = '#';
		printf("��������Ҫ������������ʽ��");
		gets(str);
		strcat(str, "#");
		int J = 1;                             //ѭ���Ŀ���
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
					if (n1 != n2)	printf("������Ϊ:%lf\n", *n1);
					else printf("�ƺ�û��ֵqwq\n");                //���ܲ�����
					p++;
				}	break;
				case 1:
				{
					b = *--n2;
					if (n2 == n1)
					{
						printf("�����ʽ�Ӻ��񲻶�Ŷ����Ҫ��Ϊ�����ˣ�������qwq\n");
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
							printf("����������Ϊ0��qwq\n");
							J = 0;
						}
						else *(n2 - 1) = *(n2 - 1) / b;
					}	break;
					case'(':
					{
						printf("���ŵ�������һ��С����ѽ��\n");
						J = 0;
					}   break;
					case')':
					{
						printf("���ŵ�������һ��С����ѽ��\n");
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
					if (*p == 'q') printf("�ټ� qwq\n");
					else printf("�ϸ磬�з�������˰ȣ�\n");
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
