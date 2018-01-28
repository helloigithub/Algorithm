/* list.c -- 支持链表操作的函数 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void InitializeList(List * plist)
{
	*plist = NULL;
}

bool ListIsEmpty(const List * plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(const List * plist)
{
	Node * pt;
	bool FULL;

	pt = (Node *)malloc(sizeof(Node));
	
	if (pt == NULL)
		FULL = true;
	else
	{
		free(pt);
		FULL = false;
	}
	return FULL;
}

unsigned int ListCount(const List * plist)
{
	unsigned int count = 0;
	Node * pnode = *plist;

	while (pnode != NULL)
	{
		count++;
		pnode = pnode->Next;
	}

	return count;
}

bool ListIsLast(const List * plist, Node * pnode)
{
	return pnode->Next == NULL;
}

bool AddList(List * plist, int item)
{
	if (ListIsFull(plist))
	{
		printf("Fail to add");
		return false;
	}

	Node * pnew;
	pnew = (Node *)malloc(sizeof(Node));
	pnew->Num = item;
	pnew->Next = NULL;
	Node * scan = *plist;
	if (ListIsEmpty(plist))
		*plist = pnew;
	else
	{
		while (scan->Next != NULL)
			scan = scan->Next;
		scan->Next = pnew;
	}

	return true;
}

void DelList(List * plist, int item)
{
	Node * previous = FindPrevious(plist, item);
	Node * pthis = FindList(plist, item);
	if (pthis == NULL)
		return 0;
	if (previous == NULL)
		return 0;
	previous->Next = pthis->Next;
	free(pthis);
}

Node * FindList(List * plist, int item)
{
	Node * pnode = *plist;
	while (pnode != NULL)
	{
		if (pnode->Num == item)
			break;
		else
			pnode = pnode->Next;
	}
	return pnode;
}

Node * FindPrevious(List * plist, int item)
{
	Node * previous = *plist;
	if (previous == NULL)
		return NULL;
	while (previous->Next != NULL)
	{
		if (previous->Next->Num == item)
		{
			return previous;
		}
		else
			previous = previous->Next;
	}
		return NULL;
}

bool InsertList(List * plist, int item, unsigned int position)
{
	Node * pnew;
	pnew = (Node *)malloc(sizeof(Node));
	pnew->Num = item;
	Node * pnode = *plist;
	int count = ListCount(plist);
	if (count + 1 < position)
		return false;
	if (position == 1)
	{
		pnew->Next = pnode;
		*plist = pnew;
	}
	for (int i = 2; i < position;i++)
		pnode = pnode->Next;
	pnew->Next = pnode->Next;
	pnode->Next = pnew;

	return true;
}

