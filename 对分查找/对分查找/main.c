#include <stdio.h>

int BinarySearch(const int A[], int X, int N);
int main(void)
{
	int ar[5] = { 1, 2, 3, 4, 5 };
	int found = BinarySearch(ar, 5, 5);
	printf("%d", found);
	getchar();
	return 0;
}

int BinarySearch(const int A[], int X, int N)
{
	int low, mid, high;

	low = 0;
	high = N - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (A[mid] < X)
			low = mid + 1;
		else if (A[mid]>X)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}