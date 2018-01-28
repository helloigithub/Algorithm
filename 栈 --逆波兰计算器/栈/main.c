#include <stdio.h>
#include <string.h>
#include "stack.h"

//输入字符串的函数
char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}

//优先级判断函数
int set_first(int sign)
{
	switch (sign)
	{
	case '(': return 0; break;
	case '+': 
	case '-': return 1; break;
	case '*':
	case '/': return 2; break;
	default: return -1;
	}
}

//将两个数出栈，再把根据符号计算后的数入栈
void calculate_two(Stack * pstack, int sign)
{
	int num;
	int num1 = stack_out(pstack);
	int num2 = stack_out(pstack);
	switch (sign)
	{
	case '+': num = num1 + num2; break;
	case '_': num = num2 - num1; break;
	case '*': num = num1 * num2; break;
	case '/': num = num2 / num1; break;
	}
	stack_enter(pstack, num);
}

//符号栈比较
void sign_enter(Stack * nstack, Stack * sstack, int sign)
{
	int topsign;

	if (stack_is_empty(sstack) || sign == '(')
	{
		stack_enter(sstack, sign);
		return;
	}
	topsign = stack_top(sstack);

	if (set_first(sign) > set_first(topsign))
	{
		stack_enter(sstack, sign);
		return;
	}
	while (set_first(sign) <= set_first(topsign))
	{
		calculate_two(nstack, topsign);
		stack_out(sstack);
		if (stack_is_empty(sstack))
			break;
		topsign = stack_top(sstack);
	}
	stack_enter(sstack, sign);
	return;
}

//计算括号中的值
void right_brackets(Stack * nstack, Stack * sstack)
{
	int topsign = stack_top(sstack);
	while (topsign != '(')
	{
		calculate_two(nstack, topsign);
		stack_out(sstack);
		topsign = stack_top(sstack); 
	}
	stack_out(sstack);
}

int main(void)
{
	char str[100];
	printf("输入要计算的表达式：");
	s_gets(str, 100);

	int value=0;
	int i=0;
	int flag=0;

	Stack * num0, *sign0;
	num0 = stack_creat();
	sign0 = stack_creat();

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10 + str[i]-'0';
			flag = 1;
		}
		else
		{
			if (flag)
			{
				stack_enter(num0, value);
				flag = 0;
				value = 0;
			}
			if (str[i] == ')')
				right_brackets(num0, sign0);
			else
				sign_enter(num0,sign0,str[i]);
		}
		i++;
	}
	if (flag)
	{
		stack_enter(num0, value);
		while (!(stack_is_empty(sign0)))
			calculate_two(num0, stack_out(sign0));
	}
	printf("%d", num0->date[num0->top]);

	getchar();
	return 0;
}