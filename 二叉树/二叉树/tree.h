/* tree.h -- ��������� */
/*			���в��������ظ����� */	
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>

/* ���ݾ���������¶��� Item */
#define SLEN 20
typedef struct item
{
	char name[SLEN];
	char kind[SLEN];
}Item;

#define MAXSIZE 10
typedef struct trnode
{
	Item item;
	struct trnode * left;
	struct trnode * right;
}Trnode;

typedef struct tree
{
	Trnode * root;
	int size;
}Tree;

/* ����ԭ�� */

/* ������������ʼ��Ϊ�� */
/* ǰ��������ptreeָ��һ���� */
/* ����������������ʼ��Ϊ�� */
void InitializeTree(Tree* ptree);

/* ������ȷ�����Ƿ�Ϊ�� */
/* ǰ��������ptreeָ��һ���� */
/* ���������������Ϊ�գ��ú�������true�����򷵻�false */
bool TreeIsEmpty(const Tree * ptree);

/* ������ȷ�����Ƿ����� */
/* ǰ��������ptreeָ��һ���� */
/* ����������������������ú�������true�����򷵻�false */
bool TreeIsFull(const Tree * ptree);

/* ������ȷ���������� */
/* ǰ��������ptreeָ��һ���� */
/* ���������������������� */
int TreeItemCount(const Tree * ptree);

/* ���������������һ���� */
/* ǰ��������pi�Ǵ������ĵ�ַ��ptreeָ��һ���Ѿ���ʼ������ */
/* �������������������ӣ��ú��������������һ�������true�����򷵻�false */
bool AddItem(Item * pi, Tree * ptree);

/* �����������в���һ���� */
/* ǰ��������piָ��һ���ptreeָ��һ���Ѿ���ʼ������ */
/* ��������������������з���true�����򷵻�false */
bool InTree(const Item * pi, const Tree * ptree);

/* ������������ɾ��һ���� */
/* ǰ��������pi��ɾ����ĵ�ַ��ptreeָ��һ���Ѿ���ʼ������ */
/* ������������������гɹ�ɾ��һ����ú�������true�����򷵻�false */
bool DeleteItem(const Item * pi, Tree * ptree);

/* �������Ѻ������������е�ÿһ�� */
/* ǰ��������ptreeָ��һ������pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ */
/* ����������pfunָ����������Ϊ���е�ÿһ��ִ��һ�� */
void Traverse(const Tree * ptree, void(*pfun)(Item item));

/* ������ɾ�����е��������� */
/* ǰ��������ptreeָ��һ���Ѿ���ʼ������ */
/* ��Ϊ�� */
void DeletAll(Tree * ptree);

#endif