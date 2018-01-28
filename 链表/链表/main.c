#include <stdio.h>
#include "list.h"

int main(void)
{
	List list;
	InitializeList(&list);
	AddList(&list,5);
	AddList(&list, 6);
	InsertList(&list, 7, 2);
	Node * new = FindList(&list, 7);
	bool a =ListIsEmpty(&list);
	printf("%d", new->Num);
	
	bool b = ListIsLast(&list, new);

	printf("%d", b);
	
	getchar();
	return 0;
}