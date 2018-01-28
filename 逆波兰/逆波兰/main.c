#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int k=0;
	char br[10];
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (isdigit(ch))
		{
			printf("%d", ch - '0');
		}
		
		if (!(isdigit(ch)))
		{
			printf(" ");
			if (k == 0)
				br[k++] = ch;
			else
			{
				if (ch > 45 && br[k - 1] <= 45)
					br[k++] = ch;
				else
				{
					printf("%c ", br[k - 1]);
					br[k - 1] = ch;
				}
			}

			
		}
	}
	for (int i = k - 1; i >= 0; i--)
		printf(" %c", br[i]);
	getchar();
	return 0;
}