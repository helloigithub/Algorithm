/* 使用二叉查找树 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"

char menu(void);
void addpet(Tree * pt);
void droppet(Tree * pt);
void showpets(const Tree * pt);
void findpet(const Tree * pt);
void printitem(Item item);
void uppercase(char * str);
char * s_gets(char * st, int n);

int main(void)
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch(choice)
		{
			case 'a': addpet(&pets);
				break;
			case 'l': showpets(&pets);
				break;
			case 'f': findpet(&pets);
				break;
			case 'n': printf(" %d pets in club\n", TreeItemCount(&pets));
				break;
			case 'd': droppet(&pets);
				break;
			default: printf("Switching error");
		}
	}
	DeletAll(&pets);
	puts("Bye.");

	getchar();
	return 0;
}

char menu(void)
{
	int ch;

	puts("Nerfville pet club menbership program");
	puts("Enter the letter corresponding to your choice:");
	puts(" a) add a pet			l) show list of pets");
	puts(" n) number of pets		f) find pets");
	puts(" d) delete a pet		q) quit");
	while ((ch = getchar()) != EOF)
	{
		while (getchar() != '\n');
		ch = tolower(ch);
		if (strchr("alrfndq", ch) == NULL)
			puts("Please enter an a l f n d or q:");
		else
			break;
	}
	if (ch == EOF)
		ch = 'q';
	return ch;
}

void addpet(Tree *pt)
{
	Item temp;

	if (TreeIsFull(pt))
		puts(" no room in the club!");
	else
	{
		puts("please enter name of pet:");
		s_gets(temp.name,SLEN);
		puts("please enter pet kind:");
		s_gets(temp.kind, SLEN);
		uppercase(temp.name);
		uppercase(temp.kind);
		AddItem(&temp, pt);
	}
}

void showpets(const  Tree * pt)
{
	if (TreeIsEmpty(pt))
		puts("No entries!");
	else
		Traverse(pt, printitem);
}

void printitem(Item item)
{
	printf("Pet: %-19s  kind: %-19s\n", item.name, item.kind);
}

void findpet(const Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}
	puts("Please enter name of pet yuo wish to find:");
	s_gets(temp.name, SLEN);
	puts("Please enter pet kind:");
	s_gets(temp.kind, SLEN);
	uppercase(temp.name);
	uppercase(temp.kind);
	printf("%s the %s ", temp.name, temp.kind);
	if (InTree(&temp, pt))
		printf("is a member\n");
	else
		printf("is not a member.\n");
}

void droppet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		puts("No entries!");
		return;
	}

	puts("please enter name of pet you wish to delete:");
	s_gets(temp.name, SLEN);
	puts("Please enter pet kind:");
	s_gets(temp.kind, SLEN);
	uppercase(temp.name);
	uppercase(temp.kind);
	printf("%s of %s ", temp.name, temp.kind);
	if (DeleteItem(&temp, pt))
		printf("is dropped from the club.\n");
	else
		printf("is not a member");
}

void uppercase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

char* s_gets(char *st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (*find)
			*find = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}