#include <stdio.h>

long int pow(long int x, unsigned int n);
int main(void)
{
	int a = pow(2, 11);
	printf("%d", a);
	getchar();
	return 0;
}

long int pow(long int x, unsigned int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	if (n % 2 == 0)
		return pow(x*x, n / 2);
	else
		return pow(x*x, n / 2)*x;
}