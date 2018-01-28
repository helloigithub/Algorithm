#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX 10
typedef struct stack
{
	int date[MAX];
	int top;
}Stack;

/* 操作：创建一个栈 */
/* 前置条件：无参数传入 */
/* 后置条件： 返回指向创建栈的指针 */
Stack * stack_creat();

/* 操作：判断栈是否为空 */
/* 前置条件：pstack是指向栈的指针 */
/* 后置条件： 若栈为空返回true，否则返回false */
bool stack_is_empty(Stack * pstack);

/* 操作：数据入栈 */
/* 前置条件：pstack指向一个栈，n是要入栈的数据 */
/* 后置条件：入栈成功返回true，否则返回false */
bool stack_enter(Stack * pstack, int n);

/* 操作：数据出栈 */
/* 前置条件：pstack指向一个栈 */
/* 后置条件：返回出栈的数据 */
int stack_out(Stack * pstack);

/* 操作：查看栈顶数据 */
/* 前置条件：pstack指向一个栈 */
/* 后置条件：返回栈顶数据 */
int stack_top(Stack * pstack);

/* 操作：打印栈中数据 */
/* 前置条件：pstack指向一个栈 */
/* 后置条件： 打印栈中数据 */
void stack_print(Stack * pstack);

#endif
