#ifndef _CHINESE_H_
#define _CHINESE_H_

typedef struct item
{
	char * chinese;
	char * graph;
}Item;

typedef struct node
{
	Item items;
	struct node * left;
	struct node * right;
}Node;

typedef struct node * Tree;

Node * Tree_Find(char ar[], Tree ptree);
Tree Tree_Chinese_Enter(char(*br)[2][10],int num);

#endif
