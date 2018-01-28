#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "chinese.h"


static Node * Make_Node(char(*ar)[10]);
static Tree Node_Insert(Tree ptree, Node * pnode);

Tree Tree_Chinese_Enter(char(*br)[2][10],int num)
{
	Node * pnode;
	Tree  ptree = NULL;
	for (int i = 0; i < num; i++)
	{
		pnode = Make_Node(br[i]);
		ptree = Node_Insert(ptree, pnode);
	}
	return ptree;
}

static Node * Make_Node(char (*ar)[10])
{
	Node * new_node;
	new_node = (Node *)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		fprintf(stderr, "can't creat node");
		exit(EXIT_FAILURE);
	}
	new_node->items.chinese = ar[0];
	new_node->items.graph = ar[1];
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

static Tree Node_Insert(Tree ptree, Node * pnode)
{
	if (ptree == NULL)
		ptree = pnode;
	else if (strcmp(ptree->items.chinese, pnode->items.chinese) > 0)
		ptree->left=Node_Insert(ptree->left, pnode);
	else if (strcmp(ptree->items.chinese, pnode->items.chinese) < 0)
		ptree->right=Node_Insert(ptree->right, pnode);

	return ptree;
}

Node * Tree_Find(char ar[], Tree ptree)
{
	while (ptree != NULL)
	{
		if (strcmp(ar, ptree->items.chinese) < 0)
			ptree = ptree->left;
		else if (strcmp(ar, ptree->items.chinese) > 0)
			ptree = ptree->right;
		else
			break;
	}
	return ptree;
}

