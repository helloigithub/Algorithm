#include <stdio.h>

#define RAdIX_10 10		//整形排序
#define KEYNUM_10 10	//整形位数

int GetNumInPos(int num, int pos)   //找到num从低到高的第pos位数
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}

void ReadixSort(int * DateArray, int DateNum)
{
	int * radixarrays[RAdIX_10];     //0-9的序列空间
	for (int i = 0; i < RAdIX_10; i++)
	{
		radixarrays[i] = (int *)malloc(sizeof(int)*(DateNum + 1));
		radixarrays[i][0] = 0;
	}

	for (int pos = 1; pos <= KEYNUM_10; pos++)
	{
		for (int i = 0; i < DateNum; i++)
		{
			int num = GetNumInPos(DateArray[i], pos);
			int index = ++radixarrays[num][0];
			radixarrays[num][index] = DateArray[i];
		}

		for (int i = 0, j = 0; i < RAdIX_10; i++)
		{
			for (int k = 1; k <= radixarrays[i][0]; k++)
				DateArray[j++] = radixarrays[i][k];
			radixarrays[i][0] = 0;
		}
	}
}

int main(void)
{
	int ar[10] = { 10, 9876, 565, 12, 105794564, 15648, 1, 999, 1235648, 156483 };
	ReadixSort(ar, 10);
	for (int i = 0; i < 10; i++)
		printf("%d\n", ar[i]);
	getchar();
	return 0;
}