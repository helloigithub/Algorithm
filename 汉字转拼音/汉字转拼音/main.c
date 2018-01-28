#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "chinese.h"

char * s_gets(char * st, int n);
int main(void)
{
	FILE  * fp = fopen("chinese.dat", "r");
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
	fclose(fp);
	Tree  chinese_tree = Tree_Chinese_Enter(chinese, i + 1);
	char ar[100][3];
	int n = 0,m=0;
	while ((ch = getchar()) != '\n')
	{
		if (ch < 0)
		{
			n++;
			ar[m][n - 1] = ch;
			if (n % 2 == 0)
			{
				ar[m][n] = '\0';
				Node * pnode = Tree_Find(ar[m], chinese_tree);
				if (pnode == NULL)
					printf("%s", ar[m]);
				else
					printf("%s ", pnode->items.graph);
				m++;
				n = 0;
			}
		}
		else
			printf("%c ", ch);
	}
	
	
	getchar();
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}

