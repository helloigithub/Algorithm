#include <stdio.h>
int main(void)
{
	int ar[7] = { -1, 1, 5, -7, 11 ,-1,6};
	int ThisSum=0, MaxSum=0;
	for (int i = 0; i < 7; i++)
	{
		ThisSum += ar[i];
		if (ThisSum < 0)
			ThisSum = 0;
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
	}
	printf("%d", MaxSum);
	getchar();
	return 0;
}