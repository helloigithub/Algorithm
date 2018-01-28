#include <stdio.h>
int MaxSubsequenceSum(const int A[], int N);
int main(void)
{
	int ar[5] = { 1, -1, 3, -2, 4 };
	int c=MaxSubsequenceSum(ar, 5);
	printf("%d", c);
	getchar();
	return 0;
}

int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, i, j, k;

	MaxSum = 0;
	for (i = 0; i < N; i++)
		for (j = i; j < N; j++)
		{
			ThisSum = 0;
			for (k = i; k <= j; k++)
				ThisSum += A[k];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	return MaxSum;
}