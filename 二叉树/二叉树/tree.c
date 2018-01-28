/* tree.c -- 树的支持函数 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

/* 局部数据类型 */
typedef struct pair
{
	Trnode * parent;
	Trnode  * child;
}Pair;

/* 局部函数原型 */
static Trnode * MakeNode(const Item * pi);
static bool ToLeft(const Item* i1, const Item * i2);
static bool ToRight(const Item * i1, const Item *i2);
static void AddNode(Trnode * new_node, Trnode * root);
static void InOrder(const Trnode * roots, void (*pfun)(Item  item));
static Pair SeekItem(const Item * pi, const Tree * ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode * ptr);

/* 函数定义 */
void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree* ptree)
{
	if (ptree->size == MAXSIZE)
		return true;
	else
		return false;
}

int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(Item * pi, Tree * ptree)
{
	Trnode * new_node;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "tree is full\n");
		return false;			/* 提前返回 */
	}

	if (SeekItem(pi, ptree).child != NULL)
	{
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;			/* 提前返回 */
	}

	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Could't creat node\n");
		return false;			/* 提前返回 */
	}

	ptree->size++;

	if (ptree->root == NULL)
		ptree->root = new_node;
	else
		AddNode(new_node, ptree->root);

	return true;
}

bool InTree(const Item * pi, const Tree* ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)
		DeleteNode(&(ptree->root));
	else if ((look.parent)->left == look.child)
		DeleteNode(&(look.parent->left));
	else
		DeleteNode(&(look.parent->right));
	ptree->size--;

	return true;
}

void Traverse(const Tree * ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeletAll(Tree * ptree)
{
	if (ptree != NULL)
	{
		DeleteAllNodes(ptree->root);
		ptree->root = NULL;
		ptree->size = 0;
	}
}

/* 局部函数 */
static void AddNode(Trnode * new_node, Trnode * root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft(const Item * i1, const Item * i2)
{
	int temp;

	if ((temp = strcmp(i1->name, i2->name)) < 0)
		return true;
	else if (temp == 0 && strcmp(i1->kind, i2->kind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item * i1, const Item * i2)
{
	int temp;

	if ((temp = strcmp(i1->name, i2->name)) > 0)
		return true;
	else if (temp == 0 && strcmp(i1->kind, i2->kind) > 0)
		return true;
	else
		return false;
}

static Pair SeekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;

	if (look.child == NULL)
		return look;

	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}

static void DeleteNode(Trnode **ptr)
{
	Trnode * temp;
	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(*ptr);
	}
	else
	{
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right);
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static void InOrder(const Trnode * roots, void (*pfun)(Item  item))
{
	if (roots != NULL)
	{
		InOrder(roots->left, pfun);
		(*pfun)(roots->item);
		InOrder(roots->right, pfun);
	}
}

static void DeleteAllNodes(Trnode * root)
{
	Trnode * pright;

	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static Trnode * MakeNode(const Item * pi)
{
	Trnode * new_node;

	new_node = (Trnode *)malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}