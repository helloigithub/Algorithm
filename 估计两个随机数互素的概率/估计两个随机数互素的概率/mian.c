#include <stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N);

int main(void)
{
	int Rel = 0; int Tot = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = i + 1; j <= 100; j++)
		{
			Tot++;
			if (Gcd(i, j) == 1)
				Rel++;
		}
	printf("%d//%d", Rel, Tot);
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