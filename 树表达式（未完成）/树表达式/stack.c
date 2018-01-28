#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * stack_creat()
{
	Stack * sk;
	sk = (Stack *)malloc(sizeof(Stack));
	if (sk == NULL)
	{
		fprintf(stderr, "can't creak stack");
		exit(EXIT_FAILURE);
	}
	sk->top = -1;
	
	return sk;
}

bool stack_is_empty(Stack * pstack)
{
	if (pstack == NULL)
	{
		fprintf(stderr, "No stack");
		exit(EXIT_FAILURE);
	}
	if (pstack->top == -1)
		return true;
	else
		return false;
}

bool stack_enter(Stack * pstack, int n)
{

	if (pstack == NULL)
	{
		fprintf(stderr, "No stack");
		exit(EXIT_FAILURE);
	}
	if ((pstack->top) == MAX - 1)
		return false;
	(pstack->top)++;
	pstack->date[pstack->top] = n;
	return true;
}

int stack_out(Stack * pstack)
{

	if (pstack == NULL)
	{
		fprintf(stderr, "No stack");
		exit(EXIT_FAILURE);
	}
	if (pstack->top == -1)
	{
		printf("can't out stack");
		exit(EXIT_FAILURE);
	}
	int i = pstack->date[pstack->top];
	(pstack->top)--;
	return i;
}

int stack_top(Stack * pstack)
{
	if (pstack == NULL)
	{
		fprintf(stderr, "No stack");
		exit(EXIT_FAILURE);
	}
	if (pstack->top != -1)
		return pstack->date[pstack->top];
	else
		exit(EXIT_FAILURE);
}