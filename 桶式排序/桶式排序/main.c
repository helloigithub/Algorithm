//桶式排序有很多局限性，第一，数组元素必须都是正整数
//第二，数组元素不能太大，如果排序的数中有1001，那么我们就要构建一个1001大小的数组

#include <stdio.h>
#include <string.h>
#define MAX 100

void bucketsort(int A[], int size, int max_num)   //size表示排序数组大小，nax_num表示排序数组中的最大值
{
	int count[MAX];
	memset(count, 0, sizeof(count));
	for (int i = 0; i < size; i++)
		++count[A[i]];

	for (int j = 0; j <= max_num; j++)
		while (count[j]>0)
		{
			printf("%d ", j);
			count[j]--;
		}
	printf("\n");
}

int main(void)			//测试
{
	int a[] = { 2, 5, 6, 12, 4, 8, 8, 6, 7, 8, 8, 10, 7, 6, 0, 1 };
	bucketsort(a, sizeof(a) / sizeof(a[0]), 12);
	getchar();
	return 0;
}