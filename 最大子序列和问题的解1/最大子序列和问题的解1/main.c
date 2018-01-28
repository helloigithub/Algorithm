#include <stdio.h>
int MaxSubsequenceSum(const int A[], int N);
int main(void)
{
	int ar[5] = { -1, 1, 4, -2, 5 };
	int c = MaxSubsequenceSum(ar, 5);
	printf("%d", c);
	getchar();
	return 0;
}

int MaxSubsequenceSum(const int A[], int N)
{
	int ThisSum, MaxSum, i, j;

	MaxSum = 0;
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];

			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}

	return MaxSum;
}