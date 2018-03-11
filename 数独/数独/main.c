#include <stdio.h>
#include <time.h>
#include <stdbool.h>

bool isok = false;

void force(int k,char *ar);
void show(char *ar);
int main(void)
{
	int start = clock();
	char ar[82] = "509004010600802005040300607004007900060920030900040070050010003090085020001200400";
	force(0, ar);
	int end = clock();
	printf("\n ºÄÊ±:%d ms",end - start);
	getchar();
	return 0;
}

void force(int k, char *ar)
{
	if (isok)
		return;
	if (!(ar[k]-'0'))
	{
		for (int m = 1; m <= 9; m++)
		{
			bool mm = true;
			for (int n = 0; n < 9; n++)
			{
				if ((m == ar[k % 9 + 9 * n]-'0') || (m == ar[k / 9 * 9 + n]-'0') || (m == ar[k / 27 * 27 + (k % 9 / 3) * 3 + n + n / 3 * 6]-'0'))
				{
					mm = false;
					break;
				}
			}
			if (mm)
			{
				ar[k] = m + '0';
				if (k == 80)
				{
					isok = true;
					show(ar);
					return;
				}
				force(k + 1,ar);
			}
		}
		ar[k] = 0 + '0';
		
	}
	else
	{
		if (k == 80)
		{
			isok = true;
			show(ar);
			return;
		}
		force(k + 1,ar);
	}
}

void show(char *ar)
{
	if (isok)
	{
		for (int i = 0; i <= 80; i++)
		{
			printf("%c ", ar[i]);
			if ((i + 1) % 9 == 0)
				printf("\n");
		}
	}
}