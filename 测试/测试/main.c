#include <stdio.h>
#include <ctype.h>

int main(void)
{
	FILE  * fp = fopen("chinese.txt", "r");
	char chinese[7000][2][10];
	int i = 0;
	int j = 0;
	char ch;

	while ((ch = getc(fp)) != EOF)
	{
		if (ch < 0)
		{
			chinese[i][0][0] = ch;
			chinese[i][0][1] = getc(fp);
			chinese[i][0][2] = '\0';
		}
		else if (isalpha(ch))
			chinese[i][1][j++] = ch;
		else if (ch == '\n')
		{
			ch = getc(fp);
			chinese[i][1][j] = '\0';
			i++;
			j = 0;
		}
	}
	chinese[i][1][j] = '\0';


	for (int m = 0; m <= i; m++)
	{
		printf("%s	", chinese[m][0]);
		printf("%s\n", chinese[m][1]);
	}

	printf("\nºº×Ö×Ü×ÖÊý£»%d", i + 1);
	fclose(fp);
	getchar();
	return 0;
}