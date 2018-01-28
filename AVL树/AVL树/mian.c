#include <stdio.h>
#include "val.h"

int main(void)     //≤‚ ‘
{
	Val * VAL = NULL;

	int ar[5] = { 4,2,5,0,1 };
	for (int i = 0; i < 5; i++)
	{
		VAL = Val_Add(VAL, ar[i]);
	}
	
	
	
	printf("%d", VAL->right->date);
	getchar();
	return 0;
}