#include <stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N);

int main(void)
{
	int gcd = Gcd(16, 60);
	printf("%d", gcd);
	getchar();
	return 0;
}

unsigned int Gcd(unsigned int M, unsigned int N)
{
	unsigned int rem;

	while (N > 0)
	{
		rem = M % N;
		M = N;
		N = rem;
	}
	
	return M;
}