#include <stdio.h>

int max(int a, int b, int c);
int MaxSubSum(const int A[], int Left, int Right);


int main(void)
{
	int ar[6] = { -1, 1,-1, 5, -4, 8 };
	int a = MaxSubSum(ar, 0, 5);
	printf("%d", a);
	getchar();
	return 0;
}

int MaxSubSum(const int A[], int Left, int Right)
{
	if (Left == Right)
		return A[Left];

	int mid = (Left + Right) / 2;

	int ThisLeftBorderSum=0, MaxLeftBorderSum=0;
	for (int i = mid; i >= Left; i--)
	{
		ThisLeftBorderSum += A[i];
		if (ThisLeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = ThisLeftBorderSum;
	}

	int ThisRightBorderSum = 0, MaxRightBorderSum=0;
	for (int i = mid + 1; i <= Right; i++)
	{
		ThisRightBorderSum += A[i];
		if (ThisRightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = ThisRightBorderSum;
	}

	int MaxLeftSum, MaxRightSum;
	MaxLeftSum = MaxSubSum(A, Left, mid);
	MaxRightSum = MaxSubSum(A, mid + 1, Right);

	return max(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}

int max(int a, int b, int c)
{
	int Max=a;

	if (b > Max)
		Max = b;
	if (c > Max)
		Max = c;

	return Max;
}